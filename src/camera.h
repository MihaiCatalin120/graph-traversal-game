#include "raylib.h"
#ifndef CAMERA_H
#define CAMERA_H

void InitCamera(Camera2D *camera, Vector2 startPosition);
void UpdateCameraPosition(Camera2D *camera, Vector2 targetPosition, float delta,
                          int currentNodeIndex);

#endif
