#include "camera.h"
#include "maingamer.h"
#include "config.h"

myCamera::myCamera(double x,double y):posX(x),posY(y)
{

}

void myCamera::move()
{
    movableX = true;
    auto gamer = mainGamer::getInstance();
    posX+=gamer->speedX*0.8;
    posY+=gamer->speedY*0.8;
    if(posX<=-BATTLE_FIELD_WIDTH/3){
        movableX = false;
        posX = -BATTLE_FIELD_WIDTH/3;
    }
    if(posX>=BATTLE_FIELD_WIDTH/3){
        movableX = false;
        posX = BATTLE_FIELD_WIDTH/3;
    }
    if(posY<=-BATTLE_FIELD_HEIGHT/3){
        movableY = false;
        posY = -BATTLE_FIELD_HEIGHT/3;
    }
    if(posY>=BATTLE_FIELD_HEIGHT/3){
        movableY = false;
        posY = BATTLE_FIELD_HEIGHT/3;
    }


}
