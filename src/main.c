#include "raylib.h"

#include "camera.h"
#include "config.h"
#include "node.h"
#include "player.h"
#include "ui.h"

#include <stdio.h>

int main() {
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, GAME_TITLE);
  InitAudioDevice();
  const char *appPath = GetApplicationDirectory();

  Player player = {0};
  player.position = (Vector2){WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f};

  Camera2D camera = {0};
  InitCamera(&camera, player.position);

  int currentNodeIndex = 2;
  Node currentNode = nodes[currentNodeIndex];

  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    float delta = GetFrameTime();
    UpdatePlayer(&player, &currentNode, &currentNodeIndex, &camera, delta);
    BeginDrawing();

    ClearBackground(WHITE);
    BeginMode2D(camera);

    // TODO: Create animated game title

    for (size_t i = 0; i < MAX_NODES; i++) {
      DrawNode(nodes[i].position);
      DrawNodeHint(i, currentNode);
    }

    DrawCircleV(player.position, CIRCLE_RADIUS / 2.0f, BLUE);

    EndMode2D();

    EndDrawing();
  }
  return 0;
}
