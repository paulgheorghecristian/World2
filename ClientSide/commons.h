#ifndef COMMONS_H
#define COMMONS_H

#include "box.h"
#include "sphere.h"
#include "pickable_object.h"
#include "puzzle_object.h"
#include "player.h"

class Player;
class PickableObject;
class Box;
class Sphere;

enum Type{
    BOX,
    SPHERE,
    PICKABLE_OBJECT,
    PUZZLE_OBJECT,
    PLAYER,
    GROUND
};

union PtrType{
    Box *box;
    Sphere *sphere;
    PickableObject *pickableObject;
    PuzzleObject *puzzleObject;
    Player *player;
};

struct UserPointer{
    Type type;
    PtrType ptrType;
};


#endif // COMMONS_H