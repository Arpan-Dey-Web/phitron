# AGENTS.md

## Purpose

This repository contains my complete programming learning journey from the beginning of the Phitron Foundation Track until I finish the course.

The main purpose of this repository is to keep my learning materials, class notes, code, problem-solving practice, corrections, and progress organized in a way that remains useful for revision and future interview preparation.

These instructions apply to AI agents working on this repository.

---

# 1. Core Principle

When I provide raw notes from a class, lecture, video, or personal learning session, do not simply correct grammar or rewrite the text word-for-word.

Transform the raw notes into a:

> **clear, technically correct, well-explained, beginner-friendly study note**

The final note should help me understand the concept later without needing to rewatch the class immediately.

Preserve what I actually learned that day. Do not turn a daily note into a large roadmap or unrelated tutorial.

---

# 2. Learning Context

I am following a long-term programming course. The course progressively covers:

- C programming
- C++ programming
- Data Structures
- Algorithms
- Competitive Programming / Problem Solving

The course itself is the main learning path.

AI assistance should support the course instead of constantly replacing or expanding the course syllabus.

Do not introduce advanced topics just because they are important for Big Tech interviews unless they are directly related to the current lesson or specifically requested.

---

# 3. Note-Writing Workflow

Whenever I provide raw notes, follow this process:

### Step 1 — Understand the raw notes

Identify:

- What topics were actually taught
- What examples were used
- What terminology I learned
- What questions or explanations are already present
- Which statements are technically incorrect or incomplete

### Step 2 — Correct technical mistakes

Fix inaccurate programming concepts before producing the final note.

Do not preserve an incorrect explanation just because it appeared in my raw notes.

If a concept is commonly misunderstood, explicitly mark it as an **Important Correction** or **Important Note**.

### Step 3 — Improve the explanation

For each important concept, prefer this structure:

1. Concept name
2. Simple definition
3. How it works
4. Small example
5. Code example when useful
6. Expected output when useful
7. Important notes / common mistakes

The explanation should be detailed enough for revision but should remain appropriate for the level of the lesson.

### Step 4 — Preserve the learning order

Keep topics in approximately the same order in which they were learned unless rearranging them clearly improves understanding.

Do not unnecessarily reorganize a lesson into an advanced curriculum.

### Step 5 — Add a short revision section

At the end, include a concise:

- Quick Revision
- Key Takeaways

Use whichever heading fits the note naturally.

### Step 6 — Add a short "What Next?" section

At the very end, add only a short section explaining:

> Based on today's topic, what should I understand next?

This section should contain only a few closely related concepts.

Do not add a long career roadmap, Big Tech roadmap, system design roadmap, or unrelated advanced syllabus unless I explicitly ask for it.

---

# 4. Explanation Style

Use clear English for the notes unless I explicitly request another language.

Technical terms should stay in their standard English form, such as:

- variable
- memory address
- pointer
- function
- compiler
- runtime
- data type
- stack
- heap
- array
- recursion
- time complexity

When a technical term is difficult, explain it using simple language first and then give the technical meaning.

Prefer concrete examples over abstract explanations.

Use small code snippets rather than unnecessarily large programs.

---

# 5. Beginner-Friendly Standard

The notes must be understandable to someone who is still building their programming fundamentals.

Avoid assuming advanced knowledge.

For example, instead of only saying:

> `&x` is the address-of operator.

Explain:

> `&x` gives the memory address of `x`. Functions such as `scanf()` need this address when they have to store a value inside the variable.

Then show a small example.

---

# 6. Technical Accuracy Rules

Always prioritize correctness over preserving my original wording.

Important examples:

- `int main()` returns an `int`; it does not mean that `main()` returns nothing.
- `stdio.h` provides declarations and related library definitions needed for standard I/O usage; do not incorrectly describe it as simply containing the complete implementation of `printf()`.
- C does not have a built-in `string` type in the same sense as many higher-level languages; C strings are represented using character arrays terminated by `\\0`.
- `&variable` in `scanf()` refers to the variable's memory address.
- Typical sizes such as `int = 4 bytes` and `long long = 8 bytes` are common, but exact sizes should not be presented as universal unless the C standard guarantees them.
- Signed integer overflow is undefined behavior in C; do not describe overflow as guaranteed to produce a specific garbage value.

When size, range, or behavior depends on the implementation, clearly say so.

---

# 7. Code Standards

All code added to learning notes should be:

- syntactically valid when practical
- beginner-friendly
- properly formatted
- consistent with the language/version being learned
- accompanied by a short explanation when the code introduces a new concept

Use C code for C lessons and C++ code for C++ lessons.

Do not silently mix C and C++ syntax.

When a distinction matters, explicitly point it out.

---

# 8. Examples and Output

When an example produces visible output, show the expected output.

Example:

```c
printf("Hello\\nWorld");
```

Output:

```text
Hello
World
```

For implementation-dependent behavior, do not claim an exact output unless it is guaranteed.

---

# 9. Memory and Low-Level Concepts

When the lesson involves memory, explain concepts progressively:

```text
Variable
  ↓
Memory
  ↓
Memory Address
  ↓
Pointer
```

Do not jump directly into advanced pointer concepts when the lesson is still about variables and basic input/output.

The goal is to build the mental model step by step.

---

# 10. Problem-Solving Focus

As the course progresses toward Data Structures and Algorithms, notes should increasingly include:

- intuition
- step-by-step reasoning
- edge cases
- complexity when relevant
- common mistakes
- why one approach is preferable to another

For algorithm notes, prefer:

```text
Problem
↓
Idea / Intuition
↓
Approach
↓
Step-by-step Example
↓
Code
↓
Complexity
↓
Common Mistakes
```

Do not add time/space complexity to trivial syntax notes unless it is useful.

---

# 11. Avoid Over-Engineering Notes

Do not turn every lesson into a huge article.

The note length should match the lesson.

A simple syntax lesson should stay focused.

A difficult algorithm should receive a deeper explanation.

Depth should follow the complexity of the topic.

---

# 12. What NOT to Do

Do not:

- rewrite my notes without checking technical accuracy
- add unrelated topics
- insert a complete Big Tech preparation roadmap into every daily note
- make every note overly advanced
- use unnecessary jargon without explanation
- assume that memorizing syntax means understanding the concept
- remove useful examples from my original notes without a reason
- change the topic sequence unnecessarily
- give generic motivational content inside technical notes

---

# 13. Big Tech / High-Level Company Preparation

I am preparing these notes so that my fundamentals will eventually be strong enough for high-level software engineering interviews.

However, this repository should remain a **learning-first repository**, not an interview-roadmap repository.

Only add interview-oriented advice when it is directly relevant to the current topic.

At the end of a lesson, a very short section like this is appropriate:

### What to Learn Next

- Pointers
- Memory addresses
- Type casting

The section should normally be only a few items and directly connected to the day's lesson.

---

# 14. Repository Organization

Keep the repository easy to navigate.

A suitable structure is:

```text
.
├── README.md
├── AGENTS.md
├── C/
│   ├── basics/
│   ├── operators/
│   ├── conditions/
│   ├── loops/
│   ├── functions/
│   ├── arrays/
│   ├── pointers/
│   ├── strings/
│   └── ...
├── C++/
│   └── ...
├── Data-Structures/
│   └── ...
├── Algorithms/
│   └── ...
└── Problem-Solving/
    └── ...
```

The exact structure can evolve with the course.

Do not create unnecessary directories merely to make the repository look complex.

---

# 15. README.md Standard

The root `README.md` should be a high-level index of the learning journey.

It should contain things such as:

- what the repository is
- current learning stage
- course information
- topic index
- links to important notes
- progress tracking

Do not put every detailed daily explanation into the root README.

Detailed lessons should live in their appropriate folders/files.

---

# 16. Daily Lesson Naming

Use clear, predictable names for lesson files.

Example:

```text
Day-01-Introduction-to-C.md
Day-02-Variables-and-Data-Types.md
Day-03-Operators.md
```

If the course already provides a specific lesson numbering system, follow that numbering instead.

Avoid inconsistent names such as:

```text
Day1.md
c-basic-final.md
newnotes2.md
```

---

# 17. GitHub-Friendly Markdown

All notes should be comfortable to read directly on GitHub.

Use:

- clear headings
- tables when comparison helps
- fenced code blocks
- short paragraphs
- bullet lists where appropriate
- consistent terminology

Avoid excessive formatting, unnecessary emojis, or decorative content.

---

# 18. When I Ask for a Note Improvement

If I say something like:

> "Here is my note, make it better"

assume I want the complete cleaned-up version, not only a list of corrections.

The result should be ready to paste into the repository.

If I say:

> "Explain this more"

expand only that concept instead of rewriting the entire lesson unless necessary.

If I say:

> "Make it short"

reduce the explanation while keeping the technical correctness.

---

# 19. Preserve My Learning Progress

Do not assume that a future concept has already been learned just because it appears in an explanation.

Introduce concepts gradually and label prerequisites when needed.

For example:

> This will become clearer when pointers are introduced later.

This helps maintain a realistic learning progression.

---

# 20. Default Output Format for Raw Daily Notes

Unless I request a different format, use this structure:

```text
# Day X — Topic Name

## 1. Topic
### Definition
### Explanation
### Example
### Code
### Output / Result
### Important Note

## 2. Next Topic
...

# Quick Revision

# Important Corrections

# What to Learn Next
```

Not every section is mandatory for every topic. Use only the sections that improve understanding.

---

# Final Rule

The purpose of this repository is to build a strong technical foundation over the duration of the course.

Every note should answer three questions clearly:

1. **What is this?**
2. **How does it work?**
3. **Why should I understand it?**

For code-based topics, also answer:

4. **How do I use it?**

Always optimize for **understanding, accuracy, revision value, and gradual progression**.
