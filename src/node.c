#include "node.h"
#include "config.h"

// TODO: Add first level at least
Node nodes[MAX_NODES];

void LoadNodes(Node *nodes) {
  Node nodeCursor = {
      {WINDOW_WIDTH / 2.0f - 8 * CIRCLE_RADIUS, WINDOW_HEIGHT / 2.0f}, {1}, 1};

  nodes[0] = nodeCursor;

  nodeCursor.position.x += 4 * CIRCLE_RADIUS;
  nodeCursor.options[0] = 0;
  nodeCursor.options[1] = 2;
  nodeCursor.optionsLength = 2;
  nodes[1] = nodeCursor;

  nodeCursor.position.x += 4 * CIRCLE_RADIUS;
  nodeCursor.options[0] = 1;
  nodeCursor.options[1] = 3;
  nodeCursor.optionsLength = 2;
  nodes[2] = nodeCursor;

  nodeCursor.position.x += 4 * CIRCLE_RADIUS;
  nodeCursor.options[0] = 2;
  nodeCursor.options[1] = 4;
  nodeCursor.optionsLength = 2;
  nodes[3] = nodeCursor;

  nodeCursor.position.x += 4 * CIRCLE_RADIUS;
  nodeCursor.position.y += 3.0f / 2.0f * CIRCLE_RADIUS;
  nodeCursor.options[0] = 3;
  nodeCursor.optionsLength = 1;
  nodes[4] = nodeCursor;
}

void ChangeNode(int targetIndex, int *currentIndex, Node *currentNode) {
  *currentIndex = targetIndex;
  *currentNode = nodes[targetIndex];
}
