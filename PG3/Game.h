#pragma once

#include "IScene.h"

#include <memory>

class Game {
public:
    Game();
    void Update(const InputManager& input);
    void Draw() const;

private:
    void ChangeScene(SceneType next);

    SceneType current_ = SceneType::Title;
    std::unique_ptr<IScene> scene_;
};
