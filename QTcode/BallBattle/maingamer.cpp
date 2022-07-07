#include "maingamer.h"
#include "camera.h"
#include "config.h"
mainGamer::mainGamer(int x)
{

}

void mainGamer::start(QString path)
{
    Pic.load(path);
    absX =INITWIDTH/2-Pic.width()/2;
    absY = INITHEIGHT/2-Pic.height()/2;
    x = absX;
    y = absY;
}
void mainGamer::move(myCamera *cam){
    if(abs(speedX)>=6){speedX=6*(speedX)/abs(speedX);}
    if(abs(speedY)>=6){speedY=6*(speedY)/abs(speedY);}
    absX+=speedX;
    absY+=speedY;
    if(absX>=BATTLE_FIELD_WIDTH*2/3-Pic.width()/2){
        absX = BATTLE_FIELD_WIDTH*2/3-Pic.width()/2;
        speedX = 0;
    }
    if(absX<=-BATTLE_FIELD_WIDTH/3-50){
        absX = -BATTLE_FIELD_WIDTH/3-50;
        speedX = 0;
    }
    if(absY>=BATTLE_FIELD_HEIGHT*2/3-Pic.height()/2){
        absY = BATTLE_FIELD_HEIGHT*2/3-Pic.height()/2;
        speedY = 0;
    }
    if(absY<=-BATTLE_FIELD_HEIGHT/3-50){
        absY = -BATTLE_FIELD_HEIGHT/3-50;
        speedY = 0;
    }


    x = absX-cam->posX;
    y = absY-cam->posY;
}

void mainGamer::collisionCheck(std::vector<food *> foodset)
{
    double centerX = absX+Pic.width()/2;
    double centerY = absY+Pic.height()/2;
    int i = 0;
    for(auto tmp:foodset){
        if(tmp==nullptr){
            i++;
            continue;
        }
        double fcX = tmp->absX+tmp->picW/2;
        double fcY = tmp->absY+tmp->picH/2;
        double dis =sqrt(pow(centerX-fcX,2)+pow(centerY-fcY,2));
        if(dis<=std::min(tmp->picW/2,tmp->picH/2)+std::min(Pic.width()/2,Pic.height()/2)){
            tmp->absX = (double)rand()/RAND_MAX-BATTLE_FIELD_WIDTH/3;
            tmp->absY = (double)rand()/RAND_MAX-BATTLE_FIELD_HEIGHT/3;
            score+=10;
        }
        i++;
    }
}
