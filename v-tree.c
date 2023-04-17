#include "FPToolkit.c"

void midpoint(double p[], double q[], double m[])
{
  double x0, y0, x1, y1;
  x0 = p[0];
  y0 = p[1];
  x1 = q[0];
  y1 = q[1];

  m[0] = x0 + ((1 / 2.0) * (x1 - x0));
  m[1] = y0 + ((1 / 2.0) * (y1 - y0));
}

void square(double p0[], double p1[], int n)
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

  // G_fill_circle(P[0], P[1], 2);
  G_line(p1[0], p1[1], P[0], P[1]);

  square(p1, P, n - 1);
}

void v_tree(double a[], double b[], double c[], int depth)
{
  if (depth == 0)
  {
    return;
  }
  double m1[2], m2[2];
  midpoint(a, b, m1);
  midpoint(b, c, m2);

  square(a, m1, 4);
  square(m2, c, 4);
}

int main()
{
  int swidth, sheight;

  swidth = 600;
  sheight = 400;
  G_init_graphics(swidth, sheight); // interactive graphics

  G_rgb(1, 1, 1);
  G_clear();

  double p[2], a[2];
  p[0] = 300;
  p[1] = 10;
  a[0] = 490;
  a[1] = 200;
  G_rgb(0, 0, 0);
  // First line from p to q
  G_line(p[0], p[1], a[0], a[1]);

  square(p, a, b, c 4);

  v_tree(, 1);

  int key;
  key = G_wait_key();
}