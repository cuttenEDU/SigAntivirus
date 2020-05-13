#ifndef HEXVIEW_H
#define HEXVIEW_H

#include <QDialog>
#include "qhexedit.h"

namespace Ui {
class HexView;
}

class HexView : public QDialog
{
    Q_OBJECT

public:
    explicit HexView(QString* fileName,QWidget *parent = nullptr);
    ~HexView();
    QHexEdit* qhe;
	

private:
    Ui::HexView *ui;
};

#endif // HEXVIEW_H
