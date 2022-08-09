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
        SpinnerWindow(QWidget *);
    public slots:
        void updateWheel();
        void spinWheel();
        void displayWinner(QString);
    private:
        SpinningWheel *wheel;
        QPlainTextEdit *editor;
        QPushButton *spin;
        QLabel *winner;
        QWidget *winnerBackground;
        bool spun = false;
    protected:
        void resizeEvent(QResizeEvent *);
};

#endif // WINDOW_H_
