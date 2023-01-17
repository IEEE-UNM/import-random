#include "SpinnerWindow.h"
#include <QGridLayout>
#include <QGraphicsOpacityEffect>

/** Constructor for SpinnerWindow.
 *
 * @param parent The parent of the window.
 * */
SpinnerWindow::SpinnerWindow(QWidget *parent): QMainWindow(parent) {
    // Setting Up Widgets
    wheel = new SpinningWheel(this);
    editor = new QPlainTextEdit(this);
    spin = new QPushButton("Spin", this);
    reset = new QPushButton("Reset", this);
    winner = new QLabel(wheel);
    winnerBackground = new QWidget(wheel);
    button_layout = new QStackedLayout();
    QWidget *centralWidget = new QWidget(this);
    QGridLayout *layout = new QGridLayout(centralWidget);

    // Setting button_layout
    button_layout->addWidget(spin);
    button_layout->addWidget(reset);

    // Setting winner widget
    winner->setAlignment(Qt::AlignCenter);
    QFont font = winner->font();
    font.setPointSize(25);
    winner->setFont(font);

    // Setting winnerBackground widget
    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(winnerBackground);
    effect->setOpacity(0.5);
    winnerBackground->setGraphicsEffect(effect);

    // Disabling spin button
    spin->setDisabled(true);

    // Setting up the layout
    layout->addWidget(wheel, 0, 0);
    layout->addWidget(editor, 0, 1);
    layout->addLayout(button_layout, 1, 1);

    // Setting centralWidget
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    // Connecting signals
    connect(editor, &QPlainTextEdit::textChanged, this, &SpinnerWindow::updateWheel);
    connect(spin, &QPushButton::clicked, this, &SpinnerWindow::spinWheel);
    connect(wheel, &SpinningWheel::stopped, this, &SpinnerWindow::displayWinner);
    connect(reset, &QPushButton::clicked, this, &SpinnerWindow::resetWheel);
}

/** Slot called to update the items on the wheel.
 *
 * This is called when the QPlainTextEdit::textChanged() signal is emited from
 * the QPlainTextEditor (editor). It adds and removes the items on the wheel
 * accordingly.
 * */
void SpinnerWindow::updateWheel() {
    // Getting all the items
    QStringList items = editor->toPlainText().split('\n', Qt::SkipEmptyParts);

    // Disabling and enabling the spinning the wheel if there is no text
    if (items.size() > 0 && !spun) {
        spin->setDisabled(false);
    } else if (items.size() > 0 && spun) {
        resetWheel();
    } else {
        spin->setDisabled(true);
    }

    // Adding items to wheel
    wheel->updateItems(items);
}

/** Slot called when the user stared spinning the wheel. */
void SpinnerWindow::spinWheel() {
    wheel->spin();
    spun = true;

    // Disabling spin button and editor
    spin->setDisabled(true);
    editor->setDisabled(true);
}

/** Slot called when the SpinningWheel stoped spinning.
 *
 * This is called when the SpinningWheel::stopped() signal is emited.
 * It makes the background visible and displays the winner on the screen.
 * */
void SpinnerWindow::displayWinner(QString selected) {
    winnerBackground->setStyleSheet("background: white");
    winner->setText("Winner:\n" + selected);
    editor->setDisabled(false);
    button_layout->setCurrentIndex(1);
}

/** Slot called to reset the SpinningWheel. */
void SpinnerWindow::resetWheel() {
    // Resetting Winner
    winnerBackground->setStyleSheet("background: none");
    winner->setText("");

    // Resetting Wheel
    wheel->reset();
    spun = false;

    // Resetting buttons
    spin->setDisabled(false);
    button_layout->setCurrentIndex(0);
    updateWheel();
}

/** Method that handles the logic when the window is resized.
 *
 * It changes the size of the winner background and text. The size is based
 * on the size of the SpinningWheel.
 *
 * @param event The resize event.
 * */
void SpinnerWindow::resizeEvent(QResizeEvent *event) {
    QMainWindow::resizeEvent(event);

    // Resizing winner background
    QSize wheelSize = wheel->size();
    winnerBackground->resize(wheelSize);

    // Resizing winner text
    int size = wheelSize.width();
    if (wheelSize.width() > wheelSize.height()) {
        size = wheelSize.height();
    } else {
        size = wheelSize.width();
    }
    winner->resize(size, size);
}
