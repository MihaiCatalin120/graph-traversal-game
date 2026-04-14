#include "ui.h"
#include "font.h"
#include "utils.h"

void DrawNode(Vector2 position) {
  DrawCircleV(position, CIRCLE_RADIUS + CIRCLE_BORDER, BLACK);
  DrawCircleV(position, CIRCLE_RADIUS, WHITE);
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
