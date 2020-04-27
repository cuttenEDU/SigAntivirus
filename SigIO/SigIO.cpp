#include "SigIO.h"
#include <QDebug>

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
	fileStream = new QDataStream(basefile);
	basefile->seek(0);
	isPrefixValid = true;
	if (basefile->size() == 0)
		//*fileStream << "zhmakin";
		basefile->write("zhmakin",7);
	else
	{
		QString pref;
		*fileStream >> pref;
		if (pref.compare("zhmakin"))
			basefile->seek(fileoffs);
		
		else
			isPrefixValid = false;
	}

	currentRec = 1;
}

Record* SigFileIO::readRecord(unsigned recIndex)
{
	if (isEof || recIndex > currentRec)
	{
		basefile->seek(fileoffs);
		currentRec = 1;
		isEof = false;
	}
	Record* r = new Record();
	*fileStream >> *r;
	while (currentRec != recIndex)
	{
		currentRec++;
		*fileStream >> *r;
	}
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


bool SigFileIO::is_prefix_valid() const
{
	return isPrefixValid;
}

QDataStream& operator <<(QDataStream& ds, const Record& r)
{
	//TODO: redo to read raw data(cause of serialization)
	qDebug() << "write positions:";
	ds << r.recLen;
	ds << r.nameLen;
	ds.writeRawData(r.name,r.nameLen);
	ds << r.sigLen;
	ds.writeRawData(r.pref, sizeof(r.pref));
	ds.writeRawData(r.hash, sizeof(r.hash));
	ds << r.strtoffs;
	ds << r.endoffs;
	return ds;
}

QDataStream& operator >>(QDataStream& ds, Record& r)
{
	//TODO: redo to read raw data(cause of serialization)
	qDebug() << "read positions:";
	ds >> r.recLen;
	ds >> r.nameLen;
	r.name = new char[r.nameLen];
	ds.readRawData(r.name,r.nameLen);
	ds >> r.sigLen;
	ds.readRawData(r.pref, sizeof(r.pref));
	ds.readRawData(r.hash, sizeof(r.hash));
	ds >> r.strtoffs;
	ds >> r.endoffs;
	return ds;
}
