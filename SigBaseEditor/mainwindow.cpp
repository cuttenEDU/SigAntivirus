#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
                                          , ui(new Ui::MainWindow) {
	recAmount = 0;
	ui->setupUi(this);
	connect(ui->openBaseButton, SIGNAL(triggered()), SLOT(loadBase()));
}

MainWindow::~MainWindow() {
	delete ui;
}


void MainWindow::loadBase() {
	RecordModel* recordModel = new RecordModel();
	//for (int i = 0; i < 6; ++i) {
	//	QVariant data = recordModel->data(recordModel->index(0, i));
	//	qDebug() << data;
	//}
	//qDebug() << recordModel->rowCount();
	//qDebug() << recordModel->columnCount();
	
	ui->tableView->setModel(recordModel);
	recordModel->recList.append(new Record(new QString("cool record 44"), 200, new QByteArray(PREF_SIZE, 'p'), new QByteArray(HASH_SIZE, 'h'),
		233, 412));
	QModelIndex topLeft = recordModel->index(0, 0);
	QModelIndex bottomRight = recordModel->index(recordModel->rowCount() - 1, recordModel->columnCount() - 1);

	// QString *fileName = new QString(QFileDialog::getOpenFileName(this, tr("Открыть файл базы..."),
	                                                             //".",
	                                                             //tr("Файл базы данных сигнатур (.edb)")));

	//while (true) {
	//	Record *r = file.readRecord();
	//	if (r == nullptr)
	//		break;
	//	recList.append(r);
	//	recAmount++;
	//}
	
}
