#include "data_process.h"

#include <math.h>

int normalization(double *data, int n) {
  int result = 1;
  double max_value = fmax(*data, n);
  double min_value = fmin(*data, n);
  double size = max_value - min_value;

  if (fabs(size) > EPS) {
    for (int i = 0; i < n; i++) {
      data[i] = data[i] / size - min_value / size;
    }
  } else {
    result = 0;
  }

  return result;
}