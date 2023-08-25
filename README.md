# ANSI-C-exercises
Examples of solutions to exercises from the book "The C Programming Language, Second Edition" by B. Kernighan and D. Ritchie.

## Chapter 1 - A Tutorial Introduction
- [x] __Ex 1-1.__ Run the "hello, world" program on your system. Experiment with leaving out parts of the program, to see what errors messages you get. -> [Solution](https://github.com/cd2dot0/ANSI-C-exercises/blob/master/CH1-01-1.c)
- [x] __Ex 1-2.__ Experiment to find out what happens when `printf`'s argument string contains `\c`, where `c` is some character not listed above. -> [Solution](https://github.com/cd2dot0/ANSI-C-exercises/blob/master/CH1-02-1.c)
- [x] __Ex 1-3.__ Modify the temperature conversion program to print a heading above the table. -> [Solution](https://github.com/cd2dot0/ANSI-C-exercises/blob/master/CH1-03-1.c)
- [x] __Ex 1-4.__ Write a program to print the corresponding Celsius to Fahrenheit table. -> [Solution](https://github.com/cd2dot0/ANSI-C-exercises/blob/master/CH1-04-1.c)
- [x] __Ex 1-5.__ Modify the temperature conversion program to print the table in reverse order, that is, from 300 degrees to 0. -> [Solution](https://github.com/cd2dot0/ANSI-C-exercises/blob/master/CH1-05-1.c)
- [x] __Ex 1-6.__ Verify that the expression `getchar() != EOF` is 0 or 1. -> [Solution](https://github.com/cd2dot0/ANSI-C-exercises/blob/master/CH1-06-1.c)
- [x] __Ex 1-7.__ Write a program to print the value of `EOF`. -> [Solution](https://github.com/cd2dot0/ANSI-C-exercises/blob/master/CH1-07-1.c)
- [x] __Ex 1-8.__ Write a program to count blanks, tabs, and newlines. -> [Solution](https://github.com/cd2dot0/ANSI-C-exercises/blob/master/CH1-08-1.c)
- [x] __Ex 1-9.__ Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank. -> [Solution](https://github.com/cd2dot0/ANSI-C-exercises/blob/master/CH1-09-1.c)
- [x] __Ex 1-10.__ Write a program to copy its input to its output, replacing each tab by `\t`, each backspace by `\b`, and each backslash by `\\`. This makes tabs and backspaces visible in an unambiguous way. -> [Solution](https://github.com/cd2dot0/ANSI-C-exercises/blob/master/CH1-10-1.c)
- [x] __Ex 1-11.__ How would you test the word count program? What kinds of input are most likely to uncover bugs if there are any? -> [Solution](https://github.com/cd2dot0/ANSI-C-exercises/blob/master/CH1-11-1.c)
- [x] __Ex 1-12.__ Write a program that prints its input one word per line. -> [Solution](https://github.com/cd2dot0/ANSI-C-exercises/blob/master/CH1-12-1.c)
- [x] __Ex 1-13.__ Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging. -> Solutions: [no. 1 (horizontal)](https://github.com/cd2dot0/ANSI-C-exercises/blob/master/CH1-13-1.c), [no. 2 (vertical)](https://github.com/cd2dot0/ANSI-C-exercises/blob/master/CH1-13-2.c)
- [x] __Ex 1-14.__ Write a program to print a histogram of the frequencies of different characters in its input. -> [Solution](https://github.com/cd2dot0/ANSI-C-exercises/blob/master/CH1-14-1.c)
- [x] __Ex 1-15.__ Rewrite the temperature conversion program of Section 1.2 to use a function for conversion. -> [Solution](https://github.com/cd2dot0/ANSI-C-exercises/blob/master/CH1-15-1.c)
- [x] __Ex 1-16.__ Revise the main routine of the longest-line program so it will correctly print the length of arbitrary long input lines, and as much as possible of the text. -> [Solution](https://github.com/cd2dot0/ANSI-C-exercises/blob/master/CH1-16-1.c)
- [x] __Ex 1-17.__ Write a program to print all input lines that are longer than 80 characters. -> [Solution](https://github.com/cd2dot0/ANSI-C-exercises/blob/master/CH1-17-1.c)
- [x] __Ex 1-18.__ Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines. -> [Solution](https://github.com/cd2dot0/ANSI-C-exercises/blob/master/CH1-18-1.c)
- [x] __Ex 1-19.__ Write a function `reverse(s)` that reverses the character string `s`. Use it to write a program that reverses its input a line at a time. -> [Solution](https://github.com/cd2dot0/ANSI-C-exercises/blob/master/CH1-19-1.c)
- [x] __Ex 1-20.__ Write a program `detab`  that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every `n` columns. Should `n` be a variable or a symbolic parameter? -> [Solution](https://github.com/cd2dot0/ANSI-C-exercises/blob/master/CH1-20-1.c)
- [x] __Ex 1-21.__ Write a program `entab` that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab. When either a tab or a single blank would suffice to reach a tab stop, which should be given preference? -> [Solution](https://github.com/cd2dot0/ANSI-C-exercises/blob/master/CH1-21-1.c)
- [x] __Ex 1-22.__ Write a program to "fold" long input lines into two or more shorter lines after the last non-blank character that occurs before  the `n`-th column of input. Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column. -> [Solution](https://github.com/cd2dot0/ANSI-C-exercises/blob/master/CH1-22-1.c)
- [x] __Ex 1-23.__ Write a program to remove all comments from a C program. Don't forget to handle quoted strings and character constants properly. C comments don't nest. -> [Solution](https://github.com/cd2dot0/ANSI-C-exercises/blob/master/CH1-23-1.c)
- [x] __Ex 1-24.__ Write a program to check a C program for rudimentary syntax errors like unmatched parentheses, brackets and braces. Don't forget about quotes, both single and double, escape sequences, and comments. (This program is hard if you do it in full generality.) -> [Solution](https://github.com/cd2dot0/ANSI-C-exercises/blob/master/CH1-24-1.c)

## Chapter 2 - Types, Operators and Expressions
- [x] __Ex 2-1.__ Write a program to determine the ranges of `char`, `short`, `int`, and `long` variables, both `signed` and `unsigned`, by printing appropriate values from standard headers and by direct computation. Harder if you compute them: determine the ranges of the various floating-point types. -> [Solution](https://github.com/cd2dot0/ANSI-C-exercises/blob/master/CH2-01-1.c)
- [x] __Ex 2-2.__ Write a loop equivalent to the `for` loop above without using `&&` or `||`. -> [Solution](https://github.com/cd2dot0/ANSI-C-exercises/blob/master/CH2-02-1.c)
- [x] __Ex 2-3.__ Write a function `htoi(s)`, which converts a string of hexadecimal digits (including an optional `0x` or `0X`) into its equivalent integer value. The allowable digits are `0` through `9`, `a` through `f`, and `A` through `F`. -> [Solution](https://github.com/cd2dot0/ANSI-C-exercises/blob/master/CH2-03-1.c)
- [x] __Ex 2-4.__ Write an alternative version of `squeeze(s1,s2)` that deletes each character in `s1` that matches any character in the string `s2`. -> [Solution](https://github.com/cd2dot0/ANSI-C-exercises/blob/master/CH2-04-1.c)
- [x] __Ex 2-5.__ Write the function `any(s1,s2)`, which returns the first location in a string `s1` where any character from the string `s2` occurs, or -1 if `s1` contains no characters from `s2`. (The standard library function `strpbrk` does the same job but returns a pointer to the location.) -> [Solution](https://github.com/cd2dot0/ANSI-C-exercises/blob/master/CH2-05-1.c)
- [x] __Ex 2-6.__ Write a function `setbits(x,p,n,y)` that returns `x` with the `n` bits that begin at position `p` set to the rightmost `n` bits of `y`, leaving the other bits unchanged. -> [Solution](https://github.com/cd2dot0/ANSI-C-exercises/blob/master/CH2-06-1.c)
- [x] __Ex 2-7.__ Write a function `invert(x,p,n)` that returns `x` with the `n` bits that begin at position `p` inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged. -> [Solution](https://github.com/cd2dot0/ANSI-C-exercises/blob/master/CH2-07-1.c)
- [x] __Ex 2-8.__ Write a function `rightrot(x,n)` that returns the value of the integer `x` rotated to the right by `n` positions. -> [Solution](https://github.com/cd2dot0/ANSI-C-exercises/blob/master/CH2-08-1.c)
- [x] __Ex 2-9.__ In a two's complement number system, `x &= (x-1)` deletes the rightmost 1-bit in `x`. Explain why. Use this observation to write a faster version of `bitcount`. -> [Solution](https://github.com/cd2dot0/ANSI-C-exercises/blob/master/CH2-09-1.c)
- [x] __Ex 2-10.__ Rewrite the function `lower`, which converts upper case letters to lower case, with a conditional expression instead of if-else. -> [Solution](https://github.com/cd2dot0/ANSI-C-exercises/blob/master/CH2-10-1.c)

## Chapter 3 - Control Flow
- [x] __Ex 3-1.__ Our binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside). Write a version with only one test inside the loop and measure the difference in run-time. -> [Solution](https://github.com/cd2dot0/ANSI-C-exercises/blob/master/CH3-01-1.c)
- [x] __Ex 3-2.__ Write a function `escape(s,t)` that converts characters like newline and tab into visible escape sequences like `\n` and `\t` as it copies the string `t` to `s`. Use a `switch`. Write a function for the other direction as well, converting escape sequences into the real characters. -> Solution: [escape(s,t)](https://github.com/cd2dot0/ANSI-C-exercises/blob/master/CH3-02-1.c), [reescape(r,s)](https://github.com/cd2dot0/ANSI-C-exercises/blob/master/CH3-02-2.c)
- [x] __Ex 3-3.__ Write a function `expand(s1,s2)` that expands shorthand notation like `a-z` in the string `s1` into the equivalent complete list `abc...xyz` in `s2`. Allow for letters of either case and digits, and be prepared to handle cases like `a-b-c` and `a-z0-9` and `-a-z`. Arrange that a leading or trailing `-` is taken literally. -> [Solution](https://github.com/cd2dot0/ANSI-C-exercises/blob/master/CH3-03-1.c)
- [x] __Ex 3-4.__ In a two's complement number representation, our version of `itoa` does not handle the largest negative number, that is, the value of `n` equal to `-(2 to power (wordsize - 1))`. Explain why not. Modify it to print that value correctly, regardless of the machine on which it runs. -> [Solution](https://github.com/cd2dot0/ANSI-C-exercises/blob/master/CH3-04-1.c)
- [x] __Ex 3-5.__ Write the function `itob(n,s,b)` that converts the integer `n` into a base `b` character representation in the string `s`. In particular, `itob(n,s,16)` formats `n` as a hexadecimal integer in `s`. -> [Solution](https://github.com/cd2dot0/ANSI-C-exercises/blob/master/CH3-05-1.c)
- [x] __Ex 3-6.__ Write a version of `itoa` that accepts three arguments instead of two. The third argument is a minimum field width; the converted number must be padded with blanks on the left if necessary to make it wide enough. -> [Solution](https://github.com/cd2dot0/ANSI-C-exercises/blob/master/CH3-06-1.c)

## Chapter 4 - Functions and Program Structure
- [ ] __Ex 4-1.__ Write the function `strrindex(s,t)` which returns the position of the _rightmost_ occurence of `t` in `s`, or -1 if there is none. -> TO DO
- [ ] __Ex 4-2.__ Extend `atof` to handle scientific notation of the form `123.45e-6` where a floating-point number may be followed by `e` or `E` and an optionally signed exponent. -> TO DO
- [ ] __Ex 4-3.__ Given the basic framework, it's straightforward to extend the calculator. Add the modulus (%) operator and provisions for negative numbers. -> TO DO
- [ ] __Ex 4-4.__ Add the commands to print the top elements of the stack without popping, to duplicate it, and to swap the top two elements. Add a command to clear the stack. -> TO DO
- [ ] __Ex 4-5.__ Add access to library functions like `sin`, `exp`, and `pow`. See `<math.h>` in Appendix B, Section 4. -> TO DO
- [ ] __Ex 4-6.__ Add commands for handling variables. (It's easy to provide twenty-six variables with single-letter names.) Add a variable for the most recently printed value. -> TO DO
- [ ] __Ex 4-7.__ Write a routine `ungets(s)` that will push back an entire string onto the input. Should `ungets` know about `buf` and `bufp`, or should it just use `ungetch`? -> TO DO
- [ ] __Ex 4-8.__ Suppose that there will never be more than one character of pushback. Modify `getch` and `ungetch` accordingly. -> TO DO
- [ ] __Ex 4-9.__ Our `getch` and `ungetch` do not handle a pushed-back `EOF` correctly. Decide what their properties ought to be if an `EOF` is pushed back, then implement your design. -> TO DO
- [ ] __Ex 4-10.__ An alternate organization uses `getline` to read an entire input line; this makes `getch` and `ungetch` unnecessary. Revise the calculator to use this approach. -> TO DO
- [ ] __Ex 4-11.__ Modify `getop` so that if doesn't need to use `ungetch`. Hint: use an internal static variable. -> TO DO
- [ ] __Ex 4-12.__ Adapt the ideas of `printd` to write a recursive version of `itoa`; that is, convert an integer into a string by calling a recursive routine. -> TO DO
- [ ] __Ex 4-13.__ Write a recursive version of the function `reverse(s)`, which reverses the string `s` in place. -> TO DO
- [ ] __Ex 4-14.__ Define a macro `swap(t,x,y)` that interchanges two arguments of type `t`. (Block structure will help.) -> TO DO

## Chapter 5 - Pointers and Arrays
- [ ] __Ex 5-1.__ As written, `getint` treats a `+` or `-` not followed by a digit as a valid representation of zero. Fix it to push such a character back on the input. -> TO DO
- [ ] __Ex 5-2.__ Write `getfloat`, the floating-point analog of `getint`. What type does `getfloat` return as its function value? -> TO DO
- [ ] __Ex 5-3.__ Write a pointer version of the function `strcat` that we showed in Chapter 2: `strcat(s,t)` copies the string `t` to the end of `s`. -> TO DO
- [ ] __Ex 5-4.__ Write the function `strend(s,t)`, which returns 1 if the string `t` occurs at the end of the string `s`, and zero otherwise. -> TO DO
- [ ] __Ex 5-5.__ Write versions of the library functions `strncpy`, `strncat`, and `strncmp`, which operate on at most the first `n` characters of their argument strings. For example, `strncpy(s,t,n)` copies at most `n` characters of `t` to `s`. Full descriptions are in Appendix B. -> TO DO
- [ ] __Ex 5-6.__ Rewrite appropriate programs from earlier chapters and exercises with pointers intead of array indexing. Good possiblities include `getline` (Chapters 1 and 4), `atoi`, `itoa`, and their variants (Chapters 2, 3, and 4), `reverse` (Chapter 3), and `strindex` and `getop` (Chapter 4). -> TO DO
- [ ] __Ex 5-7.__ Rewrite `readlines` to store lines in an array supplied by `main`, rather than calling `alloc` to maintain storage. How much faster is the program? -> TO DO
- [ ] __Ex 5-8.__ There is no error checking in `day_of_year` or `month_day`. Remedy this defect. -> TO DO
- [ ] __Ex 5-9.__ Rewrite the routines `day_of_year` and `month_day` with pointers instead of indexing. -> TO DO
- [ ] __Ex 5-10.__ Write the program `expr`, which evaluates a reverse Polish expression from the command line, where each operator or operand is a separate argument. For example, `expr 2 3 4 + *` evaluates 2×(3+4). -> TO DO
- [ ] __Ex 5-11.__ Modify the program `entab` and `detab` (written as exercises in Chapter 1) to accept a list of tab stops as arguments. Use the default tab settings if there are no arguments. -> TO DO
- [ ] __Ex 5-12.__ Extend `entab` and `detab` to accept the shorthand `entab -m +n` to mean tab stops every `n` columns, starting at column `m`. Choose convenient (for the user) default behavior. -> TO DO
- [ ] __Ex 5-13.__ Write the program `tail`, which prints the last `n` lines of its input. By default, `n` is set to 10, let us say, but it can be changed by an optional argument so that `tail -n` prints the last `n` lines. The program should behave rationally no matter how unreasonable the input or the value of `n`. Write the program so it makes the best use of available storage; lines should be stored as in the sorting program of Section 5.6, not in a two-dimensional array of fixed size. -> TO DO
- [ ] __Ex 5-14.__ Modify the sort program to handle a `-r` flag, which indicates sorting in reverse (decreasing) order. Be sure that `-r` works with `-n`. -> TO DO
- [ ] __Ex 5-15.__ Add the option `-f` to fold upper and lower case together, so that case distinctions are not made during sorting; for example, `a` and `A` compare equal. -> TO DO
- [ ] __Ex 5-16.__ Add the `-d` ("directory order") option, which makes comparisons only on letters, numbers and blanks. Make sure it works in conjunction with `-f`. -> TO DO
- [ ] __Ex 5-17.__ Add a field-searching capability, so sorting may be done on fields within lines, each field sorted according to an independent set of options. (The index for this book was sorted with `-df` for the index category and `-n` for the page numbers.) -> TO DO
- [ ] __Ex 5-18.__ Make `dcl` recover from input errors. -> TO DO
- [ ] __Ex 5-19.__ Modify `undcl` so that it does not add redundant parentheses to declarations. -> TO DO
- [ ] __Ex 5-20.__ Expand `dcl` to handle declarations with function argument types, qualifiers like `const`, and so on. -> TO DO

## Chapter 6 - Structures
- [ ] __Ex 6-1.__ Our version of `getword` does not properly handle underscores, string constants, comments, or preprocessor control lines. Write a better version. -> TO DO
- [ ] __Ex 6-2.__ Write a program that reads a C program and prints in alphabetical order each group of variable names that are identical in the first 6 characters, but different somewhere thereafter. Don't count words within strings and comments. Make 6 a parameter that can be set from the command line. -> TO DO
- [ ] __Ex 6-3.__ Write a cross-referencer that prints a list of all words in a document, and for each word, a list of the line numbers on which it occurs. Remove noise words like "the," "and," and so on. -> TO DO
- [ ] __Ex 6-4.__ Write a program that prints the distinct words in its input sorted into decreasing order of frequency of occurrence. Precede each word by its count. -> TO DO
- [ ] __Ex 6-5.__ Write a function `undef` that will remove a name and definition from the table maintained by `lookup`  and `install`. -> TO DO
- [ ] __Ex 6-6.__ Implement a simple version of the `#define` processor (i.e., no arguments) suitable for use  with C programs, based on the routines of this section. You may also find `getch` and `ungetch` helpful. -> TO DO

## Chapter 7 - Input and Output
- [ ] __Ex 7-1.__ Write a program that converts upper case to lower or lower case to upper, depending on the name it is invoked with, as found in `argv[0]`. -> TO DO
- [ ] __Ex 7-2.__ Write a program that will print arbitrary input in a sensible way. As a minimum, it should print non-graphic characters in octal or hexadecimal according to local custom, and break long text lines. -> TO DO
- [ ] __Ex 7-3.__ Revise `minprintf` to handle more of the other facilities of `printf`. -> TO DO
- [ ] __Ex 7-4.__ Write a private version of `scanf` analogous to `minprintf` from the previous section. -> TO DO
- [ ] __Ex 7-5.__ Rewrite the postfix calculator of Chapter 4 to use `scanf` and/or `sscanf` to do the input and number conversion. -> TO DO
- [ ] __Ex 7-6.__ Write a program to compare two files, printing the first line where they differ. -> TO DO
- [ ] __Ex 7-7.__ Modify the pattern finding program of Chapter 5 to take its input from a set of named files or, if no files are named as arguments, from the standard input. Should the file name be printed when a matching line is found? -> TO DO
- [ ] __Ex 7-8.__ Write a program to print a set of files, starting each new one on a new page, with a title and a running page count for each file. -> TO DO
- [ ] __Ex 7-9.__ Functions like `isupper` can be implemented to save space or to save time. Explore both possibilities. -> TO DO

## Chapter 8 - The UNIX System Interface
- [ ] __Ex 8-1.__ Rewrite the program `cat` from Chapter 7 using `read`, `write`, `open`, and `close` instead of their standard library equivalents. Perform experiments to determine the relative speeds of the two versions. -> TO DO
- [ ] __Ex 8-2.__ Rewrite `fopen` and `_fillbuf` with fields instead of explicit bit operations. Compare code size and execution speed. -> TO DO
- [ ] __Ex 8-3.__ Design and write  `_flushbuf`, `fflush`, and `fclose`. -> TO DO
- [ ] __Ex 8-4.__ The standard library function `int fseek(FILE *fp, long offset, int origin)` is identical to `lseek` except that `fp` is a file pointer instead of a file descriptor and return value is an `int` status, not a position. Write `fseek`. Make sure that your `fseek` coordinates properly with the buffering done for the other functions of the library. -> TO DO
- [ ] __Ex 8-5.__ Modify the `fsize` program to print the other information contained in the inode entry. -> TO DO
- [ ] __Ex 8-6.__ The standard library function `calloc(n,size)` returns a pointer to `n` objects of size `size`, with the storage initialized to zero. Write `calloc`, by calling `malloc` or by modifying it. -> TO DO
- [ ] __Ex 8-7.__ `malloc` accepts a size request without checking its plausibility; `free` believes that the block it is asked to free contains a valid size field. Improve these routines so they make more pains with error checking. -> TO DO
- [ ] __Ex 8-8.__ Write a routine `bfree(p,n)` that will free any arbitrary block `p` of `n` characters into the free list maintained by `malloc` and `free`. By using `bfree`, a user can add a static or external array to the free list at any time. -> TO DO
