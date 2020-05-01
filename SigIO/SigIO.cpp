#include "SigIO.h"
#include <QDebug>





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
	Record* r = new Record(0,0,0,0,0,0);
	*fileStream >> *r;
	while (currentRec != recIndex)
	{
		currentRec++;
		*fileStream >> *r;
	}
	return r;
}

int SigFileIO::writeRecord(Record* r)
{
	basefile->seek(basefile->size());
	isEof = true;
	*fileStream << *r;
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
	//qDebug() << "write positions:";
	unsigned nlen = r.getNameLen();
	ds << r.getSize();
	ds << nlen;
	ds.writeRawData(r.getRawName(), nlen);
	ds << r.getSigLen();
	ds.writeRawData(r.getRawPref(), PREF_SIZE);
	ds.writeRawData(r.getRawHash(), HASH_SIZE);
	ds << r.getStrtOffs();
	ds << r.getStrtOffs();
	return ds;
}

QDataStream& operator >>(QDataStream& ds, Record& r)
{
	//qDebug() << "read positions:";
	unsigned n;
	ds >> n;
	ds >> n;
	char* buff = new char[n+1];
	buff[n] = '\0';
	ds.readRawData(buff, n);
	QString* s = new QString(buff);
	//TODO: а нужно удалять этот кустринг и байт эррэи далее?
	r.setName(s);
	ds >> n;
	r.setSigLen(n);
	delete[] buff;
	buff = new char[PREF_SIZE];
	ds.readRawData(buff, PREF_SIZE);
	QByteArray* ba = new QByteArray(buff, PREF_SIZE);
	r.setPref(ba);
	delete[] buff;
	buff = new char[HASH_SIZE];
	ds.readRawData(buff, HASH_SIZE);
	ba = new QByteArray(buff, HASH_SIZE);
	r.setHash(ba);
	ds >> n;
	r.setStrtOffs(n);
	ds >> n;
	r.setEndOffs(n);
	delete[] buff;
	return ds;
}
