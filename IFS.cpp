#include "FPToolkit.c"

// appropriate for a 600x600 window
// double x[13] = {263,338,338,450,338,338,375,300,225,263,263,150,263} ;
// double y[13] = {450,450,375,338,338,300,150,263,150,300,338,338,375} ;
double x[1] = {0.0};
double y[1] = {0.0};
int n = 1 ;
double width = 701, height = 701;


void translate (double dx, double dy)
{
  int i ;

  i = 0 ;
  while (i < n) {
    x[i] = x[i] + dx ;
    y[i] = y[i] + dy ;
    i = i + 1 ;
  }
}

void scale (double sx, double sy){
  
  for(int i = 0; i < n; ++i){
    x[i] *= sx;
    y[i] *= sy;
  }
}


void rotate(double deg){
  double r, a;
  double t = deg * (M_PI / 180);
  double temp;
  double c, s;
  c = cos(t);
  s = sin(t);
  
  for(int i = 0; i < n; ++i){
    temp = (x[i]* c) - (y[i] * s);
    y[i] = (y[i] * c) + (x[i] * s);
    x[i] = temp;
  }
}

void diagonal_line(double r ){
  if(r < 0.5){
    scale(0.5, 0.5);
  }
  else{
    scale(0.5, 0.5);
    translate(0.5, 0.5);
  }
}

void fill_triangle(double r){
  if(r < 0.25){
    scale(0.5,0.5);
  }
  else if(r < 0.5 && r>0.25){
    scale(0.5, 0.5);
    translate(0.5, 0);
  }
  else if(r < 0.75 && r > 0.5){
    scale(0.5, 0.5);
    translate(0, 0.5);
  }
  else{
    scale(0.5, 0.5);
    rotate(180);
    translate(0.5, 0.5);
  }
}

void sierpinsky(double r){
  if(r < 0.33){
    scale(0.5,0.5);
  }
  else if( r < 0.66){
    scale(0.5, 0.5);
    translate(0.5, 0);
  }
  else{
    scale(0.5, 0.5);
    translate(0, 0.5);
  }
}

void triangle_2(double r){
  if(r < 0.5){
    scale(sqrt(2) / 2,sqrt(2) / 2);
    rotate(135);
    translate(0.5, 0.5);
  }
  else{
    scale(sqrt(2) / 2,sqrt(2) / 2);
    rotate(225);
    translate(0.5, 0.5);
  }
}

void TTT(double r){
  scale(1.0/3, 1.0/3);

  if(r< 1.0/9){
 
  }
  else if(r <2.0/9){ //2
    
    translate(1.0/3, 0);
  }
  else if(r < 3.0 /9){ //3
  
    translate(2.0/3, 0);
  }
  else if(r < 4.0 /9){ //4
    translate(0, 1.0/3);
  }
  else if(r < 5.0 /9){ //5
  
  }
  else if(r < 6.0 /9){ //6
    translate(2.0/3, 1.0/3);
  }
  else if(r < 7.0 /9){ //7
    translate(0, 2.0/3);
  }
  else if(r < 8.0 /9){ //8
    translate(1.0/3, 2.0/3);
  }
  else { //9
    translate(2.0/3, 2.0/3);
  }
  
}

void koch(double r){
  if(r <0.25){
    scale(1.0/3, 1.0/3);
  }
  else if(r < 0.5){
    scale(1.0/3, 1.0/3);
    rotate(60);
    translate(1.0 / 3, 0);
    
  }
  else if (r < 0.75){
   scale(1.0/3, 1.0/3);
    rotate(300);
    translate(1.0/2, sqrt(3)/6);
  }
  else{
    scale(1.0/3, 1.0/3);
    translate(2.0/3, 0);
  }
}

void trek(double r){
  
  if(r < 0.333){
    translate(0, -.5);
    scale(.5, .5);
    translate(0, 0.5);
  G_rgb(1,0,0);
  }
  else if(r < 0.666){
    translate(0, -.5);
    scale(.5, .5);
    rotate(90);
    translate(0.5, 0.5);
      G_rgb(0,1,0);
  }
  else{
   translate(0, -.5);
    scale(.5, .5);
    rotate(270);
    translate(0.5, 0.5);
      G_rgb(0,0,1);
  }
}

void initials(double r){
  //1   N 
  if(r < 1.0 /11){
    scale(.25, 2.0/6); //shrink her down
    rotate(90); //rotate 
    translate(4.0/36, 1.0/8); //translate her up to where she needs to go
    G_rgb(1,0,0); //RED
  }
  //2  N 
  else if(r < 2.0 /11){
    scale(.1, 1.0/6); 
    rotate(135);
    translate(6.0/36, 4.0/16);
    G_rgb(1, .75, .79); //PINK
    // G_rgb(0,0,0);
  }
  //3 N
  else if(r < 3.0 /11){
    scale(.25, 2.0/6); //shrink her down
    rotate(90); //rotate 
    translate(10.0/36, 1.0/8);
    G_rgb(0.5,0,0); //MAROON
  }
 
    
  //4 M
  else if(r < 4.0 /11){
    scale(.25, 2.0/6); 
    rotate(90);
    translate(14.0/36, 1.0/8);
    G_rgb(0,1,0); //GREEN
  }
  //5  M
  else if(r < 5.0 /11){
    scale(1.0/9, 0.25);
    rotate(115);
    translate(17.0/36, 4.0/16);
    G_rgb(0, .5, 0.5); //TEAL
  }
  //6  M
  else if(r < 6.0 /11){
    scale(1.0/9, 0.25);
    rotate(60);
    translate(19.0/36, 7.0/32);
    G_rgb(.14, 0.5, 0.14); //DARK GREEN
    
  }
  //7  M
  else if(r < 7.0 /11){
    scale(.25, 2.0/6); 
    rotate(90);
    translate(24.0/36, 1.0/8);
    G_rgb(.24, .7, .44); //Green
  }
  
    
    //8  W
  else if(r < 8.0 /11){
    scale(.25, 2.0/6); 
    rotate(90);
    translate(28.0/36, 1.0/8);
    G_rgb(0,0,1); //BLUE
  }
  //9  W
  else if(r < 9.0 /11){
    scale(1.0/9, 0.25);
    rotate(60);
    translate(29.0/36, 1.0/8);
    G_rgb(0, 0.74, 0.5); // light blue
    
  }
  //10  W
  else if(r < 10.0 /11){
    scale(1.0/9, 0.25);
    rotate(115);
    translate(34.0/36, 3.0/16);
    G_rgb(0.25, 0.41, 1); //royal blue
  }
  //11  W
  else{
    scale(.25, 2.0/6); 
    rotate(90);
    translate(37.0/36, 1.0/8);
    G_rgb(0.61, 0.19, 0.88); //purple
  }
}

void fern(double r){
  if(r < 0.25){ //purple
    translate(-0.5, 0);
    
    rotate(14.715);
    scale(0, 0.156);
   
    translate(0,0);
    translate(0.5, 0);
  }
  else if(r < 0.5){ //green
    translate(-0.5, 0);

    rotate(-2.678);
    scale(0.849, 0.849);
    translate(0, 0.160);
    
    translate(0.5, 0);
  }
  else if(r < 0.75){ //yellow
    translate(-0.5, 0);

    rotate(52.462);
    scale(-0.383, 0.383);
    translate(0, 0.040);
    
    translate(0.5, 0);
  }
  else{ //red
    translate(-0.5, 0);

    rotate(51.418);
    scale(0.335, 0.335);
    translate(0, 0.160);
    translate(0.5, 0);
  }
}

void mio(double r){
  if(r < 1.0 /9){
    scale(2.0/12, 2.0/24);
    rotate(30);
    translate(4.0/12, 19.0/24);
    G_rgb(1,0,0); //RED

  }
  else if(r < 2.0 / 9){
    scale(2.0/12, 2.0/24);
    rotate(330);
    translate(6.5/12, 21.0/24);
    G_rgb(1, .75, .79); //PINK
  }
  else if(r < 3.0 / 9){
    scale(3.0/12, 10.0/24);
    rotate(270);
    translate(3.5/12, 21.0/24);
    G_rgb(0.5,0,0); //MAROON
  }
  else if(r < 4.0 / 9){
    scale(2.0/12, 5.0/24);
    rotate(270);
    translate(5.0/12, 17.0/24); 
    G_rgb(0,1,0); //GREEN
  }
  else if(r < 5.0 / 9){
    scale(3.0/12, 10.0/24);
    rotate(270);
    translate(3.5/12, 15.0/24);
    G_rgb(0,0,1); //BLUE
  }
  else if(r < 6.0 / 9){
    scale(2.0/12, 3.0/24);
    rotate(165);
    translate(7.50/12, 10.5/24); 
    G_rgb(0, .5, 0.5); //TEAL
  }
  else if(r < 7.0 / 9){
    scale(3.0/12, 10.0/24);
    rotate(270);
    translate(7.0/24, 10.0/24); 
    G_rgb(0, 0.74, 0.5); // mint
  }
  else if(r < 8.0 / 9){
    scale(2.0/12, 4.0/24);
    rotate(150);
    translate(6.5/12, 5.0/24); 
    G_rgb(.14, 0.5, 0.14); //DARK GREEN
  }
  else{
    scale(2.0/12, 4.0/24);
    rotate(45);
    translate(15.0/24, 0.9/24 ); 
    G_rgb(0.61, 0.19, 0.88); //purple
  }
  
}


int main() 
{
  int q ;

  G_init_graphics(width, height) ;
  G_rgb(0,0,0) ;
  G_clear() ;
  srand48(200);
  G_rgb(1,1,1);
  G_fill_rectangle(2,2,width-4, height-4);
  G_rgb(1,0,0);
  
  double r;
  
  for (int i = 0; i < 500000000; ++i){
    r = drand48();
    // diagonal_line(r);
    // fill_triangle(r);
    // sierpinsky(r);
    // triangle_2(r);
    // TTT(r);
    // koch(r);
    // trek(r);
    // initials(r);
    // fern(r); 

    mio(r);
    G_rgb(0,0,0);
    G_point(x[0]* width, y[0]* width);
    // G_rgb(r,r*2,r);
    if(i % 1000 == 0){
    
    G_display_image();
    usleep(1000);
      }
    }
  //draw a red square of some kind here
  
  
  q = G_wait_key() ;
  
  
}

