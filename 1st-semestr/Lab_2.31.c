#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	float a, b, c, d, max1, max2, min1, min2;
	
	while(1)
		{
			printf("Input sides of first rectangle: ");
			scanf ("%f", &a);
			scanf ("%f", &b);
			if ((a>0) && (b>0))
				break;
			else printf("Input corect values: ");
		}
		
	while(1)
		{
			printf("Input sides of second rectangle: ");
			scanf ("%f", &c);
			scanf ("%f", &d);
			if ((c>0) && (d>0))
				break;
			else printf("Input corect values: ");
		}
	
	if (a>b)
		{
			max1 = a;
			min1 = b;
		}
		else
			{
				max1 = b;
				min1 = a;
			}
	
	if (c>d)
		{
			max2 = c;
			min2 = d;
		}
		else
			{
				max2 = d;
				min2 = c;
			}
	
	if ( ((max1>=max2) && (min1>=min2)) || ((max1<=max2) && (min1<=min2)) )
		printf("Yes");
	else printf("No");
		
	return 0;
}
