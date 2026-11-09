#pragma once

#include "ICommand.h"

class MovableRectangle;

class MoveRightCommand : public ICommand {
public:
    explicit MoveRightCommand(MovableRectangle& rectangle);
    void Execute() override;

private:
    MovableRectangle& rectangle_;
};
