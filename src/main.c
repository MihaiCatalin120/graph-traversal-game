#include "raylib.h"

#include "camera.h"
#include "config.h"
#include "node.h"
#include "player.h"
#include "ui.h"

#include <math.h>
#include <stdio.h>

int main() {
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, GAME_TITLE);
  InitAudioDevice();
  const char *appPath = GetApplicationDirectory();

  Image mainLogo =
      LoadImage(TextFormat("%s%s", appPath, "assets/icons/logo.png"));
  SetWindowIcon(mainLogo);

  Player player = {0};
  InitPlayer(&player);

  Camera2D camera = {0};
  InitCamera(&camera, player.position);

  LoadNodes(nodes);

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
      DrawDirectionArrows(nodes[i]);
      DrawNodeHint(i, currentNode);
    }

    DrawCircleV(player.position,
                PLAYER_RADIUS * powf((2.0f * player.moveAnimationTimer -
                                      PLAYER_MOVE_ANIMATION_DURATION) /
                                         PLAYER_MOVE_ANIMATION_DURATION,
                                     2),
                BLUE);

    EndMode2D();

    EndDrawing();
  }

  CloseAudioDevice();
  UnloadImage(mainLogo);
  CloseWindow();
  return 0;
}
