//Varun Ved
//strings.c

#include <stdio.h>

void concat(char *A, char *B)
{
	int h = 0;
	int a = 0;
	int j = 0;
	int k = 0; 
	while (B[h] >= 32)
	{
		h++;
		j++;
	}
	while (A[a] >=32)
	{
		a++;
		k++;
	}

	char *C = new char[k];

	for (int i = 0; i < k; ++i)
	{
		C[i] = A[i];
	}

	int length = j + k;

	A = new char[length];

	for (int i = 0; i < length; ++i)
	{
		A[i] = C[i];
	}
	
	for (int i = 0; i < j; ++i)
	{
		A[i + k] = B[i];
	}
	
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

int length(char *A)
{
	int i = 0;
	int j = 0;
	while (A[i] != '\0')
	{
		i++;
		j++;
	}

	for (int k = 1; k < j + 1; k++)
	{
		for (int i = 0; i < j; i++)
		{
			A[i] = A[k];
		}
	}
	A[0] = j;
	return A[0];
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

void trim(char *s)
{
	int max = length(s);
	for(int i = max; i < 0; i--)
	{
		if(s[i]=='\n')
		{
			s[i] = '\0';
		}
		else break;
	}
}

void trimall(char *s)
{
	int max = length(s);

	for(int i = max; i < 0; i--)
	{
		if( s[max] == '\t' ||
			s[max] == '\n' ||
			s[max] == '\r' ||
			s[max] == ' '
		   )
			{
				s[i] = '\0';
			}
		else 
			break;
	}
}



int main()
{
	
}
