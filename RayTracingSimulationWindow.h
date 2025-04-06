#pragma once
#include "std_lib_facilities.h"
#include "AnimationWindow.h"

class RayTracingSimulationWindow : public AnimationWindow {
    private:
    TDT4102::Point rayStart;
    TDT4102::Point rayEnd;
    TDT4102::Color rayColor;

    double angle;
        
    public:
    RayTracingSimulationWindow(int x = 50, int y = 50, int width = 1600, int height = 900, const std::string& title = "RayTracing Simulation Window");

    bool collisionCircle(TDT4102::Point rayPoint, TDT4102::Point circleOrigin, double circleRadius);

    bool collisionEdgeOfWindow(TDT4102::Point rayPoint, RayTracingSimulationWindow window);

    void drawRay(TDT4102::Point rayStart, TDT4102::Point rayEnd, double angle, TDT4102::Color rayColor);

    TDT4102::Point calculateRayEndPoint(TDT4102::Point rayStart, double angle);

    
    };