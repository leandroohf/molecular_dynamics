// * ****************************************************************
//   Programer[s]: Leandro Fernandes
//   Company/Institution: Fine Image Technology
//   email: leandroohf@gmail.com
//   Program: Force                                                    
//   Commentary: Computes force on all of the particles                
//   Reference: Giordano Bruno, Computational Phisycs                  
//   Date: March 29, 2009
// * ****************************************************************


#include "force.h"

// computes force on particle j due to all other particles in the gas
void force(int np,particle *p,int len)
{
  
  int i = 0, j = 0;
  double dx = 0.0, dy = 0.0, r = 0.0;
  double f = 0.0 ,u = 0.0;

  for (int i = 0; i < np; ++i) {
    
    p[i].fx = 0.0;
    p[i].fy = 0.0;
    
  }
  
  for (i = 0; i < np; ++i){
    
    for (j = i+1; j < np; ++j){
      
      r = find_spacing(i,j,p,len,dx,dy);
      
      //  force is null when r > 4*sigma
      if (r < 3){
	
	lennard_jones_pair_force(r,f,u);
	
	p[i].fx = p[i].fx + f*dx/r;
	p[i].fy = p[i].fy + f*dy/r;
      
	p[j].fx = p[j].fx - f*dx/r;
	p[j].fy = p[j].fy - f*dy/r;
	
      }
      
    }
  }
}


double find_spacing(int i,int j,particle *p,int len, double &dx,double &dy)
{
  
  double half_len = len/2.0;
  
  dx = p[j].x - p[i].x;
  dy = p[j].y - p[i].y;

  if (fabs(dx) > half_len){
    
    if (dx > 0.0){
      
      dx = dx - len;
    
    }else{
      
      dx = dx + len;
      
    }
  }

  if (fabs(dy) > half_len){
    
    if (dy > 0.0){
      
      dy = dy - len;
    
    }else{
      
      dy = dy + len;
      
    }
  }
    
  return sqrt(dx*dx + dy*dy);

}


void lennard_jones_pair_force(double r,double &f,double &u)
{

  u = 4.0*(1.0/pow(r,12) - 1.0/pow(r,6));

  f = 24.0*(2.0/pow(r,13) - 1.0/pow(r,7));
  // f = 24.0*(2.0/pow(r,2) - 1.0/pow(r,3));

  if (f > 28.0){

    f = 28.0;
  }
}
