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
    G_point(point[0], point[1]);
  }
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
  G_rgb(0, 0, 0);
  G_line(p1[0], p1[1], P[0], P[1]);
  square(p1, P, n - 1);
}

void square_iterative(double p0[], double p1[], double p2[], double p3[])
{
  double x[4];
  double y[4];
  double dx01 = (p1[0] - p0[0]);
  double dy01 = (p1[1] - p0[1]);
  p2[0] = p1[0] - dy01;
  p2[1] = p1[1] + dx01;

  double dx12 = (p2[0] - p1[0]);
  double dy12 = (p2[1] - p1[1]);
  p3[0] = p2[0] - dy12;
  p3[1] = p2[1] + dx12;
  G_rgb(0, 0, 0);
  G_line(p0[0], p0[1], p1[0], p1[1]); // 0-1
  G_line(p1[0], p1[1], p2[0], p2[1]); // 1-2
  G_line(p2[0], p2[1], p3[0], p3[1]); // 2-3
  G_line(p3[0], p3[1], p0[0], p0[1]); // 3-0

  G_rgb(0, 0.5, 0);
  x[0] = p0[0];
  y[0] = p0[1];
  x[1] = p1[0];
  y[1] = p1[1];
  x[2] = p2[0];
  y[2] = p2[1];
  x[3] = p3[0];
  y[3] = p3[1];
  G_fill_polygon(x, y, 4);
  G_wait_key();
}

void triangle(double p0[], double p1[], double pz[])
{
  double x0 = p0[0];
  double y0 = p0[1];
  double x1 = p1[0];
  double y1 = p1[1];

  double dx = x1 - x0;
  double dy = y1 - y0;
  double f = 0.70;
  double g = sqrt(f * (1 - f));

  double x2 = x0 + f * dx;
  double y2 = y0 + f * dy;

  pz[0] = x2 - g * dy;
  pz[1] = y2 + g * dx;

  G_rgb(0, 0, 1);
  G_line(pz[0], pz[1], p0[0], p0[1]);
  G_line(pz[0], pz[1], p1[0], p1[1]);
}

void tree(double p0[], double p1[], int depth)
{

  if (depth == 0)
  {
    return;
  }

  double p2[2];
  double p3[2];
  double pz[2];

  square_iterative(p0, p1, p2, p3);
  triangle(p3, p2, pz);
  // --depth;
  tree(p3, pz, --depth);
  tree(pz, p2, depth);
  return;
}

int main()
{
  int swidth, sheight;
  double p0[2], p1[2];
  int n;
  double p[2], q[2];

  swidth = 400;
  sheight = 400;
  G_init_graphics(600, 600); // interactive graphics

  G_rgb(1, 1, 1);
  G_clear();

  G_rgb(0, 0, 0);

  // Get first point
  G_wait_click(p);
  // Get second point
  G_wait_click(q);
  p0[0] = p[0];
  p0[1] = p[1];
  p1[0] = q[0];
  p1[1] = q[1];
  // First line from p to q
  G_line(p0[0], p0[1], p1[0], p1[1]);

  tree(p0, p1, 5);

  int key;
  key = G_wait_key();
}