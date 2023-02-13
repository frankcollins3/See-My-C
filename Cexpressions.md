<strcat>
#include <stdio.h>
#include <string.h>

int main() {
#    char lets[100] = "see", see[] = "\thappen";

   // concatenates lets and see
   // the resultant string is stored in lets.
#   strcat(lets, see);

#   puts(lets);
#   puts(see);

   return 0;
}
<strcat/>


<scanf>
#include <stdio.h>
#include <string.h>

*** 1) basic int && char (type numbers or 1 letter) ***
int main() {
  //int age; // declare var

  //scanf("%d", &age);    
  // 1) format specifier 
  // 2) & amprasand for memory address. age is variable.
  // scan f takes 
  //printf("This is my %d", age);


  char letter;
  scanf("%c", &letter);
  printf("I just typed %c", letter);
}
*** 2) 1 word output ***
int main() {
  char entry[100];                                              <!-- intiialize variable to equal or greater than size of expected input) -->
  scanf("%s", entry);                                           <!--- format specifier for string that then outputs the the entry which is referenced by the "%s" in first argument of scanf>
  printf("My String: %s", entry);                               <!-- output the entry as a variable whenever the "%s" appears in the first argument of printF>
  return 0;
}

*** 3) sentence output ***
int main() {
  char sentence[75];
  char goodone[100];
#   scanf("%[^\t]s", sentence);        <!-- this code allows a user to keep hitting enter and to create a couple lines worth of inputs, because it doesn't validate the \n constraint which is met [enter] -->
  printf("i feel like:  %s today", sentence);
  return 0;
}

<scanf/>


<Loop>

*** 1) loop example ***
#include <stdio.h>
#include <string.h>
int main()
{
    char str[] = "Live Your Life";
    int i, j = 0;  
 <!-- *  Traversing the Character array -->
    for (i = 0; i < strlen(str); i++) {  
 <!-- To store first character of String if it is not a whitespace. -->
        if (i == 0 && str[i] != ' ') {
          printf("%c ", str[i]);
        } 
 <!-- To check whether Character is first character of word and if yes store it.  && str[i - 1] == ' ') whitespace checking code. -->
        else if (i > 0 && str[i - 1] == ' ') {
            printf("%c ", str[i]);
        }
    }
    return 0;
}
***  end of loop example 1 ***
* * * * * * * * * * * * * * * * * * * * * * * *


*** 2) loop example ***
#include <stdio.h>
#include <string.h>

char myletter = 'o';


int countO(char *str) {
  int count = 0;
  int length = strlen(str);
  for (int i = 0; i < length; i++) {
    if (str[i] == myletter) {
      count++;
    }
  }
  return count;
}

int main() {
  char str[] = "go for gold";
  int number_of_o = countO(str);
printf("%c appears in %s %d\t", myletter, str, number_of_o);
}


***  end of loop example 2 ***
* * * * * * * * * * * * * * * * * * * * * * * *

*** loop example 3 ***
#include <stdio.h>
#include <string.h>

  int main () {
    int c_count = 0;
    char me[20] = "wow thats Cool";
    for (int i = 0; i < strlen(me); i++) {
        if (me[i] == 'C') {
            //  printf("hey found a C");
            c_count++;
        } else {
            
        }
    }
    printf("also found that c appears %d many times in: %s", c_count, me);
    return 0;
}

*** loop example 3 ***
<c--------loopexampleEND**********/>
   
   
concat user Input to a pre-defined global string
   
   #include <stdio.h>
#include <string.h>


int main () {
int b = 42;  
int *a = &b;  // pointer a (is set to) address of b 
//  printf("b:\t %d\n", b);  // print value of b
//  printf("&b:\t %p\n", &b);  // print memory address of b
//  printf("a:\t %p", a);  // print memory address of A.

//int *sexmemory = &sex;
int lotto = 777;
int *gamble = &lotto;
char fullOfCrap[100] = "Youre full of %[^/n]s";

char pleasantmsg[20] = "Please Enter Input\n";
char input[100];

char destination[45] = "Atleast we didnt: ";

  if (lotto == 777) {
//    printf("you heard");
    printf("my favorite number is %d\n", lotto);
printf("I cant remember the last time I %p\n", gamble);
  } else {
    printf("%s", fullOfCrap);
  } 

  printf("%s", pleasantmsg);
  scanf("%[^\n]s", input);

  strcat(destination, input);
  printf("%s\n", input);
  printf("%s", destination);
  
  return 0;
}




