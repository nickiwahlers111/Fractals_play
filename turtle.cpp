#include "FPToolkit.c"

char u[10000000];
char temp[10000000];
char s[10];
char w[10][1000];
int n = 0; // number of rules in Grammar

void function(int depth) {
	if (depth == 0) {
		return;
	}
	bool flag = false;
	temp[0] = '\0';
	char dumb[2];
	for (int i = 0; i < strlen(u); ++i) {	 // GO THROUGH U
		for (int j = 0; j < strlen(s); ++j) { // GO THROUGH AND COMPARE WITH S
			if (u[i] == s[j]) {
				strcat(temp, w[j]);
				flag = true;
				break;
			} else {
				flag = false;
			}
		}
		if (flag == false) {
			dumb[0] = u[i];
			dumb[1] = '\0';
			strcat(temp, dumb);
		}
	}
	strcpy(u, temp);
	function(depth - 1);
}

void color(int i) {
	switch (i % 3) {
	case 0: // RED
		G_rgb(1, 0, 0);
		break;
	case 1: // GREEN
		G_rgb(0, 0.5, 0.15);
		break;
	case 2: // ORANGE
		G_rgb(1, 0.84, 0);
		break;
	case 3: // YELLOW
		G_rgb(1, 1, 0);
		break;
	defaut:
		break;
	}
}

int main() {
	int swidth, sheight;

	double deg = 60;
	double unit = 10;

	double turtle[2];
	double potential[2];
	double hold[2];
	double x, y;
	bool flag = false;

	swidth = 600;
	sheight = 600;
	// double init = swidth /2;
	double initx = 100;
	double inity =100;

	// GET GRAMMAR
	printf("Enter Axiom: ");
	scanf("%s", u);
	printf("Enter how many rules: ");
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		printf("Rule # %d ", i);
		printf("Letter to replace: ");
		scanf("%s", &s[i]);
		printf("\nReplace with: ");
		scanf("%s", &w[i][0]);
	}

	function(5);

	G_init_graphics(swidth, sheight); // interactive graphics

	G_rgb(0, 0, 0);
	G_clear();
	// INITIALIZE TURTLE
	turtle[0] = initx;
	turtle[1] = inity;
	potential[0] = turtle[0] + unit;
	potential[1] = turtle[1];

	// COLOR OF TURTLE!!
	G_rgb(0, 1, 0);
	G_fill_circle(turtle[0], turtle[1], 1);
	G_wait_key();

	// LETS START MOVING
	double c, s;

	double theta;
	double temp;
	theta = deg * M_PI / 180;
	c = cos(theta);
	s = sin(theta);
	
		for (int i = 0; i < strlen(u); ++i) {
			color(i);
			if (u[i] == '+') { //+

				potential[0] = potential[0] - turtle[0];
				potential[1] = potential[1] - turtle[1];

				hold[0] = (potential[0] * c - potential[1] * s);
				hold[1] = (potential[0] * s + potential[1] * c);

				potential[0] = hold[0] + turtle[0];
				potential[1] = hold[1] + turtle[1];
			} else if (u[i] == '-') { //+

				potential[0] = potential[0] - turtle[0];
				potential[1] = potential[1] - turtle[1];

				hold[0] = (potential[0] * c) + (potential[1] * s);
				hold[1] = -(potential[0] * s) + (potential[1] * c);

				potential[0] = hold[0] + turtle[0];
				potential[1] = hold[1] + turtle[1];
			}

			else if (u[i] <= 'Z' && u[i] >= 'A') { // uppercase letter
				// G_wait_key();

				G_line(turtle[0], turtle[1], potential[0], potential[1]);
				hold[0] = potential[0] - turtle[0];
				hold[1] = potential[1] - turtle[1];

				turtle[0] = potential[0];
				turtle[1] = potential[1];

				potential[0] += hold[0];
				potential[1] += hold[1];

				G_fill_circle(turtle[0], turtle[1], 1);
			} else {
				continue;
			}
		}
 

	int key;
	key = G_wait_key();
}