#include "controller.h"
#include <iostream>
#include <ui/primitives/button.h>

namespace dsv {

Controller::Controller(UI::UI& ui, Model& model) : ui_{ui}, model_{model} {
    UI::Primitives::Button left{{"left", {100, 200}}};
    UI::Primitives::Button mid{{"mid", {250, 200}}};
    UI::Primitives::Button right{{"right", {400, 200}}};
    left.onClick = [](auto this_) {
        std::cout << "1" << std::endl;
    };
    mid.onClick = [](auto) {
        std::cout << "2" << std::endl;
    };
    right.onClick = [](auto) {
        std::cout << "3" << std::endl;
    };
    ui.addPrimitive(std::make_shared<UI::Primitives::Button>(left));
    ui.addPrimitive(std::make_shared<UI::Primitives::Button>(mid));
    ui.addPrimitive(std::make_shared<UI::Primitives::Button>(right));
}

}// namespace dsv
