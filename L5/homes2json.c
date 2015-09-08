#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 95816,80017179,328 22nd St,525000,4,2,1448
#define LEN 80

typedef struct homes
{
  char zip[LEN];
  char bigNum[LEN];
  char add[LEN];
  char price[LEN];
  char bed[LEN];
  char bath[LEN];
  char sqft[LEN];

}homes;

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
void addBeginning(FILE* fileIN)
{
  char openBrack = '[';
  fprintf(fileIN,"%c\n", openBrack);

}

void fixEnding(FILE* fileIN)
{
  char closeBrack = ']';
  fprintf(fileIN,"%c\n", closeBrack);

}

void getJSON()
{


}

int main()
{
    int count = 0;
    FILE* stream = fopen("homes200.csv", "r");
    FILE* stream2 = fopen("homes2json.json","w");
    char zip[LEN];
    char price[LEN];
    char add[LEN];
    char otherBigNum[LEN];
    char bed[LEN];
    char bath[LEN];
    char sqft[LEN];
    char zipName[] = "{ \"zip\": ";
    char addressName[] = ", \"address\":";
    char priceName[] = ", \"price\":";
    char areaName[] = ", \"area\":";
    char closeLine[] = " },";
    char closeLineLast[] = " }";
    char newLine = '\n';

    addBeginning(stream2);

    char line[1024];
    while (fgets(line, 1024, stream))
    {
        char* tmp = strdup(line);
        char* tmp2 = strdup(line);
        char* tmp3 = strdup(line);
        char* tmp4 = strdup(line);
        char* tmp5 = strdup(line);
        char* tmp6 = strdup(line);
        char* tmp7 = strdup(line);

        strcpy(zip,getfield(tmp, 1));
        strcpy(price,getfield(tmp2, 2));
        strcpy(add,getfield(tmp3, 3));
        strcpy(price,getfield(tmp4, 4));
        strcpy(bed,getfield(tmp5, 5));
        strcpy(bath,getfield(tmp6, 6));
        strcpy(sqft,getfield(tmp7, 7));
        //{ "zip": 95678, "address": "123 Main St.", "price": 234000, "area": 1700 },


        fprintf(stream2,"%s",zipName);
        fprintf(stream2,"%s",zip);
        fprintf(stream2,"%s",addressName);
        fprintf(stream2,"%c", '"');
        fprintf(stream2,"%s",add);
        fprintf(stream2,"%c", '"');
        fprintf(stream2,"%s",priceName);
        fprintf(stream2,"%s",price);
        fprintf(stream2,"%s",areaName);
        fprintf(stream2,"%s",sqft);
        if(strdup(line) != newLine)
        {
          fprintf(stream2,"%s",closeLine);

        }
        else
        {
          fprintf(stream2,"%s",closeLineLast);

        }


        free(tmp);
        free(tmp2);
        free(tmp3);
        free(tmp4);
        free(tmp5);
        free(tmp6);
        free(tmp7);

    }
    fixEnding(stream2);

}
