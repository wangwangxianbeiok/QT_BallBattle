#ifndef MAINGAMER_H
#define MAINGAMER_H
#include "object.h"
#include "camera.h"
#include "food.h"
#include<QString>
class mainGamer:public Object{

private:
    mainGamer(int x);
    ~mainGamer();
public:

    static mainGamer* getInstance(){
        if(gamePointer==nullptr){
            gamePointer = new mainGamer(1);
        }
        return gamePointer;
    }
    void start(QString path);
    void move(myCamera *cam);
    void collisionCheck(std::vector<food*> foodset);
private:
    static mainGamer* gamePointer;
public:
    double speedX = 0;//速度
    double speedY = 0;
    int score = 0;

};

#endif // MAINGAMER_H
