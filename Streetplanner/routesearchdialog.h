#ifndef ROUTESEARCHDIALOG_H
#define ROUTESEARCHDIALOG_H

#include <QDialog>
#include <map.h>

namespace Ui {
class routeSearchDialog;
}

class routeSearchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit routeSearchDialog(Map *map, QGraphicsScene& scene, QWidget *parent = nullptr);
    ~routeSearchDialog();

private slots:
    void on_buttonBox_accepted();

    void on_lineEdit_routeSearch_origin_editingFinished();

    void on_comboBox_origin_currentTextChanged(const QString &arg1);

    void on_comboBox_target_currentTextChanged(const QString &arg1);

private:
    Ui::routeSearchDialog *ui;
    Map *map;
    QGraphicsScene& scene;
};

#endif // ROUTESEARCHDIALOG_H
