# Two Pointer Pattern (DSA Notes)

The **Two Pointer Pattern** is one of the most important DSA patterns used to solve problems on linear data structures such as:

- Arrays
- Strings
- Linked Lists

Instead of using nested loops, we use **two pointers (variables)** that move through the data structure in a controlled manner.

This often reduces complexity from **O(n²)** to **O(n)**.

---

# Why is it called Two Pointers?

Because we use two variables to traverse data.

### Examples

```cpp
int i = 0;
int j = n - 1;
```

or

```cpp
int slow = head;
int fast = head;
```

### Common Pointer Names

- `left`, `right`
- `i`, `j`
- `start`, `end`
- `slow`, `fast`

---

# Types of Two Pointer Patterns

## 1. Opposite Direction Pointers

Pointers start from opposite ends.

```cpp
i = 0;
j = n - 1;
```

Move toward each other.

```cpp
while(i < j)
{
    // compare
    i++;
    j--;
}
```

### Used For

- Palindrome
- Pair Sum in Sorted Array
- Container With Most Water
- Reverse Array

---

## 2. Fast-Slow Pointers

Both start from the beginning.

```cpp
slow = head;
fast = head;
```

### Movement

```cpp
slow = slow->next;       // 1 step
fast = fast->next->next; // 2 steps
```

### Used For

- Detect Cycle
- Find Middle Node
- Happy Number
- Remove Nth Node from End

---

## 3. Sliding Window (Special Two Pointer)

Both pointers move forward.

```cpp
left = 0;
right = 0;
```

### Used For

- Longest Substring
- Maximum Sum Subarray
- Minimum Window Substring

---

# When Should You Think of Two Pointers?

Look for keywords like:

### Comparing Elements

- Palindrome
- Reverse String

### Finding Pairs

- Pair Sum
- Triplet Sum
- 4 Sum

### Partitioning

- Sort 0s 1s 2s
- Move Zeroes
- Remove Duplicates

### Merging

- Merge Two Sorted Arrays
- Merge Two Sorted Lists

---

# Example 1: Valid Palindrome

## Problem

**Input**

```text
"madam"
```

**Output**

```text
true
```

Because:

```text
m == m
a == a
d == d
```

---

## Brute Force Approach

Reverse the string and compare.

```cpp
string s = "madam";

string rev = s;

reverse(rev.begin(), rev.end());

if(s == rev)
{
    return true;
}
```

### Complexity

| Metric | Complexity |
|----------|----------|
| Time | O(n) |
| Space | O(n) |

Extra reversed string is created.

---

## Optimized Two Pointer Approach

### Idea

Compare first and last characters.

```text
left = 0
right = n - 1
```

If equal:

```text
left++
right--
```

Continue until they cross.

---

### Code

```cpp
bool isPalindrome(string s)
{
    int left = 0;
    int right = s.length() - 1;

    while(left < right)
    {
        // Characters must match
        if(s[left] != s[right])
        {
            return false;
        }

        left++;
        right--;
    }

    return true;
}
```

---

### Dry Run

```text
s = "madam"

left    right    chars
0       4        m,m
1       3        a,a
2       2        d
```

Done.

Return:

```text
true
```

---

### Complexity

| Metric | Complexity |
|----------|----------|
| Time | O(n) |
| Space | O(1) |

No extra memory is used.

---

# Two Pointer Template (Single Input)

When there is only one array/string.

```cpp
int left = 0;
int right = n - 1;

while(left < right)
{
    if(condition)
    {
        left++;
    }
    else
    {
        right--;
    }
}
```

### Examples

- Palindrome
- Pair Sum in Sorted Array
- Reverse Array

---

# Two Pointer Template (Two Inputs)

When there are two arrays.

```cpp
vector<int> a;
vector<int> b;

int i = 0;
int j = 0;

while(i < a.size() && j < b.size())
{
    if(a[i] < b[j])
    {
        i++;
    }
    else
    {
        j++;
    }
}
```

### Used In

- Merge Two Sorted Arrays
- Intersection of Arrays
- Union of Arrays

---

# Example Template: Merge Two Sorted Arrays

```cpp
while(i < n && j < m)
{
    if(a[i] <= b[j])
    {
        ans.push_back(a[i]);
        i++;
    }
    else
    {
        ans.push_back(b[j]);
        j++;
    }
}
```

---

# Quick Revision

### Opposite Direction

```cpp
left = 0;
right = n - 1;
```

Used for:

- Palindrome
- Pair Sum
- Reverse Array

### Fast-Slow

```cpp
slow += 1 step;
fast += 2 steps;
```

Used for:

- Cycle Detection
- Middle Node
- Happy Number

### Sliding Window

```cpp
left++;
right++;
```

Used for:

- Longest Substring
- Maximum Sum Subarray
- Minimum Window Substring

---

# Key Takeaway

Whenever you see:

- Comparisons from both ends
- Pair/Triplet sum problems
- Palindromes
- Merging sorted data
- Linked list cycle detection
- Window-based substring/subarray problems

Think:

> **Can this be solved using the Two Pointer Pattern instead of nested loops?**

This simple pattern frequently reduces solutions from **O(n²)** to **O(n)**.