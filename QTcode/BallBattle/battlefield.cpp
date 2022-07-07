#include "battlefield.h"
#include "ui_battlefield.h"
#include "maingamer.h"
#include "config.h"
#include "mydock.h"
#include <QPainter>
#include <QPushButton>
#include <QDockWidget>
#include <QSize>
Battlefield::Battlefield(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Battlefield)
{
    p = new myCamera(0,0);
    ui->setupUi(this);
    resize(INITWIDTH,INITHEIGHT);
    dock= new myDock(this);
    dock->initDock(this->width()-dock->width(),0);
    dock->setParent(this);
    timer.setInterval(1000/64);
    speedtimer.setInterval(500);
    mainGamer::getInstance()->start(INITPIC);
    for(int i = 0;i<50;i++){
        auto tmp = new food;
        tmp->absX = (double)rand()/RAND_MAX*BATTLE_FIELD_WIDTH-BATTLE_FIELD_WIDTH/3;
        tmp->absY = (double)rand()/RAND_MAX*BATTLE_FIELD_HEIGHT-BATTLE_FIELD_HEIGHT/3;
        foodset.push_back(tmp);
    }
    auto player = mainGamer::getInstance();
    double centerX = player->absX+player->Pic.width();
    double centerY = player->absY+player->Pic.height();
    for(int i = 0;i<3;i++){
        auto tmp = new AI;
        tmp->absX = (double)rand()/RAND_MAX*BATTLE_FIELD_WIDTH-BATTLE_FIELD_WIDTH/3;
        tmp->absY = (double)rand()/RAND_MAX*BATTLE_FIELD_HEIGHT-BATTLE_FIELD_HEIGHT/3;
        QString qrs = ":/res/ball/role_0";
        int index = floor((double)rand()/RAND_MAX*5+1);
        QString qrst = QString::fromStdString(std::to_string(index));
        qrs.append(qrst);
        qrs.append(".png");
        tmp->Pic.load(qrs);
        tmp->picH = tmp->Pic.height();
        tmp->picW = tmp->Pic.width();
        double fcX = tmp->absX+tmp->picW/2;
        double fcY = tmp->absY+tmp->picH/2;
        double dis =sqrt(pow(centerX-fcX,2)+pow(centerY-fcY,2));
        while(dis<=std::min(tmp->picW/2,tmp->picH/2)+std::min(player->Pic.width()/2,player->Pic.height()/2)){
            tmp->absX = (double)rand()/RAND_MAX*BATTLE_FIELD_WIDTH-BATTLE_FIELD_WIDTH/3;
            tmp->absY = (double)rand()/RAND_MAX*BATTLE_FIELD_HEIGHT-BATTLE_FIELD_HEIGHT/3;
        }
        AIset.push_back(tmp);
    }
    gameBegin();
}

Battlefield::~Battlefield()
{
    delete ui;
}

void Battlefield::paintEvent(QPaintEvent *event)
{    QPainter qp(this);
     QPixmap l1;
     QPixmap l2;
     l1.load(FLOOR);
     l2.load(":/res/food/food_01.png");
     auto player = mainGamer::getInstance();
     for(double x = -BATTLE_FIELD_WIDTH/3-p->posX;x<=BATTLE_FIELD_WIDTH/3*2-p->posX;){
        for(double y = -BATTLE_FIELD_WIDTH/3-p->posY;y<=BATTLE_FIELD_HEIGHT/3*2-p->posY;){
            qp.drawPixmap(x,y,l1.width(),l1.height(),l1);
            y+=l1.height();
         }
        x+=l1.width();
    }
      for(auto tmp:foodset){
          int x = tmp->absX-p->posX;
          int y = tmp->absY-p->posY;
          tmp->picW = l2.width();
          tmp->picH = l2.height();
          qp.drawPixmap(x,y,l2.width(),l2.height(),l2);
      }
       for(auto tmp:AIset){
           int x = tmp->absX-p->posX;
           int y = tmp->absY-p->posY;
           qp.drawPixmap(x,y,tmp->picW,tmp->picH,tmp->Pic);
       }

    qp.drawPixmap(player->x,player->y,player->Pic.width(),player->Pic.height(),player->Pic);
}
void Battlefield::gameBegin(){
    timer.start();
    speedtimer.start();
    connect(&speedtimer,&QTimer::timeout,[=]{
       auto player = mainGamer::getInstance();
       player->speedX = player->speedX*0.7;
       player->speedY = player->speedY*0.7;
       for(auto tmp:AIset){
           tmp->chageSpeed();
       }
    });
    connect(&timer,&QTimer::timeout,[=]{
        p->move();
        auto player = mainGamer::getInstance();
        player->move(p);
        player->collisionCheck(foodset);
        for(auto tmp:AIset){
            tmp->move();
            tmp->collisionCheck(foodset);
        }
        auto qstr = QString::fromStdString(std::to_string(mainGamer::getInstance()->score));
        dock->score->setText(qstr);
        update();
    });
}

void Battlefield::keyPressEvent(QKeyEvent *event){
    auto player = mainGamer::getInstance();
    if(event->key()==Qt::Key_W){
        player->speedY-=0.5;
    }
    if(event->key()==Qt::Key_S){
        player->speedY+=0.5;
    }
    if(event->key()==Qt::Key_A){
        player->speedX-=0.5;
    }
    if(event->key()==Qt::Key_D){
        player->speedX+=0.5;
    }
}

