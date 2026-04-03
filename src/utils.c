#include "utils.h"

size_t GetElementIndex(int value, int *array, int length) {
  for (size_t i = 0; i < length; i++) {
    if (array[i] == value)
      return i;
  }

  return -1;
}
