]#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
// #include <conio.h>.   no clrscr() to [cls|clear] console.

#define MAX_WORDS 100
#define MAX_WORDS_LENGTH 1000

struct word {
    int length;
    char prefix[5];
    struct word* next;
};

struct node {
    struct word data;
    struct node* next;
};

struct word *head = ( struct word * ) NULL;
struct word *end = (struct word * ) NULL;

struct word words[MAX_WORDS];
char sentence[100];
float x,y,sum;
char ch, list, search_again;

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

char* search_word_insensitive(char* search, int length)
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
                if (tolower(head->prefix[j]) != tolower(search[j])) {  // convert both characters to lowercase before comparison
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

struct word* search_word_one(char* search, int length)
{
    struct word* head = &words[0];
    while (head != NULL) {
        if (head->length != 0) {
            int matches = 1;
  for (int j = 0; j < length && j < 4; j++) { // only compare up to the first 4 letters
                if (head->prefix[j] != search[j]) {
                    matches = 0;
                    break;
                }
            }
            if (matches) {
                return head; // return the first matching word found
            }
        }
        head = head->next;
    }
    return NULL; // return NULL if no matching word found
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
            if (strncasecmp(current->prefix, current->next->prefix, 4) > 0) {
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

    // If there are no empty slots, returnin
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

int upperInChar(char sentence[100], int length) {
  int upperCount = 0; 
  for (int i = 0; i < length; i++) {
    if (isupper(sentence[i])) {
      upperCount++;
    }
  }
  if (upperCount > 0) {
    return 1;
  } else if (upperCount == 0) {
    return 0;
  }
}

int main(void)
{
    beginning:
    init_words();
    printf("math: {minimum:concept}{maximum:prob-solv}15mins!solve?lookup\n");
    printf("simple enough instructions:computer can do anything\n");
    // scanf ("%f",&x);
    // scanf("%[^\n]s", sentence);
    fgets(sentence, sizeof(sentence), stdin);
    printf("heres my sentence:\t %s \n \t \t \t \n", sentence);

    char word[MAX_WORDS_LENGTH];
    // struct word words;

  
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

    firstSearch:      // nice. goto working as intended at this moment.
        head = &words[0];
    while (head != NULL) {
      if (head->length > 1) {

              printf("\n\n\n");
          char searchsentence1[100];
      printf("please search up to the first four letters. \n");
            // fgets(searchsentence1, 4, stdin);
            scanf(" %[^\n]", searchsentence1);
            int searchsentence1Length = sizeof(searchsentence1);
            // for (int i = 0; i < sizeof(searchsentence1); i++) {
            //       if (isupper(searchsentence1[i])) {
            //           // case sensitive. 
            //         printf("there are capital letters \n");
            //         break;
            //       } 
            // }
        
int searchsentence_is_upper = upperInChar(searchsentence1, searchsentence1Length);
          printf("do i have uppercase?:\t %d \n", searchsentence_is_upper);
        
                  // * * searchsentence1 uppercase based searching
  // if you have an F uppercase in search. have to be insensitive and dont lowercase char
        
struct word* result = search_word_one(searchsentence1, strlen(searchsentence1));
        
    if (result != NULL) {
        printf("prefix: %s length: %d\n", result->prefix, result->length);
    } else {
        goto firstSearch;
    }
    printf("would you like to search again? Y \n");
    scanf(" %c", &search_again);
    if (search_again == 'y') {
      goto firstSearch;
    }
        
        break;
      } else {
        printf("there is no linked list data to present: \n");
        break;
      }
    }
  
    do {
// printf("linked list data presented below: {prefix: up to 4 letters} {length: of word}  \n ");

      head = &words[0];
    while (head != NULL) {
      if (head->length > 1) {
printf("linked list data presented below: {prefix: up to 4 letters} {length: of word}\n\n\n");
        break;
      } else {
        printf("there is no linked list data to present: \n");
        break;
      }
    }
      
        print_list();
        printf("\n \n \n");
// printf("below is an input that interacts with a linked list.\n");
// printf("a to add a word to the linked list data. prefix up to 4 letters and length is saved\n");
// printf("s to do a sensitive search. S for an insensitive search\n");
// printf("d to delete the list");
printf("a to add a word.s (insensitive) S (sensitive) search modes. d to delete c to clear\n");
        scanf(" %c", &list);
        if (list == 'a') {
            printf("enter a word into the input to add it to the list please \n");
            // char sentence2[100];
            // fgets(sentence2, sizeof(sentence2), stdin);
            // scanf("%[^\n]s", sentence2);
            char new2[10];
            // fgets(new, 5, stdin);
            scanf(" %[^\n]s", new2);
            int new_len = strlen(new2);
            add_word(new2, new_len);
            printf("I Just printed %s \n \n", new2);

            ch = 'G';   // surprised this works and validates while block
            // printf ("G or g to Go again:\n");
            // scanf(" %c", &ch);
        } else if (list == 'S') {
            // s || S
            char searchsentence[100];
printf("capitalization matters. search up to 4 letters please: \n");
            // fgets(searchsentence, 4, stdin);
            scanf(" %[^\n]", searchsentence);
            char* prefix = search_word(searchsentence, strlen(searchsentence));
            // printf("My Returned Search Result: \t %s\n", prefix);
            head = &words[0];
            search_word(searchsentence, strlen(searchsentence));
            printf("* * * * * * * search results above \n");
            ch = 'G';
        } else if (list == 's') {
          char searchsentence2[100];
    printf("capitalization doesnt matter its insensitive!!!!: \n");
            // fgets(searchsentence, 4, stdin);
            scanf(" %[^\n]", searchsentence2);
            char* prefix = search_word(searchsentence2, strlen(searchsentence2));
            // printf("My Returned Search Result: \t %s\n", prefix);
            head = &words[0];
            search_word_insensitive(searchsentence2, strlen(searchsentence2));
            printf("* * * * * * * search results above \n");
            ch = 'G';
        }
        else if (list == 'd') {
            printf("the list has been deleted \n");
   //          delete_list();
   //          ch = 'g';
    goto beginning;   // tried to use to restart the entry of sentence[100]
        } else if (list == 'c') {
                        printf(" * * * empty list rendered below: \n\n\n * * * ");
            printf("\033[2J\033[H");   // ANSI escape codes to clear screen
            // printf("Screen cleared!\n");
            ch = 'G';
      // goto beginning;
        } else {
    printf ("(g | G) to go again please.\n");
            scanf(" %c", &ch);
        }


    } while (ch == 'g' || ch == 'G');
    printf("thanks for playing");
}
