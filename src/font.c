#include "font.h"
#include "raylib.h"

Font font;

void InitFont(const char *appPath) {
  font = LoadFont(
      TextFormat("%s%s", appPath, "../assets/fonts/gasalt.regular.ttf"));
}
