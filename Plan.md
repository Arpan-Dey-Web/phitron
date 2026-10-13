# 52-Week Plan: Phitron + 8-Hour Internship

## Read this first

- The original plan assumed 10-12 study hours a week. Phitron alone needs about 24-25 hours a week at 6 hours per module day, on top of 40 internship hours (about 65 hours total).
- This version cuts the load: Phitron is the only study track for weeks 1-17, then the DSA/CS/interview plan runs in weeks 18-52.
- Assumption 1: the internship runs Sunday to Thursday, so Friday and Saturday daytime are free. If that is wrong, move the hour caps below to match your real free days.
- Assumption 2: the Phitron topic list is copied from the Phitron tags in your plan document and merged into 17 weeks. It is NOT the official syllabus. Check it against Phitron's real schedule and replace the topic column if it differs.
- Assumption 3: practice days take about 2 hours each (Phitron only says 4-5 problems).

---

## Phase A: Weeks 1-17 (Phitron only)

### Rules for this phase

1. Phitron comes first. There is no separate DSA track, no contests, and no problem-count targets. Phitron's practice problems are your DSA.
2. Cut module time from 6 hours to about 4:
   - Watch explanation-only parts at 1.25-1.5x. Slow down only for code-along.
   - Keep one page of cheat-sheet notes per module, not full notes.
   - Keep "reproduce the key code without looking". That is what builds skill.
3. Split every module into two sittings. Never plan a 6-hour single session on a workday.
4. Take the exam on Friday (Phitron allows this for working students).
5. Lag limit: at most 2-3 days behind. The exam covers that week's content.
6. If a day's hour cap is exceeded, push the rest to the next buffer slot: Mon, Wed or Fri.

### Weekly routine

| Day | Phitron event | What you do | Hour cap |
|---|---|---|---|
| Sat | Module A releases (early access 8 pm) | Sitting 1 of A: video + code-along | 2 |
| Sun | Module B releases | Sitting 2 of A (practice + cheat sheet), then Sitting 1 of B | 3.5 |
| Mon | Practice day | Sitting 2 of B, then Phitron practice set | 3.5 |
| Tue | Module C releases | Sitting 1 of C | 2 |
| Wed | Practice day | Sitting 2 of C, then Phitron practice set, fix gaps before exam | 3.5 |
| Thu | Exam released | Review difficult topics only, then rest | 0.5 |
| Fri | Exam day for you | Exam (2-3 hrs), mistake review, 1 job application (20-30 min) | 3.5 |
| **Total** | | | **18.5** |

Real rest slots: Saturday daytime and Thursday evening. Protect them.

### Week by week

| Week | Phitron topics (verify against official syllabus) | End-of-week checkpoint |
|---|---|---|
| 1 | C syntax, variables, data types, I/O, operators, conditions, for/while loops | Trace a loop by hand. Spot int overflow. |
| 2 | 1D arrays: traversal, searching, updating | Solve a frequency-count problem. |
| 3 | C strings: strlen, strcpy, strcmp, character traversal | Write a palindrome check. |
| 4 | Functions, parameters, return values, nested loops, pointers | Explain why a nested loop is O(N^2). |
| 5 | 2D arrays, matrix operations, recursion | Write a base case and a recursive state. |
| 6 | C++ syntax, cin/cout, dynamic memory (new/delete) | Convert one C solution to C++. |
| 7 | Classes, objects, C++ strings, vector, pair, sort | Use sort with a custom comparator. |
| 8 | Complexity analysis, vector, binary search | Write lower_bound / upper_bound logic. |
| 9 | Singly linked list: node, traverse, insert, delete | Reverse a list. Find the middle. |
| 10 | Doubly linked list, std::list, midterm | Midterm done. Review its mistakes. |
| 11 | Stack, queue (array and linked-list versions) | Solve valid-parentheses style problems. |
| 12 | Binary tree: preorder, inorder, postorder, level order | Compute tree height. |
| 13 | BST, min/max heap, priority_queue | Find the kth largest element. |
| 14 | Graph representation, BFS, DFS | Count connected components on a grid. |
| 15 | Cycle detection (directed, undirected), Dijkstra | Write priority-queue Dijkstra. |
| 16 | Bellman-Ford, negative cycle, Floyd-Warshall, DSU | Write DSU with path compression. |
| 17 | Subset sum, 0/1 knapsack, unbounded knapsack, LCS, merge sort, Kruskal/MST | Explain DP as state, choice, transition, base case. |

Warning: week 17 is overloaded. If the real syllabus really packs all of it into one week, expect spillover into week 18. That is why week 18 is a catch-up week.

### Job search during Phase A

- Week 1, one-time (about 2 hrs): check that the resume, GitHub and portfolio link are current.
- Weeks 1-17: 1 application per week, on Friday after the exam. More than that is not realistic at this load.

---

## Phase B: Weeks 18-52 (after Phitron)

### Weekly pattern

| Day | Focus | Time |
|---|---|---|
| Mon | DSA pattern + problems | 1.5-2 hrs |
| Tue | DSA + CS fundamentals | 1.5 hrs |
| Wed | DSA + timed practice | 1.5-2 hrs |
| Thu | DSA + explain solutions aloud | 1.5 hrs |
| Fri | Light review, error log, applications | 45-60 min |
| Sat | Contest or mock (optional, skip if tired) | 1.5-2 hrs |
| Sun | Revision / recovery | 30 min |

Problem target: 4-6 quality problems a week, plus re-solving older ones. Applications: 3-5 per week from week 18.

### Week by week

| Week | Focus | Do | Done when |
|---|---|---|---|
| 18 | Catch-up + DP review | Finish unfinished Phitron topics. Review knapsack, LCS, LIS. Start the error log. Refresh the one-page resume. | You can solve a basic DP problem without help. |
| 19 | Math, bits, sliding window | GCD, primes, modulo, AND/OR/XOR, shifts. Fixed and variable windows, two pointers. | Window problems feel routine. |
| 20 | Intervals + matrix | Merge/insert intervals, overlap, spiral matrix, rotation. | Merge Intervals solved cold. |
| 21 | Prefix sum + hashing | Prefix sums, difference array, subarray sums with hash map. | Subarray Sum Equals K solved cold. |
| 22 | Topological sort | DAGs, Kahn's algorithm, DFS version, cycle detection. | Course Schedule I and II solved. |
| 23 | Trie | Insert, search, startsWith, prefix search. | Implement Trie from memory. |
| 24 | 2D DP + string DP | Unique paths, min path sum, edit distance. | Edit Distance solved with explanation. |
| 25 | Tree DP + backtracking | Max path sum, subsets, permutations, combination sum. | You see recursion, backtracking and DP as one chain. |
| 26 | Greedy | Sorting + greedy, interval greedy. | You can justify why a greedy choice is safe. |
| 27 | Advanced binary search | Search space, monotonic predicate, min/max feasible answer. | Binary search on answer solved cold. |
| 28 | Monotonic stack + queue | Next greater/smaller, histogram, sliding window maximum. | Daily Temperatures and Histogram solved. |
| 29 | Heap + intervals + greedy | Heap scheduling, top-K, meeting rooms. | Meeting Rooms II solved. |
| 30 | Consolidation + timed mixed mediums | 1 unseen Medium per serious day. Explain, code, test, state complexity. | 3 unseen Mediums done in timed sessions. |
| 31 | First full mock | 2 coding mocks, 1 CS mock, 1 behavioral session. | Written list of weak spots. |
| 32 | Operating systems I | Process, thread, context switch, scheduling, system calls. | Explain each in plain language. |
| 33 | Operating systems II | Mutex, semaphore, race condition, deadlock, virtual memory, paging. | Explain each in plain language. |
| 34 | Networks I | OSI, TCP/IP, TCP vs UDP, handshake, ports. | Explain TCP vs UDP. |
| 35 | Networks II | HTTP, HTTPS, DNS, TLS basics, WebSocket, REST. | Explain what happens when you enter a URL. |
| 36 | Databases I | Relational vs NoSQL, keys, normalization, joins, transactions, ACID. | Write joins from memory. |
| 37 | Databases II | Indexes, EXPLAIN, isolation levels, locks, pagination, N+1. | Spot an N+1 in your own project. |
| 38 | OOP + SOLID | Encapsulation to polymorphism, composition vs inheritance, SOLID. | Answer "composition or inheritance?" |
| 39 | Design patterns | Factory, Strategy, Observer, Decorator, Singleton, DI. Problem, pattern, trade-off. | Name the trade-off for each. |
| 40 | LLD problems | Parking Lot, Tic-Tac-Toe. | Both designed end to end. |
| 41 | LLD + basic HLD | Elevator, rate limiter. Load balancer, cache, queue, CDN, replication. | Draw a basic HLD from scratch. |
| 42 | Resume + project stories | One-page resume. 2-3 project stories (built, why, hard part, trade-offs). | Each story told in 2 minutes. |
| 43 | Behavioral | STAR stories: bug, conflict, failure, ownership, deadline, decision. | 8-10 stories ready. |
| 44 | Full interview simulation | 3 coding mocks, 1 CS, 1 LLD/HLD, 2 behavioral. No notes, no editorial. | Mock feedback logged. |
| 45-49 | Buffer, then bonus | First use these weeks to absorb any slipped week. If none slipped, pick from: segment tree, Fenwick, bitmask DP, bridges/Tarjan, KMP/Z. | Core weeks all complete. |
| 50 | DSA final revision | Re-solve one problem from every Tier 1 pattern. | No Tier 1 pattern feels shaky. |
| 51 | CS + design revision | OS, networks, DB, OOP, LLD, HLD. | Quick-fire answers out loud. |
| 52 | Final mocks + application push | 2 coding mocks, 1 behavioral, resume final check. | Applications still active. |

---

## Slip rules

1. Weeks 45-49 are the buffer. Spend them on slipped weeks first.
2. Still behind after that: drop bonus topics (segment tree, Fenwick, bitmask DP, Tarjan, KMP/Z).
3. Never drop Tier 1: arrays, strings, hashing, two pointers, sliding window, prefix sum, binary search, linked list, stack, queue, trees, heap, BFS/DFS, greedy, backtracking, DP, intervals.
4. One low-energy day is fine. If a whole week is lost, do not try to double up. Move the missed week into the buffer.

## Targets (revised)

- The old target of 200-250 problems is cut. Realistic target: 120-150 quality problems in Phase B, plus Phitron's own practice sets.
- Mock interviews: 10+. Timed sessions: 30+.
- Phitron weeks are judged by finished modules and passed exams, not problem counts.

## Open decisions

1. Which internship days do you actually work? The hour caps depend on it.
2. Is the real target a full stack/frontend job or big-tech SDE-1? If a job is needed soon, increase applications in Phase A and shorten Phase B CS weeks 32-37 to focus on HTTP, databases and OOP.
3. Check the Phitron syllabus and replace the Phase A topic column if my mapping is wrong.
