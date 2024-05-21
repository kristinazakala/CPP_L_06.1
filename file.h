#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <string>
using namespace std;


class Point {
protected:
    double x;
    double y;
    string color;

public:
    Point(double x = 0.0, double y = 0.0, string color = "black");
    virtual ~Point() {}

    // переміщення точки
    virtual void move(double dx, double dy);

    // зміна кольору точки
    virtual void changeColor(const string& newColor);

    // виведення інформації про точку
    virtual void display() const;
};


class Vector : public Point {
protected:
    double length;
    double angle; 

public:
    Vector(double x = 0.0, double y = 0.0, double length = 1.0, double angle = 0.0, string color = "black");

    //зміна розміру вектора
    void resize(double factor);

    //обертання вектора на заданий кут
    void rotate(double deltaAngle);

    //виведення інформації про вектор
    void display() const;
};

#endif 
#pragma once
