tuesday wednesday last week:
90 minutes reading and coding x2:

format-specifiers. 

# february 11th:
60 minutes.
The gets() and puts() Functions
The char *gets(char *s) function reads a line from stdin into the buffer pointed to by s until either a terminating newline or EOF (End of File).

11:00pm-12:00am: 
1) https://www.tutorialspoint.com/cprogramming/c_input_output.htm
2) https://www.geeksforgeeks.org/gets-is-risky-to-use/

# february 11th:


<!-- * february 12th: -->
sleep at midnight exact. wake up probably around 7:45am up out of bed 8:30am coding at 9:30am

input and the difference between:        1) string | char output.         2) 1 word output as char      3) whitespace ignoring input that takes whole sentence from the user from scanf()


# 11:00     2/12/2023  {2 hours: from 9:30-11:30am} to start seeing user input that stores every word 
int main() {
  char sentence[75];
  char goodone[100];
  scanf("%[^\n]s", sentence);
  printf("i feel like:  %s today", sentence);
  return 0;

//    char sentence[75];
  scanf("%[^\n]s", goodone);
  printf("i feel like:  %s today", goodone);

//      char sen[100];
//    scanf("%[^\n]s", sen);
//    printf("Output : %s", sen);
//    return 0;
}

# 4:00 another 3 hours in doing loops and strings comparisons and debugging.


# 8:30pm another 3 hours of learning pointers, concatenating userinput 


2/12/2023 learnings:
1) pointers.
2) strcat()  ------------>   char firstName[10] charlast[10] strcat(first_name, char_last)  
3) scanf(%[^\n], varname)    // storing input as variable.
4)    #define VAR_SIZE = 40;     ------>      char restaurant[VAR_SIZE] = 'burger king';

5) You can use  if(food[i] === 'w') { prinf("%c\n", food[i])}    but you can't do the same for whole strings. have to use strncomp. but for looping the standard JS if statement is valid for value comparison.
6) 2d array []. Works like columns and rows, must have a specified value. && storing userinput data into a 2d array.

spent another 4 hours or so totaling close to 10 hours on pointers, strings, 2d matrix
<!-- * february 12th: -->




<!-- ? february 13th -->
# by 12:30 posted an issue spent about 3 hours combining concepts of: structs, 2d arrray, strcopy to load a then-specified 2nd argument string to be appended into the struct, and RAM/pointers w/ struct keys
I  was jumping the gun and going to create the dictionary without knowing much about structs or pointers which was a good waste of about 3 or so hours.


<!-- ? february 13th -->

i attacked the problem of being nowhere at all on being how to set up a linked list and every example discussing malloc.
I resorted to chatGPT to see a global memory-allocated example 
I was getting more help in seeing peoples stack overflow responses and appreciated bias-breaking support saying linked-lists are kind of simple, and make it easy to add/delete
I started focusing more on learning the fundamentals of of the key words in the top of the programmers challenge document
I already knew i understood user input from scanf() and then moving onto fgets()

I googled "static data structure" and everything made more sense on reddit and comments on stack overflow started getting more relevant



<!-- * february 16th: -->
task description: 
initialize the linked list functionality with an iterative loop that stores index+1 based .next object key that navigates the list with [i+1] and to set
 value/understanding of struct

 upon doing so I encountered a problem where I didn't know how to orchestrate the ability to:
 search -> create/delete an item -> search again. If I were to do so with 1 input, I didn't see a way to toggle case insensitivity with 1 input. I looked into clicks.
 It made C made more sense that C doesn't have clicks as a general & operating system based language.

 7:30 search functionality 
<!-- * february 16th: -->

<february 17th>
task: get the search-list input to the second search:
<!--
 I dont want to use fgets() before looking into whether this is automatically true with fgets() i want to use scanf() 
 because I can specify: the new line \n in scanf and make sure the falsy else block condition that would complete listening for the search is also triggered with \n
 This would/should pair the condition to the input. 
-->

I was fixing an issue with:
1) strstr(head->prefix, searchinput)
 returning search results from the linked list that didn't correspond to the search input, returning head->prefix data that included letters at all

It took from 10:30-12:30pm to overcome. Update it took an additional 90 minutes to match the indeces of head->prefix[i] to the searchsentence[i] Done at 2 also ate lunch.  
2:30-8:30pm to get my add_word function to work. Using memset to google what was causing the problem made all the difference.

8:30pm-11:30pm Tried to solve: 
```
  if (strstr(sentence2, "create")) {
    printf("create\ta\tnice\tone\n");
    char new[10];
    // fgets(new, 5, stdin);          // fgets requires length designation. This causes 'sat' for example to be designated to length of 4 
    scanf("%[^\n]s", new);            // before stumbling upon scanf which lets you designate length after input entered, I was using loops and index[i]
    int new_len = strlen(new);
    
    add_word(new, new_len); // heythere 7
    print_list();
  }
```
I solved the length issue at 8:30am the next day 
<february 17th>

 

<february 18>
solved length issue at 8:30 and spent about 9:00am-12:30 rewriting my search function as a void callback function in global scope. 
spent another 90 minutes understanding the concept of returning pointers from a callback function

2:00 Begin working on initializing (deleting) the linked list.
Completed Around 8:30-9:00 and had a multi-hour issue in which typing 1 space bar character into the input fixes everything. I posted an issue in github as well.

10:00 working on learning regex in C and using scanf([a-z]) to constrain characters to lowercase alpha-characters  
<february 18/>

# ways i could've improved my output:
I wanted to return the whole entire prefixArray as a pointer and it seems to be returning 1 value.
I see the requirement is: deleting the current linked list. I am already considering the callback function to accept an argument distinguishing between: delete node | delete all
# ways i could've improved my output:



<!-- EASY || HARD  -->
seeing forloops, array-based indexing, specifying types (like typescript) are a little more familiar with it.

I'm not super strong in typescript so remembering to "think in types" while creating a function: balancing the type of the function with that function's return type while keeping that separate from func params.

structs after a while went from hard to easy because it feels a little bit like a JSON object or even like a [ let userMAP = new Map() ] map object in javascript.
seeing what javascript does for you like memory, & understanding the types on its own without the dev specifying types, makes it a little easier to jump in. 

<!-- focusing on one thing at a time   -->
arguably too personal to be relevant but another thing that made this easy was taking 11 days to finish my next APP. I wanted to finish it in 7 and do this assignment in <10 days (counting from the 7)
I see myself lucking out on being quick with realizing I forgot: <include <string.h>> when doing strlen. And instantly seeing "let" and changing it to "int" or "char" 
I can't imagine learning C while budgeting time to finish a JS app
<!--  -->

I wouldn't say extremely challenging but a good bit hard and surprisingly so: Loop and count the wordlength using [index-1 = ' '] 

<!-- EASY || HARD  -->

<!--  -->

<!-- *  example of input/output -->
each leac easports earn
<!-- * example of input/output -->


questions to google:
linked lists in C without malloc.

<!--  -->

<!--  -->
https://stackoverflow.com/questions/3856317/linked-lists-in-c-without-malloc

<!--  -->

output: the bear is really fast

trying to get the words and separate from '' white space was like 8 hours


massive help was looking at a javascript linked list and seeing how .next would literally be an object key to layer into itself to see another set of data with another:
 navigating into-the-object-ward .next key with a value of i+1 essentially bringing the next data seen in [i+1] to be essentially a .get() at first key and a .nextNode() at 2nd
<!-- * the turning point in the app or atleast the first turning point was understanding why an init data() for loop is just populating and declaring the data.  -->