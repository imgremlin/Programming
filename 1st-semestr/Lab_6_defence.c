#include <stdio.h>
#include <string.h>

int main()
{
    int i, j, n;
    printf("How many words do you want to sort: ");
    scanf("%i", &n);
    char str[10][100], temp[100];

    printf("Enter your words:\n");

    for(i=0; i<n; i++)
        scanf("%s",str[i]);

    for(i=0; i<n-1; i++)
        for(j=i+1; j<n ; j++)
        {
            if(strcmp(str[i], str[j])>0)
            {
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
	printf("\n");
    printf("In lexicographical order: \n");
    for(i=0; i<n; ++i)
    {
        puts(str[i]);
    }

    return 0;
}
