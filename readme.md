# Phitron — Fundamentals of Competitive Programming

This repository is my **C programming learning journey** — from the very first `printf()` up to
pointers, recursion and 2D arrays. Everything here comes from the Phitron Foundation Track
course: class notes, problem statements, my solutions, quizzes and practice sets.

I keep it organized so that I can revise any topic later without rewatching the class. Every
folder follows the same shape:

```text
Module-X/
├── readme.md     ← my notes for the topic (definition, example, code, corrections)
├── quiz.md       ← practice questions with answers (as comments)
├── main.c        ← problem statements + my solutions (kept as block comments)
├── input.txt     ← last input I tested with
└── output.txt    ← output produced for that input
```

**How to use a `main.c`:** all solutions are commented out. To run one, uncomment it and comment
the others, then compile:

```bash
gcc -Wall -Wextra -o main main.c
./main < input.txt
```

---

## Folder Layout

```text
.
├── C/                      ← everything from the C course
│   ├── Module-1 … 18       ← theory modules + extra-practice sets
│   ├── Assaignment-1..3    ← graded assignment problem sets
│   ├── Mid-Exam            ← my mid-exam solutions
│   └── week-1, week-2      ← weekly problem-solving practice
├── Pattern-Printing/       ← 11 nested-loop patterns (index below)
├── Plan.md                 ← my 52-week study plan
└── readme.md               ← this file
```

---

## Topic Index

### Core Modules

| Module | Topic | Notes | Quiz |
| ------ | ----- | ----- | ---- |
| [Module 1](C/Module-1/readme.md) | Introduction to Programming with C — first program, `stdio.h`, `main()`, input/output | ✓ | ✓ |
| [Module 2](C/Module-2/readme.md) | Operators and Conditional Statements — arithmetic, `if` / `else`, comparison | ✓ | ✓ |
| [Module 3](C/Module-3/readme.md) | Loops — `while`, `for`, `do-while`, break/continue | ✓ | ✓ |
| [Module 5](C/Module-5/readme.md) | Conditions Problem Set — practice problems on `if`/`else` | ✓ | — |
| [Module 6](C/Module-6/readme.md) | Loops Problem Set — practice problems on loops | ✓ | ✓ |
| [Module 7](C/Module-7/readme.md) | Arrays — declaration, indexing, traversal, common mistakes | ✓ | ✓ |
| [Module 9](C/Module-9/readme.md) | Array Insert, Delete, Swap and Reverse | ✓ | ✓ |
| [Module 10](C/Module-10/readme.md) | Strings — character arrays, `\0`, input, iteration | ✓ | ✓ |
| [Module 11](C/Module-11/readme.md) | String Functions — `strcpy`, `strcat`, `strcmp` | ✓ | ✓ |
| [Module 13](C/Module-13/readme.md) | Nested Loop Recap — star patterns and pair sum | ✓ | ✓ |
| [Module 14](C/Module-14/readme.md) | Functions — syntax, 4 combinations, scope, math functions | ✓ | ✓ |
| [Module 15](C/Module-15/readme.md) | Pointers — address, dereference, pass by value/reference, arrays as pointers | ✓ | — |
| [Module 17](C/Module-17/readme.md) | Recursion — call stack, base case, stack overflow, recursive array printing | ✓ | ✓ |
| [Module 18](C/Module-18/readme.md) | 2D Arrays and Matrices — declaration, storage, matrix types, diagonals | ✓ | ✓ |

> Modules 4, 8, 12 and 16 are not in this repo — I have no notes for them yet.

### Extra Practice Sets

| Folder | Topic | Notes |
| ------ | ----- | ----- |
| [Module 10.5](C/Module-10.5-Practice/readme.md) | Practice: Arrays + Strings | ✓ |
| [Module 11.5](<C/Module-11.5(Extra-Practice)/readme.md>) | Frequency Array and String Compare | ✓ |
| [Module 14.5](<C/Module-14.5(extraPractice)/>) | Shape problems (P. Shape1, T. Shape2) | code only |
| [Pattern-Printing](Pattern-Printing/readme.md) | 11 nested-loop patterns — square to diamond | ✓ |

### Assignments, Exams and Weekly Practice

| Folder | What is inside |
| ------ | -------------- |
| [Assignment 1](C/Assaignment-1/) | 5 problems: Panta Vat, Multiplication, Divisible by 3, Divisible by 3 and 7, Punjabi and Shoes |
| [Assignment 2](C/Assaignment-2/) | 5 problems: I Want More Assignments, Positive/Negative Range, Odd Indexes in Reverse, Sum of Pos/Neg, Update Index then Print Reverse |
| [Assignment 3](C/Assaignment-3/) | 5 problems: `odd_even()`, `is_palindrome()`, `count_before_one()`, number pattern, diamond pattern |
| [Mid-Exam](C/Mid-Exam/readme.md) | 5-problem contest set: divisibility, consonants, farmers and days, letter counting, letter frequency |
| [Week 1](<C/week-1(problem-solving)/readme.md>) | Problem solving: zero/non-zero, marks, multiple or not, floating point, read 4 types |
| [Week 2](<C/week-2(problem-solving)/readme.md>) | Problem solving: next alphabet, Ali Baba and puzzles, divisors, lucky numbers |
| [Extra Contest](C/extraContest/) | Multiply Them! (two-number multiplication) |

---

## How I Write My Notes

Every note answers four questions:

1. **What is this?** — a simple definition first
2. **How does it work?** — step by step, with a small example
3. **How do I use it?** — code with expected output
4. **Why should I understand it?** — where it matters later

At the end of each note you will find:

- **Quick Revision** — the whole topic on one screen
- **Important Corrections** — things I got wrong first (kept visible on purpose)
- **What to Learn Next** — the closely related topics that come next

---

## Progress

| Stage | Status |
| ----- | ------ |
| Modules 1–3 (basics, operators, loops) | ✅ done |
| Modules 5–7 (problem sets, arrays) | ✅ done |
| Modules 9–11 (array tricks, strings, string functions) | ✅ done |
| Modules 13–15 (nested loops, functions, pointers) | ✅ done |
| Modules 17–18 (recursion, 2D arrays and matrices) | ✅ done |
| Extra practice + Pattern-Printing | ✅ done |
| Assignments 1–3 + Mid-Exam | ✅ done |
| Weeks 1–2 problem solving | ✅ done |
| Modules 4, 8, 12, 16 | ⬜ no notes yet |

**Current stage:** finished the 2D array and matrix module — the C basics track through Module 18
is covered. Next up: keep solving problem sets and continue with the follow-on modules (transpose,
matrix operations, then the course's next topic) as they come.

---

## Course

- **Platform:** Phitron — Fundamentals of Competitive Programming
- **Study plan:** [Plan.md](Plan.md) (52-week plan around the course + internship)
