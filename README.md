# Push Swap

## Description
The Push Swap project is a simple algorithm project that involves sorting a set of integer values using two stacks and a set of instructions. The goal is to write a program in C called `push_swap` that calculates and displays the smallest program, made of Push Swap language instructions, that sorts the integers received as arguments.

Writing a sorting algorithm is an essential step in a developer’s journey. It is often the first encounter with the concept of complexity. Sorting algorithms and their complexity are part of the classic questions discussed during job interviews. This project provides an opportunity to gain familiarity with these concepts and algorithms, especially focusing on their complexity.

## Project Details
- The project involves sorting a set of integers into ascending order using two stacks named a and b.
- At the beginning:
  - Stack a contains a random amount of negative and/or positive numbers that cannot contain duplicates.
  - Stack b is initially empty.
- The following operations are available to manipulate both stacks:
  - `sa` (swap a): Swap the first 2 elements at the top of stack a.
  - `sb` (swap b): Swap the first 2 elements at the top of stack b.
  - `ss`: Perform `sa` and `sb` simultaneously.
  - `pa` (push a): Take the first element at the top of b and put it at the top of a.
  - `pb` (push b): Take the first element at the top of a and put it at the top of b.
  - `ra` (rotate a): Shift up all elements of stack a by 1.
  - `rb` (rotate b): Shift up all elements of stack b by 1.
  - `rr`: Perform `ra` and `rb` simultaneously.
  - `rra` (reverse rotate a): Shift down all elements of stack a by 1.
  - `rrb` (reverse rotate b): Shift down all elements of stack b by 1.
  - `rrr`: Perform `rra` and `rrb` simultaneously.
- The `push_swap` program must:
  - Take as an argument the stack a formatted as a list of integers, with the first argument at the top of the stack.
  - Display the smallest list of instructions possible to sort the stack a, with the smallest number being at the top.
  - Separate instructions by a newline character.
  - Sort the stack with the lowest possible number of operations.
  - Handle errors properly and display "Error" followed by a newline on the standard error in case of any error.

## Usage
To configure the program (on Linux):
```bash
make
```

To use the `push_swap` program:
```bash
./push_swap [list_of_integers]
```
