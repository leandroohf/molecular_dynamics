/* ****************************************************************
  Programer[s]: Leandro Fernandes
  Company/Institution: Fine Image Technology
  email: leandroohf@gmail.com
  Program: Molecular Dynamics in 2 dimensions
  Commentary: This program simulated Argon gas                      
  Reference: N. Giordano; Computational Physics                  
  Date: March 29, 2009
  * *************************************************************** */

#include <stdio.h>
#include <cmath>
#include <csignal>
#include <iostream>

#include "physics.h"
#include "boundary.h"
#include "initialize.h"
#include "update.h"
#include "initdisplay.h"
#include "display.h"
#include "stat.h"


//  Run it with: ./md | gnuplot
int main(int argc,char **argv){

  int i = 0,j = 0, k = 0;
  int n_particles = 30,N = 1500000;
  int burning = 2000;
  double t = 0.0,dt = 0.00025, v0 = 1.0,vm = 0.0,v2m = 0.0;
  int len = 35;
  int c = '0' ;
  int nplot = 1000;
  
  particle p[n_particles];
  
  // 4 velocity distribution computation
  FILE *fdv = NULL, *fdvx = NULL;
  double *vxbins,*vbins,*v,*v2,*vx;
  int *hv,*hvx,*hacc_v,*hacc_vx,nbins = 20;
  int hm_v = 0,hm_vx = 0; 
  
  hv = (int *) malloc(nbins*sizeof(int));
  hacc_v = (int *) malloc(nbins*sizeof(int));
  
  hvx = (int *) malloc(nbins*sizeof(int));
  hacc_vx = (int *) malloc(nbins*sizeof(int));
  
  v = (double *) malloc(n_particles*sizeof(double));
  v2 = (double *) malloc(n_particles*sizeof(double));
  vx = (double *) malloc(n_particles*sizeof(double));
  
  for(k = 0; k < nbins; k++)
    {
      
      hacc_v[k] = 0;
      hv[k] = 0;
      
      hacc_vx[k] = 0;
      hvx[k] = 0;
      
    }

  // Initialing system
  initialize(p,n_particles,len,dt,v0);
  
  // copying velocities
  for(k = 0; k < n_particles; k++){
    
    v[k] = sqrt(p[k].vx*p[k].vx +  p[k].vy*p[k].vy);
    v2[k] = v[k]*v[k];
    vx[k] = p[k].vx;
      
    }
  
  // vm = vmean(n_particles,v);
  // printf("vm = %f\n",vm);
  
  // v2m = vmean(n_particles,v2);
  // printf("v2m = %f\n",v2m);

  // vm = vmean(n_particles,vx);
  // printf("vx = %f\n",vm);

  initdisplay(n_particles,len);
  
  display(p,n_particles,len);
  
  c = getchar();
  
  // Burnning
  for (i = 0; i < burning; ++i)
    {
    
      if (j > nplot)
	{
	  
	display(p,n_particles,len);
	j = 0;
      }

      t = t + dt;
      j++;
      update(p,n_particles,len,dt);
    }
  
  j = 0;
  
  // make histograms of velocity
  // vbins = mkvbins(nbins,0,3.0*v0);
  // vxbins = mkvbins(nbins,-3.*v0,3.0*v0);
  
  for (i = 0; i < N; ++i){
    
    if (j > nplot){
      
      display(p,n_particles,len);
      j = 0;
    }
    
    // copying velocities
    for(k = 0; k < n_particles; k++){

      v[k] = sqrt(p[k].vx*p[k].vx +  p[k].vy*p[k].vy);
      v2[k] = v[k]*v[k];
      vx[k] = p[k].vx;
      
    }

    //mkhist(int *h, int nv, double *v,int nbins, double *vbins);
    // mkhist(hv,n_particles,v,nbins,vbins);
    // mkhist(hvx,n_particles,vx,nbins,vxbins);
    
    // updating accumulated histogram
    // for(k = 0; k < nbins; k++){
      
    //   hacc_v[k] = hacc_v[k] + hv[k];
    //   hacc_vx[k] = hacc_vx[k] + hvx[k];
      
    // }
    
    t = t + dt;
    j++;
    
    update(p,n_particles,len,dt);
  }
  
  
  // saving histograms and normalizing
  // fdv = fopen("hist_v.dat","w");
  // fdvx = fopen("hist_vx.dat","w");

  // hm_v = vmax(nbins,hacc_v);
  // hm_vx = vmax(nbins,hacc_vx);
  
  // for ( k = 0; k < nbins; ++k){
      
  //   // printf("hacc/hm = %f\n",(double) hacc[k]/hm);
  //   fprintf(fdv,"%f %f\n",vbins[k],(double) hacc_v[k]/hm_v );
  //   fprintf(fdvx,"%f %f\n",vxbins[k],(double) hacc_vx[k]/hm_vx );
    
  // }
  
  // fclose(fdv);
  // fclose(fdvx);
  
  // printf("hm_v = %d\n",hm_v);
  // printf("hm_vx = %d\n",hm_vx);
  
}
