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
- `upper_bound(a.begin(), a.end(), x) - 1` returns the last element `<= x` directly (the `-1` *is* the step back — don't decrement again).

Compare the two elements(`iterator`) returned by these searches to choose the closest element to `x`.

the following concepts needs to be added , mainly the median one 

## 16. Arranging the sheep

> 🏷️ **Tags:** &ensp; `median` &ensp;•&ensp; `binary search` &ensp;•&ensp; `two pointers`

- todo -> clearly analyze all the three solutions
  - binary search
  - pointer 
  - median approach (`goated`)

## Bit Manipulation — Trailing Ones & Binary Counting

> 🏷️ **Tags:** &ensp; `bit manipulation` &ensp;•&ensp; `popcount` &ensp;•&ensp; `counting`

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

## Pairwise |a_i - a_j| Sum via Sorted Prefix Sums

> 🏷️ **Tags:** &ensp; `prefix sum` &ensp;•&ensp; `sorting` &ensp;•&ensp; `pairwise sums`

**Source:** 14. A Weird Sum

the question: given an array, compute $\sum_{i<j} |a_i - a_j|$ — the sum of absolute differences over every pair — without brute-forcing all $O(n^2)$ pairs.

### The Trick

sort the array first. once it's sorted, `|a_i - a_j|` for `i < j` is just `a[j] - a[i]` (no more absolute value needed). so the whole double sum becomes:

$$\sum_{j} \left( j \cdot a[j] - \sum_{i<j} a[i] \right)$$

element `a[j]` is farther than all `j` elements before it, each contributing exactly `a[j] - a[i]`. summing that over a fixed `j` gives `j * a[j] - prefix_sum(j-1)` — a running prefix sum turns the whole thing into a single `O(n log n)` pass (dominated by the sort):

```cpp
sort(all(a));
int pre = 0, ans = 0;
for (int i = 1; i < n; i++) {
    pre += a[i-1];
    ans += i * a[i] - pre;
}
```

### Worked Example

| sorted `a` | `2` | `5` | `9` |
|:---:|:---:|:---:|:---:|
| `i` (0-indexed) | 0 | 1 | 2 |
| `pre` before this step | — | 2 | 7 |
| contribution `i*a[i] - pre` | — | `1*5 - 2 = 3` | `2*9 - 7 = 11` |

total = `3 + 11 = 14`, matching the brute-force sum `|2-5| + |2-9| + |5-9| = 3 + 7 + 4 = 14`.

### Where Else This Shows Up

> [!TIP]
> Any time a problem needs "sum of pairwise absolute differences" — grid problems (rows/columns independently, as in [14. A Weird Sum](Good_Questions.md)), 1-D coordinate problems, even as a subroutine inside a bigger DP — reach for sort + prefix sum instead of reaching for $O(n^2)$.

## Divisibility-Chain DP via Multiple-Iteration

> 🏷️ **Tags:** &ensp; `dp` &ensp;•&ensp; `divisibility` &ensp;•&ensp; `multiples` &ensp;•&ensp; `complexity`

**Source:** 22. Orac and Models, 31. Mashmokh and ACM

both problems build a DP over chains where each next index/value must be a **multiple** of the previous one. The naive way to fill `dp[j]` is "for every `j`, loop over all divisors of `j`" — that needs a sieve and is easy to get wrong. The clean way is to flip the direction: **from `i`, push the update forward onto every multiple of `i`.**

### The Pattern

```cpp
for (int v = 1; v <= n; v++)
    for (int mult = v; mult <= n; mult += v)
        dp[mult] = combine(dp[mult], dp[v]);   // relax forward, not pull backward
```

this single shape handles both flavors seen in the sheet:
- **optimization (22. Orac and Models):** `dp[mult] = max(dp[mult], 1 + dp[v])` guarded by a value condition — longest divisibility chain.
- **counting (31. Mashmokh and ACM):** `dp[len+1][mult] += dp[len][v]` — number of divisibility chains of a fixed length (an extra `len` dimension on top of the same `v -> mult` push).

### Why It's O(n log n), Not O(n√n)

for each `i` from `1` to `n`, the inner loop runs `n/i` times. Summing over all `i`:

$$\sum_{i=1}^{n} \frac{n}{i} = n \sum_{i=1}^{n} \frac{1}{i} \approx n \ln n$$

that's the harmonic series — a classic bound that shows up anywhere you iterate "for each `i`, visit all multiples of `i` up to `n`" (same idea as a sieve of Eratosthenes). Looping over *divisors* of each `j` instead costs $O(\sqrt j)$ per `j`, i.e. $O(n\sqrt n)$ total — asymptotically worse and needs extra sieve pre-computation to even list the divisors.

> [!NOTE]
> Recognize this shape whenever a DP transition says "the next state must divide/be-divided-by the current one" — the multiples-forward-push is almost always available and almost always faster than the divisors-backward-pull.

## Monotonic Bitwise AND Enables Binary Search

> 🏷️ **Tags:** &ensp; `binary search` &ensp;•&ensp; `bitwise and` &ensp;•&ensp; `monotonic`

**Source:** 6. Iva & Pav

### The Observation

extending a range only ever **removes** set bits from a running AND, never adds them — `AND(a[l..r])` is monotonically non-increasing as `r` grows for fixed `l`. Monotonicity is the one ingredient binary search needs, so "find the largest `r` such that `AND(a[l..r]) >= k`" binary searches cleanly on `r`.

### Two Ways to Answer a Range-AND Query Fast

- **Sparse table:** since AND is idempotent (`AND(x, x) = x`), a sparse table works directly — `sp[i][j]` = AND of `2^j` elements starting at `i`. Range query and construction are the same as a min/max sparse table.
- **Per-bit prefix counts:** for each bit `p` (0 to ~30), keep a prefix count of how many elements have bit `p` set. Bit `p` survives `AND(l, r)` iff its count over `[l,r]` equals the range length `r - l + 1`. `O(30)` per query instead of `O(1)`, but needs no sparse table.

### Where Else This Shows Up

> [!TIP]
> The same argument works for OR (bits only turn on, monotonically non-decreasing) and GCD (only shrinks as the range grows). Any idempotent operation that loses information monotonically as a range extends is a candidate for "binary search the endpoint."