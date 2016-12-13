#include <stdio.h>

double f2c(double f);

int main()
{
	double fahr, celsius;
	
	scanf("%lf", &fahr);
	printf("%.2lf\n", f2c(fahr));

	return 0;
}

double f2c(double f)
{
	return (5.0/9.0)*(f-32.0);
}
