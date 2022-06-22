

#include "FPToolkit.c"

int main() {
	int swidth, sheight;
  double n;
  double p[2], q[2], point[2];

	swidth = 400;
	sheight = 400;

  printf("Enter n: ");
  scanf("%lf", &n);
	G_init_graphics(swidth, sheight); // interactive graphics
  G_rgb(0.3, 0.3, 0.3);
	G_clear();

  double x0,y0,x1,y1 ;

  G_rgb(0,1,0);
  G_wait_click(p);
  x0 = p[0] ;
  y0 = p[1] ;
  G_fill_circle(x0,y0,2);
  
  G_wait_click(p);
  x1 = p[0] ;
  y1 = p[1] ;
  G_fill_circle(x1, y1, 2);

  G_line(x0,y0, x1, y1) ;
  double distance = sqrt(pow(x1- x0, 2) + pow(y1 - y0, 2));
  double cx,cy;
  double t;
  for(double i = 1; i < n*2; i+=2){
    t=i/(2*n);
    cx = x0 + (t*(x1 - x0));
    cy = y0 + (t*(y1 - y0));
    G_circle(cx, cy, distance/(n*2));
  }

	int key;
	key = G_wait_key();
}