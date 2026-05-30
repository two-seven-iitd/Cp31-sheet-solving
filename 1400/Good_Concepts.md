# Good Concepts
---
### Segment Intersection
---
> 🏷️ **Tags:** &ensp; `intersection` &ensp;

- [usaco guide](https://usaco.guide/bronze/rect-geo)

Short theory:

Intersection of two segments [l1, r1] and [l2, r2] is the interval

$$\max(l_1, l_2) \quad \text{to} \quad \min(r_1, r_2)$$

The number of integer points in the intersection is

$$\max\Big(0, \  \min(r_1, r_2) - \max(l_1, l_2) + 1\Big)$$

### Nearest Element using Binary Search
---
> 🏷️ **Tags:** &ensp; `nearest` &ensp;•&ensp; `closest` &ensp;•&ensp; `binary search`

For a sorted array `a` and a value `x`, the nearest element can be found with binary search.

- `lower_bound(a.begin(), a.end(), x)` returns the first element `>= x`.
- `upper_bound(a.begin(), a.end(), x) - 1` and then stepping back returns the last element `<= x`.

Compare the two elements(`iterator`) returned by these searches to choose the closest element to `x`.

