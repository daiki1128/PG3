#include "MovableRectangle.h"

#include <Novice.h>

#include <algorithm>

namespace {
constexpr int kWindowWidth = 1280;
}

void MovableRectangle::MoveBy(int distance) {
    x_ = std::clamp(x_ + distance, 0, kWindowWidth - kWidth);
}

void MovableRectangle::Draw() const {
    Novice::DrawBox(x_, kY, kWidth, kHeight, 0.0f, WHITE, kFillModeSolid);
}
