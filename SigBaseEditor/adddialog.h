#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>
#include "qhexedit.h"
#include "hexview.h"
#include <qfiledialog.h>

namespace Ui {
class AddDialog;
}

class AddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDialog(QWidget *parent = nullptr);
    ~AddDialog();
    HexView* hv;

public slots:
    void openHex();

private:
    Ui::AddDialog *ui;
};

#endif // ADDDIALOG_H
