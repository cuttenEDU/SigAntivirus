/********************************************************************************
** Form generated from reading UI file 'hexview.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEXVIEW_H
#define UI_HEXVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_HexView
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;

    void setupUi(QDialog *HexView)
    {
        if (HexView->objectName().isEmpty())
            HexView->setObjectName(QString::fromUtf8("HexView"));
        HexView->resize(388, 357);
        gridLayout = new QGridLayout(HexView);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton = new QPushButton(HexView);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);


        retranslateUi(HexView);

        QMetaObject::connectSlotsByName(HexView);
    } // setupUi

    void retranslateUi(QDialog *HexView)
    {
        HexView->setWindowTitle(QCoreApplication::translate("HexView", "\320\222\321\213\320\261\320\276\321\200 \321\201\320\270\320\263\320\275\320\260\321\202\321\203\321\200\321\213", nullptr));
        pushButton->setText(QCoreApplication::translate("HexView", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HexView: public Ui_HexView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEXVIEW_H
