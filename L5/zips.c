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

    //creating a "fake hashtable" with an array
    //allows me to map each zip code to an index on the array
  int hashTableArray[10000] = 0;
  char line[1024];
  char zipStr[10] ="";
  char addStr[50] ="";
  char col[] = " : ";
  int sqft;
  int i =0;

  while (fgets(line, 1024, stream))
  {
    char* tmp = strdup(line);
    char* tmp2 = strdup(line);

    strcpy(zipStr,getfield(tmp, 1));
    zip = atoi(zipStr);

    hashTableArray[zip] = i++;

  }

}
