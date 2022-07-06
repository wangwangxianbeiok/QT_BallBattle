#ifndef MYDOCK_H
#define MYDOCK_H

#include <QDockWidget>
#include <QTextBrowser>
#include <QGraphicsOpacityEffect>
#include <QLabel>
#include <QPalette>
#include <windows.h>
class myDock : public QDockWidget
{
    Q_OBJECT
public:
    explicit myDock(QWidget *parent = nullptr);
    muDock();
    ~myDock();
    void initDock(double W,double H);

    QLabel* score;

signals:

public slots:
};

#endif // MYDOCK_H
