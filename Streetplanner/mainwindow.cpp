#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , scene(new QGraphicsScene(this))
    , map(new Map())
    , mapIo(new MapIoNrw)

{

    ui->setupUi(this);
    ui->graphicsView->setScene(scene);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
    delete map;
    delete mapIo;


}


//BUTTONS WITH TEST FUNCTION_________________________________________________________________________________________________________
//-----------------------------------------------------------------------------------------------------------------
void MainWindow::on_pushButton_teste_was_clicked()
{
    testLineEdit();
}

void MainWindow::on_drawNewPoint_clicked()
{
    testDrawCities();
}

void MainWindow::on_pushButton_test_draw_street_clicked()
{
    testDrawStreets();
}

void MainWindow::on_drawNewMap_clicked()
{
    testDrawMapWithCitiesAndStreets();
}

void MainWindow::on_pushButton_test_abstract_map_clicked()
{
    testAbstractMap();
}
void MainWindow::on_pushButton_test_Dijkstra_clicked()
{
    testDijkstra();
}


//BUTTONS WITH REAL FUNCTION_________________________________________________________________________________________________________
//-----------------------------------------------------------------------------------------------------------------



void MainWindow::on_actionExit_2_triggered()
{
    close();

}


void MainWindow::on_actionClear_Scene_triggered()
{
    scene->clear();
}


void MainWindow::on_actionAbout_triggered()
{

    QMessageBox::about(this, "About", "Dies ist eine kurze Beschreibung Ihrer Anwendung.");

}


void MainWindow::on_checkBox_teste_was_clicked()
{
    if (ui->checkBox_teste_was->isChecked())
    {
        ui->drawNewMap->hide();
        ui->drawNewPoint->hide();
        ui->pushButton_addCIty->hide();
        ui->pushButton_addStreet->hide();
        ui->pushButton_fillMap->hide();
        ui->pushButton_find_shortest_way->hide();
        ui->pushButton_test_Dijkstra->hide();
        ui->pushButton_test_abstract_map->hide();
        ui->pushButton_test_draw_street->hide();
        ui->pushButton_teste_was->hide();
    }
    else {
        ui->drawNewMap->show();
        ui->drawNewPoint->show();
        ui->pushButton_addCIty->show();
        ui->pushButton_addStreet->show();
        ui->pushButton_fillMap->show();
        ui->pushButton_find_shortest_way->show();
        ui->pushButton_test_Dijkstra->show();
        ui->pushButton_test_abstract_map->show();
        ui->pushButton_test_draw_street->show();
        ui->pushButton_teste_was->show();
    }

}


void MainWindow::on_pushButton_addCIty_clicked()
{
    Dialog dialog(this);

    while (true) {
        int result = dialog.exec(); // Show Dialog modally

        if (result == QDialog::Accepted) {
            City* newCity = dialog.getCreatedCity();
            if (newCity) {
                QString cityName = newCity->getName();

                // Convert QString to std::string for validation
                std::string stdCityName = cityName.toStdString();

                // Define valid characters (for example: letters, spaces, and hyphens)
                std::string validChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ -";

                // Check if the city name is not empty and contains only valid characters
                if (!stdCityName.empty() && stdCityName.find_first_not_of(validChars) == std::string::npos) {
                    qDebug() << "Neue Stadt erstellt: " << cityName;
                    // Add the new city to the map
                    map->addCity(newCity);
                    map->draw(*scene);
                    break; // Exit the loop if the city was added successfully
                } else {
                    QMessageBox::warning(this, "Ungültige Eingabe", "Der Name der Stadt darf nicht leer sein und nur gültige Zeichen enthalten. Bitte versuchen Sie es erneut.");
                    continue;
                }
            } else {
                QMessageBox::warning(this, "Fehler", "Die Stadt konnte nicht erstellt werden.");
                continue;
            }
        } else {
            qDebug() << "Dialog wurde abgebrochen.";
            break; // Exit the loop if the dialog was canceled
        }
    }
}


void MainWindow::on_pushButton_addStreet_clicked()
{
    NewStreet newstreet(this);

    while (true) {
        int result = newstreet.exec(); // Dialog modal anzeigen

        if (result == QDialog::Accepted) {
            QVector<QString> cities = newstreet.getCityNames();
            QString city_1 = cities[0];
            QString city_2 = cities[1];

            // Convert QString to std::string for validation
            std::string stdCity1 = city_1.toStdString();
            std::string stdCity2 = city_2.toStdString();

            // Define valid characters (for example: letters, spaces, and hyphens)
            std::string validChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ -";
            City* copie_1 = map->findCity(city_1);
            City* copie_2 = map->findCity(city_2);

            // Check if the city names are not empty and contain only valid characters
            if (!stdCity1.empty() && stdCity1.find_first_not_of(validChars) == std::string::npos &&
                !stdCity2.empty() && stdCity2.find_first_not_of(validChars) == std::string::npos) {

                if (!(copie_1 ==nullptr && copie_2 == nullptr)) {
                    qDebug() << "Neue Strasse erstellt zwischen Städten: " << city_1 << " und " << city_2;
                    // Add the new street to the map
                    Street* street = new Street(map->findCity(city_1), map->findCity(city_2));
                    map->addStreet(street);
                    map->draw(*scene);
                    break; // Exit the loop if the street was added successfully
                } else
                {
                    QMessageBox::warning(this, "Ungültige Eingabe", "Eine oder beide Städte existieren nicht in der Karte. Bitte versuchen Sie es erneut.");
                    continue;
                }
            } else
            {
                QMessageBox::warning(this, "Ungültige Eingabe", "Die Namen der Städte dürfen nicht leer sein und müssen nur gültige Zeichen enthalten. Bitte versuchen Sie es erneut.");
                continue;
            }
        } else
        {
            qDebug() << "Dialog wurde abgebrochen.";
            break; // Exit the loop if the dialog was canceled
        }
    }
}

void MainWindow::on_pushButton_fillMap_clicked()
{
    mapIo->fillMap(*map);  // Karte füllen
    map->draw(*scene);  // Karte zeichnen (angenommen, draw() ist eine Methode von AbstractMap)

}

void MainWindow::on_pushButton_find_shortest_way_clicked()
{
    bool validInput = false;
    QString errorMessage;

    while (!validInput) {
        ShortWay shortwayDialog(this);
        int result = shortwayDialog.exec();

        if (result == QDialog::Accepted)
        {
            validInput = shortwayDialog.validateCityNames(errorMessage);
            if (!validInput)
            {
                QMessageBox::warning(this, "Ungültige Eingabe", errorMessage);
                continue; // Show the dialog again
            }

            QVector<QString> cities = shortwayDialog.getCityNames();
            QString city_1 = cities[0];
            QString city_2 = cities[1];
            QVector<Street*> shortestPath = Dijkstra::search(*map, city_1, city_2);
            if (!shortestPath.isEmpty()) {
                for (Street* street : shortestPath)
                {
                    qDebug() << street->getCity1()->getName() << "->" << street->getCity2()->getName() << " Länge:" << street->getLength();
                    street->drawRed(*scene); // Zeichnen der Straße in rot
                }
            }
            else
            {
                QMessageBox::warning(this, "Keine Verbindung", "Es konnte kein Weg zwischen den angegebenen Städten mit diesen Namen gefunden werden. Probiere noch mal ");
                continue;
            }
        }
        else
        {
            qDebug() << "Dialog wurde abgebrochen.";
            break;
        }
    }
}



//TEST METHODS_________________________________________________________________________________________________________
//-----------------------------------------------------------------------------------------------------------------


void MainWindow::testDrawCities()
{
    qDebug() << "Button Test Draw City was clicked!";

    City* city1 = new City("Berlin", 100, 100);
    City* city2 = new City("Munich", 200, 150);

    //     Zeichnen der Karte
    city1->draw(*scene);
    city2->draw(*scene);
}
// Hinzufügen von Städten zu einer Karte und Zeichnen der Städte über die Karte
void MainWindow::testDrawMapWithCitiesAndStreets()
{
    qDebug() << "Button New Map was clicked!";
    //Map map;
    // Erstellen und Hinzufügen der Städte zur Karte, falls noch nicht vorhanden
    City* city1 = new City("Berlin", 100, 100);
    City* city2 = new City("Munich", 200, 150);
    City* city3 = new City("Moscow", 400, 400);

    map->addCity(city1);
    map->addCity(city2);


    // Erstellen und Hinzufügen der Straße zur Karte
    Street* street = new Street(city1, city2);
    Street* street_1 = new Street(city1, city3);
    map->addCity(city3);

    map->addStreet(street);
    map->addStreet(street_1);

    // Zeichnen der Karte
    map->draw(*scene);
}



void MainWindow:: testDrawStreets()
{
    QGraphicsScene scene;
    City city1("City1", 0, 0);
    City city2("City2", 100, 100);
    Street street(&city1, &city2);

    // Zeichne die Straße auf der Szene
    street.drawRed(scene);

    // Überprüfen, ob eine Linie zur Szene hinzugefügt wurde
    QList<QGraphicsItem*> items = scene.items();
    if (items.size() == 1) {
        qDebug() << "Test passed: One item added to the scene.";
    } else {
        qDebug() << "Test failed: Expected 1 item, found" << items.size();
    }

    QGraphicsLineItem* line = dynamic_cast<QGraphicsLineItem*>(items.first());
    if (line != nullptr) {
        qDebug() << "Test passed: Item is a QGraphicsLineItem.";
    } else {
        qDebug() << "Test failed: Item is not a QGraphicsLineItem.";
    }
}

void MainWindow::testRejectStreet()
{
    Map map;

    City* city1 = new City("City1", 0, 0);
    City* city2 = new City("City2", 100, 100);

    map.addCity(city1);
    map.addCity(city2);

    Street* street1 = new Street(city1, city2);
    Street* street2 = new Street(city1, city2); // Duplizierte Straße

    bool added1 = map.addStreet(street1);
    bool added2 = map.addStreet(street2);

    if (added1) {
        qDebug() << "Test passed: First street added successfully.";
    } else {
        qDebug() << "Test failed: First street was not added.";
    }

    if (!added2) {
        qDebug() << "Test passed: Duplicate street was rejected.";
    } else {
        qDebug() << "Test failed: Duplicate street was added.";
    }
}
//void testShowDialog(){
//    DialogAddCity dialog;
//    int result = dialog.exec();
//    qDebug() << QString("Dialog result: %1").arg(result);
//}
void MainWindow::testDijkstra(){
    Map* map = new Map();
    City* cityA = new City("a", 200, 100);
    City* cityB = new City("b", 100, 200);
    City* cityC = new City("c", 300, 300);

    map->addCity(cityA);
    map->addCity(cityB);
    map->addCity(cityC);

    Street* streetAB = new Street(cityA, cityB);
    Street* streetBC = new Street(cityB, cityC);
    Street* streetAC = new Street(cityC, cityA);

    map->addStreet(streetAB);
    map->addStreet(streetBC);
    map->addStreet(streetAC);
    map->draw(*scene);
    QVector<Street*> shortestPath = Dijkstra::search(*map, "a", "b");

    // Ausgabe des kürzesten Weges
    if (shortestPath.isEmpty())
    {
        qDebug() << "Kein Weg gefunden";
    } else {
        qDebug() << "Kürzester Weg gefunden:";
        for (Street* street : shortestPath)
        {
            qDebug() << street->getCity1()->getName() << "->" << street->getCity2()->getName() << " Länge:" << street->getLength();
            street->drawRed(*scene); // Zeichnen der Straße in rot

        }
    }

    // Speicher freigeben
    delete cityA;
    delete cityB;
    delete cityC;
    delete streetAB;
    delete streetBC;
    delete streetAC;
}

// Diese Funktion testet, ob die Klasse Map das Interface "AbstractMap" korrekt implementiert.
void MainWindow::testAbstractMap()
{
    Map testMap;
    City *a = new City("a", 0, 0);
    City *b = new City("b", 0, 100);
    City *c = new City("c", 100, 300);
    Street *s = new Street(a, b);
    Street *s2 = new Street(b, c);


    qDebug() << "MapTest: Start Test of the Map";
    {
        qDebug() << "MapTest: adding wrong street";
        bool t1 = testMap.addStreet(s);
        if (t1) {
            qDebug() << "-Error: Street should not bee added, if cities have not been added.";
        }
    }

    {
        qDebug() << "MapTest: adding correct street";
        testMap.addCity(a);
        testMap.addCity(b);
        bool t1 = testMap.addStreet(s);
        if (!t1) {
            qDebug() << "-Error: It should be possible to add this street.";
        }
    }

    {
        qDebug() << "MapTest: findCity";
        City* city = testMap.findCity("a");
        if (city != a)
            qDebug() << "-Error: City a could not be found.";

        city = testMap.findCity("b");
        if (city != b)
            qDebug() << "-Error: City b could not be found.";

        city = testMap.findCity("c");
        if (city != nullptr)
            qDebug() << "-Error: If city could not be found 0 should be returned.";
    }

    testMap.addCity(c);
    testMap.addStreet(s2);

    {
        qDebug() << "MapTest: getOppositeCity";
        const City *city = testMap.getOppositeCity(s, a);
        if (city != b)
            qDebug() << "-Error: Opposite city should be b.";

        city = map->getOppositeCity(s, c);
        if (city != nullptr)
            qDebug() << "-Error: Opposite city for a city which is not linked by given street should be 0.";
    }

    {
        qDebug() << "MapTest: streetLength";
        double l = testMap.getLength(s2);
        double expectedLength = 223.6;
        // compare doubles with 5% tolerance
        if (l < expectedLength * 0.95 || l > expectedLength *1.05)
            qDebug() << "-Error: Street Length is not equal to the expected.";

    }

    {
        qDebug() << "MapTest: getStreetList";
        QVector<Street*> streetList1 = testMap.getStreetList(a);
        QVector<Street*> streetList2 = testMap.getStreetList(b);
        if (streetList1.size() != 1) {
            qDebug() << "-Error: One street should be found for city a.";
        }
        else if (*streetList1.begin() != s) {
            qDebug() << "-Error: The wrong street has been found for city a.";
        }

        if (streetList2.size() != 2)
            qDebug() << "-Error: Two streets should be found for city b.";
    }

    qDebug() << "MapTest: End Test of the Map.";
}

void MainWindow::testLineEdit()
{
    qDebug() << "Button wurde geklickt!";
    QString text = ui->lineEdit_teste_was->text();
    // Ausgabe des Textes auf der Konsole mit qDebug() und QString::arg()
    bool ok;
    int number = text.toInt(&ok);

    if (ok) {
        // Zahl um 4 erhöhen und ausgeben
        number += 4;
        QString result = QString("Der eingegebene Text ist eine Zahl. Erhöht um 4: %1").arg(number);
        qDebug() << result;       // Grafische Ausgabe mit QMessageBox
        int x = QRandomGenerator::global()->bounded(50); // Zufällige x-Position
        int y = QRandomGenerator::global()->bounded(50); // Zufällige y-Position
        int width = 30;
        int height = 30;

        QPen pen1;
        QBrush brush1;

        pen1.setColor(Qt::red);
        pen1.setWidth(2);
        pen1.setStyle(Qt::DashLine);
        pen1.setCapStyle(Qt::RoundCap);

        brush1.setColor(Qt::red);
        brush1.setStyle(Qt::SolidPattern);
        QLinearGradient gradient(0, 0, 100, 100);
        gradient.setColorAt(0, Qt::red);
        gradient.setColorAt(1, Qt::red);

        scene->addRect(x * 10, y * 10, width, height, pen1, brush1);


        QMessageBox msgBox;
        msgBox.setText(result);
        msgBox.exec();
    } else {
        // Ausgabe, wenn der Text keine Zahl ist
        qDebug() << "Der eingegebene Text ist keine Zahl.";
        QString result  = QString("Button wurde geklickt! Eingetragener Text: %1").arg(text);
        qDebug() << result;

        int x = QRandomGenerator::global()->bounded(50); // Zufällige x-Position
        int y = QRandomGenerator::global()->bounded(50); // Zufällige y-Position
        int width = 30;
        int height = 30;
        QPen pen;
        QBrush brush;

        pen.setColor(Qt::blue);
        pen.setWidth(2);
        pen.setStyle(Qt::DashLine);
        pen.setCapStyle(Qt::RoundCap);

        brush.setColor(Qt::blue);
        brush.setStyle(Qt::SolidPattern);
        QLinearGradient gradient(0, 0, 100, 100);
        gradient.setColorAt(0, Qt::black);
        gradient.setColorAt(1, Qt::blue);

        scene->addRect(x * 10, y * 10, width, height, pen, brush);
        QMessageBox msgBox;
        msgBox.setText(result);
        msgBox.exec();
        // Ein zufällig positioniertes Rechteck in die Szene einfügen

    }
}

