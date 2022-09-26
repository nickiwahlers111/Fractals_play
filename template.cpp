#include "FPToolkit.c"

int main() {
	int swidth, sheight;

	swidth = 400;
	sheight = 400;
	G_init_graphics(swidth, sheight); // interactive graphics

	G_rgb(1, 1, 1);
	G_clear();

	int key;
	key = G_wait_key();
}