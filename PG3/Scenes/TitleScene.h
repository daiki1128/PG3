#pragma once

#include "../IScene.h"

class TitleScene : public IScene {
public:
    SceneType Update(const InputManager& input) override;
    void Draw() const override;
};
