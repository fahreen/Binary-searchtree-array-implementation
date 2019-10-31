#include <stdio.h>
#include <stdlib.h>



int main(void) {

	/*Decralre variables*/
	double e,temp=0.0, value=0.0, four = 4.0, two = 2.0, one = 1.0, neg_one = -1.0 ;
	long long n = 1;
	
	/* ask user for small precision */
	printf("Please enter a double precision  number ξ :");   
	scanf("%lf", &e); 

	/* calculate pi */
	while (1)
	{
		temp =(four/((two*n)-one));

		/*account for negative or positive*/
		if (n%2 == 0)
			temp =( temp * (neg_one));
		value = value +temp;
		if ((four/ (two*(n+one)-one)) <  e)
                	break;

		n++;
	}
	
	printf ("π  =  %lf", value);
}
