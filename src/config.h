#ifndef CONFIG_H
#define CONFIG_H

#include <stdbool.h>

#include "rini.h"

#define CONFIG_FILENAME "config.ini"
#define DEBUG_MODE true

#define CIRCLE_RADIUS 40
#define CIRCLE_BORDER 2
#define PLAYER_RADIUS (CIRCLE_RADIUS / 2.0f)
#define MOVE_HINT_SPACING 30

#define GAME_TITLE "graph-traversal"

#define MAX_NEIGHBOURS 10
#define MAX_NODES 100

#define PLAYER_MOVE_ANIMATION_DURATION .5f

#define STARTING_LEVEL_DESCRIPTION "Level from where the game is starting"

void LoadConfig();

extern rini_data config;

#endif
