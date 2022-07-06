#ifndef CAMERA_H
#define CAMERA_H
class myCamera
{
public:
    myCamera(double x,double y);
    ~myCamera();
    void move();
public:
    double posX;//此处代表镜头左上角位置
    double posY;
    bool movableX = true;//是否可以移动X轴
    bool movableY = true;//是否可以移动Y轴
    double index = 1;//缩放系数
};

#endif // CAMERA_H
