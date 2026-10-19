#pragma once

#include "../IScene.h"

class StageScene : public IScene {
public:
    SceneType Update(const InputManager& input) override;
    void Draw() const override;

private:
    static constexpr int kPlayerY = 620;
    static constexpr int kPlayerWidth = 40;
    static constexpr int kPlayerHeight = 40;

    static constexpr int kEnemyX = 610;
    static constexpr int kEnemyY = 120;
    static constexpr int kEnemyWidth = 60;
    static constexpr int kEnemyHeight = 60;

    static constexpr int kBulletWidth = 8;
    static constexpr int kBulletHeight = 16;

    int playerX_ = 620;
    int bulletX_ = 0;
    int bulletY_ = 0;
    bool bulletActive_ = false;
};
