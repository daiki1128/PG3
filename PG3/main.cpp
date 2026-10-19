#include <iostream>

class IShape {
public:
    virtual void Size() = 0;
    virtual void Draw() = 0;
    virtual ~IShape() = default;
};

class Circle : public IShape {
private:
    double radius;
    double area = 0;

public:
    Circle(double r) : radius(r) {}

    void Size() override {
        area = 3.141592653589793 * radius * radius;
    }

    void Draw() override {
        std::cout << "Circle area: " << area << '\n';
    }
};

class Rectangle : public IShape {
private:
    double width;
    double height;
    double area = 0;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    void Size() override {
        area = width * height;
    }

    void Draw() override {
        std::cout << "Rectangle area: " << area << '\n';
    }
};

int main() {
    Circle circle(3.0);
    Rectangle rectangle(4.0, 5.0);

    IShape* shapes[] = { &circle, &rectangle };

    for (IShape* shape : shapes) {
        shape->Size();
        shape->Draw();
    }

    return 0;
}