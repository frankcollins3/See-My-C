#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include <conio.h>.   no clrscr() to [cls|clear] console.

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

// char* search_word(char* search, int length) {
//   static char prefixArr[100];
//   printf("search character: \t %s search results below: \n", search);
//   char matchArr[length];
//   head = &words[0];
//   while (head != NULL) {
//       for (int j = 0; j < 1; j++) {
//         if (head->prefix[j] == search[j]) {
// printf("equal: headprefix[i]\t %c, search[i] \t %c, prefix:\t %s, length:\t %d \n ", head->prefix[j], search[j], head->prefix, head->length);
//         matchArr[j] = search[j];
// memcpy(prefixArr, head->prefix, 4);
//         }
//       }
//       head = head->next;
//   }
//   return prefixArr;
// }

// char* search_word(char* search, int length) {
//   static char prefixArr[100];

//   printf("search character: \t %s search results below: \n", search);
//   char matchArr[length];
//   head = &words[0];
//   while (head != NULL) {
//     if (head->length != 0) {
//         for (int j = 0; j < length; j++) {
//             if (head->prefix[j] != search[j]) {
//                 printf("prefix:\t %s \n", head->prefix);
//                 strcpy(noMatch.noMatchWord, head->prefix);
//             }
//         }
//     }
//       for (int k = 0; k < sizeof(noMatch.noMatchWord); k++) {
//           printf("here are those words: %s", nomatch.noMatchWord)
//       }
//       head = head->next;
//   }
//   return prefixArr;
// }

struct noMatch {
    char noMatchWord[100];
};

char* search_word(char* search, int length)
{
    static char prefixArr[100];
    struct noMatch noMatchArr[100];
    int noMatchIndex = 0;

printf("* * * * * search character: \t %s \t\t\t search results below: \n", search);
    char matchArr[length];
    head = &words[0];
    while (head != NULL) {
        if (head->length != 0) {
            int matches = 1;
            for (int j = 0; j < length; j++) {
                if (head->prefix[j] != search[j]) {
                    matches = 0;
                    strcpy(noMatchArr[noMatchIndex].noMatchWord, head->prefix);
                    noMatchIndex++;
                    break;
                }
            }
            if (matches) {
                // do something with matching words
                printf("search results. - - - - - - - - - \n");
                printf("prefix: %s length: %d \n ", head->prefix, head->length);
                printf("search results. - - - - - - - - - \n \n\n\n");
            }
        }
        head = head->next;
    }
    // do something with non-matching words in noMatchArr
    return prefixArr;
}

void swap(struct word* a, struct word* b) {
int temp_length = a->length;
char temp_prefix[5];
strncpy(temp_prefix, a->prefix, 4);
temp_prefix[4] = '\0';

a->length = b->length;
strncpy(a->prefix, b->prefix, 4);
a->prefix[4] = '\0';

b->length = temp_length;
strncpy(b->prefix, temp_prefix, 4);
b->prefix[4] = '\0';
}

// Function to sort the list in alphabetical order
void alphabetize(struct word* head) {
struct word* current = head;
struct word* next = NULL;

if (head == NULL) {
    return;
}

int swapped;
do {
    swapped = 0;
    current = head;
    while (current->next != next) {
 if (strcmp(current->prefix, current->next->prefix) > 0) {
swap(current, current->next);
swapped = 1;
}
        current = current->next;
    }
    next = current;
} while (swapped);
}


void add_word(char* prefix, int length)
{
    // Find the first empty slot in the words array
    struct word* new_word = NULL;
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].length == 0) {
            new_word = &words[i];
            break;
        }
    }

    // If there are no empty slots, return
    if (new_word == NULL) {
        return;
    }

    // Copy the prefix and length into the new word
    memset(new_word, 0, sizeof(struct word));
    strncpy(new_word->prefix, prefix, sizeof(new_word->prefix) - 1);
    new_word->prefix[sizeof(new_word->prefix) - 1] = '\0';
    new_word->length = length;

    // Find the last word in the list
    struct word* current = &words[0];
    while (current->next != NULL) {
        current = current->next;
    }

    // Add the new word to the end of the list
    current->next = new_word;
    new_word->next = NULL;
    alphabetize(&words[0]);
}



void init_words()
{
    for (int i = 0; i < MAX_WORDS; i++) {
        words[i].length = 0;
        memset(words[i].prefix, 0, sizeof(words[i].prefix));
        words[i].next = &words[i+1];
    }
    words[MAX_WORDS-1].next = NULL;
}

void print_list()
{
    head = &words[0];
    while (head != NULL) {
        if (head->length != 0) {
            printf("length:\t %d prefix:\t %s \n", head->length, head->prefix);
        }
        // alphabetize(&words[0]);
        head = head->next;
    }
}

  void delete_list() {
    printf("im in the delete function!\n");
  
    struct word* current = &words[0];
    // struct word* current = head;
    while (current != NULL) {
        struct word* next = current->next;
        current->length = 0;
memset(current->prefix, 0, 0);
// memset(current->prefix, 0, sizeof(current->prefix));
        current->next = NULL;
        current = next;
    }
    // head = NULL;
    // end = NULL;
    
    print_list();
  }

int main(void)
{
    init_words();

    printf("math: {minimum:concept}{maximum:prob-solv}15mins!solve?lookup\n");
    printf("simple enough instructions:computer can do anything\n");
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
            } else {
                head->next = NULL;
            }
            head = head->next;
            i++;
            word_index = 0;
        } else {
// Add the current character to the current word:
            if (word_index < MAX_WORDS_LENGTH-1) {
                word[word_index] = c;
                word_index++;
            }
        }
        // alphabetize(&words[0]);
    }
    print_list();
    printf("\n\n\n");

    // // printf ("Enter the second number:");
    // // scanf ("%f",&y);
    // // sum=x+y;
    // printf ("The total number is:%f\n",sum);

    do {
        printf("heres the list: \n");
        print_list();
        printf("do you want to add or search to the list?\n");

        scanf(" %c", &list);
        if (list == 'a') {
            printf("enter a word into the input to add it to the list please \n");
            // char sentence2[100];
            // fgets(sentence2, sizeof(sentence2), stdin);
            // scanf("%[^\n]s", sentence2);
            printf("Press Space & Type To enter a new item into the list!\n");
            char new2[10];
            // fgets(new, 5, stdin);
            scanf(" %[^\n]s", new2);
            int new_len = strlen(new2);
            add_word(new2, new_len);
            printf("I Just printed %s \n", new2);

            ch = 'G';   // surprised this works and validates while block
            // printf ("G or g to Go again:\n");
            // scanf(" %c", &ch);
        } else if (list == 's') {
            // s || S
            char searchsentence[100];
            printf("search into the input please: \n");
            // fgets(searchsentence, 4, stdin);
            scanf(" %[^\n]", searchsentence);
            char* prefix = search_word(searchsentence, strlen(searchsentence));
            // printf("My Returned Search Result: \t %s\n", prefix);
            head = &words[0];
            search_word(searchsentence, strlen(searchsentence));
            printf("* * * * * * * search results above \n");
            ch = 'G';
        } else if (list == 'd') {
            printf("oh you want to delete? \n");
            delete_list();
            ch = 'g';
        }
        else {
            printf ("Do you want to repeat the operation g for Go Y/N:\n");
            scanf(" %c", &ch);
        }


    } while (ch == 'g' || ch == 'G');
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
