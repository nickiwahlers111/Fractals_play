#include "FPToolkit.c"


void koch(int depth, double p0[], double p1[]){
if(depth == 0){
  G_rgb(0,0,0);
  G_line(p0[0], p0[1], p1[0], p1[1]);
  return;
  }
  G_rgb(0,0,0);
  // G_line(p0[0], p0[1], p1[0], p1[1]);
  double dx = p1[0] - p0[0]; //x distance between original points
  double dy = p1[1] - p0[1]; //y distance between original points
  double t0[2], t1[2], t2[2]; //1/3 and 2/3 and midpoint
  double z[2]; //the top point
  
  double f = 0.5; //half
  
  t0[0] = p0[0] + (1.0/3) * dx; //1/3 point x
  t0[1] = p0[1] + (1.0/3 )*dy; //1/3 point y val
  
  t1[0] = p1[0] - (1.0/3) * dx; //2/3 point x
  t1[1] = p1[1] - (1.0/3)*dy;  //2/3 point y

  t2[0] = p1[0] - (1.0/2)* dx;
  t2[1] = p1[1] - (1.0/2) * dy; //midpoint
  
  f = sqrt(3) / 6;
  z[0] = t2[0] - (f * dy);
  z[1] = t2[1] + (f*dx);

  koch(depth -1, p0, t0);
  koch(depth-1, t0, z);
  koch(depth -1, z, t1);
  koch(depth -1, t1, p1);
};

void koch_mama(double p[], double q[], double z[]){
  koch(5, q, p);
  koch(5,z,q );
  koch(5,p,z );
}

void snowflake(double p[], double q[], double t[], double z[]){

  double t1[2];
  double t2[2];
  double t3[2];

  //distance between p and q 
  double dx = q[0] - p[0];
  double dy = q[1] - p[1];

  //half between p and q
  t[0] = p[0] + 0.5*dx;
  t[1] = p[1] + 0.5*dy;

  //find z point
  double f = sqrt(3) / 2;
  z[0] = t[0] - f*dy;
  z[1]= t[1] + f*dx;
 
}


int main() {
	int swidth, sheight;

	swidth = 601;
	sheight = 601;
	G_init_graphics(swidth, sheight); // interactive graphics
  G_rgb(1, 1, 1);
	G_clear();
  
  double p[2], q[2];
  double t[2], z[2];
  p[0] = 100;
  p[1] = 150;
  q[0] = 500;
  q[1] = 150;

  snowflake(p, q, t, z);
  koch_mama(p, q, z);
  double mid1[2];

  //distance between p and q 
  // double dx = q[0] - p[0];
  // double dy = q[1] - p[1];

  // //half between p and q
  // t[0] = p[0] + 0.5*dx;
  // t[1] = p[1] + 0.5*dy;
  
  mid1[0] = q[0] + 0.5*(z[0] - q[0]);
  mid1[1] = q[1] + 0.5*(z[1] - q[1]);
  snowflake(t, mid1, z, q);
  koch_mama(t, mid1, q);
  
  

  
	G_rgb(1, 1, 1);
	G_clear();
  
  
  

	int key;
	key = G_wait_key();
}