#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
	
	char sent[100], *pw, delim[]=" ";
	int k;
	
	printf("Input sentence: ");
	gets(sent);
	pw = strtok(sent, delim);
	
	printf("%s ", pw);
	pw = strtok(NULL, delim);
	
	do{
		char i = strchr(pw, ',');
		if (isupper(*pw))
		{
			printf("***");
			if (i!=0) printf(",");
			printf(" ");
		}
			
			
		else{
			
			printf("%s", pw);
			printf(" ");
			
		}
		pw = strtok(NULL, delim);
	}while(pw != NULL);
	
	return 0;
}
