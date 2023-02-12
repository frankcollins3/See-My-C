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
