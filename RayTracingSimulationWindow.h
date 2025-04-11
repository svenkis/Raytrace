#pragma once
#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "dynamicObjects.h"


class RayTracingSimulationWindow : public AnimationWindow {
    private:
    std::vector<Circle> circles;
    std::vector<LineSegment> lineSegments;
       
    public:

    TDT4102::Color rayColor;

    RayTracingSimulationWindow(int x = 50, int y = 50, int width = 1000, int height = 1000, const std::string& title = "RayTracing Simulation Window");

    void addCircle(const TDT4102::Point& origin, double radius);

    void addLineSegment(const TDT4102::Point& start, TDT4102::Point& end);

    TDT4102::Point traceRay( TDT4102::Point rayStart, double angle);

    void drawRay(TDT4102::Point rayStart, double angle, TDT4102::Color rayColor);

    void fillRays(TDT4102::Point rayStart, TDT4102::Color rayColor, int numRays);

    };