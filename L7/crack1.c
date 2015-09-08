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
    int guessLength = strlen(guess);
    char * hashedGuess = md5(guess,guessLength);
    // Compare the two hashes
    int isEqual = strcmp(hash,hashedGuess);
    // Free any malloc'd memory
    if(isEqual == 0) return 1;
    else return 0;
}

// Read in a file and return the array of strings.
// Use the technique we showed in class to expand the
// array as you go.
char **readfile(char *filename)
{
    return NULL;
}


int main(int argc, char *argv[])
{
    if (argc < 3) 
    {
        printf("Usage: %s hash_file dict_file\n", argv[0]);
        exit(1);
    }

    // Read the hash file into an array of strings
    char **hashes = readfile("hashes.txt");

    // Read the dictionary file into an array of strings
    char **dict = readfile("passwords.txt");

    // For each hash, try every entry in the dictionary.
    // Print the matching dictionary entry.
    // Need two nested loops.
}
