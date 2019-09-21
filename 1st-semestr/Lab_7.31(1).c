#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int i, j, n, len;
    int count = 0;
    int k = 0;

    printf("How many words do you want to sort: ");
    scanf("%i", &n);
    char str[n][100], temp[100], c;

    printf("Enter your words:\n");

    for(i=0; i<n; i++)
        scanf("%s",str[i]);

    for(i=0; i<n; i++)
    {	
    	len = strlen(str[i]);
    	
    	for(j=0; j<len; j++)
		{
			c = str[i][j];
			count+=isupper(c);
		}
		
		if (count==len)
			k++;
			
		count = 0;
	}
	
	printf("Total amount of words = %i", k);	
			
    return 0;
}
