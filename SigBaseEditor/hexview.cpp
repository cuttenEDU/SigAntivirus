#include "hexview.h"
#include "ui_hexview.h"

HexView::HexView(QString* fileName, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HexView)
{
    ui->setupUi(this);
    qhe = new QHexEdit(this);
    QFile* file = new QFile(*fileName,this);
    qhe->setData(*file);
    qhe->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    ui->gridLayout->addWidget(qhe);
    qhe->show();
}

HexView::~HexView()
{
    delete ui;
}
