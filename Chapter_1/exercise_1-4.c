#include <stdio.h>

/*  print Celsius-Fahrenheit table
    for celsius = 0, 20, . . ., 300; floating-point version  */

int main()
{
	double celsius, fahr;
	int lower, upper, step;

	lower = 0;    /*  lower lmit of temperature table  */
	upper = 300;  /*  upper limit                      */
	step = 20;    /*  step size                        */
	
	printf("Celsius Fahr\n");
	celsius = lower;
	while (celsius <= upper) {
		fahr = (9.0/5.0) * celsius + 32.0;
		printf("%3.0f   %6.1f\n", celsius, fahr);
		celsius += step;
	}
}
