#include "SigIO.h"


QString* Record::toString()
{
	QString* str = new QString("Record size: ");
	*str += this->recLen;
	*str += "\nName size: ";
	*str += this->nameLen;
	*str += "\nName: ";
	*str += this->name;
	*str += "\nSignature size: ";
	*str += this->sigLen;
	*str += "\nPrefix: ";
	*str += this->pref;
	*str += "\nHash: ";
	*str += this->hash;
	*str += "\nStart offset: ";
	*str += this->strtoffs;
	*str += "\nEnd offset: ";
	*str += this->endoffs;
	return str;
}

SigIO::SigIO()
{
}

SigFileIO::SigFileIO(QString fileName)
{
	basefile = new QFile(fileName);
	basefile->open(QIODevice::ReadWrite);
	basefile->seek(fileoffs);
	fileStream = new QDataStream(basefile);
	currentRec = 1;
}

Record* SigFileIO::readRecord(unsigned recIndex)
{
	if (isEof)
	{
		basefile->seek(fileoffs);
		currentRec = 1;
	}
	Record* r = new Record();
	do
	{
		*fileStream >> *r;
		currentRec++;
	}
	while (currentRec != recIndex);
	return r;

}

int SigFileIO::writeRecord(Record r)
{
	basefile->seek(basefile->size());
	isEof = true;
	*fileStream << r;
	return 0;
}

int SigFileIO::deleteRecord(unsigned recIndex)
{
    return 0;
}

QDataStream& operator << (QDataStream& ds, const Record& r)
{
	ds << r.recLen;
	ds << r.nameLen;
	ds << r.name;
	ds << r.sigLen;
	ds.writeRawData(r.pref, sizeof(r.pref));
	ds.writeRawData(r.hash, sizeof(r.hash));
	ds << r.strtoffs;
	ds << r.endoffs;
	return ds;
}

QDataStream& operator >> (QDataStream& ds, Record& r)
{
	ds >> r.recLen;
	ds >> r.nameLen;
	ds >> r.name;
	ds >> r.sigLen;
	ds.readRawData(r.pref, sizeof(r.pref));
	ds.readRawData(r.hash, sizeof(r.hash));
	ds >> r.strtoffs;
	ds >> r.endoffs;
	return ds;
}



