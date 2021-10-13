#pragma once

/*
作者 ：guangjie2333
时间 ：2021.10.5
单位 ：SZU
版本 ：V1.0.0
*/

#include <wingdi.h> 
#include <afx.h>
#include <math.h>
using namespace std;

/*************************宏定义区*******************************/

/*两个窗口之间传递信息*/
#define WM_GET_DIALOG_HSV_SLIDER_VAL		(WM_USER + 1)         //  IDD_MFCAPPLICATION1_DIALOG  -  IDD_DIALOG1
#define WM_GET_DIALOG_LINE_CHANGE_VAL       (WM_USER + 2)         //  IDD_MFCAPPLICATION1_DIALOG  -  IDD_DIALOG_LINER
#define WM_GET_DIALOG_NLINE_CHANGE_VAL      (WM_USER + 3)         //  IDD_MFCAPPLICATION1_DIALOG  -  IDD_DIALOG_LINER


/***********************结构体定义区******************************/

/*lab2*/

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

//滚动条数值结构体
typedef struct
{
    int H_slider;
    int S_slider;
    int V_slider;
}HSV_SLIDER_STRUCT;


typedef struct
{
    BYTE* pBmpData;             //图像数据
    BITMAPFILEHEADER bmpHeader; //文件头
    BITMAPINFOHEADER bmpInfo;   //信息头
    CFile bmpFile;              //记录打开文件
}bmpData;


/*lab3*/

typedef  struct
{
    int a; //线性变换系数a
    int b; //线性变换系数b
}LINE_CHANGE_STRUCT;

typedef  struct
{
    float a; //非线性变换系数a
    float b; //非线性变换系数b
    float c; //非线性变换系数c
}NLINE_CHANGE_STRUCT;