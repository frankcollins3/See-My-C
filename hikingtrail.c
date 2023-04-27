#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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

// void print(char *s, int newtab, int newline) 
// print(char s) wont work it decays into a pointer. arg must be: *s || s[]
void print(char s[], int newtab, int newline) 
{
    printf("my sentence:\t %s %c %s", s, newtab ? '\t' : '\0', newline ? "\n" : "\0");
    // print("sure!", 1, 1); invoke like so!
}

int main() {
    struct sentence my_sen[MAX_WORDS];    // initialize the struct
    
    
    
    print("hey thats a nice one!", 1, 1);
    
    scanf(" %[^\n]", &portal);
    
    // portal == 'o' ? goto word1 :  print("nice one" 1, 1); 
    
    if (portal == 'o') {
        print("yeah", 1, 1);
        
    }
    
    if (portal) {
    word1: 
    for (int i = 0; i < sizeof(sentence1); i++) { sentence1[i] = "\0"; }
    scanf(" %[^\n]", sentence1);
    // print("my_sentence1:\t %s", sentence1);
    print(sentence1, 1, 1);
    }
    word_1_junior:
    print("hehe", 1, 1);
    
    

    
    return 0;
}
