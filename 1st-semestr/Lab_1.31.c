#include <stdio.h>
#include <math.h>
#include <conio.h>
int
main ()
{
  float r, a, b, c;

  while (1)
    {
      printf ("Input a:");
      scanf ("%f", &a);

      printf ("Input b:");
      scanf ("%f", &b);

      printf ("Input c:");
      scanf ("%f", &c);

      if ((a == 0) && (b == 0) && (c == 0))
	    printf ("a, b, c cant be 0 at the same time \n");
      else
    	break;
    }
  r = log(a*a + b*b + c*c) + exp(a+1);
  printf("%f", r);
  return 0;
}
