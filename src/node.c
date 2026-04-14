#include "node.h"
#include "config.h"

#include <math.h>

// TODO: Add first level at least
Node nodes[MAX_NODES];
size_t nodesLength = 0;

void MoveCursorAndInsertNode(Node *cursor, Node *nodes, float xDiff,
                             float yDiff, int options[], int optionsLength,
                             const char *innerText) {
  cursor->position.x += xDiff;
  cursor->position.y += yDiff;

  for (size_t i = 0; i < optionsLength; i++) {
    cursor->options[i] = options[i];
  }
  cursor->optionsLength = optionsLength;
  cursor->innerText = innerText;

  nodes[nodesLength++] = *cursor;
}

void LoadNodes(Node *nodes) {
  Node mainMenuCursor = {
      {WINDOW_WIDTH / 2.0f - 8 * CIRCLE_RADIUS, WINDOW_HEIGHT / 2.0f},
      {1},
      1,
      "Exit"};

  nodes[nodesLength++] = mainMenuCursor;

  MoveCursorAndInsertNode(&mainMenuCursor, nodes, 4 * CIRCLE_RADIUS, 0,
                          (int[]){0, 2}, 2, "Options");

  MoveCursorAndInsertNode(&mainMenuCursor, nodes, 4 * CIRCLE_RADIUS, 0,
                          (int[]){1, 3}, 2, "");

  float gameTitleSideLength = 1.2f;
  Node gameTitleCursor = {
      {mainMenuCursor.position.x - gameTitleSideLength * CIRCLE_RADIUS,
       mainMenuCursor.position.y - 8 * CIRCLE_RADIUS},
      {6},
      1,
      "Graph"};

  MoveCursorAndInsertNode(&mainMenuCursor, nodes, 4 * CIRCLE_RADIUS, 0,
                          (int[]){2, 4}, 2, "");

  MoveCursorAndInsertNode(&mainMenuCursor, nodes, 4 * CIRCLE_RADIUS,
                          3.0f / 2.0f * CIRCLE_RADIUS, (int[]){3}, 1, "");

  nodes[nodesLength++] = gameTitleCursor;

  MoveCursorAndInsertNode(&gameTitleCursor, nodes,
                          2 * gameTitleSideLength * CIRCLE_RADIUS, 0,
                          (int[]){7}, 1, "Traversal");

  MoveCursorAndInsertNode(
      &gameTitleCursor, nodes, -gameTitleSideLength * CIRCLE_RADIUS,
      gameTitleSideLength * sqrtf(3.0f) * CIRCLE_RADIUS, (int[]){5}, 1, "Game");
}

void ChangeNode(int targetIndex, int *currentIndex, Node *currentNode) {
  *currentIndex = targetIndex;
  *currentNode = nodes[targetIndex];
}
