#include "FPToolkit.c"
#include <complex.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int Wsize = 600;

void print_complex(complex z) {
	printf("%lf + %lfi\n", creal(z), cimag(z));
}

void mandelbrot(
	double rcen,
	double icen,
	double radius,
	double cutoff,
	double mlimit) {
	int xp, yp;  // points to plot. 600x600 plane
	double x, y; // corresponding points in complex plane
	complex z;   // z to check for convergence
	complex c;   // complex number

	for (yp = 0; yp < Wsize; yp++) {
		for (xp = 0; xp < Wsize; xp++) {
			x = (((xp - 300) / 300.0) * radius) + rcen;
			y = (((yp - 300) / 300.0) * radius) + icen;
			c = x + y * I;
			z = 0;
			for (int i = 0; i < mlimit; ++i) {
				z = cpow(z, 2) + c;
			}
			if (cabs(z) > cutoff) { // going to infinity
				G_rgb(0, 0, 0);		/// black
			} else {				// converging or ping ponging
				G_rgb(0, 0, 1);		// blue
			}
			G_point(xp, yp);
			// G_fill_circle(xp, yp, 1);
		}
	}
}

void julia(
	double rcen,
	double icen,
	double radius,
	double cutoff,
	double mlimit) {
	int xp, yp;  // points to plot. 600x600 plane
	double x, y; // corresponding points in complex plane
	complex z;   // z to check for convergence
	complex c;   // complex number

	for (yp = 0; yp < Wsize; yp++) {
		for (xp = 0; xp < Wsize; xp++) {
			x = (((xp - 300) / 300.0) * radius) + rcen;
			y = (((yp - 300) / 300.0) * radius) + icen;

			c = -0.8 + 0.156 * I;
			z = x + y * I;
			for (int i = 0; i < mlimit; ++i) {
				z = cpow(z, 2) + c;
			}
			if (cabs(z) > cutoff) {				 // going to infinity
				G_rgb(0, 0, 0);					 /// black
			} else if (cabs(z) > cutoff / 3.0) { // converging or ping ponging
				G_rgb(1, 0.41, 0.7);			 // pink

			} else if (cabs(z) > cutoff / 2.0) { // converging or ping ponging
				G_rgb(0, 1, 0);					 // green
			}

			else if (cabs(z) > cutoff / 4.0) { // converging or ping ponging
				G_rgb(1, 0.07, 0.57);		   // orange
			}

			else {
				G_rgb(0, 0.75, 1);
			}
			G_point(xp, yp);
			// G_fill_circle(xp, yp, 1);
		}
	}
}

int main() {
	G_init_graphics(Wsize, Wsize); // interactive graphics
	G_rgb(0, 0, 0);
	G_clear();

	double cutoff = 2;
	double mlimit = 256;

	// go across bottom -2 to 2
	// go up -2 to 2

	// double rcen = 0.35;
	// double icen = 0.1;
	// double radius = 0.25;
	double rcen = 0;
	double icen = 0;
	double radius = 1.5;

	// mandelbrot(rcen, icen, radius,  cutoff, mlimit);
	julia(rcen, icen, radius, cutoff, mlimit);
	double p[2], q[2];

	for (int i = 0; i < 3; ++i) {
		G_wait_click(p); // center point
		G_wait_click(q); // determine radius

		double x0 = (((p[0] - 300) / 300.0) * radius) + rcen;
		double y0 = (((p[1] - 300) / 300.0) * radius) + icen;

		double x1 = (((q[0] - 300) / 300.0) * radius) + rcen;
		double y1 = (((q[1] - 300) / 300.0) * radius) + icen;

		rcen = x0;
		icen = y0;

		double dx = x1 - x0;
		double dy = y1 - y0;
		radius = sqrt(pow(dx, 2) + pow(dy, 2));

		mlimit -= 50;
		julia(rcen, icen, radius, cutoff, mlimit);
		// mandelbrot(rcen, icen, radius,  cutoff, mlimit);
	}

	int key;
	key = G_wait_key();
}