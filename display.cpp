// * ****************************************************************
//   Programer[s]: Leandro Fernandes
//   Company/Institution: Fine Image Technology
//   email: leandroohf@gmail.com
//   Program: display with gnuplot                                     
//   Commentary: display molecular dynamics using gnuplot              
//   Date: March 29, 2009
// * ****************************************************************

#include "display.h"

#define tab "\t"

using namespace std;

void display(particle *p,int np,int len)
{
  
  int i = 0;

  // XXX shadow
  // printf("plot [0.0:%d][0.0:%d] '-' pt 6 ps 2 \n",len,len);
  cout << "plot [0.0:" << len << "][0.0:" << len << "] '-' pt 6 ps 1" << endl;
  // cout <<"plot [0.0:" << len << "][0.0:" << len << "] '-' ps 2" << endl;
  // cout << "'-' pt 5 ps 1" << endl;
  
  
  for (i = 0; i < np; ++i){
     
    // printf("\t %f \t %f \n",p[i].x,p[i].y);
    cout << tab <<p[i].x << tab << p[i].y << endl;
    
  }
  
  // printf("'e'\n");
  // fflush(stdout);
  cout << 'e' << endl;


//    for (int i = 0; i < np; ++i)
//    {
     
//      cout<< tab <<p[i].xp << tab <<p[i].yp << endl;
     
//    }
   
//    cout << 'e' << endl << flush;
   
}
