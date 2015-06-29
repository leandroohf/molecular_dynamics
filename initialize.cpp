// * ****************************************************************
//   Programer[s]: Leandro Fernandes
//   Company/Institution: Fine Image Technology
//   email: leandroohf@gmail.com
//   Program: initialize                                               
//   Commentary: Initialize molecular dynamics                         
//   Reference: Giordano Bruno, Computational Physics                  
//   Date: March 29, 2009
// * ****************************************************************

#include "initialize.h"


void initialize(particle *p,int np,int len, double dt,double v0)
{
  
  int i = 0,j = 0,n = 0, k = 0;
  int nx = 0, ny = 0;
  double rd = 0 ;
  double pi,theta = 0.0;
  double gridx = 0.0,gridy = 0.0;
  

  pi = 4.0*atan(1);
  
  // number of particle in y
  ny = (int) sqrt(np);
  nx = (int) ceil(np/ny);

  gridx = len/nx;
  gridy = len/ny;
  
  printf("np = %d\n",np);
  printf("len = %d\n",len);

  printf("ny = %d\n",ny);
  printf("nx = %d\n",nx);
  
  printf("gridx = %f\n",gridx);
  printf("gridy = %f\n",gridy);

  for (k = 0; k; ++k){
    
    p[k].fx = 0.0;
    p[k].fy = 0.0;

  }

  srand(time(0));
  
   while ( n < np && i < nx){
    
     while(n < np && j < ny){

       // init position
       // rd =  ( (double) rand()/ (double) RAND_MAX ) - 0.5;
      
       // p[n].x = (i + rd) * gridx + 0.45*gridx;  
       
       p[n].x = (i + 0.5)*gridx;
       
//        rd =  ( (double) rand()/ (double) RAND_MAX ) - 0.5;
//        p[n].y = (j + rd )* gridy + 0.45*gridy; 

       p[n].y = (j+0.5)*gridy;
	
       // init velocity
       theta = (double (rand())/RAND_MAX)*2.0*pi;
       p[n].vx = v0*cos(theta);
       
       p[n].vy = v0*sin(theta);
	
       // init previous position
       p[n].xp = p[n].x - p[n].vx*dt;
       p[n].yp = p[n].y - p[n].vy*dt;
      
       j++;
       n++;
     }
    
     j = 0;
     i++;
   }
}
