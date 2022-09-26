#include "FPToolkit.c"

int main()
{
  int i ;
  char fname[100] ;
  char base[100] ;
  int start, end ;
  
  printf("enter base name ") ;
  scanf("%s",base) ;

  printf("enter starting frame number ") ;
  scanf("%d",&start) ;

  printf("enter ending frame number ") ;
  scanf("%d",&end) ;  
  // strcat(base, start);
  
  G_init_graphics(600,600) ;

  for (i = start ; i <= end ; i++) {
    sprintf(fname, "%s%04d.bmp",base,start+i) ;
    printf("faame = .%s.\n",fname) ;
    G_display_bmp_file(fname,0,0) ;
    G_wait_key() ;
  }

  while (G_wait_key() != 'q') ;
}
