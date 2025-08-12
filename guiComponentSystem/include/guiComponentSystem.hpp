#ifndef GUICOMPONENTSYSTEM_HPP
#define GUICOMPONENTSYSTEM_HPP

#include <iostream>
#include <memory>
#include <vector>

class UIComponent {
public:
    virtual ~UIComponent() = default;

    virtual void draw(std::ostream&) const = 0;
    virtual void onClick(int x, int y) = 0;
protected:
    int m_x;
    int m_y;
    int m_w;
    int m_h;
};

class Button : public UIComponent {
public:
    void draw(std::ostream&) const override;
    void onClick(int x, int y) override;
};

class Checkbox : public UIComponent {
public:
    void draw(std::ostream&) const override;
    void onClick(int x, int y) override;
};

class TextField : public UIComponent {
public:
    void draw(std::ostream&) const override;
    void onClick(int x, int y) override;
};

class UIScreen {
public:
    void add(std::unique_ptr<UIComponent>);
    void layout();
    void renderAll();
    void dispatchClick(int x, int y);
private:
    std::vector<std::unique_ptr<UIComponent>> m_components;
};


#endif /* GUICOMPONENTSYSTEM_HPP */