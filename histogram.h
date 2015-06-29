#ifndef _HISTOGRAM_H
#define _HISTOGRAM_H

#include <stdio.h>
#include <stdlib.h>

double* mkvbins(int nbins, double min, double max);
void mkhist(int *h, int nv, double *v,int nbins, double *vbins);

#endif //  _HISTOGRAM_H
