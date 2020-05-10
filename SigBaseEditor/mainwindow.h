#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTWidgets>
#include <QDebug>
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
    SigFileIO file;
    unsigned recAmount;
    RecordModel* recordModel;
    //void MainWindow::resizeEvent(QResizeEvent* event) override;
public slots:
    void loadBase();

signals:
	
};
#endif // MAINWINDOW_H
