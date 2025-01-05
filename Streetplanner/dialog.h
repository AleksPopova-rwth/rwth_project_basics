#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug>
#include <city.h>

namespace Ui {
class Dialog;
}
/**
 * @brief The Dialog class represents a dialog for creating a city.
 *  The Dialog class provides a dialog window that allows the user to input
 *  details for creating a new city. It emits a signal when a new city is created.
 */
class Dialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor.
     *  Constructs a Dialog with an optional parent widget.
     *
     *  @param parent Pointer to the parent widget. Defaults to nullptr.
     */
    explicit Dialog(QWidget *parent = nullptr);
    /**
     * @brief Gets the created city.
     *  Returns a pointer to the city created in the dialog.
     *
     *  @return Pointer to the created city.
     */
    City* getCreatedCity() const; // Rückgabewert für die erstellte Stadt

     ~Dialog();

signals:
    /**
     * @brief Signal emitted when a city is created.
     *  This signal is emitted when the user accepts the dialog and a new city
     *  is created.
     *
     *  @param newCity Pointer to the created city.
     */
    void cityCreated(City* newCity); // Signal, das eine neue Stadt überträgt



private slots:
    /**
     * @brief Slot called when the accept button is clicked.
     *  This slot is called when the user accepts the dialog. It creates a new
     *  city and emits the cityCreated signal.
     */
    void on_button_accept_reject_accepted();

    /**
     * @brief Slot called when the reject button is clicked.
     *  This slot is called when the user rejects the dialog. It closes the dialog
     *  without creating a city.
     */
    void on_button_accept_reject_rejected();

private:
    Ui::Dialog *ui;
    City* createdCity;
};

#endif // DIALOG_H
