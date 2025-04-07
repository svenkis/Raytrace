
#include "std_lib_facilities.h"
#include "RayTracingSimulationWindow.h"

int main() {
    

    RayTracingSimulationWindow window;
    window.setBackgroundColor(TDT4102::Color::black);

    //circle
    int radius = 25;
    TDT4102::Color circleColor = TDT4102::Color::white;

    while(!window.should_close()) {
        TDT4102::Point mouseCoordinates = window.get_mouse_coordinates();

        if (window.is_left_mouse_button_down() != false){
        window.draw_circle(mouseCoordinates,radius,circleColor);
        }

        

        window.next_frame();
    }

    return 0;
}