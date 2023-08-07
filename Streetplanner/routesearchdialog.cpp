#include "routesearchdialog.h"
#include "ui_routesearchdialog.h"
#include <dijkstra.h>

routeSearchDialog::routeSearchDialog(Map *map, QGraphicsScene& scene, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::routeSearchDialog),
    map(map),
    scene(scene)
{
    ui->setupUi(this);
    QVector<City*> cityList = map->getCityList();
    for(City* city : cityList)
    {
        ui->comboBox_origin->addItem(city->name);
        ui->comboBox_target->addItem(city->name);
    }
    if(cityList.length() == 0)
    {
        ui->comboBox_origin->setPlaceholderText("No Cities");
        ui->comboBox_target->setPlaceholderText("No Cities");
    }
}

routeSearchDialog::~routeSearchDialog()
{
    delete ui;
}


/**
 * @brief Is executed when OK-button is clicked: Finds route between two given cities and draws it in red.
 */
void routeSearchDialog::on_buttonBox_accepted()
{
    QString origin = ui->comboBox_origin->currentText();
    QString target = ui->comboBox_target->currentText();
    QVector<Street*> pathStreets;
    pathStreets = Dijkstra::search(*map, origin, target);
    for(Street* street : pathStreets)
    {
        Street* tempStreet = new Street(street->origin, street->target, "red");
        map->addStreet(tempStreet);
    }
    map->draw(scene);
}

void routeSearchDialog::on_lineEdit_routeSearch_origin_editingFinished()
{
    qDebug() << "event: editing finished";
}


/**
 * @brief Prevents both boxes having the same entry chosen, so there's no street drawn from and to the same city
 */
void routeSearchDialog::on_comboBox_origin_currentTextChanged(const QString &arg1)
{
    qDebug() << "origin text changed";
    if(ui->comboBox_origin->currentText() == ui->comboBox_target->currentText())
    {
        ui->comboBox_target->setCurrentIndex(ui->comboBox_target->currentIndex()+1);
    }
}

/**
 * @brief Prevents both boxes having the same entry chosen, so there's no street drawn from and to the same city
 */
void routeSearchDialog::on_comboBox_target_currentTextChanged(const QString &arg1)
{
    qDebug() << "target text changed";
    if(ui->comboBox_target->currentText() == ui->comboBox_origin->currentText())
    {
        ui->comboBox_origin->setCurrentIndex(ui->comboBox_origin->currentIndex()+1);
    }

}

