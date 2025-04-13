#include "RayTracingSimulationWindow.h"

RayTracingSimulationWindow::RayTracingSimulationWindow(int x, int y, int width, int height, const std::string& title) : AnimationWindow(x, y, width, height, title) {}

void RayTracingSimulationWindow::addCircle(const TDT4102::Point& origin, double radius){
    circles.emplace_back(origin, radius);
}

void RayTracingSimulationWindow::addLineSegment(const TDT4102::Point& start, TDT4102::Point& end){
    lineSegments.emplace_back(start,end);
}

TDT4102::Point RayTracingSimulationWindow::traceRay(TDT4102::Point rayStart, double angle){
    double x = rayStart.x;
    double y = rayStart.y;
    

    double stepSize = 10.0;
    double dx = stepSize*cos(angle);
    double dy = stepSize*sin(angle);

    int maxIter = 10000;
    int iter = 0;

    //Using a thickness for a treshold for the lines. This is needed because the step size can "jump" over the line an not calculating collison.
    const double lineThickness = 7.0;

    while(iter<maxIter){
        for(const Circle& circle : circles){
            double dX = x - circle.origin.x;
            double dY = y - circle.origin.y;
            double distanceSquared = dX*dX + dY*dY;

            if(distanceSquared <= circle.radius*circle.radius){
                return TDT4102::Point{static_cast<int>(x), static_cast<int>(y)};
            }
        }

        if(x <0 || x > width() || y <0 || y > height()){
            break;
        }

        for(const LineSegment& lineSegment : lineSegments){

        //ax+bx+c=0

        double a = lineSegment.end.y -lineSegment.start.y;
        double b = lineSegment.start.x -lineSegment.end.x;
        double c = lineSegment.end.x *lineSegment.start.y -lineSegment.start.x * lineSegment.end.y;

        double length = sqrt(a*a + b*b);
        double distance = fabs(a* x + b* y +c) / length;

        double kx = lineSegment.end.x - lineSegment.start.x;
        double ky = lineSegment.end.y - lineSegment.start.y;
        
        double lengthSquared = kx*kx + ky*ky;
        double t = ((x -lineSegment.start.x) *kx + (y -lineSegment.start.y) *ky ) /lengthSquared;

        if(t>= 0 && t <= 1 && distance < lineThickness){
            return TDT4102::Point{static_cast<int>(x), static_cast<int>(y)};
        }

        }


        x += dx;
        y += dy;
        iter++;
    } 

    return TDT4102::Point{static_cast<int>(x), static_cast<int>(y)};

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