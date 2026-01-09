# Bookkeeping of Seen Strings

## 1. List of Strings

This requirement could be met by simply using a raw list to store all strings. A vector was used to not have to worry about resizing.

In the case of `check()`, since it iterates over each entry to find a match, it has `O(n)` complexity in time. Since the memory footprint is unrelated to the number of strings seen, it has `O(1)` complexity in space.

`add()` needs to call `check()` in order to avoid duplicate entries, so it must also be `O(n)` in time, even if adding items at the end of a vector is `O(1)` by itself. It stores all strings as-is, so space complexity is `O(nl)` where `l` is the length of the strings.

## 2. Sorted List of Strings

The requirement of the list being sorted makes searches faster. Since the list will be build from scratch, no sorting algorithms are actually needed, and the list will be constructed to be sorted at all moments instead, for better efficiency.

`check()` takes advantage of the list being sorted to perform a binary search, which makes it `O(log n)` in time complexity, and `O(1)` in space complexity.

`add()` might use a binary search to find the place to insert into faster, but because it must push all the later entries down the list after doing so, it has `O(n)` time complexity. It still stores all strings as-is, so space complexity is `O(nl)` where l is the
length of the strings.

## 3. List of Lists

The requirements were more vague this time, which left more room to experimentation. After a failed attempt at using a recursive hash map, it was decided to use the proven solution for these kind of problems: a trie.

Searching a trie has `O(l)` time and space complexity, where l is the string length. The number of strings seen so far is irrelevant.

Inserting in a trie has `O(l)` time complexity, where l is string length. The number of strings seen so far is irrelevant. Space complexity is `O(nl)` in the worst case when strings have no common root, but average is closer to `O(n)`.
