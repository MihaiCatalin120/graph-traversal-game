#include "ui.h"
#include "font.h"
#include "raylib.h"
#include "raymath.h"
#include "utils.h"

void DrawNode(Node node, Player player) {
  DrawCircleV(node.position, CIRCLE_RADIUS + CIRCLE_BORDER, BLACK);
  DrawCircleV(node.position, CIRCLE_RADIUS, WHITE);
  int fontSize = 32;
  Vector2 fontSpace = MeasureTextEx(font, node.innerText, fontSize, 0);

  if (!Vector2Equals(node.position, player.position)) {
    DrawTextEx(font, node.innerText,
               (Vector2){node.position.x - fontSpace.x / 2.0f,
                         node.position.y - fontSpace.y / 2.0f},
               32, 0, BLACK);
  }
}

void DrawDirectionArrows(struct Node node) {
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
