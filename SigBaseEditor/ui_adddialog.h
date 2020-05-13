/********************************************************************************
** Form generated from reading UI file 'adddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDDIALOG_H
#define UI_ADDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_AddDialog
{
public:
    QGridLayout *gridLayout_2;
    QDialogButtonBox *buttonBox;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QLabel *label_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_4;
    QLabel *label;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_5;
    QLabel *label_2;
    QLabel *label_6;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *AddDialog)
    {
        if (AddDialog->objectName().isEmpty())
            AddDialog->setObjectName(QString::fromUtf8("AddDialog"));
        AddDialog->resize(392, 426);
        gridLayout_2 = new QGridLayout(AddDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        buttonBox = new QDialogButtonBox(AddDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_2 = new QLineEdit(AddDialog);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setReadOnly(true);

        gridLayout->addWidget(lineEdit_2, 5, 0, 1, 1);

        pushButton = new QPushButton(AddDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 3, 0, 1, 1);

        label_5 = new QLabel(AddDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 12, 0, 1, 1);

        lineEdit_6 = new QLineEdit(AddDialog);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        gridLayout->addWidget(lineEdit_6, 15, 0, 1, 1);

        lineEdit_4 = new QLineEdit(AddDialog);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setReadOnly(true);

        gridLayout->addWidget(lineEdit_4, 10, 0, 1, 1);

        label = new QLabel(AddDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_3 = new QLineEdit(AddDialog);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setReadOnly(true);

        gridLayout->addWidget(lineEdit_3, 8, 0, 1, 1);

        label_4 = new QLabel(AddDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 9, 0, 1, 1);

        label_3 = new QLabel(AddDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 7, 0, 1, 1);

        lineEdit = new QLineEdit(AddDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 0, 1, 1);

        lineEdit_5 = new QLineEdit(AddDialog);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        gridLayout->addWidget(lineEdit_5, 13, 0, 1, 1);

        label_2 = new QLabel(AddDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 4, 0, 1, 1);

        label_6 = new QLabel(AddDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 14, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer_2, 11, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(AddDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddDialog);
    } // setupUi

    void retranslateUi(QDialog *AddDialog)
    {
        AddDialog->setWindowTitle(QCoreApplication::translate("AddDialog", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\275\320\276\320\262\320\276\320\271 \320\267\320\260\320\277\320\270\321\201\320\270", nullptr));
        pushButton->setText(QCoreApplication::translate("AddDialog", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \321\201\320\270\320\263\320\275\320\260\321\202\321\203\321\200\321\203...", nullptr));
        label_5->setText(QCoreApplication::translate("AddDialog", "\320\235\320\260\321\207\320\260\320\273\321\214\320\275\320\276\320\265 \321\201\320\274\320\265\321\211\320\265\320\275\320\270\320\265", nullptr));
        label->setText(QCoreApplication::translate("AddDialog", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\262\321\200\320\265\320\264\320\276\320\275\320\276\321\201\320\275\320\276\320\263\320\276 \320\276\320\261\321\212\320\265\320\272\321\202\320\260", nullptr));
        label_4->setText(QCoreApplication::translate("AddDialog", "SHA-256", nullptr));
        label_3->setText(QCoreApplication::translate("AddDialog", "\320\237\321\200\320\265\321\204\320\270\320\272\321\201", nullptr));
        label_2->setText(QCoreApplication::translate("AddDialog", "\320\224\320\273\320\270\320\275\320\260 \321\201\320\270\320\263\320\275\320\260\321\202\321\203\321\200\321\213", nullptr));
        label_6->setText(QCoreApplication::translate("AddDialog", "\320\232\320\276\320\275\320\265\321\207\320\275\320\276\320\265 \321\201\320\274\320\265\321\211\320\265\320\275\320\270\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddDialog: public Ui_AddDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDIALOG_H
