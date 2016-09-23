#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "md5.h"

const int PASS_LEN=20;        // Maximum any password can be
const int HASH_LEN=33;        // Length of MD5 hash strings

int hashRows;
int passRows;

// Given a hash and a plaintext guess, return 1 if
// the hash of the guess matches the given hash.
// That is, return 1 if the guess is correct.

/*
 * @param char*, char*
 * @returns int
 */
int tryguess(char *hash, char *guess)
{
    // Hash the guess using MD5
    char *guessedHash = md5(guess, strlen(guess));

    // Compare the two hashes
    if (strcmp(guessedHash, hash) == 0)
    {
        free(guessedHash);
        return 1;
    }
    // Free any malloc'd memory
    free(guessedHash);
    return 0;
}

// TODO
// Read in the hash file and return the array of strings.
// Use the technique we showed in class to expand the
// array as you go.

/*
 * @param char *
 * @returns char **
 */
char **readFile(char *filename)
{
    FILE *fp = fopen(filename, "r");
    int size = 50;
    char stringArr[40];
    char **passwords = (char**)malloc(size * sizeof(char *));
    int i = 0;

    if(!fp)
    {
        printf("Filename %s cannot be open for reading\n", filename);
        exit(1);
    }

    while(fscanf(fp, "%s\n", stringArr) != EOF)
    {
       if (i == size)
       {
           size = size + 51;
           char **biggerArr = (char **)realloc(passwords, size * sizeof(char *));
           if (biggerArr != NULL) 
           {
                passwords = biggerArr;
           }
           else
           {
               printf("Realloc failed with exit code: \n");
               exit(1);
           }
       }
       char *newStringArr = (char *)malloc((strlen(stringArr)+1) * sizeof(char));
       strcpy(newStringArr, stringArr);
       passwords[i] = newStringArr;
       i++;
    }
    i++;
    passwords[i] = '\0';
    fclose(fp);
    return passwords;
}

/*
 * @param char**
 * @returns int
 */
void freeArr(char** input)
{
    for(int i =0; input[i] != NULL; i++)
    {
        free(input[i]);
    }
}

/*
 * @param char**
 * @returns int
 */
int counter(char** input)
{
    int count = 0;
    while(input[count] != '\0')
    {
        count++;
    }
    return count-1;
}

/*
 * @param int, char**
 * @returns int
 */
int main(int argc, char *argv[])
{
    if (argc < 3) 
    {
        printf("Usage: %s hash_file dict_file\n", argv[0]);
        exit(1);
    }

    // Read the hash file into an array of strings
    char **hashes = readFile(argv[1]);

    // Read the dictionary file into an array of strings
    char **dict = readFile(argv[2]);
    
    int hashCount = counter(hashes);
    int dictCount = counter(dict); 

    // For each hash, try every entry in the dictionary.
    // Print the matching dictionary entry.
    // Need two nested loops.
    for(int i = 0; i < hashCount; i++)
    {
        for(int j = 0; j < dictCount; j++)
        {
            if(tryguess(hashes[i], dict[j]))
            {
                printf("%s = %s\n", hashes[i], dict[j]); 
            }
        }
    }
    free(hashes);
    free(dict);
}
