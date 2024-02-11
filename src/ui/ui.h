#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <ui/primitives/base.h>

namespace dsv::UI {

class UI {
public:
    UI();
    void addPrimitive(const std::shared_ptr<Primitives::Base>& primitive) {
        primitives_.push_back(primitive);
    }
    int run();
    ~UI();

private:
    std::vector<std::shared_ptr<Primitives::Base>> primitives_;
};

}// namespace dsv::UI
