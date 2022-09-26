#include "FPToolkit.c"

// appropriate for a 600x600 window
// double x[13] = {263,338,338,450,338,338,375,300,225,263,263,150,263} ;
// double y[13] = {450,450,375,338,338,300,150,263,150,300,338,338,375} ;
double x[1] = {0.0};
double y[1] = {0.0};
int n = 1 ;
double width = 701, height = 301;


//UTILITY FUNCTIONS
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


void mio(double r){
  if(r < 1.0/16){
    
  }
  else if(r < 2.0/16){
    
  }
  else if(r < 3.0/16){
    
  }
  else if(r < 4.0/16){
    
  }
  
  else if(r < 5.0/16){
    
  }
  else if(r < 6.0/16){
    
  }
  else if(r < 7.0/16){
    
  }
  else if(r < 8.0/16){
    
  }
  else if(r < 9.0/16){
    
  }
  else if(r < 10.0/16){
    
  }
  else if(r < 11.0/16){
    
  }
  else if(r < 12.0/16){
    
  }
  else if(r < 13.0/16){
    
  }
  else if(r < 14.0/16){
    
  }
  else if(r < 15.0/16){
    
  }
  else{}
}

int main() 
{
  int q ;

  G_init_graphics(width, height) ;
  G_rgb(0,0,0) ;
  G_clear() ;
  srand48(200);
  G_rgb(1,1,1);
  G_fill_rectangle(2,2,width-4, height-4);
  G_rgb(1,0,0);
  
  double r;
  
  for (int i = 0; i < 50000000; ++i){
    r = drand48();
    
    mio(r);
    // G_rgb(1,1,1);
    G_point(x[0]* width, y[0]* width);

    if(i % 1000== 0){
    
      G_display_image();
      usleep(1000);
      }
    }
  
  q = G_wait_key() ;
  
  
}