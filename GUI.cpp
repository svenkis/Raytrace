#include "GUI.h"
#include <iostream>

GUI::GUI(RayTracingSimulationWindow& simulationWindow)
    : simWindow(simulationWindow),
      colorOptions{"Black", "Green", "Blue", "Yellow", "Cyan", "Magenta"},
      colorDropdown(TDT4102::Point{50, 50}, 150, 30, colorOptions)
{
    simWindow.add(colorDropdown);
    colorDropdown.setCallback(std::bind(&GUI::colorChanged, this));
    int sliderMin = 5;
    int sliderMax = 100;
    radiusSlider = new TDT4102::Slider(TDT4102::Point{50, 100}, 200, 30, 5, 100, 25, 1);
    simWindow.add(*radiusSlider);
}


void GUI::colorChanged() {
    std::string selected = colorDropdown.getSelectedValue();

    if (selected == "Black") {
        simWindow.rayColor = TDT4102::Color::black;
    } else if (selected == "Green") {
        simWindow.rayColor = TDT4102::Color::green;
    } else if (selected == "Blue") {
        simWindow.rayColor = TDT4102::Color::blue;
    } else if (selected == "Yellow") {
        simWindow.rayColor = TDT4102::Color::yellow;
    } else if (selected == "Cyan") {
        simWindow.rayColor = TDT4102::Color::cyan;
    } else if (selected == "Magenta") {
        simWindow.rayColor = TDT4102::Color::magenta;
    }
}