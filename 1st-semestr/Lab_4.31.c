#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
int main()
{
  srand(time(NULL));
  int i, j, max, n;
  int choice = 0;
  printf("Input size of matrix: ");
  scanf("%i", &n);
  
  int a[n][n]; 
  
  printf("How do you want to input matrix: \n");
  printf("1 - generate random elements \n");
  printf("2 - enter by keyboard \n");
  	
  while(1)
  {
  	scanf("%i", &choice);
  	if (choice==1)
  	{
  			for (i = 0; i<n; i++)
  			{
    			for (j = 0; j<n; j++) 
    			{
      				a[i][j] = 0 + rand() %100;
    			}
 			}
  		break;
	}
	else if (choice==2)
	{
	    for(i=0; i<n; ++i)
	    {
	       for(j=0; j<n; ++j)
	       {
	    		printf("a[%i][%i] = ", i, j);
	        	scanf("%i", &a[i][j]);
		   }
	    }
			break;
		}
	else printf("Enter correct number: \n");
  }
  

	

  
  
  for (i = 0; i<n; i++)  
  {
    for (j = 0; j<n; j++) 
    {
      printf("%d ", a[i][j]);
    }
    printf("\n"); 
  }
  
  printf("\n");
  
  max = a[0][0];
  
  for (i=0; i<=(n/2)-1; i++)
	{
		for(j=0; j<=i; j++)
		{
			printf("%i ", a[i][j]);
			if (a[i][j] > max)
				max = a[i][j];
			
		}
		printf("\n");	
	}
	
	for (i=n/2; i<=n-1; i++)
	{
		for(j=0; j<=n-1-i; j++)
		{
			printf("%i ", a[i][j]);
			if (a[i][j] > max)
				max = a[i][j];
		}
		printf("\n");
	}
	printf("MAX = ");
	printf("%i", max);
  return 0;
}
