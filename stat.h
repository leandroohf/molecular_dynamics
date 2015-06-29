#ifndef STAT_H
#define STAT_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

#include "histogram.h"

double vmean(int n, double *v);
int vmax(int n, int *v);
int vmin(int n, int *v);

#endif //STAT_H
