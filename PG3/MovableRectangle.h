#pragma once

class MovableRectangle {
public:
    static constexpr int kY = 320;
    static constexpr int kWidth = 80;
    static constexpr int kHeight = 80;

    void MoveBy(int distance);
    void Draw() const;

private:
    int x_ = 600;
};
