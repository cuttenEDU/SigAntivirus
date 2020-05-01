#include "Record.h"

Record::Record()
{
	
}
Record::~Record()
{

}
//TODO: исправить, некорректно отображает числовые значения
QString* Record::toString()
{
	QString* str = new QString("Record size: ");
	*str += QString(this->getSize());
	*str += "\nName size: ";
	*str += QString(this->getNameLen());
	*str += "\nName: ";
	*str += this->getName();
	*str += "\nSignature size: ";
	*str += QString(this->getSigLen());
	*str += "\nPrefix: ";
	*str += this->getRawPref();
	*str += "\nHash: ";
	*str += this->getRawHash();
	*str += "\nStart offset: ";
	*str += this->getStrtOffs();
	*str += "\nEnd offset: ";
	*str += this->getEndOffs();
	return str;
}

unsigned Record::getNameLen() const
{
	return name->size();
}
//
//void Record::setNameLen(unsigned name_len)
//{
//	nameLen = name_len;
//}



unsigned Record::getSigLen() const
{
	return sigLen;
}

void Record::setSigLen(unsigned sig_len)
{
	sigLen = sig_len;
}


unsigned Record::getStrtOffs() const
{
	return strtoffs;
}

void Record::setStrtOffs(unsigned strtoffs)
{
	strtoffs = strtoffs;
}

unsigned Record::getEndOffs() const
{
	return endoffs;
}

void Record::setEndOffs(unsigned endoffs)
{
	endoffs = endoffs;
}

QString* Record::getName()
{
	return name;
}

void Record::setName(QString* chars)
{
	name = chars;
}

QByteArray* Record::getPref()
{
	return pref;
}

void Record::setPref(QByteArray* pref)
{
	this->pref = pref;
}

QByteArray* Record::getHash()
{
	return hash;
}

void Record::setHash(QByteArray* hash)
{
	this->hash = hash;
}


const char* Record::getRawPref() const
{
	return pref->data();
}


const char* Record::getRawHash() const
{
	return hash->data();
}

const char* Record::getRawName() const
{
	return name->toLocal8Bit().data();
}


int Record::getSize() const
{
	int l;
	l += sizeof(getNameLen());
	l += name->size();
	l += sizeof(sigLen);
	l += pref->size();
	l += hash->size();
	l += sizeof(strtoffs);
	l += sizeof(endoffs);
	return l;
}
