#include "player.h"
#include "camera.h"
#include "node.h"
#include "raylib.h"

void UpdatePlayer(Player *player, Node *currentNode, Camera2D *camera,
                  float delta) {
  int stepIndex = -1;

  if (IsKeyPressed(KEY_ZERO))
    stepIndex = 0;
  if (IsKeyPressed(KEY_ONE))
    stepIndex = 1;
  if (IsKeyPressed(KEY_TWO))
    stepIndex = 2;

  if (stepIndex >= 0 || stepIndex < currentNode->optionsLength) {
    *currentNode = nodes[currentNode->options[stepIndex]];
    player->position = currentNode->position;
  }

  UpdateCameraPosition(camera, player->position, delta);
}
