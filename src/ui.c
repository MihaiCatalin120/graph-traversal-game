#include "ui.h"
#include "utils.h"

void DrawNode(Vector2 position) {
  DrawCircleV(position, CIRCLE_RADIUS + CIRCLE_BORDER, BLACK);
  DrawCircleV(position, CIRCLE_RADIUS, WHITE);
}
void DrawNodeHint(int nodeIndex, struct Node currentNode) {
  int optionIndex = GetElementIndex(nodeIndex, currentNode.options,
                                    currentNode.optionsLength);
  if (optionIndex >= 0) {
    DrawText(TextFormat("[%d]", optionIndex),
             nodes[nodeIndex].position.x - CIRCLE_RADIUS - MOVE_HINT_SPACING,
             nodes[nodeIndex].position.y - CIRCLE_RADIUS - MOVE_HINT_SPACING,
             16, BLACK);
  }
}
