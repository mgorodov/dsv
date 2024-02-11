#pragma once
#include <model/model.h>
#include <ui/ui.h>

namespace dsv {

class Controller {
public:
    Controller(UI::UI& ui, Model& model);

private:
    UI::UI& ui_;
    Model& model_;
};

}// namespace dsv
