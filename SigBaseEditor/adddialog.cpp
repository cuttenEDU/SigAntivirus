#include "adddialog.h"


#include "ui_adddialog.h"

AddDialog::AddDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::AddDialog) {
	ui->setupUi(this);
	connect(ui->pushButton, SIGNAL(clicked()), SLOT(openHex()));
}

AddDialog::~AddDialog() {
	delete ui;
}

void AddDialog::openHex() {
	QString *fileName = new QString(QFileDialog::getOpenFileName(this, tr(u8"Открыть файл..."),"."));
	hv = new HexView(fileName, this);
	hv->show();
}
