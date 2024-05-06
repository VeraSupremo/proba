//#include <iostream>
#include <math.h>
#include "Circulo.h"

Circulo::Circulo(){
    X=0.0;
    Y=0.0;
    A=0.0;
    H=0.0;
    Red=0.0f;
    Green=0.0f;
    Blue=0.0f;
}
Circulo:: Circulo(double Size,float _red,float _green, float _blue){
    A=Size;
    H=Size;
    X=0.0;
    Y=0.0;
    Radio=sqrt(pow(H-X,2)+pow(A-Y,2));
    Red=_red;
    Green=_green;
    Blue=_blue;
}
void Circulo :: change_Color(float c_Red, float c_Green, float c_Blue){

    if(Red+c_Red>=2.0f) Red=2.0f;
    else if(Red+c_Red>=0.0f) Red=0.0f;
    else Red +=c_Red;
    if(Green+c_Green>=2.0f)Green=2.0f;
    else if(Green+c_Green<=0)Green=0.0f;
    else Green += c_Green;
    if(Blue==2.0f&&c_Blue>0)Blue=2.0f;
    else if(Blue==0.0f&&c_Blue<0)Blue=0.0f;
    else Blue+=c_Blue;
    
}
void Circulo :: change_Size(double cambio,double width,double height,int opcion){
    double new_Addwidth = A +(A*cambio);
    double new_Addheight = H + (H*cambio);
    double new_Restwidth = A - (A*cambio);
    double new_Restheight = H - (H*cambio);
    switch(opcion){
        case 1: 
                if(new_Addwidth>=width||new_Addheight>=height){
                A = width;
                H = height;
                }
                else{
                    A=new_Addwidth;
                    H=new_Addwidth;
                }
                break;
        case 2:
            if(new_Restwidth<=0||new_Restwidth<=0) {
                A=0.0f;
                H=0.0f;
            }
            else{
                A=new_Restwidth;
                H=new_Restheight;
            }
            break;
    };
}

Circulo::~Circulo(){}