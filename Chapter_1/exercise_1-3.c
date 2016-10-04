#include <stdio.h>

/*  print Fahrenheit-Celsius table
		for fahr = 0, 20, . . ., 300; floating-point version  */
		
int main()
{
	double fahr, celsius;
	int lower, upper, step;
	
	lower = 0;    /*  lower lmit of temperature table  */
	upper = 300;  /*  upper limit                      */
	step = 20;    /*  step size                        */
	
	printf("Fahr Celsius\n");
	fahr = lower;
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%3.0f   %6.1f\n", fahr, celsius);
		fahr += step;
	}
	
	return 0;
}
