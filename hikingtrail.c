#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <setjmp.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 100

struct sentence {
    int length;
    char word[MAX_WORD_LENGTH];
};

char sen[MAX_WORD_LENGTH];
char portal;
int teleport = 0;
char sentence1[20];
char sentence2[20];
char sentence3[20];
jmp_buf buf;

void print(char s[], int newtab, int newline) 
{
    printf("my sentence:\t %s %c %s", s, newtab ? '\t' : '\0', newline ? "\n" : "\0");
}

int main() {
    struct sentence my_sen[MAX_WORDS];

    print("hey that's a nice one!", 1, 1);

    scanf(" %[^\n]", &portal);

    if (portal == 'o') {
        print("yeah", 1, 1);
        if (setjmp(buf) == 0) {
            longjmp(buf, 1);
        }
    }

    if (setjmp(buf) == 0) {
        if (teleport == 1) {
            printf("we're in here\n");
            for (int i = 0; i < sizeof(sentence1); i++) { 
                sentence1[i] = "\0"; 
            }
            scanf(" %[^\n]", sentence1);
            print(sentence1, 1, 1);
        }
    }
    return 0;
}
