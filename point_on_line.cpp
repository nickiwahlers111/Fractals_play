#include "FPToolkit.c"

void parametric(double percent, double point[], double p[], double q[]){
  point[0] = p[0] + (percent*(q[0] - p[0]));
  point[1] = p[1] + (percent*(q[1] - p[1]));
}

void my_line(double p[], double q[]){
  double point[2];
  G_rgb(0,0,0);
  for(double i = 0; i < 1; i += 0.001 ){
    point[0] = p[0] + (i *(q[0] - p[0]));
    point[1] = p[1] + (i *(q[1] - p[1]));
    G_rgb(i, i, i);
    G_point(point[0], point[1]);
  }
}

int main() {
	int swidth, sheight;
  double p[2], q[2], m[2], t[2];

	swidth = 400;
	sheight = 400;
	G_init_graphics(swidth, sheight); // interactive graphics

	G_rgb(0.3, 0.3, 0.3);
	G_clear();

  G_rgb(0,1,0);
  G_wait_click(p);
  G_fill_circle(p[0],p[1],2);
  
  G_wait_click(q);
  G_fill_circle(q[0], q[1], 2);

  G_rgb(1, 0, 0);
  // G_line(p[0],p[1], q[0],q[1]) ;
  my_line(p, q);

  //midpoint
  m[0] = (p[0] + q[0]) / 2;
  m[1] = (p[1] + q[1]) / 2;

  G_rgb(0,1,0);
  G_fill_circle(m[0], m[1], 2);

  //one third point
  parametric((1/3.0), t, p, q);
  G_rgb(0,0,1);
  G_fill_circle(t[0], t[1], 2);

	int key;
	key = G_wait_key();
}