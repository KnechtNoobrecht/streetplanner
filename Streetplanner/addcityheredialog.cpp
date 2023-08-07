#include "addcityheredialog.h"
#include "ui_addcityheredialog.h"

addCityHereDialog::addCityHereDialog(int posX, int posY, Map *map, QGraphicsScene& scene, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addCityHereDialog),
    posX(posX),
    posY(posY),
    map(map),
    scene(scene)
{
    ui->setupUi(this);
}

addCityHereDialog::~addCityHereDialog()
{
    delete ui;
}

/**
 * @brief Event listener for when the ok button is pressed: Checks given data if it is a string, then adds city with that name at the coordinates the user clicked at.
 */
void addCityHereDialog::on_buttonBox_accepted()
{
    QString cityname = ui->lineEdit->text();
    cityname = cityname.trimmed();
    bool isInt;
    cityname.toInt(&isInt);
    if(!isInt && cityname != "" )
    {
        map->addCity(cityname, posX, posY);
        map->draw(scene);
        //this->close();
    }
}

