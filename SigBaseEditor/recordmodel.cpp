#include "recordmodel.h"

RecordModel::RecordModel(QObject *parent) {
	recList.append(new Record(new QString("cool record"), 100, new QByteArray(PREF_SIZE, 'p'),
	                          new QByteArray(HASH_SIZE, 'h'), 20,
	                          40));
	recList.append(new Record(new QString("cool record 22"), 200, new QByteArray(PREF_SIZE, 'p'),
	                          new QByteArray(HASH_SIZE, 'h'),
	                          233, 412));
	recList.append(new Record(new QString("cool record 33"), 100, new QByteArray(PREF_SIZE, 'p'),
	                          new QByteArray(HASH_SIZE, 'h'), 20,
	                          40));
	recList.append(new Record(new QString("cool record 44"), 200, new QByteArray(PREF_SIZE, 'p'),
	                          new QByteArray(HASH_SIZE, 'h'),
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
		int i = index.row();
		switch (index.column()) {
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


bool RecordModel::setData(const QModelIndex &index, const QVariant &value, int role) {
	if (role == Qt::EditRole) {
		if (!checkIndex(index))
			return false;
		int i = index.row();
		QByteArray* ba;
		QString* s;
		switch (index.column()) {
			case 0:
				s = new QString(value.toString());
				recList.at(i)->setName(s);
				break;
			case 1:
				recList.at(i)->setSigLen(value.toInt());
				break;
			case 2:
				ba = new QByteArray(value.toByteArray());
				recList.at(i)->setPref(ba);
				break;
			case 3:
				ba = new QByteArray(value.toByteArray());
				recList.at(i)->setHash(ba);
				break;
			case 4:
				recList.at(i)->setStrtOffs(value.toInt());
				break;

			case 5:
				recList.at(i)->setEndOffs(value.toInt());
				break;
		}
		emit dataChanged(index, index);
		return true;
	}
	return false;
}

Qt::ItemFlags RecordModel::flags(const QModelIndex &index) const {
	return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}

QVariant RecordModel::headerData(int section, Qt::Orientation orientation, int role) const {
	if (role != Qt::DisplayRole) {
		return QVariant();
	}

	if (orientation == Qt::Vertical) {
		return section;
	}

	switch (section) {
	case 0:
		return tr(u8"Имя объекта");
	case 1:
		return tr(u8"Длина сигнатуры");
	case 2:
		return tr(u8"Префикс");
	case 3:
		return tr(u8"SHA-256");
	case 4:
		return tr(u8"Начальное смещ.");
	case 5:
		return tr(u8"Конечное смещ.");
	}

	return QVariant();
}

void RecordModel::AppendRecord(Record *r) {
	int row = recList.size();
	beginInsertRows(QModelIndex(), row, row);
	recList.append(r);
	endInsertRows();
}
void RecordModel::AppendTestRecord() {
	Record* r = new Record(new QString("This is a test record"), 200, new QByteArray(PREF_SIZE, 'p'),
		new QByteArray(HASH_SIZE, 'h'),
		233, 412,this);
	int row = recList.size();
	beginInsertRows(QModelIndex(), row, row);
	recList.append(r);
	endInsertRows();
}

 
