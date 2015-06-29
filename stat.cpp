#include "stat.h"


double vmean(int n, double *v){

  int i = 0;
  double vmean = 0.0;;

  for ( i = 0; i < n; ++i)
  {
    
    vmean += v[i]; 
  }

  vmean = vmean/n;

  return vmean;
  
}


int vmax(int n, int *v){

  int i = 0;
  int vmax = -INT_MAX;

  for ( i = 0; i < n; ++i)
  {
    
    if (v[i] > vmax){
      
      vmax = v[i];

    }
  }
  
  return vmax;
  
}


int vmin(int n, int *v){

  int i = 0;
  int vmin = INT_MAX;

  for ( i = 0; i < n; ++i)
  {
    
    if (v[i] < vmin){
      
      vmin = v[i];

    }
  }
  
  return vmin;
  
}
