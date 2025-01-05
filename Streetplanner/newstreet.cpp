#include "newstreet.h"
#include "ui_newstreet.h"

NewStreet::NewStreet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewStreet)
{
    ui->setupUi(this);
}

NewStreet::~NewStreet()
{
    delete ui;
}

void NewStreet::on_buttonBox_accepted()
{
    QString city_name_1 = ui->lineEdit->text();
    QString city_name_2 = ui->lineEdit_2->text();
    qDebug() << city_name_1;
    qDebug() << city_name_2;
    QVector<QString> cityNames;
    cityNames.append(city_name_1);
    cityNames.append(city_name_2);
    setCityNames(cityNames);
    accept();
}

void NewStreet::setCityNames(const QVector<QString>& city)
{
    cities = city;
}

QVector<QString> NewStreet::getCityNames() const
{
    return cities;
}

void NewStreet::on_buttonBox_rejected()
{
    reject();
}

