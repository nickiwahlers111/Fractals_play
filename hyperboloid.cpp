// Your graph paper code goes below

#include "FPToolkit.c"

int main() {
	int swidth, sheight;
	double xval, yval, theta;
	double prev_x, prev_y;

	swidth = 400;
	sheight = 400;
	G_init_graphics(swidth, sheight); // interactive graphics

	G_rgb(1, 1, 1);
	G_clear();

	G_rgb(0, 0, 0);

  //TOP ELLIPSE
  theta = (360 / 40) * (M_PI / 180);
	prev_x = (100 * cos(theta)) + 200;
	prev_y = (20 * sin(theta)) + 300;
	for (double i = 0; i < 360; i += 1) {
		theta = ((360 / 40) * i) * (M_PI / 180);

		xval = (100 * cos(theta)) + 200;
		yval = (20 * sin(theta)) + 300;

		G_line(xval, yval, prev_x, prev_y);
		prev_x = xval;
		prev_y = yval;
	}

  //BOTTOM ELLIPSE
  theta = (360 / 40) * (M_PI / 180);
	prev_x = (100 * cos(theta)) + 200;
	prev_y = (20 * sin(theta)) + 100;
  
	for (int i = 0; i < 360; i += 1) {
		theta = ((360 / 40) * i) * (M_PI / 180);

		xval = (100 * cos(theta)) + 200;
		yval = (20 * sin(theta)) + 100;
  
		G_line(xval, yval, prev_x, prev_y);
		prev_x = xval;
		prev_y = yval;
	}

  double ux[6];
  double uy[6];
  double lx[6];
  double ly[6];
  //POINTS
  //UPPER
  for(int i =0; i <= 6; ++i){
    theta = ((360 / 6) * i) * (M_PI / 180);
    
    xval = (100 * cos(theta)) + 200;
    yval = (20 * sin(theta)) + 300;

    prev_x = xval;
    prev_y = yval;
    ux[i] = xval;
    uy[i] = yval;
    G_fill_circle(xval, yval, 2);
  }

  //LOWER POINTS
  for(int i =0; i <= 6; ++i){
    theta = ((360 / 6) * i) * (M_PI / 180);
    
    xval = (100 * cos(theta)) + 200;
    yval = (20 * sin(theta)) + 100;
    lx[i] = xval;
    ly[i] = yval;
    prev_x = xval;
    prev_y = yval;
    G_fill_circle(xval, yval, 2);
  }

  for(int i = 0; i <= 6; ++i){
      G_rgb(0,0,0);
      G_line(ux[i], uy[i], lx[i], ly[i]);
  }
  

  

  

  

	int key;
	key = G_wait_key();
}