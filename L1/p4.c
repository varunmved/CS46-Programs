//Varun Ved
//arrow

#include <stdio.h>

int main()
{
	int arrowLength =0;
	printf("How long of an arrow? ");
	scanf("%d",arrowLength);
	printf("\n");

	for(int i =1; i < arrowLength; i++)
	{
		printf("-");
	}
	printf(">");
}