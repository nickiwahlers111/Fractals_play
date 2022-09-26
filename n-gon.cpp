// Your graph paper code goes below

#include "FPToolkit.c"

int main() {
	int swidth, sheight;
  int n;
  double p[2], q[2];
  double theta, xval, yval;

  //Window size initialization
	swidth = 400;
	sheight = 400;
	G_init_graphics(swidth, sheight); // interactive graphics

  //user input number of segments
  printf("Enter N: ");
  scanf("%d", &n);
	G_rgb(1, 1, 1);
	G_clear();
  G_rgb(0,0,0);

  //Get center point
  G_wait_click(p);
  G_fill_circle(p[0],p[1],2);

  //Get radius distance
  G_wait_click(q);
  G_fill_circle(q[0],q[1],2);

  //Clear screen
  G_rgb(1, 1, 1);
  G_clear();
  
  //show center
  G_rgb(1,0,0);
  G_fill_circle(p[0],p[1],2);

  //get radius distance
  double radius = sqrt(pow(p[0] - q[0], 2) + pow(p[1] - q[1], 2));
  G_rgb(0,0,0);
  // theta = (360 / n) * (M_PI / 180);
  theta = 2*M_PI/n;
    
  xval = (radius * cos(0)) + p[0];
  yval = (radius * sin(0)) + p[1];
  

  double prev_x = xval;
  double prev_y = yval;
  
  for(int i =0; i <= n; ++i){
    // theta = ((360 / n) * i) * (M_PI / 180);
    
    xval = (radius * cos(i*theta)) + p[0];
    yval = (radius * sin(i*theta)) + p[1];

    G_line(xval, yval, prev_x, prev_y);
    prev_x = xval;
    prev_y = yval;
    G_fill_circle(xval, yval, 2);
  }

  

  
  

	int key;
	key = G_wait_key();
}