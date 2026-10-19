#include "StageScene.h"

#include "../InputManager.h"

#include <Novice.h>

#include <algorithm>

namespace {
constexpr int kWindowWidth = 1280;
}

SceneType StageScene::Update(const InputManager& input) {
    if (input.IsPressed(DIK_LEFT)) {
        playerX_ -= 8;
    }
    if (input.IsPressed(DIK_RIGHT)) {
        playerX_ += 8;
    }
    playerX_ = std::clamp(playerX_, 0, kWindowWidth - kPlayerWidth);

    if (input.IsTriggered(DIK_SPACE) && !bulletActive_) {
        bulletX_ = playerX_ + kPlayerWidth / 2 - kBulletWidth / 2;
        bulletY_ = kPlayerY - kBulletHeight;
        bulletActive_ = true;
    }

    if (bulletActive_) {
        bulletY_ -= 12;

        if (bulletX_ < kEnemyX + kEnemyWidth &&
            bulletX_ + kBulletWidth > kEnemyX &&
            bulletY_ < kEnemyY + kEnemyHeight &&
            bulletY_ + kBulletHeight > kEnemyY) {
            return SceneType::Clear;
        }

        if (bulletY_ + kBulletHeight < 0) {
            bulletActive_ = false;
        }
    }

    return SceneType::Stage;
}

void StageScene::Draw() const {
    Novice::ScreenPrintf(20, 20, "STAGE");
    Novice::ScreenPrintf(20, 50, "LEFT/RIGHT: Move   SPACE: Shoot");

    Novice::DrawBox(kEnemyX, kEnemyY, kEnemyWidth, kEnemyHeight,
                    0.0f, RED, kFillModeSolid);
    Novice::DrawBox(playerX_, kPlayerY, kPlayerWidth, kPlayerHeight,
                    0.0f, BLUE, kFillModeSolid);

    if (bulletActive_) {
        Novice::DrawBox(bulletX_, bulletY_, kBulletWidth, kBulletHeight,
                        0.0f, WHITE, kFillModeSolid);
    }
}
