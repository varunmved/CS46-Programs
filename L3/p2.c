#include <stdio.h>
#include <ctype.h>
#include <string.h>

char* strcaps(char* str1, int str2)
{
	for(int i =0; i < str2; i++)
	{
		if(islower(str1[i]))
		{
			str1[i] = toupper(str1[i]);
		}
	}
	return str1;
}
int main()
{
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    strcaps(str, strlen(str));
    printf("Converted string: %s\n", str);
    return 0;
}

