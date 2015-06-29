// * ****************************************************************
//   Programer[s]: Leandro Fernandes
//   Company/Institution: Fine Image Technology
//   email: leandroohf@gmail.com
//   Program: boundary                                                 
//   Commentary: Periodic boundary condition imn molecular dynamics    
//   Reference: Giordano Bruno, Computational Phisycs                  
//   Date: March 29, 2009
// * ****************************************************************

#include "boundary.h"

void boundary(particle &p,int len)
{

  if (p.xn < 0.0){
      
    p.xn = p.xn + len;
    p.x = p.x + len;
      
  }else if (p.xn > len){

    p.xn = p.xn - len;
    p.x = p.x - len;
      
  }
  
  if (p.yn < 0.0){
      
    p.yn = p.yn + len;
    p.y = p.y + len;
    
  }else if (p.yn > len){

    p.yn = p.yn - len;
    p.y = p.y - len;
      
  }
}
