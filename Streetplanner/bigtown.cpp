#include "bigtown.h"

BigTown::BigTown(QString name, int x, int y): name(name), x(x), y(y)
{

}

void BigTown::draw(QGraphicsScene& scene)
{
    scene.addEllipse(x,y,10,10,QPen(QColor(215,215,215,255)), QBrush(QColor(215,215,215,255), Qt::SolidPattern));
    QGraphicsTextItem* descriptionName = new QGraphicsTextItem;
    descriptionName->setPos(x+10,y-8);
    descriptionName->setPlainText(name);
    descriptionName->setFont(QFont(".AppleSystemUIFont", 14, 600));
    scene.addItem(descriptionName);
    QString debug = "City '%1' drawn at %2,%3";
    qDebug() << debug.arg(name).arg(x).arg(y);
}
