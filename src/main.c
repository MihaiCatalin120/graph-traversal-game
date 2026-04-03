#include "raylib.h"

#include "camera.h"
#include "config.h"
#include "node.h"
#include "player.h"

#include <stdio.h>

int main() {
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, GAME_TITLE);
  InitAudioDevice();
  const char *appPath = GetApplicationDirectory();

  Player player = {0};
  player.position = (Vector2){WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f};

  Camera2D camera = {0};
  InitCamera(&camera, player.position);

  Node currentNode = nodes[0];

  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    float delta = GetFrameTime();
    UpdatePlayer(&player, &currentNode, &camera, delta);
    BeginDrawing();

    ClearBackground(WHITE);
    BeginMode2D(camera);

    for (size_t i = 0; i < MAX_NODES; i++) {
      DrawCircleV(nodes[i].position, CIRCLE_RADIUS + 2, BLACK);
      DrawCircleV(nodes[i].position, CIRCLE_RADIUS, WHITE);
    }

    DrawCircleV(player.position, CIRCLE_RADIUS / 2.0f, BLUE);

    EndMode2D();

    EndDrawing();
  }
  return 0;
}
