//Varun Ved
//arrow revisited

#include <stdio.h>


int get_length()
{
	int arrowLength;
	printf("How long of an arrow? ");
	scanf("%d",&arrowLength);

	return arrowLength;
}

void drawArrow(int arrowLength)
{
	for(int i =0; i < arrowLength; i++)
	{
		printf("-");
	}
	
	printf(">");

}

int main()
{
	int arLength;
	arLength= get_length();
	drawArrow(arLength);
}
