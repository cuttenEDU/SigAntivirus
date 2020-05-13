#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define W_TITLE tr(u8"Редактор базы данных сигнатур вредоносного ПО")
#include <QMainWindow>
#include <QTWidgets>
#include <QDebug>
#include "adddialog.h"
#include "recordmodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    SigFileIO* file;
    unsigned recAmount;
    RecordModel* recordModel;
    //void MainWindow::resizeEvent(QResizeEvent* event) override;
public slots:
    void loadBase();
    void openAddWindow();

signals:
    void recordLoaded(Record* r);
	
};
#endif // MAINWINDOW_H
