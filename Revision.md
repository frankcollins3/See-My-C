#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100
#define MAX_WORDS_LENGTH 1000

struct word {
    int length;
    char prefix[5];
    struct word* next;
};

struct word *head = ( struct word * ) NULL;
struct word *end = (struct word * ) NULL;

struct word words[MAX_WORDS];
char sentence[100];
float x,y,sum;
char ch, list;

void init_words() {
    for (int i = 0; i < MAX_WORDS; i++) {
        words[i].length = 0;
memset(words[i].prefix, 0, sizeof(words[i].prefix));
    words[i].next = &words[i+1];
    }
    words[MAX_WORDS-1].next = NULL;
}

void print_list() {
    head = &words[0];
    while (head != NULL) {
        if (head->length != 0) {
    printf("length:\t %d prefix:\t %s \n", head->length, head->prefix);
        }
        head = head->next;
    }
}

int main(void) {
    init_words();
    
printf("math: {minimum:concept}{maximum:prob-solv}15mins!solve?lookup\n");
        // scanf ("%f",&x);
        // scanf("%[^\n]s", sentence);
        fgets(sentence, sizeof(sentence), stdin);
        printf("heres my sentence:\t %s \n \t \t \t \n", sentence);
            
            char word[MAX_WORDS_LENGTH];
    struct word* head = &words[0];
    int i = 0;
    int word_index = 0;
    int sentence_len = strlen(sentence);
    for (int j = 0; j < sentence_len; j++) {
        char c = sentence[j];
        if (c == ' ' || c == '\n') {
            // Finish the current word and add it to the list:
            head->length = word_index;
            
          
    strncpy(head->prefix, word, head->length >= 4 ? 4 : head->length);
    // strncpy(head->prefix, word, 4);
            // strncpy(head->prefix, word, sizeof(word) > 3 ? 4 : sizeof(word));
           
            if (i < MAX_WORDS - 1) {
                head->next = &words[i+1];
            }
            else {
                head->next = NULL;
            }
            head = head->next;
            i++;
            word_index = 0;
        }
        else {
// Add the current character to the current word:
            if (word_index < MAX_WORDS_LENGTH-1) {
                word[word_index] = c;
                word_index++;
            }}}
        print_list();
        
        // // printf ("Enter the second number:");
        // // scanf ("%f",&y);
        // // sum=x+y;
        // printf ("The total number is:%f\n",sum);
    
    do {
        print_list();
        printf("do you want to add or search to the list?\n");
        
        scanf(" %c", &list);
        if (list == 'a') {
            printf("okay were adding\n");
            printf ("in add. want to go again? Y/N:\n");
        scanf(" %c", &ch);
        }

        
        printf ("Do you want to repeat the operation Y/N:\n");
        scanf(" %c", &ch);
    }
    while (ch == 'y' || ch == 'Y');
}


* * * * * * * * * 
go to 

#include<stdio.h>
int main(){
float x, y, sum;
char ch;
print:
    printf ("Enter the first number:");
    scanf ("%f",&x);
    printf ("Enter the second number:");
    scanf ("%f",&y);
    sum=x+y;
    printf ("\nThe total number is:%.2f\n",sum);
again:
    printf ("\n\t\t\t\t\tDo you want to repeat the operation(Y/N): ");
    scanf (" %c", &ch);

    if(ch == 'y' || ch == 'Y'){
        goto print;
    }
    else if(ch == 'n' || ch == 'N'){
        return 0;
    }
    else{
        printf("\n\t\t\t\t\tPlease enter Yes or NO.\n");
        goto again;
    }
   return 0;}
