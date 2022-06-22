#include "FPToolkit.c"

int main() {
	int swidth, sheight;

	swidth = 400;
	sheight = 400;
	G_init_graphics(swidth, sheight); // interactive graphics

  G_fill_circle (10, 10, 2) ;
  G_fill_circle(swidth-10, 10, 2);

  
	

	int key;
	key = G_wait_key();
}