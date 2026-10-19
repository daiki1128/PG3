#include "TitleScene.h"

#include "../InputManager.h"

#include <Novice.h>

SceneType TitleScene::Update(const InputManager& input) {
    return input.IsTriggered(DIK_RETURN) ? SceneType::Stage : SceneType::Title;
}

void TitleScene::Draw() const {
    Novice::ScreenPrintf(570, 300, "TITLE");
    Novice::ScreenPrintf(500, 350, "Press ENTER to start");
}
