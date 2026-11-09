#include <Novice.h>

#include "Commands/ICommand.h"
#include "Commands/MoveLeftCommand.h"
#include "Commands/MoveRightCommand.h"
#include "InputManager.h"
#include "MovableRectangle.h"

#include <memory>

const char kWindowTitle[] = "Command Pattern - Move Rectangle";

int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
    Novice::Initialize(kWindowTitle, 1280, 720);

    InputManager input;
    MovableRectangle rectangle;
    std::unique_ptr<ICommand> moveLeft = std::make_unique<MoveLeftCommand>(rectangle);
    std::unique_ptr<ICommand> moveRight = std::make_unique<MoveRightCommand>(rectangle);

    while (Novice::ProcessMessage() == 0) {
        Novice::BeginFrame();

        input.Update();
        if (input.IsPressed(DIK_LEFT)) {
            moveLeft->Execute();
        }
        if (input.IsPressed(DIK_RIGHT)) {
            moveRight->Execute();
        }

        Novice::DrawBox(0, 0, 1280, 720, 0.0f, BLACK, kFillModeSolid);
        rectangle.Draw();

        Novice::EndFrame();

        if (input.IsTriggered(DIK_ESCAPE)) {
            break;
        }
    }

    Novice::Finalize();
    return 0;
}
