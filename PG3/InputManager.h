#pragma once

class InputManager {
public:
    void Update();
    bool IsPressed(int key) const;
    bool IsTriggered(int key) const;

private:
    char current_[256] = {};
    char previous_[256] = {};
};
