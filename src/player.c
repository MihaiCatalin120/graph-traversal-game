#include "player.h"
#include "node.h"
#include "raylib.h"

void UpdatePlayer(Player *player, Node *currentNode, Camera2D *camera) {
  int stepIndex = -1;

  if (IsKeyPressed(KEY_ZERO))
    stepIndex = 0;
  if (IsKeyPressed(KEY_ONE))
    stepIndex = 1;
  if (IsKeyPressed(KEY_TWO))
    stepIndex = 2;

  if (stepIndex < 0 || stepIndex >= currentNode->optionsLength)
    return;

  *currentNode = nodes[currentNode->options[stepIndex]];
  player->position = currentNode->position;
  camera->target = player->position;
}
