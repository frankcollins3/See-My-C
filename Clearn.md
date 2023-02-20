<C:                                                                     C is not a Complex Language!!                   >

 printf and scan are libraries within #include <stdio.h>
C does not use camelcase:                       c = getchar()

<Variables          int, float, double, char, void >
  int i = 0, j = 0;  ||   int* p1, p2;                // you can do this! save a line of code.


'\0' is referred to as NULL character or NULL terminator It is the character equivalent of integer 0(zero) as it refers to nothing In C language it is generally used to mark an end of a string.
strict equality in C :      ==

 In C, storage for global variables (declared outside of any function) is allocated before execution of the main function starts. 

Macro is defined by #define directive. Whenever a macro name is encountered by the compiler, it replaces the name with the definition/value of the macro. ITS NOT A VARIABLE AND CANT BE CHANGED but it seems like var

*** boolean ***
<!-- "Flip A Value"         instead of reassigning value:  -->
bool whitespace_reached = false
whitespace_reached = true;
myVal = !myVal;       // redeclare a variable as the opposite if its true and it was declared as false.
<!--  -->
*** boolean end ***

<!-- format specifiers -->
no format specifier for boolean we can use the 
<!--  -->
<Variables/>


<Char>
Because an int is just an int but a string (array of char) is more than just a char. The convention in C is to use a pointer to the first char of the string to represent a string.
<Char/>


<scanF>
scanf() needs to know the memory location of a variable in order to store the input from the user.
So, the ampersand will be used in front of the variable (here ch || int) to know the address of a variable.

# reading a word in C:            |syntax|:               scanf("%s", stringvariable);          
<!-- a string is an array of characters in C -->
1) First, initailize the char array to a size equal or greater than the value of the expected input from user.        <!-- * char word[100] --> 
<!-- char word[100] word is then treated as a pointer to store the char values. -->

# Write a C program to read sentences as input from the user.     |syntax|:             scanf("%[^\n]s", sen)
<!-- "%[^\n]s"          : So scanf("%[^\n]", s); will read all characters until you reach \n (or EOF ) and put them in s.     {\n: newline} {EOF: end of file} -->
Here, %[ ] is the scanset specifier.    scanf will process only those characters which are part of scanset.
If the first character of the scanset is ‘^’, then the specifier will stop reading after the first occurrence of that character.
*** ^\n  stands for taking input until a newline isn’t encountered. ***  
<!-- ! one of my problems with taking input from a user is i'm trying to set replit up to take 2 separately created inputs from 2 separate [enter]\n  inputs. Will \t allow me to hit enter and keep grabbing input? -->

int main() {
  char sentence[75];
#   scanf("%[^\t]s", sentence);        <!-- this code allows a user to keep hitting enter and to create a couple lines worth of inputs, because it doesn't validate the \n constraint which is met [enter] -->
  printf("i feel like:  %s today", sentence);
  return 0;
}

<!-- scanf notes  -->
scan f can handle any of the C datatypes:  (int, float, char, double, etc.) But it falls short of handling strings which is an array of characters. (strings contain whitespaces which trigger scanf to stop scan)
fgets can handle those dataTypes, can handle input data from a specified textFile or console, and allows us to specify the size of the user input to be taken. (which makes it user friendly)

scanf(%[A-Z], sentence) this was restricting and specifying permittable characters through the input. 
scanf(%[a-z], sentence) 

<!-- scanf notes  -->
<scanF/>

<fgets>  
<!-- user inputs using fgets function: -->
#  fgets (<stringname>, <size of input>, stdin)               

<!-- stdin  -->
1) stdin is an "input stream", which is an abstract term for something that takes input from the user or from a file. It is an abstraction layer sitting on top of the actual file handling and I/O.
2) The purpose of streams is mainly to make your code portable between different systems.
<!-- stdin  -->



<fgets/>


<c  getchar() putchar() functions/>
  int c;
  printf("enter a value :");
  c = getchar();
  printf("\n you entered: ");
  putchar(c);
  return 0;

expression elaboration:
1) when above code is compiled and executed, it waits for you to input text. 2) enter a text and press enter, 3) the program proceeds and reads the complete line till end 4) and displays it as follows
<!-- * source:                      https://www.tutorialspoint.com/cprogramming/c_input_output.htm -->
<getchar()-putchar()------end/>


https://www.geeksforgeeks.org/gets-is-risky-to-use/
<c      gets() function puts() function/>
<!-- dangerous, deprecated, should not be used.  -->
<!-- ! main.c:11:18: error: too many arguments to function call, expected single argument '__s', have 2 arguments -->           



<gets()-function----------end/>





<Pointers: A POINTER IS JUST A VARIABLE! />
A pointer is a variable whose value is the address of another variable, i.e., direct address of the memory location. you must declare a pointer before using it to store any variable address.
<!-- cant use variable values unless let var = 'value' has been initialized. it makes sense. C teaches you how to think about memory. -->
syntax:                         type *var-name;                                 type is the pointers based type. 

# int    *ip;    / pointer to an integer /                                      <!-- ip integer pointer-->
# double *dp;    / pointer to a double /                                        <!-- double pointer-->
# float  *fp;    / pointer to a float /                                         <!-- float pointer pointer-->
# char   *ch     / pointer to a character /                                     <!-- char is the only pointer that doesn't have the p in the declaration-->

# The Unary operator *              returns the value of the variable located at the address specified by its operand:        * 

sources:
https://www.acodersjourney.com/top-20-c-pointer-mistakes/
<Pointers/>



<string>
JS: let length = str.length;
C: int length = strlen(str);
sizeOf() method to check length.

In C, strings are always null-terminated. This means that the last element of the character array is a “null” character, abbreviated \0.



<!-- <string.h> header file   -->
strlen(s1): returns the length of a string.
strcpy(s1, s2): copies string s2 to s1
strrev(s1): reverses the given string
strcmp(s1, s2): returns 0 if s1 and s2 contain the same string.
strcat(s1, s2): concatenates two strings


<!-- "Hello World" is a 12 character string. The white space counts. And the '\o' that terminates it or the NULL terminating character is part of the string value. JS strips away quite a bit.   -->
int userinputlength = strlen(userinput);
int comparelength = strlen(comparestring);
if (userinputlength > comparelength) { 
<string/>


<c loop/>
for (int i = 0; sentence[i] != '\0'; i++) {         <!-- sentence[i] != '\0' ->       // in C strings are always null terminated, this code checks if the loop has been terminated yet.


   for (j = 0; j < 10; j++ ) {
      printf("Element[%d] = %d\n", j, n[j] );   <!-- expressing [%d] as [i] thats pretty nuts. -->
   }
<!-- line 141) // says: (i=0; if the index of sentence in the loop hasn't been NULL terminated, increment the index upward, proceeding onward into the loop)    -->



delimiter
<c loop-END/>


<!--  -->
<pointers         {varA: points to memory-address of varB} A pointer stores a memory address.>
int b = 42;  
int *a = &b;  // pointer a (is set to) address of b 
  printf("b:\t %d\n", b);  // print value of b
  printf("&b:\t %p\n", &b);  // print memory address of b
  printf("a:\t %p", a);  // print memory address of A.
 <!-- * * * * * * * * * * * * pointer example above.  * * * * * * * * * * * *   -->
  

 every var is a memory location and every memory location has its address defined which can be accessed using ampersand (&) operator, which denotes an address in memory. 
<!-- * intro to pointers-->
int x = 4;
// integer named x is set to 4;
int *px = &x;
 (int type) (* means integer now pointer to a variable)  (px pointer x.) (= set to) (& "the address of")
// "integer pointer named pX is set to the address of x"

we can pass around x by reference instead of value with a pointer. <!-- we break down functions by the actions they perform. -->
all variables (JS, node, C) are stored in memory of RAM. When you say [let myName] or char name[100]  The variable name is like a codename for the address. JS, as a high level language, does that for you.
<!-- https://www.youtube.com/watch?v=2ybLD6_2gKM -->
<!-- *  -->


 



 <!-- "Working with pointers is easy af... Just try different permutation and combinations of & and * until code works like u wanted it to work... Don't complicate easy things.."  😁😁 yt comment. -->
<pointers/>

<memory>
Memory has 2 features: 1) an address (where the memory lives) 2) the value of the memory (the data stored at that location)
1) by setting the address of a variable to the value of another variable. That variable now points to the other one.

https://craftofcoding.wordpress.com/2015/12/07/memory-in-c-the-stack-the-heap-and-static/

The heap is the diametrical opposite of the stack. The heap is a large pool of memory that can be used dynamically – it is also known as the “free store”. This is memory that is not automatically managed –
<memory/>
<!--  -->



<!--  ? linked list: 1) usually with struct 2) the blocks/nodes are data structures 3) Between the structures are so called links that link data structures together.-->
<!-- intro to linked lists https://www.youtube.com/watch?v=MCIwn7mY4jY  -->
links: pointers. We use pointers for the links.
1) define data structure
2)



<!-- tangental but google search: does call of duty use linked lists? call of duty uses a circular loop linked list.-   ->   -->
<!-- end of this youtube lesson. Kind of inspiring to see the yt video kick off explaining concept with the youtubers game made: with cars on a roadway. Each car aware of how fast the other ones are going. -->
<!-- intro to linked lists  https://www.youtube.com/watch?v=MCIwn7mY4jY   -->



A linked list is a way to store a collection of elements. Like an array these can be character or integers. Each element in a linked list is stored in the form of a node.
A node is a collection of two sub-elements or parts. A data part that stores the element and a next part that stores the link to the next node.




<!-- A linked list is formed when many such nodes are linked together to form a chain. Each node points to the next node present in the order.
 The first node is always used as a reference to traverse the list and is called HEAD. The last node points to NULL. -->

 You only have two memory spaces that you can use to store nodes, and those are root and newtemp. When you assign a new node to newtemp the old node doesn't exist anymore.
 you can build a linked list without dynamic memory like malloc but you can't build a linked list without allocating memory.

<!-- 
1)  https://www.reddit.com/r/C_Programming/comments/erssdb/dictionary_in_c_using_linked_list_updated/
2) If a function needs to change a list, given the root pointer, it must be a double pointer. Else, your change just disappers. So
3) Its better to use static (non pointer) variable for head of list, so sou dont have to pass double pointer ;)
 -->
 https://stackoverflow.com/questions/12848765/adding-nodes-to-a-global-linked-list
 https://www.hackerearth.com/practice/data-structures/linked-list/singly-linked-list/tutorial/#:~:text=In%20C%20language%2C%20a%20linked,address%20of%20the%20next%20node.
<!--  ? linked list  -->

<!-- ? dictionary -->
k:v / {key: value} pairing.
I think of a dictionary being a datatype rather than a datastructure, since it could be implemented lots of ways [list, hashtable, tree, self-balancing tree, 

in python: keys can be any data type: (char|string, int|number, boolean)  in javascript a JSON object is a dictionary.
you use the key to get the value so the order doesn't matter so much outside of preferences.

remember * each key/value needs to separately be deallocated.

<!-- *  structs:   key values (JSON is a dictionary)  -->
* void ---> data type when specifying struct fields to reserve the ability to use any data type.

<!-- *  -->
<!-- ? dictionary -->





<surprises>
printf("heres a string: %s\n\n\n\n\n\n, string) // multiple newline is possible.
printf("\n");     
<surprises/>