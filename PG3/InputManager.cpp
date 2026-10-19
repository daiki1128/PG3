#include "InputManager.h"

#include <Novice.h>

#include <cstring>

void InputManager::Update() {
    std::memcpy(previous_, current_, sizeof(current_));
    Novice::GetHitKeyStateAll(current_);
}

bool InputManager::IsPressed(int key) const {
    return current_[key] != 0;
}

bool InputManager::IsTriggered(int key) const {
    return previous_[key] == 0 && current_[key] != 0;
}
