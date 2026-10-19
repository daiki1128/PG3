#include "Game.h"

#include "Scenes/ClearScene.h"
#include "Scenes/StageScene.h"
#include "Scenes/TitleScene.h"

Game::Game() : scene_(std::make_unique<TitleScene>()) {}

void Game::Update(const InputManager& input) {
    const SceneType next = scene_->Update(input);
    if (next != current_) {
        ChangeScene(next);
    }
}

void Game::Draw() const {
    scene_->Draw();
}

void Game::ChangeScene(SceneType next) {
    current_ = next;
    switch (current_) {
    case SceneType::Title:
        scene_ = std::make_unique<TitleScene>();
        break;
    case SceneType::Stage:
        scene_ = std::make_unique<StageScene>();
        break;
    case SceneType::Clear:
        scene_ = std::make_unique<ClearScene>();
        break;
    }
}
