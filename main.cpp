
#include "std_lib_facilities.h"
#include "RayTracingSimulationWindow.h"

int main() {
    

    RayTracingSimulationWindow window;
    window.setBackgroundColor(TDT4102::Color::black);

    //light
    int radius = 5;
    TDT4102::Color circleColor = TDT4102::Color::white;
    int numRays =1000;


    TDT4102::Point origin1;
    origin1.x = 500;
    origin1.y = 500;
    window.addCircle(origin1, 100);

    TDT4102::Point origin2;
    origin2.x = 1000;
    origin2.y = 500;
    window.addCircle(origin2, 100);
 

    while(!window.should_close()) {
        TDT4102::Point mouseCoordinates = window.get_mouse_coordinates();

        
        window.draw_circle(mouseCoordinates,radius,circleColor);
        window.draw_circle(origin1,100,circleColor);
        window.draw_circle(origin2,100,circleColor);

        window.fillRays(mouseCoordinates,circleColor,numRays);
        

        

        window.next_frame();
    }

    return 0;
}