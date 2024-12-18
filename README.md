<h1 align="center">push_swap</h1>

> Hive Helsinki (School 42) 5th curriculum project (Rank02)

<h2 align="center">
	<a href="#about">About</a>
	<span> · </span>
	<a href="#program">Program</a>
	<span> · </span>
	<a href="#requirements">Requirements</a>
	<span> · </span>
	<a href="#instructions">Instructions</a>
  <span> · </span>
	<a href="#testing">Testing</a>
</h2>

## About
The repository contains a program with a sorting algorithm which sorts data of a stack. The aim is to achieve the smallest number of moves for sorting
the respective numbers of the stack (given as arguments to the program) whereby the sorting instruction are limited by the subject. The project introduced
oneself to the concept of **single linked lists** in c programming and different sorting algorithms.

## Program
The code of the push_swap program makes use of the several modificaton possibilities of single linked lists in order to sort the stack of numbers.
The executable takes an undefined amount of arguments which have to be whole numbers (both positive and negative possible), each number in the range
of min - max int. There are 2 stacks A and B, and the following instructions are allowed to be used in the algorithm:
 - swap a (sa) / swap b (sb)
 - swap a and b (ss)
 - push a (pa) / push b (pb)
 - rotate a (ra) / rotate b (rb)
 - rotate a and b (rr)
 - reverse rotate a (rra) / reverse rotate b (rrb)
 - reverse rotate a and b (rrr)
   
The algorithm makes use of several established sorting algorithm aspects such as partitioning (merge sort), insertion into sorted order (insertion sort),
cost minimization (greedy approach) and final integration (merge sort).
First, 2 numbers are pushed from A to B. Afterwards each number in A is assessed on its cost, that means how many instructions are needed to bring it into
the right position of stack B, whereby this stack is sorted in descending order. The number with the lowest costs is pushed from A to B and the calculations
start again for the remaining numbers in stack A, until 3 numbers remain. These in turn are sorted with a simple function before the sorted numbers of B are
pushed back to A (A rotates max number to top for ensuring correct order of numbers) and if needed, a final rotation is conducted in order to have the smallest
number on top of the stack.

## Requirements
-`gcc` compiler

## Instructions

### 1. Compiling the program

To compile the program, navigate into the repo folder and run:

```
$ make 
```

### 2. Run the program

Run the program by passing x amount of arguments (duplicates are forbidden), e.g.
```
$ ./push_swap 5 2 8 10 1 4
```
The output shows the abbrivations of the needed instructions for sorting the stack.

### 3. Usage of checker file
The repo contains a file which is able to check whether the allowed amount of instructions
for sorting a given set of numbers is met. It either outputs **ok** or **ko** and can be used as follows:
```
$ ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
```

## Testing
This library has been tested with [Francinette](https://github.com/xicodomingues/francinette).
