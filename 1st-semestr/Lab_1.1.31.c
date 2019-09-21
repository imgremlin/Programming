#include <stdio.h>
#include <math.h>
int main() {
	float cut1, cut2, str3, str1, str2, cut3;
	while (1)
    {
      printf ("Input first angle: ");
      scanf ("%f", &cut1);
      printf ("Input second angle: ");
      scanf ("%f", &cut2);
      printf ("Input side:");
      scanf ("%f", &str3);
      if ((cut1 > 0) && (cut1 < 180) && (cut2 > 0) && (cut2 < 180) && (str3 > 0))
		break;
      else printf ("You have to input correct values \n");
    }
    cut3 = 180 - cut1 - cut2;
    str1 = (str3*sin((M_PI*cut1)/180))/sin((M_PI*cut3)/180);
    str2 = (str3*sin((M_PI*cut2)/180))/sin((M_PI*cut3)/180);
    printf("\n");
    printf("First angle: %f \n", cut1);
    printf("Second angle: %f \n", cut2);
    printf("Third angle: %f \n", cut3);
    printf("First side: %f \n", str1);
    printf("Second side: %f \n", str2);
    printf("Third side: %f \n", str3);
	return 0;
}

