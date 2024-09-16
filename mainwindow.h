#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/qlabel.h>

class QPushButton;


class MainWindow : public QMainWindow
{
    Q_OBJECT
    // top row
    QPushButton *t1Button;
    QPushButton *t2Button;
    QPushButton *t3Button;

    // middle row
    QPushButton *m1Button;
    QPushButton *m2Button;
    QPushButton *m3Button;

    // bottom row
    QPushButton *b1Button;
    QPushButton *b2Button;
    QPushButton *b3Button;

    QPushButton *resetButton;

    bool *isXTurn;

    QString *turnIndicator;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:

    void runTurn(QPushButton* button);
    void resetButtonClicked();
    void resetAction(QPushButton* button);

    // top row
    void t1ButtonClicked();
    void t2ButtonClicked();
    void t3ButtonClicked();

    // middle row
    void m1ButtonClicked();
    void m2ButtonClicked();
    void m3ButtonClicked();

    // bottom row
    void b1ButtonClicked();
    void b2ButtonClicked();
    void b3ButtonClicked();
};
#endif // MAINWINDOW_H
