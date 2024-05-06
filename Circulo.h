#ifndef CIRCULO_H
#define CIRCULO_H

class Circulo{
    public:    
        double X,Y,A,H;//cordenada X, Coordenada Y, Alto, Ancho.
        float Radio;
        float Red,Blue,Green,Alpha;//Valores de los Colores RGB.
    
        Circulo();
        Circulo(double Size,float _red,float _green, float _blue);
        void change_Color(float c_Red,float c_Green,float c_Blue);
        void change_Size(double cambio,double width,double height,int opcion);
        ~Circulo();
};

#endif