#include "FPToolkit.c"


void midpoint(double p[], double q[], double m[]){
  double x0,y0,x1,y1 ;
  x0 = p[0] ;
  y0 = p[1] ;
  x1 = q[0] ;
  y1 = q[1] ;
  
  m[0] =  x0+ ((1/2.0)*(x1 - x0));
  m[1] = y0 + ((1/2.0)*(y1 - y0));
}

double distance(double p[], double q[], double distances[]){
  double x_dist = pow(q[0] -p[0], 2);
  double y_dist = pow(q[1] -p[1], 2);
  
  return sqrt(x_dist + y_dist);  
}

void babies(double a[], double b[], double c[], double n){

  if(n <=0){
    return;
  }
  double m1[2], m2[2], m3[2];
  midpoint(a, b, m1);
  midpoint(b,c,m2);
  midpoint(a, c, m3);
  G_rgb(0,0,0);
  G_fill_triangle(m1[0], m1[1],  m2[0], m2[1],  m3[0], m3[1]);

}

int main() {
	int swidth, sheight;
  double n;
  double a[2], b[2], c[2];


	swidth = 400;
	sheight = 400;
	G_init_graphics(swidth, sheight); // interactive graphics
  printf("Enter N: ");
  scanf("%lf", &n);

  G_rgb(1,1,1); //white
	G_clear();

  G_rgb(0,1,0);
  a[0] = 10;
  a[1] = 10;
  b[0] = 390;
  b[1] = 10;
  c[0] = 10;
  c[1] = 390;
  
  G_fill_circle(a[0], a[1], 2);
  G_fill_circle(b[0], b[1], 2);
  G_fill_circle(c[0], c[1], 2);
  G_triangle(a[0], a[1],  b[0], b[1],  c[0], c[1]);

  babies(a,b,c, n);

  
	int key;
	key = G_wait_key();
}