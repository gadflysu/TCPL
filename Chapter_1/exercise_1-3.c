#include <stdio.h>

int main()
{
	double fahr, celsius;
	int lower, upper, step;
	
	lower = 0;
	upper = 300;
	step = 20;
	
	printf(" fahr  celsius\n");
	fahr = lower;
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%5.0f %8.1f\n", fahr, celsius);
		fahr += step;
	}
	
	return 0;
}
