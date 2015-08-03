//p1
//varun ved

#include <stdio.h>

int main()
{
	int inNum1,inNum2,inDom1,inDom2,outNum,outDom = 0;
	printf("This Program will add two fractions.");
	printf("\n");
	printf("Input the first fraction: ");
	scanf("%d %*c %d",&inNum1,&inDom1);
	printf("Input the second fraction: ");
	scanf("%d %*c %d",&inNum2,&inDom2);

	if(inDom1==inDom2)
	{
		outNum=inNum2+inNum1;
		outDom=inDom1;
	}
	else
	{
		outDom=inDom2*inDom1;
		outNum=inNum1*inDom2 + inNum2*inDom1;
	}
	

	printf("The sum is: %d/%d",outNum,outDom);

}