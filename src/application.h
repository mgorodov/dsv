#pragma once

#include <controller/controller.h>
#include <model/model.h>
#include <ui/ui.h>
#include <view/view.h>

namespace dsv {

class Application {
public:
    Application();
    int run();
    ~Application();

private:
    UI::UI ui;
    Model model;
    Controller controller;
    View view;
};

}// namespace dsv
