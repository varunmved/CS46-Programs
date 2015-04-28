#include <stdio.h>

int* get_length()
{
    int length;
    printf("How long of an arrow? ");
    scanf("%d", &length);
    return *length;
} 

void draw_arrow(int* len)
{
    int i = 0;
    while (i < len)
    {
        printf("-");
        i++;
    }
    printf(">\n");
}

int main()
{
    int* length;
    length = get_length();
    draw_arrow(length);
    return 0;
} 