#include "node.h"
#include "config.h"

// TODO: Add first level at least
struct Node nodes[MAX_NODES] = {
    // MAIN MENU
    {{WINDOW_WIDTH / 2.0f - 8 * CIRCLE_RADIUS, WINDOW_HEIGHT / 2.0f}, {1}, 1},
    {{WINDOW_WIDTH / 2.0f - 4 * CIRCLE_RADIUS, WINDOW_HEIGHT / 2.0f},
     {0, 2},
     2},
    {{WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f}, {1, 3}, 2},
    {{WINDOW_WIDTH / 2.0f + 4 * CIRCLE_RADIUS, WINDOW_HEIGHT / 2.0f},
     {2, 4},
     2},
    {{WINDOW_WIDTH / 2.0f + 8 * CIRCLE_RADIUS,
      WINDOW_HEIGHT / 2.0f + 3.0f / 2.0f * CIRCLE_RADIUS},
     {3},
     1},
};
