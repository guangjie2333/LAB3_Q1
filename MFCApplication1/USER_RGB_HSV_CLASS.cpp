#include "pch.h"
#include "USER_RGB_HSV_CLASS.h"

// 构造函数
USER_RGB_HSV_CLASS::USER_RGB_HSV_CLASS(void)
{
    cout << "finish by guangjie2333 " << endl;
    cout << "Hardwork makes lucky dog " << endl;
    cout << "please enjoy your life" << endl;
}

// 构造函数
USER_RGB_HSV_CLASS::~USER_RGB_HSV_CLASS(void)
{
    cout << "finish by guangjie2333 " << endl;
    cout << "Hardwork makes lucky dog " << endl;
    cout << "thanks for using my function" << endl;
}


//RGB转换为HSV控空间的函数
// 参照：
//https://www.cnblogs.com/klchang/p/6784856.html

HSV_STRUCT USER_RGB_HSV_CLASS:: RGB2HSV(RGB_STRUCT rgb)
{ 
    // r,g,b values are from 0 to 1
    // h = [0,360], s = [0,1], v = [0,1]

    float R, G, B;
    float min, max, delta, tmp;
    HSV_STRUCT hsv;

    //归一化
    R = (float)rgb.r / 255;
    G = (float)rgb.g / 255;
    B = (float)rgb.b / 255;

    //最小值
    tmp = R > G ? G : R;
    min = tmp > B ? B : tmp;

    //最大值
    tmp = R > G ? R : G;
    max = tmp > B ? tmp : B;

    //max - min 
    delta = max - min;

    //计算v
    hsv.v = max;

    //计算s
    if (max != 0)
    {
        hsv.s = delta / max;
    }
    else
    {
        hsv.s = 0;
    }

    //计算h
    if (0 == hsv.s)
    {
        hsv.h = 0;
    }
    else if (R == max)
    {
        hsv.h = (int)((int)((G-B)/delta)%6)*60;
    }
    else if (G == max)
    {
        hsv.h = (int)((B - R) / delta + 2)  * 60;
    }
    else if (B == max)
    {
        hsv.h = (int)((R - G) / delta + 4) * 60;
    }

    //检查范围
    if ((hsv.v >= 0 && hsv.v <= 1) && (hsv.s >= 0 && hsv.s <= 1) && (hsv.h >= 0 && hsv.h <= 360))
    {
        return hsv;
    }
    else
    {
        TRACE(" RGB2HSV result error");
    }
}


//RGB转换为HSV控空间的函数
// 参照：
//ppt

RGB_STRUCT USER_RGB_HSV_CLASS::HSV2RGB(HSV_STRUCT hsv)
{
    int H;
    float S, V;
    int p, q, t,i,f;
    RGB_STRUCT rgb;

    if (360 == hsv.h)
    {
        H = 0;
    }
    S = hsv.s;
    V = hsv.v;

    i = H / 60;
    f = H % 60;

    p = V * (1 - S);
    q = V * (1 - S * f);
    t = V * (1 - S * (1 - f));

    switch (i)
    {
    case 0:
        rgb.r = V;
        rgb.g = t;
        rgb.b = p;
        break;
    case 1:
        rgb.r = q;
        rgb.g = V;
        rgb.b = p;
        break;
    case 2:
        rgb.r = p;
        rgb.g = V;
        rgb.b = t;
        break;
    case 3:
        rgb.r = p;
        rgb.g = q;
        rgb.b = V;
        break;
    case 4:
        rgb.r = t;
        rgb.g = p;
        rgb.b = V;
        break;
    case 5:
        rgb.r = V;
        rgb.g = p;
        rgb.b = q;
        break;
    default:
        break;
    }


    return rgb;

}