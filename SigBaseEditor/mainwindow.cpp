#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
                                          , ui(new Ui::MainWindow) {
	recAmount = 0;
	ui->setupUi(this);
	recordModel = new RecordModel();
	ui->tableView->setModel(recordModel);
	ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	connect(ui->openBaseButton, SIGNAL(triggered()), SLOT(loadBase()));
	connect(ui->addButton, SIGNAL(clicked()), recordModel, SLOT(AppendTestRecord()));
}

MainWindow::~MainWindow() {
	delete ui;
}


void MainWindow::loadBase() {
	
	recordModel->recList.append(new Record(new QString("cool record 55"), 200, new QByteArray(PREF_SIZE, 'p'), new QByteArray(HASH_SIZE, 'h'),
		233, 412));
	QModelIndex topLeft = recordModel->index(0, 0);
	QModelIndex bottomRight = recordModel->index(recordModel->rowCount()-1, recordModel->columnCount()-1);
	emit recordModel->dataChanged(topLeft, bottomRight);
	//QString *fileName = new QString(QFileDialog::getOpenFileName(this, tr("Открыть файл базы..."),
	                                                             //".",
	                                                             //tr("Файл базы данных сигнатур (.edb)")));
	//TODO: чтение из файла, но были более большие идеи...
	//while (true) {
	//	Record *r = file.readRecord();
	//	if (r == nullptr)
	//		break;
	//	recordModel->AppendRecord(r);
	//	recAmount++;
	//}
	
}

//void MainWindow::resizeEvent(QResizeEvent* event) {
//	QMainWindow::resizeEvent(event);
//	int width = ui->tableView->width();
//	qDebug() << width;
//	ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
//	ui->tableView->setColumnWidth(0, width * 0.38);
//	ui->tableView->setColumnWidth(1, width * 0.1);
//	ui->tableView->setColumnWidth(2, width * 0.2);
//	ui->tableView->setColumnWidth(3, width * 0.2);
//	ui->tableView->setColumnWidth(4, width * 0.05);
//	ui->tableView->setColumnWidth(5, width * 0.05);
//
//	
//}
