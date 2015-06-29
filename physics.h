#ifndef _PHYSICS_H
#define _PHYSICS_H

#include <stdio.h>

#define VecList(V)      V[1],V[2]


#define ShowVec(v_string,V)\
  printf(v_string);					\
  printf("<%0.4lf,%0.4lf,%0.4lf>\n",VecList(V)))	\
  

#define ShowParticle(p_string,p)			\
  printf (p_string);							\
  printf("Position: <%.4f,%.4f>\n",p.x,p.y );				\
  printf("Velocity: <%.4f,%.4f>\n",p.vz,p.vy);				\
  printf("Force: <%.4f,%.4f>\n",p.fx,p.fy)				\

struct particle{
  
  // curr position
  double x,y;
  
  /* previous position */
  double xp,yp;

  /* next position */
  double xn,yn;
  
  /* velocity */
  double vx,vy;

  /* force */
  double fx,fy;

};

#endif //_PHYSICSY_H
