#include "FPToolkit.c"

int main() {
	int swidth, sheight, j;

	swidth = 400;
	sheight = 400;
	G_init_graphics(swidth, sheight); // interactive graphics

	G_rgb(0.3, 0.3, 0.3);
	G_clear();

	int n; // n is number of lines
	printf("Type n for nxn\n");
	scanf("%d", &n);


  G_rgb(0,0,0);
  int half = swidth /2;
  G_line(half, 0, half, sheight);
  G_line(0, half, swidth, half);
	G_rgb(0, 0.5, 0.5);
  
  //UPPER RIGHT
  j = 0;
  for(int i = half; i < swidth; i = i + (swidth /(n+1))){
    j = swidth -i/2;
    G_line(half, i, j, half);
  }

  //UPPER LEFT

  //BOTTOM LEFT
  j = 0;
  for(int i = half; i < swidth; i = i + (swidth /(n+1))){
    j = swidth -i/2;
    G_line(half, i, j, half);
  }
  //BOTTOM RIGHT
  

  //BIG BOY
	 j = 0;
	for(int i = 0; i < sheight; i=i+(sheight/(n+1))){
	  j = swidth - i;
	  G_line(0, i, j, 0);
	  // G_line(i, 0, 0, j);
	}

 //  j = 0;
 //  for(int i =swidth; i > 0; i = i - (swidth /(n+1)) ){
 //    j = sheight - i;
 //    G_line(swidth - i, sheight, swidth, sheight-j);
 //  }



  //GRAPH PAPER
	// for (int i = 0; i < swidth; i = i + (swidth / n)) {
	// 	G_line(i, 0, i, sheight); // vertical
	// 	G_line(0, i, swidth, i);  // horizontal
	// }

	int key;
	key = G_wait_key();
}