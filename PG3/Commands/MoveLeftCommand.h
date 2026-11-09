#pragma once

#include "ICommand.h"

class MovableRectangle;

class MoveLeftCommand : public ICommand {
public:
    explicit MoveLeftCommand(MovableRectangle& rectangle);
    void Execute() override;

private:
    MovableRectangle& rectangle_;
};
