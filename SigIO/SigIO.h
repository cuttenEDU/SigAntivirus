#ifndef SIGIO_H
#define SIGIO_H

#include "SigIO_global.h"
#include <string>
#include <QTCore>
#include "Record.h"

#define PREF_LEN 7
#define AMNT_LEN sizeof(unsigned)


class SIGIO_EXPORT SigIO : public QObject
{
	Q_OBJECT
public:
	SigIO(QObject* parent = nullptr);
	unsigned recCount;
	virtual Record* readRecord(unsigned recIndex) = 0;
	virtual Record* readRecord() = 0;
	virtual int writeRecord(Record* r) = 0;
};

class SIGIO_EXPORT SigFileIO : public SigIO
{
public:
	SigFileIO(QObject* parent = nullptr);
	SigFileIO(QString fileName, QObject* parent = nullptr);
	unsigned fileoffs = PREF_LEN + AMNT_LEN;
	
	Record* readRecord(unsigned recIndex);
	Record* readRecord();
	int writeRecord(Record* r);
	bool is_prefix_valid() const;
	bool isEof() const;
private:
	bool isPrefixValid;
	unsigned currentRec;
	bool eof;
	QFile* basefile;
	QDataStream* fileStream;
	void seekRec(unsigned recIndex);
	void seekEnd();
};




QDataStream& operator << (QDataStream& ds, const Record& r);
QDataStream& operator >> (QDataStream& ds, Record& r);

#endif // SIGBASEIO_H
