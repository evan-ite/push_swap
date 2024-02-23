# Push Swap Project README

## Introduction
The Push Swap project is a fundamental algorithm project that focuses on sorting a set of integer values using two stacks and a set of instructions in the Push Swap language. The goal is to implement a sorting algorithm in C called `push_swap` that efficiently sorts the integers provided as arguments.

## Project Overview
Sorting algorithms play a crucial role in software development and are often encountered in various scenarios, including job interviews. This project offers an opportunity to delve into sorting algorithms and their complexities, enhancing one's understanding of algorithmic concepts.

## Learning Objectives
- Rigor in programming
- Proficiency in C programming language
- Understanding of basic algorithms and their complexities
- Implementation of efficient sorting algorithms

## Rules and Functionality
### Version 1: Rules
- The project involves two stacks named `a` and `b`.
- Initially, stack `a` contains a random assortment of negative and/or positive numbers without duplicates.
- Stack `b` is initially empty.
- The objective is to sort the numbers in stack `a` in ascending order.
- The following operations are available:
  - `sa`: Swap the first two elements at the top of stack `a`.
  - `sb`: Swap the first two elements at the top of stack `b`.
  - `ss`: Perform `sa` and `sb` simultaneously.
  - `pa`: Push the first element at the top of stack `b` onto stack `a`.
  - `pb`: Push the first element at the top of stack `a` onto stack `b`.
  - `ra`: Rotate all elements of stack `a` upwards by one position.
  - `rb`: Rotate all elements of stack `b` upwards by one position.
  - `rr`: Perform `ra` and `rb` simultaneously.
  - `rra`: Reverse rotate all elements of stack `a` downwards by one position.
  - `rrb`: Reverse rotate all elements of stack `b` downwards by one position.
  - `rrr`: Perform `rra` and `rrb` simultaneously.

### Project Requirements
- Submission must include a `Makefile` for compiling source files.
- Global variables are prohibited.
- The program `push_swap` must take the stack `a` as an argument, formatted as a list of integers, with the first argument representing the top of the stack.
- The program must display the smallest list of instructions required to sort stack `a`, with the smallest number at the top.
- Instructions must be separated by a newline character.
- The program should aim to minimize the number of operations required for sorting.
- If no parameters are specified, the program should not display anything and return the prompt.
- Error handling should include cases such as non-integer arguments, arguments exceeding integer limits, or duplicate arguments.

## Conclusion
The Push Swap project provides an opportunity to hone skills in C programming, algorithmic thinking, and complexity analysis. By implementing efficient sorting algorithms and adhering to project guidelines, developers can gain valuable insights into algorithmic complexities and best practices in software development.
