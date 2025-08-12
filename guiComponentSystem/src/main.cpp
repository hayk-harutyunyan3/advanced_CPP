#include "../include/guiComponentSystem.hpp"
#include <iostream>

int main() {
    UIScreen screen;

    screen.add(std::make_unique<Button>());
    screen.add(std::make_unique<Checkbox>());
    screen.add(std::make_unique<TextField>());

    screen.layout();
    screen.renderAll();
    screen.dispatchClick(10, 20);

    return 0;
}  