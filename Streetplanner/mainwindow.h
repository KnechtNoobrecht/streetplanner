#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QDebug>
#include <QMessageBox>
#include <QMenu>
#include <QFileDialog>
#include <map.h>
#include <city.h>
#include "street.h"
#include "ui_mainwindow.h"
#include "ui_addcitydialog.h"
#include "addcitydialog.h"
#include "mapio.h"
#include "mapionrw.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void hideDebug();
    void showDebug();

private slots:
    void on_pushButton_test_clicked();

    void on_actionExit_triggered();

    void on_actionClear_Scene_triggered();

    void on_actionAbout_Streetplanner_triggered();

    void on_button_testDrawCity_clicked();

    void on_button_testDrawMap_clicked();

    void on_button_testDrawStreet_clicked();

    void on_button_testAbstractMap_clicked();

    void on_actionToggle_Debbug_triggered();

    void on_pushButton_addCity_clicked();

    void on_pushButton_fillMap_clicked();

    void on_pushButton_testAbstractMap_clicked();

    void on_pushButton_test_dijkstraFixed_clicked();

    void on_pushButton_openRouteSearch_clicked();

    void on_pushButton_addStreet_clicked();

    void on_graphicsView_customContextMenuRequested(const QPoint &pos);

    void on_pushButton_clearMap_clicked();

    void on_pushButton_readFromFile_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Map map;
    MapIo* mapio;
    MapIoNrw mapionrw;
};
#endif // MAINWINDOW_H
