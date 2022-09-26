#include "FPToolkit.c"


void pythagorean_method(double p0[], double p1[], int n){
  if(n == 1){
    return;
  }
  double P[2];
  double dx = 0.97*(p1[0] -p0[0]);
  double dy = 0.97*(p1[1] - p0[1]);
  P[0]  = p1[0] - dy;
  P[1] = p1[1] + dx;


  // G_fill_circle(P[0], P[1], 2);
  G_line(p1[0], p1[1], P[0], P[1]);
  
  pythagorean_method(p1, P, n-1);
}


int main() {
	int swidth, sheight;
  double p[2], q[2];
  double theta, xval, yval;
  int n;

	swidth = 400;
	sheight = 400;
	G_init_graphics(swidth, sheight); // interactive graphics

	G_rgb(1, 1, 1);
	G_clear();

  G_rgb(0,0,0);
  
  //Get first point
  G_wait_click(p);

  //Get second point
  G_wait_click(q);


  //First line from p to q
  G_line(p[0], p[1], q[0], q[1]);

  pythagorean_method(p, q, 100);
  
  

	int key;
	key = G_wait_key();
}