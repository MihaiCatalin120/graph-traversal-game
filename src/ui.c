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
  for (size_t i = 0; i < node.optionsLength; i++) {
    const float ARCH_STRENGTH = 60.0f; // 0 = straight, 90 = very deep arch
    const float ARROW_LENGTH = 12.0f;
    const float ARROW_ANGLE = 30.0f;
    const float LINE_THICKNESS = 2.0f;
    Vector2 start = node.position;
    Vector2 end = nodes[node.options[i]].position;

    float angle = atan2f(end.y - start.y, end.x - start.x);
    float offset = ARCH_STRENGTH * DEG2RAD;
    Vector2 normal = {-sinf(angle), cosf(angle)};

    Vector2 mid = {(start.x + end.x) * 0.5f + normal.x * ARCH_STRENGTH,
                   (start.y + end.y) * 0.5f + normal.y * ARCH_STRENGTH};

    Vector2 startEdge = {
        start.x + cosf(angle + offset) * CIRCLE_RADIUS,
        start.y + sinf(angle + offset) * CIRCLE_RADIUS,
    };

    Vector2 endEdge = {
        end.x + cosf(angle + PI - offset) * CIRCLE_RADIUS,
        end.y + sinf(angle + PI - offset) * CIRCLE_RADIUS,
    };

    Vector2 points[5] = {
        start, startEdge, mid, endEdge, end,
    };

    DrawSplineCatmullRom(points, 5, 2.0f, BLACK);

    float approachAngle = atan2f(end.y - mid.y, end.x - mid.x);

    float wing1Angle = approachAngle + PI + (ARROW_ANGLE * DEG2RAD);
    float wing2Angle = approachAngle + PI - (ARROW_ANGLE * DEG2RAD);

    Vector2 wing1 = {endEdge.x + cosf(wing1Angle) * ARROW_LENGTH,
                     endEdge.y + sinf(wing1Angle) * ARROW_LENGTH};
    Vector2 wing2 = {endEdge.x + cosf(wing2Angle) * ARROW_LENGTH,
                     endEdge.y + sinf(wing2Angle) * ARROW_LENGTH};

    DrawLineEx(endEdge, wing1, LINE_THICKNESS, BLACK);
    DrawLineEx(endEdge, wing2, LINE_THICKNESS, BLACK);
  }
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
