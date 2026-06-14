# 🎯 My DSA Patterns Journey: Mastering Coding Interviews

Welcome to my personal **DSA Patterns Series** repository! 

After realizing that memorizing individual LeetCode/DSA problems is highly inefficient, I decided to take a step back and focus on **understanding the fundamental algorithmic patterns** behind them. 

This repository serves as my structured progress tracker, code playground, and documentation hub as I learn and implement every major DSA pattern from scratch in **C++**.

---

## 📅 Journey & Progress Tracker

Here is the master checklist of patterns I am covering. I will check them off as I master each pattern!

- [x] **Day 1: Two-Pointer Approach** 
  - [x] Opposite Direction (Palindromes, Pair Sums)
  - [x] Two Inputs (Array Merging)
  - [x] Fast & Slow Pointers (Theory)
- [ ] **Sliding Window**
  - [ ] Fixed Size (Subarray Maximums)
  - [ ] Dynamic Size (Longest Substring)
- [ ] **Prefix Sum & Range Queries**
- [ ] **Fast & Slow Pointers (Linked List Cycle Detection)**
- [ ] **Merge Intervals (Overlapping intervals)**
- [ ] **In-place Reversal of a Linked List**
- [ ] **Tree Breadth-First Search (BFS)**
- [ ] **Tree Depth-First Search (DFS)**
- [ ] **Two Heaps (Running Median)**
- [ ] **Subsets / Backtracking (Combinations, Permutations)**
- [ ] **Modified Binary Search**
- [ ] **Bitwise XOR**
- [ ] **Top 'K' Elements**
- [ ] **K-way Merge**
- [ ] **Dynamic Programming (Knapsack, Fibonacci)**

---

## 📂 Repository Structure

Each pattern gets its own dedicated folder containing theory files, C++ implementations, and dry-run notes:

```text
DSA/
├── 1_TwoPointerApproach/             # Day 1: Two Pointer Techniques
│   ├── 1_palindrome/                 # Palindrome verification problems
│   │   ├── 1_single.cpp              # Single-input string palindrome check
│   │   └── 2_twoinput.cpp            # Double-input string palindrome check
│   ├── 2_arrays/                     # Array manipulation using two pointers
│   │   └── 1_singleinput.cpp         # In-place array reversal
│   ├── 3_pairSum/                    # Two-pointer search on sorted arrays
│   │   └── 1_PairSum.cpp             # Target sum search (O(N) time, O(1) space)
│   └── Theory.md                     # Comprehensive notes & templates on Two Pointers
│
├── Babua DSA Patterns Questions 2025.xlsx  # Categorized pattern questions
├── Revision Sheet.xlsx                     # Revision tracker for spaced repetition
└── .gitignore                              # Git untracked settings
```

---

## 🛠️ The Day-by-Day Workflow

For each pattern, I follow a strict 3-step mastery formula:

1. **Study the Theory:** Read notes, understand the pointer behaviors (e.g., [Theory.md](./1_TwoPointerApproach/Theory.md)), and write down the generic templates.
2. **Implement Core Scenarios:** Write clean C++ implementations for the base cases (such as [1_single.cpp](./1_TwoPointerApproach/1_palindrome/1_single.cpp) or [1_PairSum.cpp](./1_TwoPointerApproach/3_pairSum/1_PairSum.cpp)).
3. **Practice & Track:** Use the spreadsheet tracker `Babua DSA Patterns Questions 2025.xlsx` to practice extra problems on LeetCode/GeeksforGeeks, and schedule spaced repetition review using `Revision Sheet.xlsx`.

---

## 🚀 How to Compile & Run the Code

To run the implementation files locally:

```bash
# Navigate to the specific pattern directory
cd 1_TwoPointerApproach/1_palindrome/

# Compile using g++
g++ -std=c++17 1_single.cpp -o main

# Run the executable
./main
```

---

> *"Don't learn to solve problems. Learn to recognize patterns."* 💻🔥
