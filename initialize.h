#ifndef _INITIALIZE_H
#define _INITIALIZE_H

#include "physics.h"
#include <cmath>
#include <stdlib.h>
#include <ctime>

#define ECA_PER 0.15

void initialize(particle *p,int np, int len, double dt,double v0);

#endif // _INITIALIZE_H
