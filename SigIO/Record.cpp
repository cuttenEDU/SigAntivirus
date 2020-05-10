#include "Record.h"

Record::Record() {

}

Record::~Record() {

}

//TODO: исправить, некорректно отображает числовые значения
QString* Record::toString() {
	QString *str = new QString("Record size: ");
	str->append(QString::number(this->getSize()));
	str->append("\nName size: ");
	str->append(QString::number(this->getNameLen()));
	str->append("\nName: ");
	str->append(this->getName());
	str->append("\nSignature size: ");
	str->append(QString::number(this->getSigLen()));
	str->append("\nPrefix: ");
	str->append(this->getRawPref());
	str->append("\nHash: ");
	str->append(this->getRawHash());
	str->append("\nStart offset: ");
	str->append(QString::number(this->getStrtOffs()));
	str->append("\nEnd offset: ");
	str->append(QString::number(this->getEndOffs()));
	return str;
}

unsigned Record::getNameLen() const {
	return name->size();
}

//
//void Record::setNameLen(unsigned name_len)
//{
//	nameLen = name_len;
//}


unsigned Record::getSigLen() const {
	return sigLen;
}

void Record::setSigLen(unsigned sig_len) {
	sigLen = sig_len;
}


unsigned Record::getStrtOffs() const {
	return strtoffs;
}

void Record::setStrtOffs(unsigned strtoffs) {
	this->strtoffs = strtoffs;
}

unsigned Record::getEndOffs() const {
	return endoffs;
}

void Record::setEndOffs(unsigned endoffs) {
	this->endoffs = endoffs;
}

QString* Record::getName() {
	return name;
}

void Record::setName(QString *chars) {
	name = chars;
}

QByteArray* Record::getPref() {
	return pref;
}

void Record::setPref(QByteArray *pref) {
	this->pref = pref;
}

QByteArray* Record::getHash() {
	return hash;
}

void Record::setHash(QByteArray *hash) {
	this->hash = hash;
}


const char* Record::getRawPref() const {
	return pref->data();
}


const char* Record::getRawHash() const {
	return hash->data();
}

QByteArray Record::getRawName() const {
	return name->toLocal8Bit();
}


int Record::getSize() const {
	int l = 0; // size of record is also stored in file
	l += sizeof(getNameLen());
	l += name->size();
	l += sizeof(sigLen);
	l += pref->size();
	l += hash->size();
	l += sizeof(strtoffs);
	l += sizeof(endoffs);
	return l;
}
