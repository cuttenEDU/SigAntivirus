#ifndef SIGIO_H
#define SIGIO_H

#include "SigIO_global.h"
#include <string>
#include <QTCore>



struct SIGIO_EXPORT Record
{
	unsigned recLen;
	unsigned nameLen;
	char* name;
	unsigned sigLen;
	char pref[50];
	char hash[32];
	unsigned strtoffs;
	unsigned endoffs;

	


	
	QString* toString();
};

class SIGIO_EXPORT SigIO
{
public:
	SigIO();
	unsigned recCount;
	virtual Record* readRecord(unsigned recIndex) = 0;
	virtual int writeRecord(Record r) = 0;
	virtual int deleteRecord(unsigned recIndex) = 0;
};

class SIGIO_EXPORT SigFileIO : public SigIO
{
public:
	SigFileIO(QString fileName);
	
	unsigned fileoffs = 7;
	
	Record* readRecord(unsigned recIndex);
	int writeRecord(Record r);
	int deleteRecord(unsigned recIndex);
	bool is_prefix_valid() const;

private:
	bool isPrefixValid;
	unsigned currentRec;
	bool isEof;
	QFile* basefile;
	QDataStream* fileStream;
	unsigned findRecInd(unsigned recIndex);
};

QDataStream& operator << (QDataStream& ds, const Record& r);
QDataStream& operator >> (QDataStream& ds, Record& r);

#endif // SIGBASEIO_H
