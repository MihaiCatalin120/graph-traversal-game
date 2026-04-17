#include "player.h"
#include "camera.h"
#include "config.h"
#include "node.h"
#include "raylib.h"

#include <math.h>

void InitPlayer(Player *player) {
  player->position = (Vector2){WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f};
  player->isMoving = false;
  player->moveAnimationTimer = 0.0f;
  player->nextPosition = NULL;
}

void UpdatePlayerPosition(Player *player, float delta) {
  if (player->isMoving)
    player->moveAnimationTimer += delta;

  if (player->moveAnimationTimer > PLAYER_MOVE_ANIMATION_DURATION) {
    player->moveAnimationTimer = 0.0f;
    player->isMoving = false;
  } else if (player->moveAnimationTimer >
                 PLAYER_MOVE_ANIMATION_DURATION / 2.0f &&
             player->isMoving && player->nextPosition != NULL) {
    player->position = *player->nextPosition;
    player->nextPosition = NULL;
  }
}

void StartPlayerMove(Player *player, Node *currentNode) {
  player->moveAnimationTimer = 0.0f;
  player->nextPosition = &currentNode->position;
  player->isMoving = true;
}

void UpdatePlayer(Player *player, Node *currentNode, int *currentNodeIndex,
                  float delta) {
  int stepIndex = -1;

  if (IsKeyPressed(KEY_ZERO))
    stepIndex = 0;
  if (IsKeyPressed(KEY_ONE))
    stepIndex = 1;
  if (IsKeyPressed(KEY_TWO))
    stepIndex = 2;

  if (stepIndex >= 0 && stepIndex < currentNode->optionsLength &&
      !player->isMoving) {
    ChangeNode(currentNode->options[stepIndex], currentNodeIndex, currentNode);

    StartPlayerMove(player, currentNode);
  }

  UpdatePlayerPosition(player, delta);
}

void UpdateGameTitle(Player *player, Node *currentNode, int *currentNodeIndex,
                     float delta, float *counter) {
  if (*counter > 3.0f) {
    *counter = fmod(*counter, 3.0f);
    ChangeNode(currentNode->options[0], currentNodeIndex, currentNode);
    StartPlayerMove(player, currentNode);
  }

  UpdatePlayerPosition(player, delta);
}
