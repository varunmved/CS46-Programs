//Varun Ved
//arrow

#include <stdio.h>

int main()
{
	int arrowLength =0;
	printf("How long of an arrow? ");
	scanf("%d",&arrowLength);
	printf("\n");

	for(int i =0; i < arrowLength; i++)
	{
		printf("-");
	}
	printf(">");
}
