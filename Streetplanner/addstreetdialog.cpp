#include "addstreetdialog.h"
#include "ui_addstreetdialog.h"
#include <iostream>


/**
 * @brief Constructor: Initializes the dialog
 * @param map to work with
 * @param scene on which is drawn
 * @param QWidget parent
 */
addStreetDialog::addStreetDialog(Map *map, QGraphicsScene& scene, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addStreetDialog),
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

/**
 * @brief Deconstructor
 */
addStreetDialog::~addStreetDialog()
{
    delete ui;
}

/**
 * @brief   If user clicks "OK", it takes the input data and creates a new street, which is added to the map.
 *          Additionally, the the map content is drawn on the scene.
 *          Finally, the window is closed.
 */
void addStreetDialog::on_buttonBox_accepted()
{
    QString streetOrigin = ui->comboBox_origin->currentText();
    QString streetTarget = ui->comboBox_target->currentText();
    map->addStreet(streetOrigin, streetTarget);
    map->draw(scene);
    this->close();
}

/**
 * @brief Closes the dialog if "Cancel" is clicked
 */
void addStreetDialog::on_buttonBox_rejected()
{
    this->close();
}

/**
 * @brief Prevents both boxes having the same entry chosen, so there's no street drawn from and to the same city
 */
void addStreetDialog::on_comboBox_origin_currentTextChanged(const QString &arg1)
{
    if(ui->comboBox_origin->currentText() == ui->comboBox_target->currentText())
    {
        ui->comboBox_target->setCurrentIndex(ui->comboBox_target->currentIndex()+1);
    }
}

/**
 * @brief Prevents both boxes having the same entry chosen, so there's no street drawn from and to the same city
 */
void addStreetDialog::on_comboBox_target_currentTextChanged(const QString &arg1)
{
    if(ui->comboBox_target->currentText() == ui->comboBox_origin->currentText())
    {
        ui->comboBox_origin->setCurrentIndex(ui->comboBox_origin->currentIndex()+1);
    }

}

