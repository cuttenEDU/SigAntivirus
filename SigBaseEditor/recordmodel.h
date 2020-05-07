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


//private:
	QList<Record*> recList;
	
};

#endif // RECORDMODEL_H
