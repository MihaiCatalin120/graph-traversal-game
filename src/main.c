#include "raylib.h"

#include "camera.h"
#include "config.h"
#include "font.h"
#include "node.h"
#include "player.h"
#include "ui.h"

#include <math.h>
#include <stdio.h>
#include <string.h>

int main() {
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, GAME_TITLE);
  InitAudioDevice();
  const char *appPath = GetApplicationDirectory();

  Image mainLogo =
      LoadImage(TextFormat("%s%s", appPath, "../assets/icons/gtg-logo.png"));
  SetWindowIcon(mainLogo);

  InitFont(appPath);

  Player player = {0};
  InitPlayer(&player);

  Player gameTitlePlayer = {0};
  InitPlayer(&gameTitlePlayer);

  Camera2D camera = {0};
  InitCamera(&camera, player.position);

  LoadNodes(nodes);

  int currentNodeIndex = 2;
  Node currentNode = nodes[currentNodeIndex];

  int gameTitleCurrentNodeIndex = 5;
  Node gameTitleCurrentNode = nodes[gameTitleCurrentNodeIndex];
  gameTitlePlayer.position = gameTitleCurrentNode.position;

  bool shouldExit = false;
  float gameTitleCounter = 0.0f;

  SetTargetFPS(60);
  while (!WindowShouldClose() && !shouldExit) {
    float delta = GetFrameTime();
    gameTitleCounter += delta;
    UpdatePlayer(&player, &currentNode, &currentNodeIndex, &camera, delta);
    UpdateGameTitle(&gameTitlePlayer, &gameTitleCurrentNode,
                    &gameTitleCurrentNodeIndex, delta, &gameTitleCounter);
    CheckCurrentNodeAction(&currentNode, &shouldExit);
    BeginDrawing();

    ClearBackground(WHITE);
    BeginMode2D(camera);

    for (size_t i = 0; i < nodesLength; i++) {
      DrawNode(nodes[i], player);
      DrawDirectionArrows(nodes[i]);
      if (!player.isMoving)
        DrawNodeHint(i, currentNode);
    }

    DrawCircleV(player.position,
                PLAYER_RADIUS * powf((2.0f * player.moveAnimationTimer -
                                      PLAYER_MOVE_ANIMATION_DURATION) /
                                         PLAYER_MOVE_ANIMATION_DURATION,
                                     2),
                BLUE);

    DrawCircleV(gameTitlePlayer.position,
                CIRCLE_RADIUS *
                    powf((2.0f * gameTitlePlayer.moveAnimationTimer -
                          PLAYER_MOVE_ANIMATION_DURATION) /
                             PLAYER_MOVE_ANIMATION_DURATION,
                         2),
                BLACK);

    // TODO: Double for could be avoided
    for (size_t i = 0; i < nodesLength; i++) {
      int fontSize = 24;
      Vector2 fontSpace = MeasureTextEx(font, nodes[i].innerText, fontSize, 0);

      if (strcmp(nodes[i].innerText, "Graph") == 0 ||
          strcmp(nodes[i].innerText, "Traversal") == 0 ||
          strcmp(nodes[i].innerText, "Game") == 0) {
        DrawTextEx(font, nodes[i].innerText,
                   (Vector2){nodes[i].position.x - fontSpace.x / 2.0f,
                             nodes[i].position.y - fontSpace.y / 2.0f},
                   fontSize, 0, WHITE);
      }
    }

    EndMode2D();

    EndDrawing();
  }

  CloseAudioDevice();
  UnloadImage(mainLogo);
  UnloadFont(font);
  CloseWindow();
  return 0;
}
