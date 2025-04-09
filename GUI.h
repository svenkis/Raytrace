#pragma once

#include "AnimationWindow.h"
#include "widgets/DropdownList.h"
#include "widgets/Slider.h"
#include "RayTracingSimulationWindow.h"
#include <vector>
#include <string>
#include <functional>


class GUI {
public:
    GUI(RayTracingSimulationWindow& simulationWindow);

    void colorChanged();

    void radiusChanged();

    int getRadius() const { return radiusSlider->getValue(); }

private:
    RayTracingSimulationWindow& simWindow;

    std::vector<std::string> colorOptions;
    TDT4102::DropdownList colorDropdown;

    TDT4102::Slider* radiusSlider;
};