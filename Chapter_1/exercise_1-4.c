#include <stdio.h>

int main()
{
	double celsius, fahr;
	int lower, upper, step;
	
	lower = 0;
	upper = 300;
	step = 20;
	
	printf("Celsius  Fahr\n");
	celsius = lower;
	while (celsius <= upper) {
		fahr = (9.0/5.0) * celsius + 32.0;
		printf("%5.0f   %5.1f\n", celsius, fahr);
		celsius += step;
	}
}
