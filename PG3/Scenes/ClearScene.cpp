#include "ClearScene.h"

#include "../InputManager.h"

#include <Novice.h>

SceneType ClearScene::Update(const InputManager& input) {
    return input.IsTriggered(DIK_RETURN) ? SceneType::Title : SceneType::Clear;
}

void ClearScene::Draw() const {
    Novice::ScreenPrintf(570, 300, "CLEAR!");
    Novice::ScreenPrintf(490, 350, "Press ENTER to return to title");
}
