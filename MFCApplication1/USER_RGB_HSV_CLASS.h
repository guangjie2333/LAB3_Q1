#pragma once

#include <iostream>
using namespace std;

/********************�ṹ�嶨����*********************/

//RGB�ṹ�嶨��
typedef struct
{
    int r;
    int g;
    int b;
} RGB_STRUCT;

//HSV�ṹ�嶨��
typedef struct
{
    int h;
    float s;
    float v;
} HSV_STRUCT;


/********************�ඨ����*********************/

class USER_RGB_HSV_CLASS
{
    public:
        //��ʼ��&�˳�
        USER_RGB_HSV_CLASS(void);//���캯������
        ~USER_RGB_HSV_CLASS(void);//������������

        //�û��Զ��庯�� 
        HSV_STRUCT RGB2HSV(RGB_STRUCT rgb);
        RGB_STRUCT HSV2RGB(HSV_STRUCT hsv);

};

