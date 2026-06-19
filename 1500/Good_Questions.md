# Good Questions

## 1. Greetings
- **Link:** https://codeforces.com/problemset/problem/1915/F
- **Idea:** People move right on intervals `[a_i, b_i]`. Two greet iff intervals "cross" — i.e. `a_i < a_j` but `b_i > b_j`. Sort by `a`, count inversions in `b` using BIT.
- **Concept:** Reduce to inversion counting — sort by `a`, then count pairs where `b` is out of order.
- **Approaches:**
  - BIT — coordinate compress `b` values, iterate left to right, for each element query how many inserted so far have rank > current (`i - bit.query(rank)`), then insert. Need to handle strictness via tie-breaking sort + query variant.
  - Ordered set (`pbds`) — iterate left to right, for each `b` value, `size() - order_of_key(b)` gives count of inserted elements > current, then insert. No coordinate compression needed. Simpler to code but ~3-5x slower and GCC-only.

## 5. Tea Tasting
 - i would say the language was not difficult, but still to come up with the solution is a really great achievement for me 
 - Combines binary search on prefix sum + difference array usage 