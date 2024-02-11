#include "application.h"

namespace dsv {

Application::Application() : controller{ui, model}{
}

int Application::run() {
    return ui.run();
}

Application::~Application() = default;

}// namespace dsv
