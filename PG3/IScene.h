#pragma once

class InputManager;

enum class SceneType {
    Title,
    Stage,
    Clear
};

class IScene {
public:
    virtual ~IScene() = default;
    virtual SceneType Update(const InputManager& input) = 0;
    virtual void Draw() const = 0;
};
