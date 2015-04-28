//Varun Ved
//orientaiton

#include <stdio.h>

int main()
{
	int width=0;
	int height=0;

	printf("Input the width and hieght of a picture: ");
	scanf("%d %d",width,height);

	if(width > height) printf("landscape");
	else if (width < height) printf("portrait");
	else printf("square");

}