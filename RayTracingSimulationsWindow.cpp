#include "RayTracingSimulationWindow.h"

RayTracingSimulationWindow::RayTracingSimulationWindow(int x, int y, int width, int height, const std::string& title) : AnimationWindow(x, y, width, height, title) {}

void RayTracingSimulationWindow::addCircle(const TDT4102::Point& origin, double radius){
    circles.emplace_back(origin, radius);
}

void RayTracingSimulationWindow::addLineSegment(const TDT4102::Point& start, TDT4102::Point& end){
    lineSegments.emplace_back(start,end);
}

TDT4102::Point RayTracingSimulationWindow::traceRay(TDT4102::Point rayStart, double angle){
    TDT4102::Point currentPoint = rayStart;
    

    double stepSize = 10.0;
    double dx = stepSize*cos(angle);
    double dy = stepSize*sin(angle);

    int maxIter = 10000;
    int iter = 0;

    //Using a thickness for a treshold for the lines. This is needed because the step size can "jump" over the line an not calculating collison.
    const double lineThickness = 7.0;

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

        for(const LineSegment& lineSegment : lineSegments){

        //ax+bx+c=0

        double a = lineSegment.end.y -lineSegment.start.y;
        double b = lineSegment.start.x -lineSegment.end.x;
        double c = lineSegment.end.x *lineSegment.start.y -lineSegment.start.x * lineSegment.end.y;

        double length = sqrt(a*a + b*b);
        double distance = fabs(a* currentPoint.x + b* currentPoint.y +c) / length;

        double kx = lineSegment.end.x - lineSegment.start.x;
        double ky = lineSegment.end.y - lineSegment.start.y;
        
        double lengthSquared = kx*kx + ky*ky;
        double t = ((currentPoint.x -lineSegment.start.x) *kx + (currentPoint.y -lineSegment.start.y) *ky ) /lengthSquared;

        if(t>= 0 && t <= 1 && distance < lineThickness){
            return currentPoint;
        }

        }

        currentPoint.x = static_cast<int>(currentPoint.x+dx);
        currentPoint.y = static_cast<int>(currentPoint.y+dy);
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