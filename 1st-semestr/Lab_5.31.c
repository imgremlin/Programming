#include <stdio.h>
#include <stdlib.h>
#include <dos.h>

void swap(int *x,int *y)
{
    int temp;
 
    temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
  srand(time(NULL));
  int i, j, max, n, min, k,maxp, minp, maxi, mini;
  int choice = 0;
  printf("Input size of matrix: ");
  scanf("%i", &n);
  
  int a[n][n]; 
  
  printf("How do you want to input matrix: \n");
  printf("1 - generate random elements \n");
  printf("2 - enter by keyboard \n");
  	
  //choice	
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
  
  //output
  for (i = 0; i<n; i++)  
  {
    for (j = 0; j<n; j++) 
    {
      printf("%d ", a[i][j]);
    }
    printf("\n"); 
  }
  
  printf("\n"); 
  
  
  //sort
  for (i=0; i<n; i++)
 {
  maxp = 0;
  minp = 0;
  for(j=0; j<n; j++)
  {
   if (a[i][j] > a[i][maxp])
   {
    maxp = j;
   }
				
			
   if (a[i][j] < a[i][minp])
   {
    minp = j;
   }
			
   }
			
  
  
  if (minp < maxp)
  {
  	
   
 	for (k = minp; k < n - 1; k++)
    {
        mini = k;
        for (j = k + 1; j < maxp; j++)
        {
            if (a[i][j] < a[i][mini])
            {
                mini = j;
            }
        }
        swap(&a[i][k], &a[i][mini]);
    }
  
  
  
	}	
}
 

 for (i = 0; i<n; i++)  
  {
    for (j = 0; j<n; j++) 
    {
      printf("%d ", a[i][j]);
    }
    printf("\n"); 
  }

  return 0;
}
