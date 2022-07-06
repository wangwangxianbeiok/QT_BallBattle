#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H
#include "camera.h"
#include "food.h"
#include "mydock.h"
#include "ai.h"
#include<QKeyEvent>
#include <QTimer>
#include <QWidget>

namespace Ui {
class Battlefield;
}

class Battlefield : public QWidget
{
    Q_OBJECT

public:
    explicit Battlefield(QWidget *parent = 0);
    ~Battlefield();
    void paintEvent(QPaintEvent *event);
    void gameBegin();
    void keyPressEvent(QKeyEvent *event);

    myDock * dock;
    QTimer timer;
    QTimer speedtimer;
    std::vector<food *> foodset;
    std::vector<AI *> AIset;

private:
    Ui::Battlefield *ui;
    myCamera* p;
};

#endif // BATTLEFIELD_H
