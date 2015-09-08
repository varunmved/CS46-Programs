//95816,80017179,328 22nd St,525000,4,2,1448
//zip,id,address,price,bed,bath,sqft

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 95816,80017179,328 22nd St,525000,4,2,1448
#define LEN 20
/*
typedef struct homes
{
char zip[LEN];
char bigNum[LEN];
char add[LEN];
char otherBigNum[LEN];
char bed[LEN];
char bath[LEN];
char sqft[LEN];

}homes;
*/
const char* getfield(char* line, int num)
{
  const char* tok;
  for (tok = strtok(line, ",");
  tok && *tok;
  tok = strtok(NULL, ",\n"))
  {
    if (!--num)
    return tok;
  }
  return NULL;
}

int main()
{
  FILE* stream = fopen("homes200.csv", "r");
  FILE* smallStream = fopen("small.txt","w");
  FILE* medStream = fopen("med.txt","w");
  FILE* largeStream = fopen("large.txt","w");

  char line[1024];
  char sqftStr[20] ="";
  char addStr[50] ="";
  char col[] = " : ";
  int sqft;

  while (fgets(line, 1024, stream))
  {
    char* tmp = strdup(line);
    char* tmp2 = strdup(line);

    strcpy(sqftStr,getfield(tmp, 7));
    strcpy(addStr,getfield(tmp2, 3));
    sqft = atoi(sqftStr);


    //large
    if (sqft > 2000)
    {
      fprintf(largeStream,"%s",addStr);
      fprintf(largeStream,"%s",col);
      fprintf(largeStream,"%s\n",sqftStr);

      free(tmp);
      free(tmp2);
    }
    //medium
    else if (sqft < 2000 && sqft > 1000)
    {
      fprintf(medStream,"%s",addStr);
      fprintf(medStream,"%s",col);
      fprintf(medStream,"%s\n",sqftStr);

      free(tmp);
      free(tmp2);
    }
    //small
    else
    {
      fprintf(smallStream,"%s",addStr);
      fprintf(smallStream,"%s",col);
      fprintf(smallStream,"%s\n",sqftStr);

      free(tmp);
      free(tmp2);

    }
  }

}
