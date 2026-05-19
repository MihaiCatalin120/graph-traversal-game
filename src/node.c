#include "node.h"
#include "config.h"
#include "raylib.h"

#include <math.h>
#include <stdlib.h>
#include <string.h>

Node *nodes;
size_t nodesLength = 0;

void MoveCursorAndInsertNode(Node *cursor, Node *nodes, float xDiff,
                             float yDiff, int options[], size_t optionsLength,
                             const char *innerText) {
  cursor->position.x += xDiff;
  cursor->position.y += yDiff;

  if (options[0] == -1) {
    cursor->options[0] = nodesLength - 1;
    cursor->options[1] = nodesLength + 1;
    cursor->optionsLength = 2;
  } else {
    for (size_t i = 0; i < optionsLength; i++) {
      cursor->options[i] = options[i];
    }
    cursor->optionsLength = optionsLength;
  }

  cursor->innerText = innerText;

  nodes[nodesLength++] = *cursor;
}

void LoadNodes(Node *nodes) {
  Node mainMenuCursor = {
      {rini_get_value(config, "WINDOW_WIDTH") / 2.0f - 8 * CIRCLE_RADIUS,
       rini_get_value(config, "WINDOW_HEIGHT") / 2.0f},
      {1},
      1,
      "Exit",
      false};

  nodes[nodesLength++] = mainMenuCursor;

  MoveCursorAndInsertNode(&mainMenuCursor, nodes, 4 * CIRCLE_RADIUS, 0,
                          (int[]){-1}, 2, "Options");

  MoveCursorAndInsertNode(&mainMenuCursor, nodes, 4 * CIRCLE_RADIUS, 0,
                          (int[]){-1}, 2, "");

  float gameTitleSideLength = 1.2f;
  Node gameTitleCursor = {
      {mainMenuCursor.position.x - gameTitleSideLength * CIRCLE_RADIUS,
       mainMenuCursor.position.y - 8 * CIRCLE_RADIUS},
      {6},
      1,
      "Graph",
      false};

  MoveCursorAndInsertNode(&mainMenuCursor, nodes, 4 * CIRCLE_RADIUS, 0,
                          (int[]){-1}, 2, "");

  MoveCursorAndInsertNode(&mainMenuCursor, nodes, 4 * CIRCLE_RADIUS, 0,
                          (int[]){3, 8}, 2, "");

  nodes[nodesLength++] = gameTitleCursor;

  MoveCursorAndInsertNode(&gameTitleCursor, nodes,
                          2 * gameTitleSideLength * CIRCLE_RADIUS, 0,
                          (int[]){7}, 1, "Traversal");

  MoveCursorAndInsertNode(
      &gameTitleCursor, nodes, -gameTitleSideLength * CIRCLE_RADIUS,
      gameTitleSideLength * sqrtf(3.0f) * CIRCLE_RADIUS, (int[]){5}, 1, "Game");

  Node levelCursor = mainMenuCursor;

  LoadLevel(rini_get_value(config, "STARTING_LEVEL"), &levelCursor, nodes);
}

void LoadLevel(int level, Node *cursor, Node *nodes) {
  switch (level) {
  case 0: {
    Node levelStartCursor = *cursor;
    MoveCursorAndInsertNode(cursor, nodes, 4 * CIRCLE_RADIUS, 0,
                            (int[]){4, 9, 19}, 3, "");

    for (size_t i = 0; i < 10; i++) {
      i != 9 ? MoveCursorAndInsertNode(cursor, nodes, 4 * CIRCLE_RADIUS, 0,
                                       (int[]){-1}, 2, "")
             : MoveCursorAndInsertNode(cursor, nodes, 4 * CIRCLE_RADIUS, 0,
                                       (int[]){nodesLength - 1}, 1, "");
    }

    MoveCursorAndInsertNode(&levelStartCursor, nodes, 6 * CIRCLE_RADIUS,
                            4 * CIRCLE_RADIUS, (int[]){8, nodesLength + 1}, 2,
                            "");
    for (size_t i = 0; i < 10; i++) {
      if (i == 9) {
        levelStartCursor.isGoal = true;
        MoveCursorAndInsertNode(&levelStartCursor, nodes, 4 * CIRCLE_RADIUS,
                                fmax((4.0f - i), 0.0f) * CIRCLE_RADIUS,
                                (int[]){nodesLength - 1}, 1, "");
      } else
        MoveCursorAndInsertNode(&levelStartCursor, nodes, 4 * CIRCLE_RADIUS,
                                fmax((4.0f - i), 0.0f) * CIRCLE_RADIUS,
                                (int[]){-1}, 2, "");
    }
  } break;
  case 1: {
    MoveCursorAndInsertNode(cursor, nodes, 4 * CIRCLE_RADIUS, 0, (int[]){4}, 1,
                            "");
  } break;
  }
}

void ChangeNode(int targetIndex, int *currentIndex, Node *currentNode) {
  *currentIndex = targetIndex;
  *currentNode = nodes[targetIndex];
}

void CheckCurrentNodeAction(Node *currentNode, bool *shouldExit) {
  if (strcmp(currentNode->innerText, "Exit") == 0) {
    *shouldExit = true;
  }

  if (currentNode->isGoal) {
    currentNode->isGoal = false;
    rini_set_value(&config, "STARTING_LEVEL",
                   rini_get_value(config, "STARTING_LEVEL") + 1,
                   STARTING_LEVEL_DESCRIPTION);
    rini_save(config, CONFIG_FILENAME);
    printf("DEBUG: Progress saved!\n");
  }
}
