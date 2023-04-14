#include "FPToolkit.c"

void my_line(double p[], double q[])
{
  double point[2];
  G_rgb(0, 0, 0);
  for (double i = 0; i < 1; i += 0.001)
  {
    point[0] = p[0] + (i * (q[0] - p[0]));
    point[1] = p[1] + (i * (q[1] - p[1]));
    G_rgb(i, i, i);
  }
}

void ta_line(double p[], double q[])
{
  double point[2];
  G_rgb(1, 0, 0);

  for (double i = 0; i < 1; i += 0.001)
  {
    point[0] = p[0] + (q[0] - p[0]) * i;
    point[1] = p[1] + (q[1] - p[1]) * i;
    G_point(point[0], point[1]);
  }
}

void pythagorean_method(double p0[], double p1[], int n)
{
  if (n == 1)
  {
    return;
  }
  double P[2];
  double dx = (p1[0] - p0[0]);
  double dy = (p1[1] - p0[1]);
  P[0] = p1[0] - dy;
  P[1] = p1[1] + dx;
  G_fill_circle(P[0], P[1], 2);

  // G_fill_circle(P[0], P[1], 2);
  // G_line(p1[0], p1[1], P[0], P[1]);
  ta_line (p1, P);
 

  pythagorean_method(p1, P, n - 1);
}

int main()
{
  int swidth, sheight;

  swidth = 400;
  sheight = 400;
  G_init_graphics(swidth, sheight); // interactive graphics

  G_rgb(1, 1, 1);
  G_clear();
  G_rgb(1, 0, 0);
  double p[2], q[2];
  G_wait_click(p);
  G_fill_circle(p[0], p[1], 2);

  G_wait_click(q);
  G_fill_circle(q[0], q[1], 2);
  // my_line(p, q);
  // ta_line(p, q); // ref: point_on_line.cpp

  pythagorean_method(p, q, 4); // TO MAKE A SQUARE, ref: square_spiral.cpp

  int key;
  key = G_wait_key();
}
