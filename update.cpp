
// * ****************************************************************
//   Programer[s]: Leandro Fernandes
//   Company/Institution: Fine Image Technology
//   email: leandroohf@gmail.com
//   Program: Update molecula dynamic system                           
//   Commentary: Update system                        
//   Reference: Giordano Bruno, Computational Phisycs                  
//   Date: March 29, 2009
// * ****************************************************************

#include "update.h"

void update(particle *p,int np,int len,double dt){
  
  int i= 0;
  double dt2 = dt*dt;
  
  force(np,p,len);
  
  for (i = 0; i < np; ++i)
    {
      
      // updating position
      p[i].xn = 2.0*p[i].x - p[i].xp + p[i].fx*dt2;
      p[i].yn = 2.0*p[i].y - p[i].yp + p[i].fy*dt2;

      // updating velocity
      p[i].vx = (p[i].xn - p[i].xp)/(2.0*dt);
      p[i].vy = (p[i].yn - p[i].yp)/(2.0*dt);
      
      // periodic boundary conditions
      boundary(p[i],len);
    }
  
  for (i = 0; i < np; ++i)
    {
      
      p[i].xp = p[i].x;
      p[i].yp = p[i].y;
      
      p[i].x = p[i].xn;
      p[i].y = p[i].yn;
      
    }
}
