#ifndef ADDSTREETDIALOG_H
#define ADDSTREETDIALOG_H

#include <QDialog>
#include <map.h>
#include <street.h>
#include <city.h>

namespace Ui {
class addStreetDialog;
}

class addStreetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addStreetDialog(Map *map, QGraphicsScene& scene, QWidget *parent = nullptr);
    ~addStreetDialog();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_comboBox_origin_currentTextChanged(const QString &arg1);

    void on_comboBox_target_currentTextChanged(const QString &arg1);

private:
    Ui::addStreetDialog *ui;
    Map *map;
    QGraphicsScene& scene;
    QString origin_lastItem;
    QString target_lastItem;
};

#endif // ADDSTREETDIALOG_H
