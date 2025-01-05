#ifndef SHORTWAY_H
#define SHORTWAY_H

#include <QDialog>

namespace Ui {
class ShortWay;
}
/**
 * @brief The ShortWay class provides a dialog for displaying the shortest path between cities.
 *  The ShortWay class is a QDialog-based class that provides a graphical user interface
 *  for displaying and interacting with the shortest path between cities. It allows the
 *  user to view and set the names of the cities involved in the shortest path calculation.
 */
class ShortWay : public QDialog
{
    Q_OBJECT

public:
    /** @brief Constructor.
     *  Constructs a ShortWay dialog.
     *
     *  @param parent The parent widget of the dialog. Defaults to nullptr.
     */
    explicit ShortWay(QWidget *parent = nullptr);
    /**
     * @brief Gets the names of the cities in the shortest path.
     *  Returns a QVector containing the names of the cities that form the shortest path.
     *
     *  @return QVector of QStrings with city names.
     */
    QVector<QString> getCityNames() const;
    /**
     * @brief Sets the names of the cities in the shortest path.
     *  Updates the internal QVector with the names of the cities that form the shortest path.
     *
     *  @param city A QVector of QStrings representing city names.
     */
    void setCityNames(const QVector<QString>& city);
    /**
     * @brief Validates the city names entered in the dialog.
     * @param errorMessage A reference to a string that will hold the error message if validation fails.
     * @return True if the city names are valid, otherwise false.
     */
    bool validateCityNames(QString& errorMessage);
    /**
     * @brief Destructor.
     *  Destroys the ShortWay dialog, releasing any allocated resources.
     */
    ~ShortWay();

private slots:
    /**
     * @brief Slot for handling the accept action.
     *  This slot is called when the user accepts the dialog (e.g., clicks the OK button).
     */
    void on_buttonBox_accepted();
    /**
     * @brief Slot for handling the reject action.
     *  This slot is called when the user rejects the dialog (e.g., clicks the Cancel button).
     */
    void on_buttonBox_rejected();

private:
    Ui::ShortWay *ui;
    QVector<QString> cities; // Membervariable zum Speichern des kürzesten Weges

};

#endif // SHORTWAY_H
