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

    // ���������� �����
    virtual void move(double dx, double dy);

    // ���� ������� �����
    virtual void changeColor(const string& newColor);

    // ��������� ���������� ��� �����
    virtual void display() const;
};


class Vector : public Point {
protected:
    double length;
    double angle; 

public:
    Vector(double x = 0.0, double y = 0.0, double length = 1.0, double angle = 0.0, string color = "black");

    //���� ������ �������
    void resize(double factor);

    //��������� ������� �� ������� ���
    void rotate(double deltaAngle);

    //��������� ���������� ��� ������
    void display() const;
};

#endif 
#pragma once
