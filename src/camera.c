#include "camera.h"
#include "config.h"
#include "raymath.h"

void InitCamera(Camera2D *camera, Vector2 startPosition) {
  camera->target = startPosition;
  camera->offset = (Vector2){WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f};
  camera->rotation = 0.0f;
  camera->zoom = 1.0f;
}

void UpdateCameraPosition(Camera2D *camera, Vector2 targetPosition,
                          float delta) {
  static float minSpeed = 100;
  static float minEffectLength = 10;
  static float fractionSpeed = 0.8f;

  camera->offset = (Vector2){WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f};
  Vector2 diff = Vector2Subtract(targetPosition, camera->target);
  float length = Vector2Length(diff);

  if (length > minEffectLength) {
    float speed = fmaxf(fractionSpeed * length, minSpeed);
    camera->target =
        Vector2Add(camera->target, Vector2Scale(diff, speed * delta / length));
  }
}
