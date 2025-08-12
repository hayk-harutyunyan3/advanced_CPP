#include "../include/guiComponentSystem.hpp"

/* Button methods */

void Button::draw(std::ostream& os) const {
    os << "[Button [" << m_x <<  "]" << "[" << m_y << "]]" << std::endl;
}

void Button::onClick(int x, int y) {
    std::cout << "Button at (" << x << ", " << y << ")" << std::endl;
}

/* Checkbox methods */

void Checkbox::draw(std::ostream& os) const {
    os << "[Checkbox [" << m_x <<  "]" << "[" << m_y << "]]" << std::endl;
}

void Checkbox::onClick(int x, int y) {
    std::cout << "Checkbox at (" << x << ", " << y << ")" << std::endl;
}

/* TextField methods */

void TextField::draw(std::ostream& os) const {
    os << "[TestField [" << m_x <<  "]" << "[" << m_y << "]]" << std::endl;
}

void TextField::onClick(int x, int y) {
    std::cout << "TextField at (" << x << ", " << y << ")" << std::endl;
}

/* UIScreen methods */

void UIScreen::add(std::unique_ptr<UIComponent> comp) {
    m_components.push_back(std::move(comp));
}

void UIScreen::layout() {
    std::cout << "Layout arranged for " << m_components.size() << " components.\n";
}

void UIScreen::renderAll() {
    for (const auto& comp : m_components) {
        comp->draw(std::cout);
    }
}

void UIScreen::dispatchClick(int x, int y) {
    for (auto& comp : m_components) {
        comp->onClick(x, y);
    }
}
