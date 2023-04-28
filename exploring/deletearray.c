#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 100
#define MAX_LETTER_COUNT 1

struct word {
    int length;
    char fullword[15];
    struct word* next;
};

    struct word my_words[MAX_WORDS];
    char sentence[100];
    char redo; 
    int i = 0; 
    
    struct word *head = (struct word *)NULL;
    struct word *end = (struct word *)NULL;
    
void init_words() {
  for (int i = 0; i < MAX_WORDS; i++) {
    my_words[i].length = 0;
    memset(my_words[i].fullword, 0, sizeof(my_words[i].fullword));
    my_words[i].next = &my_words[i + 1];
  }
  my_words[MAX_WORDS - 1].next = NULL;
}

void print(char *sen, int newtab, int newline)
{
    // printf(":\t %s %c %s", sen, newtab ? "\t" : "\0", newline ? "\n" : "\0");
    printf(": %s%c%s\n", sen, newtab ? '\t' : '\0', newline ? "\n" : "");
}

void intro() 
{
    print("whatcha got?", 0, 1);
    fgets(sentence, sizeof(sentence), stdin);
    print(sentence, 1, 1);
}

void print_list() {
  head = &my_words[0];
  while (head != NULL) {
    if (head->length != 0) {
      printf("length:\t %d fullword:\t %s \n", head->length, head->fullword);
    }
    head = head->next;
  }
}

void capture_sentence() {
    init_words(); // reset my_words
    print("please enter a sentence", 0, 1);
    char my_sen[MAX_WORD_LENGTH];
    fgets(my_sen, sizeof(my_sen), stdin);
    print(my_sen, 0, 1);
}

int main(void) {
    start:
    init_words();
    
        init_words(); // reset my_words
    print("please enter a sentence", 0, 1);
    char my_sen[MAX_WORD_LENGTH];
    for (int i = 0; i < sizeof(my_sen); i++) {
        char Index = my_sen[i];
        if (Index < 10) {
            // print("hey how is you", 0, 1);
            // printf("%d \n", Index); // cant do text theres no string.
            i++;
        }
    }
    
    fgets(my_sen, sizeof(my_sen), stdin);
    print(my_sen, 0, 1);
    
    // capture_sentence();
    
    goto start;
    
    return 0;
    
}

// auto segfault if one were to put the code below as a callback. memory in static data structure is allocated at the end of the program. 
// assuming goto deallocates the memory leads to the error. 

    // print("please enter a sentence", 0, 1);
    // char my_sen[MAX_WORD_LENGTH];
    // for (int i = 0; i < sizeof(my_sen); i++) {
    //     char Index = my_sen[i];
    //     if (Index < 10) {
    //         // print("hey how is you", 0, 1);
    //         // printf("%d \n", Index); // cant do text theres no string.
    //         i++;
    //     }
    // }