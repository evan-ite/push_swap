## Push Swap Project README

**Introduction**
The Push Swap project is a fundamental algorithm project that focuses on sorting a set of integer values using two stacks and a set of instructions. The goal is to implement a sorting algorithm in C called `push_swap` that efficiently sorts the integers provided as arguments. The main measure of effciency in this project will be number of moves performed on the stacks.

---

**Installation:**

1. Clone the repository:
   ```bash
   git@github.com:evan-ite/push_swap.git
   ```

2. Navigate to the project directory:
   ```bash
   cd push_swap
   ```

3. Compile the project using make:
   ```bash
   make
   ```

---

**Usage:**

Run the game by executing the following command:
```bash
./push_swap [list of numbers]
```
Replace `[list of numbers]` with any (unsorted) list of numbers, without duplicates.

---

**Algorithm in pseudocode**
- While stack a is bigger than 3
    1. Calculate average value of stack a
    2. Is top node of stack a below average? Push node to b
    3. Is top node of stack a above average? Rotate a
- Sort last three nodes in stack a

- While stack b exists
    - For each node in stack b
        1. Find target node in stack a (smallest bigger value)
        2. calculate push cost (how many moves to get both nodes on top and push)
    - Push cheapest node in stack b to stack a

- Rotate stack a until minimum value is on top

---
**Rules and Functionality**
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

---
**Conclusion**
The Push Swap project provides an opportunity to hone skills in C programming, algorithmic thinking, and complexity analysis. By implementing efficient sorting algorithms and adhering to project guidelines, developers can gain valuable insights into algorithmic complexities and best practices in software development.

**Acknowledgements**
- o-reo for creating a visualizer: https://github.com/o-reo/push_swap_visualizer
- checker provided by the 42 Network
