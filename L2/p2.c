//Varun Ved
//p2
//Collatz Conjecture

#include <stdio.h>

int get_start()
{
	int startNum;
	printf("Enter the starting number: ");
	scanf("%d",&startNum);
	if(startNum <= 0)
		printf("The number should be a positive integer.\n");
	else return startNum;
}

void collatz(int startNum)
{
	int n = startNum;
	int count = 0;
	printf("Collatz sequence: ");
	while(n != 1)
	{
		if(n%2 == 0)
		{
			n = n/2;
			printf("%d",n);
			printf(", ");
		} 	

		else
		{
			n= 3*n + 1;
			printf("%d",n);
			printf(", ");
		} 

		count++;
	}
	printf("Length: %d", count);
}

int main()
{
	int start = get_start();
	collatz(start);
}

