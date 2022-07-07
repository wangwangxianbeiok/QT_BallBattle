#include "mydock.h"
#include "maingamer.h"
#include <string>
myDock::myDock(QWidget *parent) : QDockWidget(parent)
{

}

myDock::muDock()
{

}

myDock::~myDock()
{

}

void myDock::initDock(double W,double H)
{



    this->resize(200,400);
    this->move(1024-200,10);
    auto text1 = new QLabel;
    auto text2 = new QLabel;
    auto text3 = new QLabel;
    score = new QLabel;
    text1->setParent(this);
    text1->setText("玩家");
    text1->move(10,-190);
    text2->setParent(this);
    text2->setText("分数");
    text2->move(90,-190);
    text3->setParent(this);
    text3->setText("您");
    text3->move(20,-160);
    auto qstr = QString::fromStdString(std::to_string(mainGamer::getInstance()->score));
    score->setText(qstr);
    score->move(100,-160);
    score->setParent(this);
    score->show();
    this->show();

}
