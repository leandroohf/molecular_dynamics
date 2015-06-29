#include <stdio.h>
#include <cmath>
#include <csignal>
#include <iostream>

#include "histogram.h"

int main(int argc,char **argv){


  int i = 0;
  double v[6] = {0,0,0,1,1,2};
  double *vbins;
  int *h,nbins = 4;
  
  
  h = (int *) malloc(nbins*sizeof(int));	

  printf("vector v: \n");
  for (i = 0; i < 6; i++){
    
    printf("v[%d] = %.1f \n",i,v[i]);

  }
    
  vbins = mkvbins(nbins,0,3);
  
  printf("vbins: \n");

  for (i = 0; i < nbins; i++){
    
    printf("vbins[%d] = %.1f \n",i,vbins[i]);

  }

  mkhist(h,6,v,nbins,vbins);

  printf("histogram: \n");
  for (i = 0; i < nbins; i++){
    
    printf("h[%d] = %d \n",i,h[i]);
    
  }

  return 0;
  
}
