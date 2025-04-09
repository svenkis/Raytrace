#include "RayTracingSimulationWindow.h"

RayTracingSimulationWindow::RayTracingSimulationWindow(int x, int y, int width, int height, const std::string& title) : AnimationWindow(x, y, width, height, title) {}

void RayTracingSimulationWindow::addCircle(const TDT4102::Point& origin, double radius){
    circles.emplace_back(origin, radius);
}

TDT4102::Point RayTracingSimulationWindow::traceRay(TDT4102::Point rayStart, double angle){
    TDT4102::Point currentPoint = rayStart;
    

    double stepSize = 25.0;
    double dx = stepSize*cos(angle);
    double dy = stepSize*sin(angle);

    int maxIter = 10000;
    int iter = 0;


    while(iter<maxIter){
        for(const Circle& circle : circles){
            double dX = currentPoint.x - circle.origin.x;
            double dY = currentPoint.y - circle.origin.y;
            double distanceSquared = dX*dX + dY*dY;

            if(distanceSquared <= circle.radius*circle.radius){
                return currentPoint;
            }
        }

        if(currentPoint.x <0 || currentPoint.x > width() || currentPoint.y <0 || currentPoint.y > height()){
            break;
        }

        currentPoint.x += dx;
        currentPoint.y += dy;
        iter++;
    } 

    return currentPoint;

}


void RayTracingSimulationWindow::drawRay(TDT4102::Point rayStart, double angle, TDT4102::Color rayColor) {
    TDT4102::Point rayEnd = traceRay(rayStart, angle); 
    draw_line(rayStart, rayEnd, rayColor);
}

void RayTracingSimulationWindow::fillRays(TDT4102::Point rayStart, TDT4102::Color rayColor, int numRays) {
    double angleStep = 2*M_PI/numRays;

    for (int i = 0; i < numRays; i++) {
        double angle = i * angleStep;

        drawRay(rayStart, angle, rayColor);
    }
}