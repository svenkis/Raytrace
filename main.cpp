
#include "std_lib_facilities.h"
#include "RayTracingSimulationWindow.h"
#include "GUI.h"


int main() {
    

    RayTracingSimulationWindow window;
    window.setBackgroundColor(TDT4102::Color::black);

    //GUI

    GUI gui(window);

    //light
    int radius = 5;
    TDT4102::Color circleColor = TDT4102::Color::white;
    


    //objects on screen
    TDT4102::Point origin1;
    origin1.x = 500;
    origin1.y = 500;
    window.addCircle(origin1, 100);

    TDT4102::Point origin2;
    origin2.x = 1000;
    origin2.y = 500; 
    window.addCircle(origin2, 100);

    TDT4102::Point start1 = {600,700};
    TDT4102::Point end1 = {900,700};
    window.addLineSegment(start1,end1);

    TDT4102::Point start2 = {900,700};
    TDT4102::Point end2 = {1000,500};
    window.addLineSegment(start2,end2);

    TDT4102::Point start3 = {600,700};
    TDT4102::Point end3 = {500,500};
    window.addLineSegment(start3,end3);

    while(!window.should_close()) {
        TDT4102::Point mouseCoordinates = window.get_mouse_coordinates();
        int numRays = gui.getRadius();

        window.fillRays(mouseCoordinates,window.rayColor,numRays);
        
        window.draw_circle(mouseCoordinates,radius,circleColor);
        window.draw_circle(origin1,100,circleColor);
        window.draw_circle(origin2,100,circleColor);
        
        window.draw_line(start1,end1, circleColor);
        window.draw_line(start2,end2, circleColor);
        window.draw_line(start3,end3, circleColor);
        

        window.next_frame();
    }

    return 0;
}