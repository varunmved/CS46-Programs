//strings.c
#include <stdlib.h>
#include <stdio.h>

int length(char *in)
{
    int i =0;
    while(in[i]!= '\0')
    {
        i++;
    }
    return i;
}

char* newS(char *input)
{
    int size = length(input);
    char *newArr = malloc( sizeof(char) * ( size + 1 ) );
    for (int i =0; i < size; ++i)
    {
        newArr[i]= input[i];
    }
    return newArr;
}
char * concat(char *dest, char *source)
{
    int size = 0;
    int sizeA = length(dest);
    int sizeB = length(source);
    
    size = sizeA+sizeB;
    
    char *j = malloc( sizeof(char) * ( size + 1 ) );
    
    for(int i = 0; i <sizeA; i++)
    {
        j[i] = dest[i];
    }
    
    dest = malloc( sizeof(char) * ( size + 1 ) );
    
    for(int i =0; i < sizeA; i++)
    {
        dest[i] = j[i];
    }
    
    for(int i = 0; i <sizeB; i++)
    {
        dest[sizeA + i] = source[i];
    }

    return dest;
}

int stringPosition(char *A, char B)
{
	int i = 0;
	int sizelol = 0;
	while (A[i] >= 32)
	{
		i++;
		sizelol++;
	}
	
	for (int i = 0; i < sizelol+1; ++i) {
		if (A[i] == B) return i;
	}
	return -1;
}

void copy(char *dest, char *source)
{
	int i = 0;
	while (dest[i] >= 32)
	{
	    dest[i] = source[i];
		  i++;
	}
}

int stringCompare(char *str1, char *str2)
{
	int same = 0;
	int i = 0;
	while (same)
	{
		if (str1[i] != str2[i])
		{
			same = str1[i]-str2[i];
		}
		break;
	}
	return same;
}

char * shiftIt(char * s)
{
    int size = length(s);
    char *j = malloc( sizeof(char) * ( size + 1 ) );
    
    for(int i=0; i < size; ++i)
    {
        j[i] = s[i+1];
    }
    
    return j;
}

void trim(char *s)
{
	int max = length(s);
    //printf(max,"%d");
        
	 if(s[max]=='\n')
		{
			s[max] = '\0';
		}

	 if(s[0]=='\n')
     {  
        s = shiftIt(s);
     }
}

void trimall(char *s)
{
    int max = length(s);
		if(s[max] == '\t' ||
			s[max] == '\n' ||
			s[max] == '\r' ||
			s[max] == ' '
		){
			s[max] = '\0';
		}

   if(s[0] == '\t' ||
			s[0] == '\n' ||
			s[0] == '\r' ||
			s[0] == ' '
		){
      s = shiftIt(s);
		}
}

int main()
{
    char *s = "source";
    char *d = "dest";
    d = concat(d,s);
    printf(d,"%s");


}
