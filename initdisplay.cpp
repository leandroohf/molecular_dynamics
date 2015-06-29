// * ****************************************************************
//   Programer[s]: Leandro Fernandes
//   Company/Institution: USP
//   email: leandro_fernandes@fineimagetech.com
//   Program: Initdisplay                                              
//   Commentary: Initialize gnuplot settungs for display               
//   Date: April 27, 2009
// * ****************************************************************

#include "initdisplay.h"


void initdisplay(int np, int len)
{

  int n = 1;
  
  n = (int) len/((int) sqrt(np));

  std::cout << "set xtics " << n << std::endl;
  std::cout << "set ytics " << n << std::endl;
  std::cout << "set nokey " << std::endl;
  std::cout << "set grid" << std::endl;
  
}
