#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>

// #include <conio.h>.   no clrscr() to [cls|clear] console.
#define MAX_WORDS 100
#define MAX_WORDS_LENGTH 1000

// https://gist.github.com/RabaDabaDoba/145049536f815903c79944599c6f952a ANSI :)
#define BLK "\e[0;30m" // these are escape codes like \t   &&  \n
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"
#define DUMMY "\0"

char *color_bucket[] = {GRN, YEL, BLU, MAG, CYN};

char *get_random_color() {
  // random number generator seeder
  srand(time(NULL));
  // get the size of color_bucket array  // arr.length() in js
  int size = sizeof(color_bucket) / sizeof(color_bucket[0]);

  // generate a random index within the range of the array
  int random_index = rand() % size;

  // color @ index
  return color_bucket[random_index];
}

// printf("This text is " GRN "green" WHT " and this text is white.\n");

struct word {
  int length;
  char prefix[5];
  struct word *next;
};

struct node {
  struct word data;
  struct node *next;
};

struct word *head = (struct word *)NULL;
struct word *end = (struct word *)NULL;

struct word words[MAX_WORDS];
char sentence[100];
float x, y, sum;
char ch, list, search_again;

struct noMatch {
  char noMatchWord[100];
};

char *search_word(char *search, int length) {
  static char prefixArr[100];
  struct noMatch noMatchArr[100];
  int noMatchIndex = 0;

  printf("* * * * * search character: \t %s \t\t\t search results below: \n",
         search);

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

char *search_word_insensitive(char *search, int length) {
  static char prefixArr[100];
  struct noMatch noMatchArr[100];
  int noMatchIndex = 0;

  printf("* * * * * search character: \t %s \t\t\t search results below: \n",
         search);
  char matchArr[length];
  head = &words[0];
  while (head != NULL) {
    if (head->length != 0) {
      int matches = 1;
      for (int j = 0; j < length; j++) {
        if (tolower(head->prefix[j]) !=
            tolower(search[j])) { // convert both characters to lowercase before
                                  // comparison
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

struct word *search_word_one(char *search, int length) {
  struct word *head = &words[0];
  int has_uppercase = 0;

  // Check if search has uppercase characters
  for (int i = 0; i < length; i++) {
    if (isupper(search[i])) {
      has_uppercase = 1;
      break;
    }
  }

  // Convert search to lowercase if there are any uppercase characters
  if (has_uppercase) {
    for (int i = 0; i < length; i++) {
      search[i] = tolower(search[i]);
    }
  }

  while (head != NULL) {
    if (head->length != 0) {
      int matches = 1;
      for (int j = 0; j < length && j < 4; j++) {
        if (tolower(head->prefix[j]) != search[j]) {
          matches = 0;
          break;
        }
      }
      if (matches) {
        return head;
      }
    }
    head = head->next;
  }
  return NULL;
}

void swap(struct word *a, struct word *b) {
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
void alphabetize(struct word *head) {
  struct word *current = head;
  struct word *next = NULL;

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

void add_word(char *prefix, int length) {
  // Find the first empty slot in the words array
  struct word *new_word = NULL;
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
  struct word *current = &words[0];
  while (current->next != NULL) {
    current = current->next;
  }

  // Add the new word to the end of the list
  current->next = new_word;
  new_word->next = NULL;
  alphabetize(&words[0]);
}

void init_words() {
  for (int i = 0; i < MAX_WORDS; i++) {
    words[i].length = 0;
    memset(words[i].prefix, 0, sizeof(words[i].prefix));
    words[i].next = &words[i + 1];
  }
  words[MAX_WORDS - 1].next = NULL;
}

int upperInChar(char sentence[4], int length) {
  // printf("heres my sentence in upperInChar function \t %s \n", sentence);
  int upperCount = 0;
  // for (int i = 0; i < length; i++) {
  for (int i = 0; i < strlen(sentence); i++) {
    if (isupper(sentence[i])) {
      upperCount++;
      printf("sentence[i]: %c, upperCount: %d\n ", sentence[i], upperCount);
    }
  }
  if (upperCount > 0) {
    return 1;
  } else if (upperCount == 0) {
    return 0;
  }
}

void dash_across_screen() {
  printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - "
         "- - \n");
}

void center_text_no_args(char *text) {
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w); // Get console size
  int text_len = strlen(text);
  int center_pos = (w.ws_col - text_len) / 2; // Calculate center position
  for (int i = 0; i < center_pos; i++) {
    printf(" "); // Print spaces before text
  }
  printf("%s \n", text);
  // printf("%s %c %s", text, newtab ? '\t' : '\0', newline ? "\n" : "\0");
}

void center_text_print_list(int head_length, char *head_prefix) {
  struct winsize w;
  char *randomColor = get_random_color();
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w); // Get console size
  int text_len = strlen(head_prefix);
  int center_pos = (w.ws_col - text_len) / 2; // Calculate center position
  for (int i = 0; i < center_pos; i++) {
    printf(" "); // Print spaces before text
  }
  // printf("length: \t %s %d" "prefix: \t %s %s \n", BLU, head_length,
  // get_random_color(), head_prefix);
  printf("length:\t"
         "%s %d \t",
         GRN, head->length);
  printf(BLK);
  printf("prefix:\t"
         "%s %s \n",
         get_random_color(), head->prefix);
  printf(BLK);
  printf("\n");
  // printf("%s %c %s", text, newtab ? '\t' : '\0', newline ? "\n" : "\0");
}

void print_list() {
  head = &words[0];
  while (head != NULL) {
    if (head->length != 0) {
      // printf("length:\t %d prefix:\t %s \n", head->length, head->prefix);
      // center_text_no_args("length:\t %d prefix:\t %s \n");
      center_text_print_list(head->length, head->prefix);
    }
    head = head->next;
  }
}

void delete_list() {
  struct word *current = &words[0];
  // struct word* current = head;
  while (current != NULL) {
    struct word *next = current->next;
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

void print_intro_instructions() {
  // printf("please type in a :sentence: and press enter to submit it.\n");
  center_text_no_args(
      "please type in a -sentence- and press enter to submit it");
  center_text_no_args(
      "Submitted data from the input will be saved as a linked list of "
      "struct word { } data:");
  // printf("1:\t A prefix of up to 4 letters. \t | \t 2: Entire word
  // length\n");
  center_text_no_args(
      "1: \t A prefix of up to 4 letters. \t 2: Entire word length \n");
  center_text_no_args("- - - - - - - - - - - - - - - - - - - - - - - - - - - - "
                      "- - - - - - - - \n");

  // printf("\n ");
  fgets(sentence, sizeof(sentence), stdin);
  printf("\n ");
  center_text_no_args("- - - - - - - - - - - - - - - - - - - - - - - - - - - - "
                      "- - - - - - - - \n");

  // if curious, uncomment the print(\t); ... it starts skipping through the
  // first search prompt.
}

// * * * * * i have to combine the print and center_text functions * * * * *

// print(char s) wont work it decays into a pointer. arg must be: *s || s[]
void print(char s[], int newtab, int newline) {
  printf("my sentence:\t %s %c %s", s, newtab ? '\t' : '\0',
         newline ? "\n" : "\0");
}
// print("sure!", 1, 1); invoke like so!

int main(void) {
beginning:
  init_words();

  print_intro_instructions();

  // Initialize the list of words:

  char word[MAX_WORDS_LENGTH];
  int i = 0;
  int word_index = 0;
  int sentence_len = strlen(sentence);

  // Parse the sentence and add each word to the linked list:
  for (int j = 0; j < sentence_len; j++) {
    char c = sentence[j];
    if (c == ' ' || c == '\n' || strpbrk(word, "!?*&%") != NULL) {
      // Finish the current word and add it to the list:
      if (strpbrk(word, "!@#$%^&*()_+-=?<>.,|")) {
        center_text_no_args("no special characters please! Words only!");
        break; // repeats without this.
        delete_list();
        goto beginning;
        // this doesn't uninitialize the array but I wanted to show the effort.
      }
      words[i].length = word_index;
      strncpy(words[i].prefix, word,
              words[i].length >= 4 ? 4 : words[i].length);
      i++;
      word_index = 0;
    } else {
      // Add the current character to the current word:
      if (word_index < MAX_WORDS_LENGTH - 1) {
        word[word_index] = c;
        word_index++;
      }
    }
  }
  // Add the last word to the list (if any):
  if (word_index > 0) {
    words[i].length = word_index;
    strncpy(words[i].prefix, word, words[i].length >= 4 ? 4 : words[i].length);
    i++;
  }

  // Sort the words alphabetically:
  for (int k = 0; k < i - 1; k++) {
    for (int l = k + 1; l < i; l++) {
      if (strcasecmp(words[k].prefix, words[l].prefix) > 0) {
        // Swap the words:
        struct word temp = words[k];
        words[k] = words[l];
        words[l] = temp;
      }
    }
  }

  // Update the pointers in the linked list:
  for (int k = 0; k < i - 1; k++) {
    words[k].next = &words[k + 1];
  }
  words[i - 1].next = NULL;

  alphabetize(&words[0]);
  print_list();

firstSearch: // goto working as intended at this moment.
  head = &words[0];
  while (head != NULL) {
    if (head->length > 1) {

      printf("\n\n\n");
      char searchsentence1[4];
      center_text_no_args("please" MAG " search" BLK " up to the first " MAG
                          "four" BLK " letters.\n");

      printf(BLK);
      // fgets(searchsentence1, 4, stdin);
      scanf(" %[^\n]", searchsentence1);
      int searchsentence1Length =
          strlen(searchsentence1) >= 4 ? 4 : strlen(searchsentence1);

      int searchsentence_is_upper =
          upperInChar(searchsentence1, searchsentence1Length);
      // printf("searchsentence_is_upper: %d\t \n\n", searchsentence_is_upper);
      if (searchsentence_is_upper == 0) {
        // printf("no caps in the search \n \n");
      } else if (searchsentence_is_upper == 1) {
        printf("capital letters included in the search\n ");
      }
      // * * searchsentence1 uppercase based searching
      // if you have an F uppercase in search. have to be insensitive and dont
      // lowercase char

      struct word *result =
          search_word_one(searchsentence1, strlen(searchsentence1));

      if (result != NULL) {
        printf("search" CYN " results" BLK " --- prefix:\t" CYN "%s" BLK
               " length:\t " CYN "%d\n\n",
               result->prefix, result->length);
        printf(BLK);
      } else {
        goto firstSearch;
      }
      center_text_no_args("would you like to search again? Y \n");
      scanf(" %c", &search_again);
      if (search_again == 'y' || search_again == 'Y') {
        goto firstSearch;
      }
      break;
    } else {
      printf("there is no linked list data to present: \n");
      break;
    }
  }

  do {
    // printf("linked list data presented below: {prefix: up to 4 letters}
    // {length: of word}  \n ");

    head = &words[0];
    while (head != NULL) {
      if (head->length > 1) {
        printf("linked list data presented below: {prefix: up to 4 letters} "
               "{length: of word}\n\n\n");
        break;
      } else {
        printf("there is no linked list data to present: \n");
        break;
      }
    }

    print_list();
    printf("\n \n \n");
    // printf("below is an input that interacts with a linked list.\n");
    // printf("a to add a word to the linked list data. prefix up to 4 letters
    // and length is saved\n"); printf("s to do a sensitive search. S for an
    // insensitive search\n"); printf("d to delete the list");
    printf("a to add a word.s (insensitive) S (sensitive) search modes. d to "
           "delete c to clear\n");
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

      ch = 'G'; // surprised this works and validates while block
                // printf ("G or g to Go again:\n");
                // scanf(" %c", &ch);
    } else if (list == 'S') {
      // s || S
      char searchsentence[100];
      printf("capitalization matters. search up to 4 letters please: \n");
      // fgets(searchsentence, 4, stdin);
      scanf(" %[^\n]", searchsentence);
      char *prefix = search_word(searchsentence, strlen(searchsentence));
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
      char *prefix = search_word(searchsentence2, strlen(searchsentence2));
      // printf("My Returned Search Result: \t %s\n", prefix);
      head = &words[0];
      search_word_insensitive(searchsentence2, strlen(searchsentence2));

      // char* my_search = search_word_insensitive(searchsentence2,
      // strlen(searchsentence2)); invoking cb and storing as pointer is causing
      // problem with loop on code line 369 printf("search characters: lets see
      // : %s \n", my_search);
      printf("* * * * * * * search results above \n");
      ch = 'G';
    } else if (list == 'd') {
      printf("the list has been deleted \n");
      //          delete_list();
      //          ch = 'g';
      goto beginning; // tried to use to restart the entry of sentence[100]
    } else if (list == 'c') {
      printf(" * * * empty list rendered below: \n\n\n * * * ");
      printf("\033[2J\033[H"); // ANSI escape codes to clear screen
      // printf("Screen cleared!\n");
      ch = 'G';
      // goto beginning;
    } else if (list == 'f') {
      goto fin;
    } else {
      printf("(g | G) to go again please.\n");
      scanf(" %c", &ch);
    }

  } while (ch == 'g' || ch == 'G');
fin:
  if (list == 'f') {
    printf("howd you get here? way to finish strong! \n");
  } else {
    printf("thanks for playing \n");
  }
}
