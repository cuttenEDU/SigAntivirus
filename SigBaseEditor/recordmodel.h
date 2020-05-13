#ifndef RECORDMODEL_H
#define RECORDMODEL_H
#include "SigIO.h"


class RecordModel : public QAbstractTableModel
{
	Q_OBJECT

	
public:
    RecordModel(QObject* parent = nullptr);
	int rowCount(const QModelIndex& parent = QModelIndex()) const override;
	int columnCount(const QModelIndex& parent = QModelIndex()) const override;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
	bool setData(const QModelIndex& index, const QVariant& value, int role);
	Qt::ItemFlags flags(const QModelIndex& index) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
	QList<Record*> recList;
	
	
//private:

public slots:
	void AppendRecord(Record* r);
	//void AppendTestRecord();


	
};

#endif // RECORDMODEL_H
