//Varun Ved
//p3 package

#include <stdio.h>

int main()
{
	double l = 0;
	double h = 0;
	double w = 0;

	printf("Enter the length, width, and height of a package: ");
	scanf("%lf %lf %lf",&l,&w,&h);
	
	double result = (l + 2*h + 2*w);
	printf("%lf\n", result);
	if(result> 84) printf("oversize");
		else printf ("regular");
	
}