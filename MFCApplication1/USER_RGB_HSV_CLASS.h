#pragma once

#include <iostream>
using namespace std;

/********************结构体定义区*********************/

//RGB结构体定义
typedef struct
{
    int r;
    int g;
    int b;
} RGB_STRUCT;

//HSV结构体定义
typedef struct
{
    int h;
    float s;
    float v;
} HSV_STRUCT;


/********************类定义区*********************/

class USER_RGB_HSV_CLASS
{
    public:
        //初始化&退出
        USER_RGB_HSV_CLASS(void);//构造函数声明
        ~USER_RGB_HSV_CLASS(void);//析构函数声明

        //用户自定义函数 
        HSV_STRUCT RGB2HSV(RGB_STRUCT rgb);
        RGB_STRUCT HSV2RGB(HSV_STRUCT hsv);

};

