#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPen>
#include <QBrush>
#include <QTime>
#include <QRandomGenerator>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QWidget>

#include "mapio.h"
#include "mapionrw.h"
#include "dijkstra.h"
#include "shortway.h"
#include "newstreet.h"

#include "city.h"
#include "map.h"
#include "street.h"
#include "dialog.h"
#include "ui_dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    /**
     * @brief Handles the click event for the test button for the line Edit.
     *
     */
    void on_pushButton_teste_was_clicked();

    /**
     * @brief Handles the trigger event for exiting the application.
     *
     */
    void on_actionExit_2_triggered();
    /**
     * @brief Handles the trigger event for clearing the scene.
     *
     */
    void on_actionClear_Scene_triggered();
    /**
     * @brief Handles the trigger event for showing the "About" dialog.
     *
     */
    void on_actionAbout_triggered();
    /**
     * @brief Handles the click event for drawing new cities.
     *
     */
    void on_drawNewPoint_clicked();
    /**
     * @brief Handles the click event for drawing a new map with cities and streets.
     *
     */
    void on_drawNewMap_clicked();
    /**
     * @brief Test function for the abstract map.
     * This function tests whether the class Map correctly implements the interface "AbstractMap".
     *
     */
    void testAbstractMap();

    /**
     * @brief Test function to draw cities.
     *
     */
    void testDrawCities();
    /**
     * @brief Test function to draw a map with cities and streets.
     *
     */
    void testDrawMapWithCitiesAndStreets();
    /**
     * @brief Test function for Dijkstra's algorithm.
     *
     */
    void testDijkstra();
    /**
     * @brief Test function for the line Edit.
     *
     */
    void testLineEdit();
    /**
     * @brief Test function to test if streets were implemented correct.
     *
     */
    void testDrawStreets();
    /**
     * @brief Test function to reject duplicate streets.
     *
     */
    void testRejectStreet();



    /**
     * @brief Handles the click event for the test checkbox.
     *
     */
    void on_checkBox_teste_was_clicked();
    /**
     * @brief Handles the click event for adding a new city.
     *
     */
    void on_pushButton_addCIty_clicked();
    /**
     * @brief Handles the click event for filling the map.
     *
     */
    void on_pushButton_fillMap_clicked();
    /**
     * @brief Handles the click event for testing the abstract map.
     *
     */
    void on_pushButton_test_abstract_map_clicked();
    /**
     * @brief Handles the click event for testing Dijkstra's algorithm.
     *
     */
    void on_pushButton_test_Dijkstra_clicked();
    /**
     * @brief Handles the click event for finding the shortest way.
     *
     */
    void on_pushButton_find_shortest_way_clicked();
    /**
     * @brief Handles the click event for drawing streets.
     *
     */
    void on_pushButton_test_draw_street_clicked();
    /**
     * @brief Slot triggered when the "Add Street" button is clicked.
     *
     * This method opens the Dialog for the user to input details of a new street.
     */
    void on_pushButton_addStreet_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Map *map;
    MapIo *mapIo;




};
#endif // MAINWINDOW_H
