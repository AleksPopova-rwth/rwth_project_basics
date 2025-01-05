#include "city.h"
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>

City::City(QString name, int x, int y)
    : name(name), x(x), y(y)
{
}

void City::draw(QGraphicsScene& scene)
{
    // Ausgabe der Debug-Information auf der Konsole
    qDebug() << "Drawing city:" << name << "at (" << x << "," << y << ")";

    // Zeichnen des roten Punktes
    QGraphicsEllipseItem *point = scene.addEllipse(x - 3, y - 3, 6, 6, QPen(Qt::red), QBrush(Qt::red));

    // Optional: Zeichnen des Namens der Stadt
    QGraphicsTextItem *text = scene.addText(name);
    text->setPos(x + 5, y - 5); // Positioniere den Text leicht versetzt neben dem Punkt
    point->setToolTip(getName()); // Hier fügen Sie einen Tooltip mit dem Namen der Stadt hinzu
}
QString City::getName() const
{
    return name;
}

int City::getX() const
{
    return x;
}

int City::getY() const
{
    return y;
}
