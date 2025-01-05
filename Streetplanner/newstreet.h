#ifndef NEWSTREET_H
#define NEWSTREET_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class NewStreet;
}
/**
 * @brief The NewStreet class provides a dialog for adding a new street between two cities.
 *
 * This class inherits from QDialog and handles user input to create a new street.
 * It allows setting and retrieving city names for the new street.
 */
class NewStreet : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a NewStreet dialog object.
     * @param parent The parent widget (default is nullptr).
     */
    explicit NewStreet(QWidget *parent = nullptr);
    /**
     * @brief Sets the names of the cities between which the street will be added.
     * @param cityNames A QVector of QStrings containing the names of the two cities.
     */
    void setCityNames(const QVector<QString>& city);
    /**
     * @brief Retrieves the names of the cities between which the street will be added.
     * @return A QVector of QStrings containing the names of the two cities.
     */
    QVector<QString> getCityNames() const;
    /**
     * @brief Destroys the NewStreet dialog object.
     */
    ~NewStreet();

private slots:
    /**
     * @brief Slot function called when the "Accept" button is clicked.
     *        Emits the accepted() signal.
     */
    void on_buttonBox_accepted();
    /**
     * @brief Slot function called when the "Reject" button is clicked.
     *        Emits the rejected() signal.
     */
    void on_buttonBox_rejected();

private:
    Ui::NewStreet *ui;
    QVector<QString> cities;
};

#endif // NEWSTREET_H
