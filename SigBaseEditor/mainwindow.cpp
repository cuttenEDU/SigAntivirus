#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
                                          , ui(new Ui::MainWindow) {
	recAmount = 0;
	ui->setupUi(this);
	recordModel = new RecordModel();
	ui->tableView->setModel(recordModel);
	ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	connect(ui->openBaseButton, SIGNAL(triggered()), SLOT(loadBase()));
	connect(ui->addButton, SIGNAL(clicked()), SLOT(openAddWindow()));
	connect(this, SIGNAL(recordLoaded(Record*)), recordModel, SLOT(AppendRecord(Record*)));
}

MainWindow::~MainWindow() {
	delete ui;
}




void MainWindow::loadBase() {
	

	QString *fileName = new QString(QFileDialog::getOpenFileName(this, tr(u8"������� ���� ����..."),
	                                                             ".",
	                                                             tr(u8"���� ���� ������ �������� (*.edb)")));
	//TODO: ������ �� �����, �� ���� ����� ������� ����...
	
	if (!fileName->isEmpty()) {
		file = new SigFileIO(*fileName);
		if (!file->is_prefix_valid()) {
			QMessageBox::critical(this, tr(u8"������!"), tr(u8"��������� ���� �� �������� ���������� ����� ������ ��� ������ �������"));
			return;
		}
		while (true) {
			Record* r = file->readRecord();
			if (r == nullptr)
				break;
			emit recordLoaded(r);
			recAmount++;
		}
		this->setWindowTitle(*fileName + QString(" - ") + W_TITLE);
	}
	
}

void MainWindow::openAddWindow() {
	AddDialog* ad = new AddDialog();
	ad->show();
}
