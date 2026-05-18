#include "config.h"
#include <stdio.h>

rini_data config;

void CreateNewConfig() {
  config = rini_load(NULL);

  rini_set_value(&config, "WINDOW_WIDTH", 800, "Window width in pixels");
  rini_set_value(&config, "WINDOW_HEIGHT", 600, "Window height in pixels");
  rini_set_value(&config, "STARTING_LEVEL", 0, STARTING_LEVEL_DESCRIPTION);

  rini_save(config, CONFIG_FILENAME);
}

void LoadConfig() {
  config = rini_load(CONFIG_FILENAME);
  if (config.count == 0) {
    printf("DEBUG: No config found. Creating new config file\n");
    CreateNewConfig();
    config = rini_load(CONFIG_FILENAME);
  }
}
