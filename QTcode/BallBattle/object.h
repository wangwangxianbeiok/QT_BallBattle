#ifndef OBJECT_H
#define OBJECT_H
#include <QPixmap>

class Object
{
public:
    void move();
    Object();
    double absX;//绝对坐标系位置
    double absY;
    double x;//相对坐标系位置
    double y;
    double picW;//贴图大小
    double picH;//
    QPixmap Pic;
};

#endif // OBJECT_H
