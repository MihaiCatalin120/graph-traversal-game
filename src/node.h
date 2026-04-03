#include "config.h"
#include "raylib.h"
#include <stdio.h>

#ifndef NODE_H
#define NODE_H

typedef struct Node {
  Vector2 position;
  int options[MAX_NEIGHBOURS];
  size_t optionsLength;
} Node;

void ChangeNode(int targetIndex, int *currentIndex, Node *currentNode);

extern struct Node nodes[MAX_NODES];
#endif
