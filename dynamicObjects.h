#pragma once
#include "std_lib_facilities.h"
#include "AnimationWindow.h"

struct Circle{
public:
    TDT4102::Point origin;
    double radius;

    Circle(const TDT4102::Point& origin, double radius) : origin(origin), radius(radius){}
};

struct LineSegment {
    TDT4102::Point start;
    TDT4102::Point end;

    LineSegment(const TDT4102::Point& start, const TDT4102::Point& end) : start(start), end(end){}
};
