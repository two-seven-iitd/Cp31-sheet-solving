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

the following concepts needs to be added , mainly the median one 

## 16. Arranging the sheep 
- todo -> clearly analyze all the three solutions
  - binary search
  - pointer 
  - median approach (`goated`)

## Bit Manipulation — Trailing Ones & Binary Counting

**Source:** 21. Johnny and Another Rating Drop

---

### Core identities

- **Sum of trailing zeros (2-adic valuation):** $\sum_{i=1}^{n} v_2(i) = n - \text{popcount}(n)$ (Legendre's formula)
- **Sum of floor divisions:** $\lfloor n/1 \rfloor + \lfloor n/2 \rfloor + \lfloor n/4 \rfloor + \dots = 2n - \text{popcount}(n)$
  - Proof sketch: each bit $b_i$ of $n$ contributes to terms $p = 0$ through $p = i$, totalling $b_i \cdot (2^{i+1} - 1)$. Sum gives $2n - \text{popcount}(n)$.
- Adding 1 to a number with `len` trailing 1s flips `len + 1` bits.

---

### Counting technique: "exactly" vs "at least"

When each object (number) contributes a weight `w`, you can count two ways:
- **Group by exact value:** count numbers with exactly `len` trailing 1s, multiply by `(len + 1)`.
- **Group by bit position:** for each bit `p`, count numbers with trailing 1s ≥ `p` — that's just `floor(n / 2^p)`. No multiplier needed.

The second is usually cleaner and less error-prone.

---

### Binary pattern counting

To count numbers in `[0, m]` matching a trailing pattern like `0 1...1` (`len` ones):
```
numbers have the form: x * 2^(len+1) + (2^len - 1)
count = floor((m - (2^len - 1)) / 2^(len+1)) + 1
```
Generalizes to any fixed suffix pattern — fix the last `k` bits, free prefix, count via division.

---

### C++ pitfalls

- **Arithmetic right shift on negatives:** `(-2) >> 1 == -1`, not `0`. Always guard with `if(... < 0) break` before shifting.
- **Off-by-one in transition counting:** transitions 0→1→…→n means iterating over `[0, n-1]`, not `[0, n]`.