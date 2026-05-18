#include "ui.h"
#include "config.h"
#include "font.h"
#include "raylib.h"
#include "raymath.h"
#include "utils.h"

#include <string.h>

void DrawNode(Node node, Player player) {
  DrawCircleV(node.position, CIRCLE_RADIUS + CIRCLE_BORDER, BLACK);
  DrawCircleV(node.position, CIRCLE_RADIUS, WHITE);
  int fontSize = 32;
  Vector2 fontSpace = MeasureTextEx(font, node.innerText, fontSize, 0);

  if (!Vector2Equals(node.position, player.position) &&
      strcmp(node.innerText, "Graph") != 0 &&
      strcmp(node.innerText, "Traversal") != 0 &&
      strcmp(node.innerText, "Game") != 0) {
    DrawTextEx(font, node.innerText,
               (Vector2){node.position.x - fontSpace.x / 2.0f,
                         node.position.y - fontSpace.y / 2.0f},
               32, 0, BLACK);
  }
}

void DrawDirectionArrows(struct Node node) {
  // WARN: Until this is implemented it will throw a warning
  // TODO: Implement
}

void DrawNodeHint(int nodeIndex, struct Node currentNode) {
  int optionIndex = GetElementIndex(nodeIndex, currentNode.options,
                                    currentNode.optionsLength);
  if (optionIndex >= 0) {
    DrawTextEx(
        font, TextFormat("%d", optionIndex),
        (Vector2){
            nodes[nodeIndex].position.x - CIRCLE_RADIUS - MOVE_HINT_SPACING,
            nodes[nodeIndex].position.y - CIRCLE_RADIUS - MOVE_HINT_SPACING},
        32, 0, BLACK);
  }
}

void DrawNodeID(int nodeIndex) {
  DrawTextEx(font, TextFormat("%d", nodeIndex),
             (Vector2){nodes[nodeIndex].position.x,
                       nodes[nodeIndex].position.y + CIRCLE_RADIUS +
                           MOVE_HINT_SPACING},
             32, 0, BLACK);
}

void DrawCurrentLevelTitle() {
  Vector2 startNodePosition = nodes[3].position; // Last node in the main menu
  const char *title = "Welcome";
  switch (rini_get_value(config, "STARTING_LEVEL")) {
  case 1:
    title = "Fin";
    break;
  }

  DrawTextEx(
      font, title,
      (Vector2){startNodePosition.x, startNodePosition.y - 6 * CIRCLE_RADIUS},
      64, 0, BLACK);
}
