#ifndef AI_H
#define AI_H
#include "object.h"
#include "food.h"
class AI : public Object{
public:
    AI();
    ~AI();
    void move();
    void collisionCheck(std::vector<food *> foodset);
    void chageSpeed();
    int score = 0;
    double speedX = 0;
    double speedY = 0;
};

#endif // AI_H
