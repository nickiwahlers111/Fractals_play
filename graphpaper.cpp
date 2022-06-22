// Your graph paper code goes below

#include "FPToolkit.c"

int main() {
	int swidth, sheight;

	swidth = 400;
	sheight = 400;
	G_init_graphics(swidth, sheight); // interactive graphics

	G_rgb(0.3, 0.3, 0.3);
	G_clear();

	int n; // n is number of lines
	printf("Type n for nxn\n");
	scanf("%d", &n);

	G_rgb(0, 0.5, 0.5);
	int j = 0;
	// for(int i = 0; i < swidth; i=i+(swidth/(n+1))){
	//   j = swidth - i;
	//   G_line(0, i, j, 0);
	//   G_line(i, 0, 0, j);
	// }

	for (int i = 0; i < swidth; i = i + (swidth / n)) {
		G_line(i, 0, i, sheight); // vertical
		G_line(0, i, swidth, i);  // horizontal
	}

	int key;
	key = G_wait_key();
}
