#include <Novice.h>

#include "Game.h"
#include "InputManager.h"

const char kWindowTitle[] = "PG3 Shooting";

int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
    Novice::Initialize(kWindowTitle, 1280, 720);

    InputManager input;
    Game game;

    while (Novice::ProcessMessage() == 0) {
        Novice::BeginFrame();

        input.Update();
        game.Update(input);
        game.Draw();

        Novice::EndFrame();

        if (input.IsTriggered(DIK_ESCAPE)) {
            break;
        }
    }

    Novice::Finalize();
    return 0;
}
