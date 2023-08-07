#ifndef ADDCITYHEREDIALOG_H
#define ADDCITYHEREDIALOG_H

#include <QDialog>
#include <map.h>

namespace Ui {
class addCityHereDialog;
}

class addCityHereDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addCityHereDialog(int posX, int posY, Map *map, QGraphicsScene& scene, QWidget *parent = nullptr);
    ~addCityHereDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::addCityHereDialog *ui;
    int posX;
    int posY;
    Map *map;
    QGraphicsScene& scene;
};

#endif // ADDCITYHEREDIALOG_H
