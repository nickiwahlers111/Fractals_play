#include "FPToolkit.c"

double p[2], q[2];
double t[2], z[2];
int Wsize = 600;

void koch(int depth, double p0[], double p1[])
{
	if (depth == 0)
	{
		G_line(p0[0], p0[1], p1[0], p1[1]);
		return;
	}

	double dx = p1[0] - p0[0];	// x distance between original points
	double dy = p1[1] - p0[1];	// y distance between original points
	double t0[2], t1[2], t2[2]; // 1/3 and 2/3 and midpoint
	double z[2];								// the top point

	double f = 0.5; // half

	t0[0] = p0[0] + (1.0 / 3) * dx; // 1/3 point x
	t0[1] = p0[1] + (1.0 / 3) * dy; // 1/3 point y val

	t1[0] = p1[0] - (1.0 / 3) * dx; // 2/3 point x
	t1[1] = p1[1] - (1.0 / 3) * dy; // 2/3 point y

	t2[0] = p1[0] - (1.0 / 2) * dx;
	t2[1] = p1[1] - (1.0 / 2) * dy; // midpoint

	f = sqrt(3) / 6;
	z[0] = t2[0] - (f * dy);
	z[1] = t2[1] + (f * dx);

	koch(depth - 1, p0, t0);
	koch(depth - 1, t0, z);
	koch(depth - 1, z, t1);
	koch(depth - 1, t1, p1);
};

void translate(double dx, double dy)
{
	p[0] = p[0] + dx;
	p[1] = p[1] + dy;

	q[0] = q[0] + dx;
	q[1] = q[1] + dy;

	z[0] = z[0] + dx;
	z[1] = z[1] + dy;
}

void rotate(double deg)
{
	double r, a;
	double t = deg * (M_PI / 180);
	double temp;
	double c, s;
	c = cos(t);
	s = sin(t);

	temp = (p[0] * c) - (p[1] * s);
	p[1] = (p[1] * c) + (p[0] * s);
	p[0] = temp;

	temp = (q[0] * c) - (q[1] * s);
	q[1] = (q[1] * c) + (q[0] * s);
	q[0] = temp;

	temp = (z[0] * c) - (z[1] * s);
	z[1] = (z[1] * c) + (z[0] * s);
	z[0] = temp;
}

void scale(double s)
{
	p[0] *= s;
	p[1] *= s;
	q[0] *= s;
	q[1] *= s;
	z[0] *= s;
	z[1] *= s;
}

int main()
{
	G_init_graphics(Wsize, Wsize); // interactive graphics
	G_rgb(0, 0, 0);
	G_clear();

	p[0] = 100;
	p[1] = 150;
	q[0] = 500;
	q[1] = 150;

	double dx = q[0] - p[0];
	double dy = q[1] - p[1];

	t[0] = p[0] + 0.5 * dx;
	t[1] = p[1] + 0.5 * dy;
	double f = sqrt(3) / 2;
	z[0] = t[0] - f * dy;
	z[1] = t[1] + f * dx;

	G_rgb(0, 0, 0);
	G_clear();

	// for (int i = 0; i < 100; ++i) {
	// 	translate(-Wsize / 2, -Wsize / 2);
	// 	scale(0.95);
	// 	rotate(2 * i);
	// 	translate(Wsize / 2, Wsize / 2);

	// 	G_rgb(0.53, 0.8, 0.98);

	// 	koch(5, q, p);
	// 	koch(5, z, q);
	// 	koch(5, p, z);

	// 	G_wait_key();
	// 	G_rgb(0, 0, 0);
	// 	G_clear();
	// }
	G_rgb(0.53, 0.8, 0.98);
	koch(3, p, q);

	int key;
	key = G_wait_key();
}