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
    //FILE* stream2 = fopen("homes2json.json","w");

    char line[1024];
    double high = 0;
    double low = 1000000;
    double sum = 0;
    double price = 0;
    int count = 0;
    double avg = 0;
    char priceSTR[20] ="";

    while (fgets(line, 1024, stream))
    {
        count++;
        char* tmp = strdup(line);
        strcpy(priceSTR,getfield(tmp, 4));
        price = atof(priceSTR);
        // printf("%lf",price);
        // printf("\n");
        //
        sum += price;
        //printf("%lf",sum);
        printf("\n");

        if (price > high)
        {
          high = price;
        }
        else if(price < low && low != 0)
        {
          low = price;
        }
        else;


        free(tmp);
    }
    avg = sum/count;
    printf("%lf %lf %lf", low, high, avg);
}
