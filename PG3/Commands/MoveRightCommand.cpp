#include "MoveRightCommand.h"

#include "../MovableRectangle.h"

MoveRightCommand::MoveRightCommand(MovableRectangle& rectangle) : rectangle_(rectangle) {}

void MoveRightCommand::Execute() {
    rectangle_.MoveBy(8);
}
