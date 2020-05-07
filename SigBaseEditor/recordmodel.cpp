#include "recordmodel.h"

RecordModel::RecordModel(QObject* parent)
{
	recList.append(new Record(new QString("cool record"), 100, new QByteArray(PREF_SIZE, 'p'), new QByteArray(HASH_SIZE, 'h'), 20,
		40));
	recList.append(new Record(new QString("cool record 22"), 200, new QByteArray(PREF_SIZE, 'p'), new QByteArray(HASH_SIZE, 'h'),
		233, 412));
	recList.append(new Record(new QString("cool record 33"), 100, new QByteArray(PREF_SIZE, 'p'), new QByteArray(HASH_SIZE, 'h'), 20,
		40));
	recList.append(new Record(new QString("cool record 44"), 200, new QByteArray(PREF_SIZE, 'p'), new QByteArray(HASH_SIZE, 'h'),
		233, 412));
}

int RecordModel::rowCount(const QModelIndex &parent) const {
	return recList.size();
}

int RecordModel::columnCount(const QModelIndex &parent) const {
	return 6;
}

QVariant RecordModel::data(const QModelIndex &index, int role) const {
	if (role == Qt::DisplayRole) {
		//QVariant result;
		int i = index.row();
		switch(index.column()) {
		case 0:
			return *recList.at(i)->getName();
		case 1:
			return recList.at(i)->getSigLen();
		case 2:
			return *recList.at(i)->getPref();
		case 3:
			return *recList.at(i)->getHash();
		case 4:
			return recList.at(i)->getStrtOffs();
		case 5:
			return recList.at(i)->getEndOffs();
		default:
			return QVariant();
		}
	}
	return QVariant();
}

