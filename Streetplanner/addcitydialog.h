#ifndef ADDCITYDIALOG_H
#define ADDCITYDIALOG_H

#include <QDialog>
#include <map.h>

namespace Ui {
class addCityDialog;
}

class addCityDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addCityDialog(Map *map, QGraphicsScene& scene, QWidget *parent = nullptr);
    ~addCityDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::addCityDialog *ui;
    Map *map;
    QGraphicsScene& scene;
};

#endif // ADDCITYDIALOG_H
