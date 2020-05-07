#include "SigIO.h"
#include <QDebug>





SigIO::SigIO(QObject* parent) : QObject(parent)
{
}

SigFileIO::SigFileIO(QString fileName,QObject* parent) : SigIO(parent)
{
	basefile = new QFile(fileName,this);
	basefile->open(QIODevice::ReadWrite);
	fileStream = new QDataStream(basefile);
	basefile->seek(0);
	isPrefixValid = true;
	int asd = 0;
	if (basefile->size() == 0)
	{
		basefile->write("zhmakin", 7);
		basefile->write((const char*)&asd, 4);
	}
	else
	{
		QString pref;
		*fileStream >> pref;
		if (pref.compare("zhmakin"))
			basefile->seek(fileoffs);
		else
			isPrefixValid = false;
	}
	currentRec = 0;
}


Record* SigFileIO::readRecord(unsigned recIndex)
{
	seekRec(recIndex);
	Record* r = new Record();
	*fileStream >> *r;
	return r;
}

int SigFileIO::writeRecord(Record* r)
{
	seekEnd();
	isEof = true;
	*fileStream << *r;
	//basefile->seek(fileoffs + 15);
	return fileStream->status();
}

int SigFileIO::deleteRecord(unsigned recIndex)
{
	
	return 0;
}


bool SigFileIO::is_prefix_valid() const
{
	return isPrefixValid;
}

void SigFileIO::seekRec(unsigned recIndex)
{
	qDebug() << "seeking to rec #" << recIndex;
	basefile->seek(fileoffs);
	for (int i = 0; i < recIndex; ++i)
	{
		unsigned recLen = 0;
		*fileStream >> recLen;
		qDebug() << "reclen=" << recLen;
		basefile->seek(basefile->pos() + recLen);
	}
	qDebug() <<"filepos="<< basefile->pos();
}

void SigFileIO::seekEnd()
{
	basefile->seek(basefile->size());
}

QDataStream& operator <<(QDataStream& ds, const Record& r)
{
	qint32 nlen = r.getNameLen();
	ds << r.getSize();
	ds << nlen;
	ds.writeRawData(r.getRawName(), nlen);
	ds << r.getSigLen();
	ds.writeRawData(r.getRawPref(), PREF_SIZE);
	ds.writeRawData(r.getRawHash(), HASH_SIZE);
	ds << r.getStrtOffs();
	ds << r.getEndOffs();
	return ds;
}

QDataStream& operator >>(QDataStream& ds, Record& r)
{
	unsigned n;
	ds >> n; // recsize read, but its not stored in class
	ds >> n;
	char* buff = new char[n+1];
	buff[n] = '\0';
	ds.readRawData(buff, n);
	QString* s = new QString(buff);
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
