#include "config.h"
#include "raylib.h"
#include <stdio.h>

#ifndef NODE_H
#define NODE_H

typedef struct Node {
  Vector2 position;
  int options[MAX_NEIGHBOURS];
  size_t optionsLength;
  const char *innerText;
  bool isGoal;
} Node;

void LoadNodes(Node *nodes);
Node LoadLevel(int level, Node *cursor, Node *nodes);
void ChangeNode(int targetIndex, int *currentIndex, Node *currentNode);
void CheckCurrentNodeAction(Node *currentNode, int *currentNodeIndex,
                            bool *shouldExit);

extern Node *nodes;
extern size_t nodesLength;
#endif
