#ifndef _FORCE_H
#define _FORCE_H

#include <cmath>
#include "physics.h"

// Find spacing taking periodic boundary conditions into account
double find_spacing(int i,int j,particle *p,int len, double &dx,double &dy);

// Compute Lennard Jones potential and force
void lennard_jones_pair_force(double r,double &f,double &u);


void force(int np,particle *p,int len);

#endif //_FORCE_H
