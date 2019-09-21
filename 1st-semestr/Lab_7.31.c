#include <stdio.h>
#include <string.h>
#include <ctype.h>

int controll(int n, char str[10][100], int(*pf)(int, int))
{
  int i, j, len;
    int count = 0;
    int k = 0;
    int result;
  printf("How many words do you want to sort: ");
    scanf("%i", &n);
    char temp[100], c;

    printf("Enter your words:\n");

    for(i=0; i<n; i++)
        scanf("%s",str[i]);
    
    result = pf(5, str);
    return result;
}

int bigleletters(int n, char str[10][100])
{
  	int i, j, len;
    int count = 0;
    int k = 0;
    char c;
    for(i=0; i<n; i++)
    {  
      len = strlen(str[i]);
      for(j=0; j<len; j++)
    {
      c = str[i][j];
      count+=isupper(c);
    }
    
    if ((count!=0)&&(count==len))
      k++;
      
    count = 0;
  }
  return k;
}

int dbleletters(int n, char str[10][100])
{
  int i, j, len;
    int count = 0;
    int k = 0;
    for(i=0; i<n; i++)
    {  
      len = strlen(str[i]);
      
      for(j=0; j<len-1; j++)
      if(toupper(str[i][j])==toupper(str[i][j+1]))
        count++;
        
    if (count>0)
      k++;
    
    count = 0;  
  }
  return k;
}

int main()
{
  char str[10][100];
     int choice, l,n, x;
    printf("Choose the function: \n");
  printf("1 - Double letters \n");
  printf("2 - Big letters \n");
        
  while(1)
  {
    scanf("%i", &choice);
      if (choice==1)
      {
        x = controll(5, str, dbleletters);
        printf("%i", x); 
        break;
    }
    else if (choice==2)
    {
      	x = controll(5, str, bigleletters);
        printf("%i", x); 
        break;
      }
  }
    
      
    return 0;
}
