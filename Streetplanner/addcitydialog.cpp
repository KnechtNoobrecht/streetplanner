#include "addcitydialog.h"
#include "ui_addcitydialog.h"

addCityDialog::addCityDialog(Map *map, QGraphicsScene& scene, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addCityDialog),
    map(map),
    scene(scene)
{
    ui->setupUi(this);
}

addCityDialog::~addCityDialog()
{
    delete ui;
}

/**
 * @brief Is executed when "OK"-button is clicked: Checks the given data and adds a city to the map, which is then drawn to the scene.
 */
void addCityDialog::on_buttonBox_accepted()
{
    QString cityname = ui->lineEdit_addCity_name->text();
    cityname = cityname.trimmed();
    bool isInt;
    cityname.toInt(&isInt);
    qDebug() << cityname;
    if(isInt || cityname.length() == 0)
    {
        this->ui->label_errorText->setText("Invalid City name");
        this->open();
        return;
    }
    int x = ui->spinBox_addCity_x->value();
    int y = ui->spinBox_addCity_y->value();
    map->addCity(cityname, x, y);
    map->draw(scene);
}

