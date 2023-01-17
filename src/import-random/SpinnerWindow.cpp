#include "SpinnerWindow.h"
#include <QGridLayout>
#include <QGraphicsOpacityEffect>

SpinnerWindow::SpinnerWindow(QWidget *parent) {
    setParent(parent);

    // Setting Up Widgets
    wheel = new SpinningWheel(this);
    editor = new QPlainTextEdit(this);
    spin = new QPushButton("Spin", this);
    winnerBackground = new QWidget(wheel);
    winner = new QLabel(wheel);
    QWidget *centralWidget = new QWidget(this);
    QGridLayout *layout = new QGridLayout(centralWidget);

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
    layout->addWidget(spin, 1, 1);

    // Setting centralWidget
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    // Connecting signals
    connect(editor, &QPlainTextEdit::textChanged, this, &SpinnerWindow::updateWheel);
    connect(spin, &QPushButton::clicked, this, &SpinnerWindow::spinWheel);
    connect(wheel, &SpinningWheel::stopped, this, &SpinnerWindow::displayWinner);
}

void SpinnerWindow::updateWheel() {
    QStringList items = editor->toPlainText().split('\n', Qt::SkipEmptyParts);
    if (items.size() > 0 && !spun) {
        spin->setDisabled(false);
    } else {
        spin->setDisabled(true);
    }
    wheel->updateItems(items);
}

void SpinnerWindow::spinWheel() {
    wheel->spin();
    spun = true;
    spin->setDisabled(true);
    editor->setDisabled(true);
}

void SpinnerWindow::displayWinner(QString selected) {
    winnerBackground->setStyleSheet("background: white");
    winner->setText("Winner:\n" + selected);
    editor->setDisabled(false);
}

void SpinnerWindow::resizeEvent(QResizeEvent *) {
    QSize wheelSize = wheel->size();
    winnerBackground->resize(wheelSize);

    int size = wheelSize.width();
    if (wheelSize.width() > wheelSize.height()) {
        size = wheelSize.height();
    } else {
        size = wheelSize.width();
    }
    winner->resize(size, size);
}
