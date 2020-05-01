#pragma once
#include "SigIO_global.h"
#include <QTCore>
#include <array>

#define PREF_SIZE 25
#define HASH_SIZE 32

typedef char hash[HASH_SIZE];




class SIGIO_EXPORT Record : public QObject
{
	Q_OBJECT


	public:
	Record(QString* name, unsigned sig_len, QByteArray* pref,
		QByteArray* hash, unsigned strtoffs, unsigned endoffs)
		: name(name),
		  sigLen(sig_len),
		  pref(pref),
		  hash(hash),
		  strtoffs(strtoffs),
		  endoffs(endoffs)
	{
	}
	Record();
	~Record();
	//Record() :name(0), sigLen(0), pref(0), hash(0), strtoffs(0), endoffs(0) {};
	int getSize() const;
	unsigned getRecLen() const;
	unsigned Record::getNameLen() const;
	void setNameLen(unsigned name_len);
	unsigned getSigLen() const;
	void setSigLen(unsigned sig_len);
	unsigned getStrtOffs() const;
	void setStrtOffs(unsigned strtoffs);
	unsigned getEndOffs() const;
	void setEndOffs(unsigned endoffs);
	QString* getName();
	void setName(QString* chars);
	QByteArray* getPref();
	void setPref(QByteArray* pref);
	QByteArray* getHash();
	void setHash(QByteArray* hash);
	const char* getRawPref() const;
	const char* getRawHash() const;
	const char* getRawName() const;
	QString* toString();
	
private:
	QString* name;
	unsigned sigLen;
	QByteArray* pref;
	QByteArray* hash;
	unsigned strtoffs;
	unsigned endoffs;
	

	
};




