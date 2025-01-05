#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
     createdCity(nullptr)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_button_accept_reject_accepted()
{
    QString city_name = ui->lineEdit_city_name->text();
    QString x_k = ui->lineEdit_x_koordinate->text();
    QString y_k = ui->lineEdit_y_koordinate->text();
    qDebug() << city_name;
    qDebug() << x_k;
    qDebug() << y_k;
    bool ok, oki;
    int i_x_k = x_k.toInt(&ok);
    int i_y_k = y_k.toInt(&oki);

    if (ok && oki)
    { // Überprüfen Sie, ob die Konvertierung erfolgreich war
        createdCity = new City(city_name, i_x_k, i_y_k);

        }
    accept();
}


void Dialog::on_button_accept_reject_rejected()
{
    reject();
}

City* Dialog::getCreatedCity() const
{
    return createdCity; // Rückgabe der erstellten Stadt
}
