# Good Concepts
---
### Segment Intersection
---
<div>
🏷️ Tags: <mark style="background:#ffcdd2;padding:2px 6px;border-radius:4px;">intersection</mark> 
</div>

- [usaco guide](https://usaco.guide/bronze/rect-geo)

Short theory:

Intersection of two segments [l1, r1] and [l2, r2] is the interval

\[\max(l_1, l_2) \;\text{to}\; \min(r_1, r_2)\]

The number of integer points in the intersection is

\[\max\bigl(0,\;\min(r_1, r_2) - \max(l_1, l_2) + 1\bigr).\]

### Nearest Element using Binary Search
---
<div>
🏷️ Tags: <mark style="background:#ffcdd2;padding:2px 6px;border-radius:4px;">nearest</mark> • <mark style="background:#c8e6c9;padding:2px 6px;border-radius:4px;">closest</mark> • <mark style="background:#bbdefb;padding:2px 6px;border-radius:4px;">binary search</mark>
</div>

For a sorted array `a` and a value `x`, the nearest element can be found with binary search.

- `lower_bound(a.begin(), a.end(), x)` returns the first element `>= x`.
- `upper_bound(a.begin(), a.end(), x) - 1` and then stepping back returns the last element `<= x`.

Compare the two elements(`iterator`) returned by these searches to choose the closest element to `x`.

