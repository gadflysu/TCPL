#include <stdio.h>

double celsius(double fahr);

/*  print Celsius-Fahrenheit table
    for celsius = 0, 20, . . ., 300; floating-point version  */
int main()
{
	double fahr;
	int lower, upper, step;
	
	lower = 0;    /*  lower lmit of temperature table  */
	upper = 300;  /*  upper limit                      */
	step = 20;    /*  step size                        */

	fahr = lower;
	while (fahr <= upper) {
		printf("%3.0f %6.1f\n", fahr, celsius(fahr));
		fahr += step;
	}

	return 0;
}

/*  celsius: convert fahr into celsius	*/
double celsius(double f)
{
	return (5.0/9.0)*(f-32.0);
}
