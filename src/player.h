#include "node.h"
#include "raylib.h"

#ifndef PLAYER_H
#define PLAYER_H

typedef struct Player {
  Vector2 position;
  float moveAnimationTimer;
  float isMoving;
  Vector2 *nextPosition;
} Player;

void InitPlayer(Player *player);
void StartPlayerMove(Player *player, Node *currentNode);
void UpdatePlayerPosition(Player *player, float delta);
void UpdatePlayer(Player *player, Node *currentNode, int *currentNodeIndex,
                  Camera2D *camera, float delta);

#endif
