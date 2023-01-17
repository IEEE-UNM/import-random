#ifndef SPINNER_WINDOW_H_
#define SPINNER_WINDOW_H_

#include <QMainWindow>
#include <QWidget>
#include <QString>
#include <SpinningWheel.h>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QResizeEvent>

class SpinnerWindow: public QMainWindow {
    Q_OBJECT
    public:
        /** Constructor for SpinnerWindow.
        *
        * @param parent The parent of the window.
        * */
        SpinnerWindow(QWidget * = nullptr);
    public slots:
        /** Slot called to update the items on the wheel.
        *
        * This is called when the QPlainTextEdit::textChanged() signal is emited from
        * the QPlainTextEditor (editor). It adds and removes the items on the wheel
        * accordingly.
        * */
        void updateWheel();
        /** Slot called when the user stared spinning the wheel. */
        void spinWheel();
        /** Slot called when the SpinningWheel stoped spinning.
        *
        * This is called when the SpinningWheel::stopped() signal is emited.
        * It makes the background visible and displays the winner on the screen.
        * */
        void displayWinner(QString);
    protected:
        /** Method that handles the logic when the window is resized.
        *
        * It changes the size of the winner background and text. The size is based
        * on the size of the SpinningWheel.
        *
        * @param event The resize event.
        * */
        virtual void resizeEvent(QResizeEvent *);
    private:
        /** The SpinningWheel object. */
        SpinningWheel *wheel;
        QPlainTextEdit *editor; /*<The text editor to insert item. */
        QPushButton *spin; /*<Button to start spining the wheel. */
        QLabel *winner; /*<Label that displays the winner.  */
        QWidget *winnerBackground; /*<Background to the winner label. */
        /** Variable that keep tracks if the SpinningWheel has be spun or not. */
        bool spun = false;
};

#endif // WINDOW_H_
