#include "street.h"
#include <QDebug>

Street::Street(City* city1, City* city2)
    : city1(city1), city2(city2)
{
}

void Street::draw(QGraphicsScene& scene) const
{
    if (city1 && city2) {
        scene.addLine(city1->getX(), city1->getY(), city2->getX(), city2->getY(), QPen(Qt::black));
        qDebug() << "Drawing street between:" << city1->getName() << "and" << city2->getName();
    }
}
City* Street::getCity1() const {
    return city1;
}

City* Street::getCity2() const {
    return city2;
}



double Street::getLength() const
{

        double dx = city1->getX() - city2->getX();
        double dy = city1->getY() - city2->getY();

        return std::sqrt(dx * dx + dy * dy);
}
void Street::drawRed(QGraphicsScene& scene)
{
    QPen pen(Qt::red);
    pen.setWidth(3);

    scene.addLine(city1->getX(), city1->getY(), city2->getX(), city2->getY(), pen);
}
