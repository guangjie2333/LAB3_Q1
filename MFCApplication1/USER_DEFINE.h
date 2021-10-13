#pragma once

/*
���� ��guangjie2333
ʱ�� ��2021.10.5
��λ ��SZU
�汾 ��V1.0.0
*/

#include <wingdi.h> 
#include <afx.h>
#include <math.h>
using namespace std;

/*************************�궨����*******************************/

/*��������֮�䴫����Ϣ*/
#define WM_GET_DIALOG_HSV_SLIDER_VAL		(WM_USER + 1)         //  IDD_MFCAPPLICATION1_DIALOG  -  IDD_DIALOG1
#define WM_GET_DIALOG_LINE_CHANGE_VAL       (WM_USER + 2)         //  IDD_MFCAPPLICATION1_DIALOG  -  IDD_DIALOG_LINER
#define WM_GET_DIALOG_NLINE_CHANGE_VAL      (WM_USER + 3)         //  IDD_MFCAPPLICATION1_DIALOG  -  IDD_DIALOG_LINER


/***********************�ṹ�嶨����******************************/

/*lab2*/

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

//��������ֵ�ṹ��
typedef struct
{
    int H_slider;
    int S_slider;
    int V_slider;
}HSV_SLIDER_STRUCT;


typedef struct
{
    BYTE* pBmpData;             //ͼ������
    BITMAPFILEHEADER bmpHeader; //�ļ�ͷ
    BITMAPINFOHEADER bmpInfo;   //��Ϣͷ
    CFile bmpFile;              //��¼���ļ�
}bmpData;


/*lab3*/

typedef  struct
{
    int a; //���Ա任ϵ��a
    int b; //���Ա任ϵ��b
}LINE_CHANGE_STRUCT;

typedef  struct
{
    float a; //�����Ա任ϵ��a
    float b; //�����Ա任ϵ��b
    float c; //�����Ա任ϵ��c
}NLINE_CHANGE_STRUCT;