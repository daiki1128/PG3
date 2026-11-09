#include "MoveLeftCommand.h"

#include "../MovableRectangle.h"

MoveLeftCommand::MoveLeftCommand(MovableRectangle& rectangle) : rectangle_(rectangle) {}

void MoveLeftCommand::Execute() {
    rectangle_.MoveBy(-8);
}
