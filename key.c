#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 1000

int main(int argc, char *argv[]) {

    // Get plaintext from command line
    char *plaintext = argv[1];

    // Get ciphertext from command line
    char *ciphertext = argv[2];

    // Get iv from command line
    char *iv = argv[3];

    // Prepare Files for reading keys

    FILE *textfile;

    textfile = fopen("words.txt", "r");
    char line[MAX_LINE_LENGTH];

    while(fgets(line, MAX_LINE_LENGTH, textfile)){
        char *key = line;
        key[strlen(key) - 1] = '\0';
        if(strlen(line) < 16){
            while(strlen(line) < 16) {
                key = strcat(key, "#"); 
            }
        }

        if(strlen(line) > 16)
        {
            continue;
        }

        printf("%s\n", key);
    }
     
    fclose(textfile);
    return 0;
    

    

}



