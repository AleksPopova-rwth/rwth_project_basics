#include "shortway.h"
#include "ui_shortway.h"

ShortWay::ShortWay(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShortWay)
{
    ui->setupUi(this);
}

ShortWay::~ShortWay()
{
    delete ui;
}

void ShortWay::on_buttonBox_accepted()
{
    // Stadtname aus den Textfeldern lesen
    QString city_name_1 = ui->name_city1->text();
    QString city_name_2 = ui->name_city2->text();
    QVector<QString> cityNames;
    cityNames.append(city_name_1);
    cityNames.append(city_name_2);
    setCityNames(cityNames);
    // Akzeptiere die Eingabe (schließt normalerweise das Dialogfenster)
    accept();
}
void ShortWay::setCityNames(const QVector<QString>& city)
{
    cities = city;
}

QVector<QString> ShortWay::getCityNames() const
{
    return cities;
}

void ShortWay::on_buttonBox_rejected()
{
    rejected();
}

bool ShortWay::validateCityNames(QString& errorMessage)
{
    QVector<QString> cities = getCityNames();
    for (const QString& city : cities) {
        if (city.isEmpty()) {
            errorMessage = "Die Stadtnamen dürfen nicht leer sein.";
            return false;
        }
        if (city.toStdString().find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZäöüÄÖÜß ") != std::string::npos) {
            errorMessage = "Die Stadtnamen dürfen nur Buchstaben und Leerzeichen enthalten.";
            return false;
        }
    }
    return true;
}
