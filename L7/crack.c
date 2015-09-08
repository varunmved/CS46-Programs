 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 #include "md5.h"
 
 const int PASS_LEN=20;        // Maximum any password can be
 const int HASH_LEN=33;        // Length of MD5 hash strings
 
// Given a hash and a plaintext guess, return 1 if
// the hash of the guess matches the given hash.
// That is, return 1 if the guess is correct.
int tryguess(char *hash, char *guess)
{
    // Hash the guess using MD5
    // Compare the two hashes
    // Free any malloc'd memory
    return 0;
}
// Read in a file and return the array of strings.
// Use the technique we showed in class to expand the
// array as you go.
char **readfile(char *filename)
{
    return NULL;
}

FILE *openfile(char *fname);
char **readfile(FILE *f, int *pNumLines);
char **storeHashes(char **lines);
int tryguess(char *hash, char *guess);
int numLines;
int numHashes;
 
 int main(int argc, char *argv[])
 {
     }
 
     // Read the hash file into an array of strings
    char **hashes = readfile("hashes.txt");
    FILE *hf, *df;
    char **dictHashes;
	
	hf = openfile(argv[1]);
    char **hashes = readfile(hf, &numHashes);
    fclose(hf);
 
     // Read the dictionary file into an array of strings
    char **dict = readfile("passwords.txt");

    df = openfile(argv[2]);
    char **dict = readfile(df, &numLines);
    fclose(df);
    
    // Make array of hashes from the dictionary array
    dictHashes = storeHashes(dict);
    
     // For each hash, try every entry in the dictionary.
     // Print the matching dictionary entry.
    // Need two nested loops.
    for (int i = 0; i <= numHashes; i++)
    {	
    	for (int j = 0; j <= numLines; j++)
    	{
    	    if(strcmp(hashes[i], dictHashes[j]) == 0)
            {
    	    	printf("hash is: %s password is: %s\n", hashes[i], dict[j]);
    			break;
    		}	
    	}
    }
    
    int idx = 0;
    while(hashes[idx] != NULL)
    {
        free(hashes[idx]);
        idx++;
    }
    int idx2 = 0;
    while(dict[idx2] != NULL)
    {
        free(dict[idx2]);
        idx2++;
    }
    int idx3 = 0;
    while(dictHashes[idx3] != NULL)
    {
        free(dictHashes[idx3]);
        idx3++;
    }
    
    free(hashes);
    free(dict);
    free(dictHashes);
}

FILE *openfile(char *fname)
{
	FILE *f = fopen(fname, "r");
	if (!f)
	{
		printf("Couldn't open %s for reading\n", fname);
		exit(2);
	}
	return f;
}

// Read in a file and return the array of strings.
char **readfile(FILE *f, int *pNumLines)
{
    // Create inital array of 50 pointers
    int arrlen = 50;
    char **arr = (char **)malloc(arrlen * sizeof(char *));
    
    // Read in file, expanding array as you go
    char line[40];
    int i = 0;
    while(fscanf(f, "%s", line) != EOF)
    {
        arr[i] = malloc((strlen(line)1) * sizeof(char));
        strcpy(arr[i], line);
        i;
        if (i == arrlen)

