#include "mainwindow.h"
#include "QtWidgets/qgroupbox.h"
#include "city.h"
#include <addcitydialog.h>
#include <routesearchdialog.h>
#include <addstreetdialog.h>
#include <addcityheredialog.h>
#include <mapio.h>
#include <mapionrw.h>
#include <mapiofileinput.h>
#include <dijkstra.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    //ui->graphicsView->setAlignment(none);
    MapIoNrw mapionrw;
    hideDebug();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief Test function: Draws a rectangle to the scene.
 */
void MainWindow::on_pushButton_test_clicked()
{
    /**
    QMessageBox msgBox;
    QString outputStr = "PushButton pressed: %1";
    QString lineEditText = ui->lineEdit_test->text();
    bool successful;
    int nr = lineEditText.toInt(&successful);
    if(successful)
        lineEditText = QString::number(nr+4);
    qDebug() << outputStr.arg(lineEditText);
    msgBox.setText(outputStr.arg(lineEditText));
    msgBox.exec();
    **/
    scene->addRect(arc4random_uniform(600), arc4random_uniform(500), 10.0, 10.0, QPen(Qt::red));
}

/**
 * @brief Closes the window if Alt+E is pressed.
 */
void MainWindow::on_actionExit_triggered()
{
    close();
}

/**
 * @brief Clears the window if Alt+S is pressed.
 */
void MainWindow::on_actionClear_Scene_triggered()
{
    scene->clear();
}

/**
 * @brief Opens a new window that shows a short description about the program if the according entry in the menu bar is clicked.
 */
void MainWindow::on_actionAbout_Streetplanner_triggered()
{
    QMessageBox msgBox;
    msgBox.about(this, "About Streetplanner", "Streetplanner is a program to plan cities using a graphical user interface.");
}

/**
 * @brief Test function: Draws to cities to the scene.
 */
void MainWindow::on_button_testDrawCity_clicked()
{
    City city1 = City("City1", 10, 20);
    City city2 = City("City2", -10, -20);
    city1.draw(*scene);
    city2.draw(*scene);
}

/**
 * @brief Test function: Adds a city to the map, then draws map.
 */
void MainWindow::on_button_testDrawMap_clicked()
{
    Map testMap;
    City city3 = City("City3",31,69);
    testMap.addCity(&city3);
    testMap.draw(*scene);
}

/**
 * @brief Test function: Draws two cities on the map, then draws street between them.
 */
void MainWindow::on_button_testDrawStreet_clicked()
{
    City city4 = City("City4", 100, 200);
    City city5 = City("City5", -100, -200);
    city4.draw(*scene);
    city5.draw(*scene);
    Street c4c5 = Street(&city4, &city5);
    c4c5.draw(*scene);
}

/**
 * @brief Test function: Tests implementation of class AbstractMap.
 */
void MainWindow::on_button_testAbstractMap_clicked()
{
    Map testMap;
    City *a = new City("a", 0, 0);
    City *b = new City("b", 0, 100);
    Street *s = new Street(a, b);


    qDebug() << "MapTest: Start Test of the Map";
    {
        qDebug() << "MapTest: adding wrong street";
        bool t1 = testMap.addStreet(s);
        if (t1) {
            qDebug() << "-Error: Street should not bee added, if cities have not been added.";
        }
    }

    {
        qDebug() << "MapTest: adding correct street";
        testMap.addCity(a);
        testMap.addCity(b);
        bool t1 = testMap.addStreet(s);
        if (!t1) {
            qDebug() << "-Error: It should be possible to add this street.";
        }
    }
}

/**
 * @brief Hides Test function buttons.
 */
void MainWindow::hideDebug()
{
    ui->pushButton_test->hide();
    ui->button_testAbstractMap->hide();
    ui->button_testDrawCity->hide();
    ui->button_testDrawMap->hide();
    ui->button_testDrawStreet->hide();
    ui->pushButton_test_dijkstraFixed->hide();
    ui->pushButton_testAbstractMap->hide();
    ui->actionToggle_Debbug->setText("Show Debug");
}


/**
 * @brief Shows test function buttons.
 */
void MainWindow::showDebug()
{
    ui->pushButton_test->show();
    ui->button_testAbstractMap->show();
    ui->button_testDrawCity->show();
    ui->button_testDrawMap->show();
    ui->button_testDrawStreet->show();
    ui->pushButton_test_dijkstraFixed->show();
    ui->pushButton_testAbstractMap->show();
    ui->actionToggle_Debbug->setText("Hide Debug");
}

/**
 * @brief If the according entry in the menu bar is pressed, the function checks if the test function buttons are visible and hides or shows them based on that.
 */
void MainWindow::on_actionToggle_Debbug_triggered()
{
    if(ui->actionToggle_Debbug->text() == "Hide Debug")
    {
        hideDebug();
    }
    else
    {
        showDebug();
    }
}

/**
 * @brief Opens dialog window to add a city to the map.
 */
void MainWindow::on_pushButton_addCity_clicked()
{
    addCityDialog* addCityDialog = new class addCityDialog(&map, *scene);
    addCityDialog->show();
}

/**
 * @brief Uses the class mapionrw to fill the map, then draws it.
 */
void MainWindow::on_pushButton_fillMap_clicked()
{
    mapionrw.fillMap(map);
    map.draw(*scene);
}

/**
 * @brief Test function button: Test implementation of AbstractMap()
 */
void MainWindow::on_pushButton_testAbstractMap_clicked()
{
    qDebug() << "Testing AbstractMap";
    Map testMap;
    City *a = new City("a", 0, 0);
    City *b = new City("b", 0, 100);
    City *c = new City("c", 100, 300);
    Street *s = new Street(a, b);
    Street *s2 = new Street(b, c);


    qDebug() << "MapTest: Start Test of the Map";
    {
        qDebug() << "MapTest: adding wrong street";
        bool t1 = testMap.addStreet(s);
        if (t1) {
            qDebug() << "-Error: Street should not bee added, if cities have not been added.";
        }
    }

    {
        qDebug() << "MapTest: adding correct street";
        testMap.addCity(a);
        testMap.addCity(b);
        bool t1 = testMap.addStreet(s);
        if (!t1) {
            qDebug() << "-Error: It should be possible to add this street.";
        }
    }

    {
        qDebug() << "MapTest: findCity";
        City* city = testMap.findCity("a");
        if (city != a)
            qDebug() << "-Error: City a could not be found.";

        city = testMap.findCity("b");
        if (city != b)
            qDebug() << "-Error: City b could not be found.";

        city = testMap.findCity("c");
        if (city != nullptr)
            qDebug() << "-Error: If city could not be found 0 should be returned.";
    }

    testMap.addCity(c);
    testMap.addStreet(s2);

    {
        qDebug() << "MapTest: getOppositeCity";
        const City *city = testMap.getOppositeCity(s, a);
        if (city != b)
            qDebug() << "-Error: Opposite city should be b.";

        city = map.getOppositeCity(s, c);
        if (city != nullptr)
            qDebug() << "-Error: Opposite city for a city which is not linked by given street should be 0.";
    }

    {
        qDebug() << "MapTest: streetLength";
        double l = testMap.getLength(s2);
        double expectedLength = 223.6;
        // compare doubles with 5% tolerance
        if (l < expectedLength * 0.95 || l > expectedLength *1.05)
            qDebug() << "-Error: Street Length is not equal to the expected.";

    }

    {
        qDebug() << "MapTest: getStreetList";
        QVector<Street*> streetList1 = testMap.getStreetList(a);
        QVector<Street*> streetList2 = testMap.getStreetList(b);
        if (streetList1.size() != 1) {
            qDebug() << "-Error: One street should be found for city a.";
        }
        else if (*streetList1.begin() != s) {
                qDebug() << "-Error: The wrong street has been found for city a.";
        }

        if (streetList2.size() != 2)
            qDebug() << "-Error: Two streets should be found for city b.";
    }

    qDebug() << "MapTest: End Test of the Map.";
}

/**
 * @brief Test button function: Test Dijkstra implementation with fixed values.
 */
void MainWindow::on_pushButton_test_dijkstraFixed_clicked()
{
    QVector<Street*> pathStreets;
    pathStreets = Dijkstra::search(map,"Aachen", "Bonn");
    for(Street* street : pathStreets)
    {
        Street* tempStreet = new Street(street->origin, street->target, "red");
        map.addStreet(tempStreet);
    }
    map.draw(*scene);
}

/**
 * @brief Opens search route dialog window.
 */
void MainWindow::on_pushButton_openRouteSearch_clicked()
{
    routeSearchDialog* routeSearchDialog = new class routeSearchDialog(&map, *scene);
    routeSearchDialog->show();
}


/**
 * @brief Opens add street dialog window.
 */
void MainWindow::on_pushButton_addStreet_clicked()
{
    addStreetDialog* addStreetDialog = new class addStreetDialog(&map, *scene);
    addStreetDialog->show();
}

/**
 * @brief Listens to the event of a right-click and opens a custom context menu at the cursor position at that time.
 * Further, opens a frameless window if the context menu entry is clicked at the current position, to enable the user to add a city to the coordinates he clicked at.
 * @param Position of the cursor at that time.
 */
void MainWindow::on_graphicsView_customContextMenuRequested(const QPoint &pos)
{
    qDebug() << "customContextMenuRequested event fired";
    int midX =  abs(-ui->graphicsView->width()/2);
    int midY = this->size().height()/2;
    int posX = midX - pos.x();
    int posY = midY - pos.y();
    qDebug() << posX;
    qDebug() << posY;

    QMenu menu;
    QString  menuStyle(
            "QMenu {"
                "background-color: transparent;"
                "padding:0;"
                "margin:0;"
                "border-radius: 8px;"
                "width 150px;"
                "border: 1px solid rgb(86,85,90);"
            "}"
            "QMenu::separator{"
                "height:1px;"
                "background: rgba(255, 255, 255, 0.2);"
             "}"
             "QMenu::item{"
                "background-color: rgb(37,35,40);"
                "color: rgb(255, 255, 255);"
                "font-family: .AppleSystemUIFont;"
                "border-radius:8px;"
                "padding: 4px 16px;"
                "margin: 4px;"

             "}"
             "QMenu::item:selected{"
                "background-color: rgb(41, 90, 185);"
                "color: rgb(255, 255, 255);"
                "font-family: .AppleSystemUIFont;"
             "}"
          );

    menu.setStyleSheet(menuStyle);
    menu.addAction( QString("Add City here") );
    QAction* selected_action = menu.exec(QCursor::pos());
    if(selected_action) {
        /*QHBoxLayout *layout = new QHBoxLayout(ui->graphicsView);
        QGroupBox *overlayWidget = new QGroupBox();
        overlayWidget->setAlignment(Qt::AlignCenter);
        overlayWidget->setMaximumSize(50,20);
        QLineEdit *cityname = new QLineEdit(overlayWidget);
        cityname->move(posX,posY);
        layout->addWidget(overlayWidget);*/

        /*
        QDialog *dialog = new QDialog();
        QLineEdit *cityname = new QLineEdit(dialog);
        QPushButton okButtoN;
        int windowWidth = 200;
        int windowHeight = 80;

        dialog->setWindowFlags(Qt::FramelessWindowHint);
        dialog->setModal(false);
        dialog->setFixedSize(windowWidth,windowHeight);



        dialog->move(QCursor::pos().x(), QCursor::pos().y()- windowHeight/2 );
        dialog->show(); //.show() ?????
        */

        addCityHereDialog* addCityHereDialog = new class addCityHereDialog(posX, posY, &map, *scene);
        int windowWidth = 212;
        int windowHeight = 132;
        addCityHereDialog->setWindowFlags(Qt::FramelessWindowHint);
        addCityHereDialog->setModal(true);
        addCityHereDialog->setFixedSize(windowWidth,windowHeight);
        addCityHereDialog->move(QCursor::pos().x(), QCursor::pos().y()- windowHeight/2 );
        addCityHereDialog->show();

    }
}

/**
 * @brief Wipes map data and clears the scene by drawing the empty map to it.
 */
void MainWindow::on_pushButton_clearMap_clicked()
{
    map.clear();
    map.draw(*scene);
}

/**
 * @brief Opens two dialog windows to select the city source file and the street source file.
 */
void MainWindow::on_pushButton_readFromFile_clicked()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setNameFilter("*.txt");
    QString cityFilename = dialog.getOpenFileName();
    QString streetFilename = dialog.getOpenFileName();
    MapIoFileinput *fileReader = new MapIoFileinput(cityFilename, streetFilename);
    map.clear();
    fileReader->fillMap(map);
    map.draw(*scene);
}

