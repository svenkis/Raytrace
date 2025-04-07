#include "RayTracingSimulationWindow.h"

RayTracingSimulationWindow::RayTracingSimulationWindow(int x, int y, int width, int height, const std::string& title) : AnimationWindow(x, y, width, height, title) {}


//Checks whether the next calculated point will hit a circle
bool RayTracingSimulationWindow::collisionCircle(TDT4102::Point rayPoint, TDT4102::Point circleOrigin, double circleRadius){
    double distanceRayToOriginSquared = pow(rayPoint.x - circleOrigin.x,2) + pow(rayPoint.y - circleOrigin.y,2);
    double circleRadiusSquared = pow(circleRadius,2);

    if(distanceRayToOriginSquared <= circleRadiusSquared){
        return true;
    }

    return false;
}

//Checks whether the next calculated point will hit the window edges
bool collisionEdgeOfWindow(TDT4102::Point rayPoint, RayTracingSimulationWindow window){
    if(rayPoint.x < 0 || rayPoint.x > window.width()){
        return true;
    }

    if(rayPoint.y < 0 || rayPoint.y > window.height()){
        return true;
    }

    return false;
}

TDT4102::Point RayTracingSimulationWindow::calculateRayEndPoint(TDT4102::Point rayStart, double angle){
    TDT4102::Point currentPoint = rayStart;
    while(true){
        //collisionCircle()
    }
}


void RayTracingSimulationWindow::drawRay(TDT4102::Point rayStart, TDT4102::Point rayEnd, double angle, TDT4102::Color rayColor){
//bruker draw_line, men med beregnet end.

    //test

}

