#include "mainwindow.h"

#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), isXTurn(new bool(true)){

    QWidget *center = new QWidget();
    setCentralWidget(center);

    QVBoxLayout *mainLayout = new QVBoxLayout(center);
    QHBoxLayout *topLayout = new QHBoxLayout();


    QLabel *title = new QLabel("Tic-Tac-Toe");
    topLayout->addWidget(title, 0);

    resetButton = new QPushButton("reset");
    topLayout->addWidget(resetButton, 1);
    connect(resetButton, &QPushButton::clicked, this, &MainWindow::resetButtonClicked);


    mainLayout->addLayout(topLayout);

    QGridLayout *buttonLayout = new QGridLayout();

    // add top row buttons
    t1Button = new QPushButton("┏┓\n┗┛");
    buttonLayout->addWidget(t1Button, 0, 0);
    connect(t1Button, &QPushButton::clicked, this, &MainWindow::t1ButtonClicked);

    t2Button = new QPushButton("┏┓\n┗┛");
    buttonLayout->addWidget(t2Button, 0, 1);
    connect(t2Button, &QPushButton::clicked, this, &MainWindow::t2ButtonClicked);

    t3Button = new QPushButton("┏┓\n┗┛");
    buttonLayout->addWidget(t3Button, 0, 2);
    connect(t3Button, &QPushButton::clicked, this, &MainWindow::t3ButtonClicked);

    // add middle row buttons
    m1Button = new QPushButton("┏┓\n┗┛");
    buttonLayout->addWidget(m1Button, 1, 0);
    connect(m1Button, &QPushButton::clicked, this, &MainWindow::m1ButtonClicked);

    m2Button = new QPushButton("┏┓\n┗┛");
    buttonLayout->addWidget(m2Button, 1, 1);
    connect(m2Button, &QPushButton::clicked, this, &MainWindow::m2ButtonClicked);

    m3Button = new QPushButton("┏┓\n┗┛");
    buttonLayout->addWidget(m3Button, 1, 2);
    connect(m3Button, &QPushButton::clicked, this, &MainWindow::m3ButtonClicked);

    // add bottom row buttons
    b1Button = new QPushButton("┏┓\n┗┛");
    buttonLayout->addWidget(b1Button, 2, 0);
    connect(b1Button, &QPushButton::clicked, this, &MainWindow::b1ButtonClicked);

    b2Button = new QPushButton("┏┓\n┗┛");
    buttonLayout->addWidget(b2Button, 2, 1);
    connect(b2Button, &QPushButton::clicked, this, &MainWindow::b2ButtonClicked);

    b3Button = new QPushButton("┏┓\n┗┛");
    buttonLayout->addWidget(b3Button, 2, 2);
    connect(b3Button, &QPushButton::clicked, this, &MainWindow::b3ButtonClicked);

    mainLayout->addLayout(buttonLayout);


}

MainWindow::~MainWindow() {
    delete isXTurn;
}

void MainWindow::runTurn(QPushButton* button) {
    button->setText(*isXTurn ? "x" : "O");
    button->setEnabled(false);

    QFont font = button->font();
    font.setPointSize(28);
    button->setFont(font);

    *isXTurn = !(*isXTurn);

    resetButton->setEnabled(true);
}

void MainWindow::resetButtonClicked() {
    resetAction(t1Button);
    resetAction(t2Button);
    resetAction(t3Button);

    resetAction(m1Button);
    resetAction(m2Button);
    resetAction(m3Button);

    resetAction(b1Button);
    resetAction(b2Button);
    resetAction(b3Button);

    *isXTurn = true;

    resetButton->setEnabled(false);
}

void MainWindow::resetAction(QPushButton* button) {
    button->setEnabled(true);

    QFont font = button->font();
    font.setPointSize(13);
    button->setFont(font);

    button->setText("┏┓\n┗┛");
}

// top buttons
void MainWindow::t1ButtonClicked() {
    runTurn(t1Button);
}

void MainWindow::t2ButtonClicked() {
    runTurn(t2Button);
}

void MainWindow::t3ButtonClicked() {
    runTurn(t3Button);
}


// middle buttons
void MainWindow::m1ButtonClicked() {
    runTurn(m1Button);
}

void MainWindow::m2ButtonClicked() {
    runTurn(m2Button);
}

void MainWindow::m3ButtonClicked() {
    runTurn(m3Button);
}


// bottom buttons
void MainWindow::b1ButtonClicked() {
    runTurn(b1Button);
}

void MainWindow::b2ButtonClicked() {
    runTurn(b2Button);
}

void MainWindow::b3ButtonClicked() {
    runTurn(b3Button);
}
