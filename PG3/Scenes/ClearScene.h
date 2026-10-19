#pragma once

#include "../IScene.h"

class ClearScene : public IScene {
public:
    SceneType Update(const InputManager& input) override;
    void Draw() const override;
};
