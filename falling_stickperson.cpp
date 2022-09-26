#include "FPToolkit.c"

// appropriate for a 600x600 window
double x[13] = {263,338,338,450,338,338,375,300,225,263,263,150,263} ;
double y[13] = {450,450,375,338,338,300,150,263,150,300,338,338,375} ;
int n = 13 ;
double width = 601, height = 601;


void translate (double dx, double dy)
{
  int i ;

  i = 0 ;
  while (i < n) {
    x[i] = x[i] + dx ;
    y[i] = y[i] + dy ;
    i = i + 1 ;
  }
}

void scale (double sx, double sy){
  
  for(int i = 0; i < n; ++i){
    x[i] *= sx;
    y[i] *= sy;
  }
}
void rotate(double deg){
  double r, a;
  double t = deg * (M_PI / 180);
  double temp;
  double c, s;
  c = cos(t);
  s = sin(t);
  
  for(int i = 0; i < n; ++i){
    temp = (x[i]* c) - (y[i] * s);
    y[i] = (y[i] * c) + (x[i] * s);
    x[i] = temp;
  }
}


int main() 
{
  int q ;

  G_init_graphics(width, height) ;
  G_rgb(0,0,0) ;
  G_clear() ;
 
  G_rgb(0,0,1) ; G_fill_polygon(x,y,n) ;
  q = G_wait_key() ;
  G_rgb(0,0,0) ;
  G_clear() ;

  // translate(100,50) ;
  for(int i = 0; i < 20; ++i){
    translate(-300,-300);
    scale(0.9, 0.9);
    rotate(2*i);
    translate(300, 300);
 
    G_rgb(0,0,1) ; G_fill_polygon(x,y,n) ;
    // G_wait_key();
    G_display_image();
    usleep(50000);
    G_rgb(0,0,0);
    G_clear();
  }

  // rotate(30);

  // G_rgb(1,0,0) ; G_fill_polygon(x,y,n) ;
  for(int i = 0; i < 50; ++i){
    // G_rgb(1.0 - (i*.01),1.0 - (i*.01),1.0 - (i*.01));
    G_rgb(1,0,0);
    G_fill_circle(300, 300, 2*i);
    G_rgb(0,0,1) ; G_fill_polygon(x,y,n) ;
    
    // G_wait_key();
    G_display_image();
    usleep(50000);
    G_rgb(0,0,0);
    G_clear();
  }
  q = G_wait_key() ;
  
}

