#include "node.h"
#include "raylib.h"

#ifndef PLAYER_H
#define PLAYER_H

typedef struct Player {
  Vector2 position;
} Player;

void UpdatePlayer(Player *player, Node *currentNode, Camera2D *camera,
                  float delta);

#endif
