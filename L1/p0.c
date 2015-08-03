#include <stdio.h>

int main()
{
    int height, width;
    printf("Enter the height and width of a rectangle: ");
    scanf("%d%d", &height, &width);
    int area = height * width;
    printf("The area is %d sq in.\n", area);
    return 0;
}