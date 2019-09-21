#include <stdio.h>
#include <stdlib.h>
int main() {
	float s, sum, i ,j;
	sum = 0;
	for (i = 1; i<100; i++){
		for (j=i; j<100; j++){
			s = 0;
			s = (j-i+1)/(i+j);
		}
		printf("%f \n", s);
		sum+=s;
	}
	printf("%f", sum);
	return 0;
}

