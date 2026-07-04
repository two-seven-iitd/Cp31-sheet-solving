# Good Question
---
## 2. Grouping Increases

`greedy`, `casework`, `dp`, `good dp`

- **Link:** https://codeforces.com/problemset/problem/1919/C

### what's good
the casework that we have to think is actually motivated by actually `simulating` the `construction` , it is just <u>construction</u> at it's core 
- also the alternative dp solution is insane, hard to understand & implement (uses segment tree)

### Editorial Solution
[link to editorial](https://codeforces.com/blog/entry/124220)
<details>

<p>Consider the following approach. We start with empty arrays <i>b</i> and <i>c</i>, then insert elements of the array <i>a</i> one by one to the back of <i>b</i> or <i>c</i>. Our penalty function only depends on adjacent elements, so at any point in time, we only care about the value of the last element of arrays <i>b</i> and <i>c</i>. Suppose we already inserted <i>a</i><sub>1</sub>, <i>a</i><sub>2</sub>, &hellip;, <i>a</i><sub><i>i</i>&minus;1</sub> into arrays <i>b</i> and <i>c</i> and we now want to insert <i>a<sub>i</sub></i>. Let <i>x</i> and <i>y</i> be the last element of arrays <i>b</i> and <i>c</i> respectively (if they are empty, use &infin;). Note that swapping arrays <i>b</i> and <i>c</i> does not matter, so without loss of generality, assume that <i>x</i> &le; <i>y</i>. We will use the following greedy approach.</p>

<ol>
  <li>If <i>a<sub>i</sub></i> &le; <i>x</i>, insert <i>a<sub>i</sub></i> to the back of the array with a smaller last element.</li>
  <li>If <i>y</i> &lt; <i>a<sub>i</sub></i>, insert <i>a<sub>i</sub></i> to the back of the array with a smaller last element.</li>
  <li>If <i>x</i> &lt; <i>a<sub>i</sub></i> &le; <i>y</i>, insert <i>a<sub>i</sub></i> to the back of the array with a bigger last element.</li>
</ol>

<p>The proof of why the greedy approach is optimal is given below:</p>

<ol>
  <li><i>a<sub>i</sub></i> &le; <i>x</i>. In this case, <i>a<sub>i</sub></i> is not greater than the last element of both arrays, so inserting <i>a<sub>i</sub></i> to the back of either array will not add additional penalties. However, it is better to insert <i>a<sub>i</sub></i> into the array with a smaller last element so that in the future, we can insert a wider range of values into the new array without additional penalty.</li>
  <li><i>y</i> &lt; <i>a<sub>i</sub></i>. In this case, <i>a<sub>i</sub></i> is greater than the last element of both arrays, so inserting <i>a<sub>i</sub></i> to the back of either array will contribute to 1 additional penalty. However, it is better to insert <i>a<sub>i</sub></i> into the array with a smaller last element so that in the future, we can insert a wider range of values into the new array without additional penalty.</li>
  <li><i>x</i> &lt; <i>a<sub>i</sub></i> &le; <i>y</i>. In this case, if we insert <i>a<sub>i</sub></i> to the back of the array with the larger last element, there will not be any additional penalty. However, if we insert <i>a<sub>i</sub></i> to the back of the array with the smaller last element, there will be an additional penalty of 1. The former option is always better than the latter. This is because if we consider making the same choices for the remaining elements <i>a</i><sub><i>i</i>+1</sub> to <i>a<sub>n</sub></i> in both scenarios, there will be at most one time where the former scenario will add one penalty more than the latter scenario as the former scenario has a smaller last element after inserting <i>a<sub>i</sub></i>. After that happens, the back of the arrays in both scenarios will become the same and hence, the former case will never be less optimal.</li>
</ol>

<p>Following the greedy approach for all 3 cases will result in a correct solution that runs in <i>O</i>(<i>n</i>) time.</p>
</details>

## 3. Jumping Through Segments

`binary search`, `greedy`, `range intersection`

- **Link:** https://codeforces.com/problemset/problem/1907/D
- **Problem:** starting at `0`, on step `i` you must move to a point within distance `d` of your current position **and** inside segment `[l_i, r_i]`. Find the minimum `d` for which finishing all `n` steps is possible.
- **Key idea:** `d` is monotonic (bigger `d` only makes things easier), so binary search on it. For a fixed `d`, don't track a single reachable point — track the whole **reachable range** `[mn, mx]`, expand it by `d`, then clip it to the current segment:
```cpp
int mn = 0, mx = 0;
for (int i = 0; i < n; i++) {
    mn = max(mn - d, l[i]);
    mx = min(mx + d, r[i]);
    if (mn > mx) return false;   // d fails
}
return true;
```
- Tracking an interval instead of a point is what makes the greedy feasibility check exact — collapsing it to "nearest reachable point" loses information the next step might need.

## 4. Array Game

`nearest element`, `binary search`, `case analysis`

- **Link:** https://codeforces.com/problemset/problem/1904/C
- **Problem:** among all pairs, take the minimum absolute difference; repeat up to `k` times; find the smallest value reachable.
- **Key idea:** direct application of [Nearest Element using Binary Search](Good_Concepts.md) — once you have a candidate difference `cur = |a[i]-a[j]|`, the next round's best move might be pairing `cur` against its **nearest neighbor already in the array**, not against another raw pair. `lower_bound`/`upper_bound` around `cur` finds that neighbor in `O(log n)` instead of rescanning everything.
- **Gotcha:** `k > 2` always outputs `0` — two rounds are already enough to guarantee the array contains (or can reach) a `0`, so there's no need to simulate further; special-case it before the `O(n^2)` pair loop.

## 6. Iva & Pav

`binary search`, `bitwise and`, `sparse table`, `monotonic`

- **Link:** https://codeforces.com/problemset/problem/1878/E
- **Problem:** for queries `(l, k)`, find the largest `r` such that `AND(a[l..r]) >= k`.
- **Key observation:** extending a range can only ever *turn bits off*, never on — `AND(a[l..r])` is monotonically non-increasing as `r` grows. That monotonicity alone licenses binary search on `r`.
- **Two implementations:**
  - **Sparse table** — build a range-AND sparse table, answer any range-AND query in `O(1)`, binary search `r` in `O(log n)`.
  - **Per-bit prefix counts** — for each of the ~30 bits, keep a prefix count of set bits; bit `j` survives a range iff its set-bit count equals the range length. `O(30)` per range-AND query.
> [!TIP]
> Whenever an operation is monotonic under range extension (AND, OR, GCD — anything idempotent that only loses information as the range grows), binary searching the endpoint is on the table. See [Monotonic Bitwise AND Enables Binary Search](Good_Concepts.md).

## 7. Bracket Coloring

`greedy`, `construction`, `strings`

- **Link:** https://codeforces.com/problemset/problem/1837/D
- **Problem:** 2-color a bracket sequence so each color, read in isolation, forms a regular bracket sequence (RBS); use as few colors as possible (1 or 2), or report impossible.
- **Key idea:** track the running balance while scanning left to right.
  - balance `> 0` after this bracket → color `1` (an *opening* excess)
  - balance `< 0` → color `2` (a *closing* excess)
  - balance `== 0` → same color as whichever excess it just closed
```cpp
if (bal > 0) { ans[i] = 1; last = 1; }
else if (bal < 0) { ans[i] = 2; last = 2; }
else ans[i] = last;
```
- If the sequence never goes negative (or never goes positive), it's already a single RBS — collapse both colors to `1`. If the overall balance never returns to `0`, no coloring saves it: output `-1`.

## 10. Make It Round

`number theory`, `greedy`

- **Link:** https://codeforces.com/problemset/problem/1759/D
- **Problem:** choose `x <= m` to maximize the number of trailing zeros of `n * x`.
- **Key idea:** trailing zeros come from factors of `10 = 2 * 5`. Count `n`'s existing power of `2` (`p2`) and power of `5` (`p5`) — the smaller one is the bottleneck. Spend budget from `x` closing that gap first (multiply by `2`s or `5`s until `p2 == p5`), then spend whatever's left multiplying by `10` to add matched pairs.
- This two-phase greedy — balance the mismatched prime first, then pump the matched factor — generalizes to any "maximize matched-pair count between two prime factors" question.

## 13. 2^Sort

`telescoping`, `prefix sum`, `sliding window`

- **Link:** https://codeforces.com/problemset/problem/1692/G
- **Problem:** count subarrays of length `k+1` such that $2^0 a_i < 2^1 a_{i+1} < 2^2 a_{i+2} < \dots < 2^k a_{i+k}$.
- **Key observation:** the scaled chain telescopes — $2^j a_{i+j} < 2^{j+1} a_{i+j+1}$ is the same condition as $a_{i+j} < 2 a_{i+j+1}$ (divide both sides by $2^j$). Every exponential-looking constraint is actually just a **pairwise** condition between neighbors.
```cpp
for (int i = 0; i + 1 < n; i++) good[i] = (a[i] < 2 * a[i+1]);
// prefix-sum good[], then a window of k+1 elements is valid
// iff all k of its internal pairs are good, i.e. prefix-sum count == k
```
- Once the telescoping is spotted, it collapses to a plain prefix-sum sliding-window count — the "hard-looking" exponential condition was never really about exponents.

## 14. A Weird Sum

`manhattan distance`, `prefix sum`, `independent axes`

- **Link:** https://codeforces.com/problemset/problem/1648/A
- **Problem:** sum of `|r_i - r_j| + |c_i - c_j|` over every pair of same-colored cells in a grid.
- **Key idea:** same lens as [Eastern Exhibition](../1500/Good_Questions.md) (1500/) — Manhattan distance splits, so sum the row-difference part and column-difference part completely independently. Group cells by color and handle rows and columns as two separate 1-D problems.
- The 1-D primitive — **sum of `|x_i - x_j|` over all pairs in a sorted array** — is a standalone reusable trick, see [Good_Concepts.md](Good_Concepts.md):
```cpp
sort(all(vec));
int pre = 0;
for (int i = 1; i < vec.size(); i++) {
    pre += vec[i-1];
    ans += i * vec[i] - pre;   // vec[i] is farther than all i earlier elements combined
}
```
> [!IMPORTANT]
> Row groups are naturally collected in row order while scanning, but column groups aren't — sort each column bucket before applying the prefix-sum formula, or the pairwise-sum trick silently gives the wrong answer.

## 16. Arranging the sheep

`median`, `binary search`, `two pointers`

- **Link:** https://codeforces.com/problemset/problem/1520/E
- todo -> clearly analyze all the three solutions
  - binary search
  - pointer 
  - median approach (`goated`)

## 18. AND Sequences

`combinatorics`, `bitwise and`, `permutations`

- **Link:** https://codeforces.com/problemset/problem/1513/B
- **Problem:** count permutations of the array such that **every** prefix's bitwise AND equals the array's total AND.
- **Key observation:** bitwise AND is monotonically non-increasing as a prefix grows, and it can only *reach* the global minimum once enough elements combine to kill every extra bit. If the global AND value `x` doesn't literally appear as an array element, no permutation works — you need actual copies of `x` at the front to force the prefix AND down immediately, not just eventually.
- **Formula:** let `c` = count of elements equal to the global AND `x`. Answer is `0` if `c < 2`, else:

$$\text{ans} = c \cdot (c-1) \cdot (n-2)!$$

  (`c*(c-1)` ordered choices for the first two slots, `(n-2)!` free permutations of the rest.)

## 19. Ball in Berland

`graph modeling`

- **Link:** https://codeforces.com/problemset/problem/1475/C
- todo -> graph formulation for the Question , how can we model it as a graph question

## 20. Zero Remainder Array

`greedy`, `scheduling`, `bucketing`

- **Link:** https://codeforces.com/problemset/problem/1374/D
- **Problem:** on round `i` (starting from 1), add `i` to any one array element. Find the minimum number of rounds until every element is divisible by `k`.
- **Key idea:** element `a[i]` first becomes fixable on round `req = (k - a[i] % k) % k` (the round number needed to push it over a multiple of `k`). Bucket elements by their `req`.
- **The scheduling twist:** only one element can be serviced per round, so if `cnt` elements share the same `req`, they queue — one every `k` rounds after that:

$$\text{rounds for this bucket} = req + (cnt - 1) \cdot k$$

  Answer is the max over all non-empty buckets (`0` if everything's already divisible by `k`).

## 21. Johnny and Another Rating Drop

`bit manipulation`, `popcount`, `counting`

- **Link:** https://codeforces.com/problemset/problem/1362/C

**Problem:** Total bit flips going 0 → 1 → 2 → … → n (i.e., sum of hamming distance of consecutive XORs).

**Key observation:** Adding 1 to a number with `len` trailing 1s flips `len + 1` bits.

---

### Three approaches

#### 1. Pattern counting (most intuitive)
For each `len`, count numbers in `[0, n-1]` matching `x0 1...1` (exactly `len` trailing 1s), multiply by `(len + 1)`.

```
count = floor((n - 2^len) / 2^(len+1)) + 1
ans += count * (len + 1)
```

#### 2. Per-bit position
Bit `p` flips whenever trailing 1s ≥ p, i.e., every `2^p`-th number.

```
ans = floor(n/1) + floor(n/2) + floor(n/4) + …
```

#### 3. Closed form
```
ans = 2n - popcount(n)
```

---

### Why `floor(n/1) + floor(n/2) + … = 2n - popcount(n)`

Each bit $b_i$ of $n$ appears in terms `floor(n/1)` through `floor(n/2^i)`, contributing $b_i \cdot (2^{i+1} - 1)$. Summing: $2 \sum b_i \cdot 2^i - \sum b_i = 2n - \text{popcount}(n)$.

---

### Gotcha
- Right-shifting a negative number gives -1 (arithmetic shift), not 0. Guard with `if(... < 0) break`.
- Count over `[0, n-1]` not `[0, n]` — the transition *from* n shouldn't be included.

## 22. Orac and Models

`dp`, `divisibility`, `multiples iteration`

- **Link:** https://codeforces.com/problemset/problem/1350/B
- **Problem:** pick the longest chain of indices `i_1 < i_2 < ...` where each divides the next (`i_{j+1} % i_j == 0`) **and** values strictly increase (`s[i_j] < s[i_{j+1}]`).
- **DP:** `dp[i]` = longest valid chain ending at index `i`. Instead of checking every divisor of `i` (needs a sieve), push forward from `i` to its **multiples**:
```cpp
for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j += i)
        if (s[j] > s[i]) dp[j] = max(dp[j], 1 + dp[i]);
```
- Iterating multiples instead of divisors turns an $O(n\sqrt n)$ scan into $O(n \log n)$ (harmonic series) — see [Divisibility-Chain DP via Multiple-Iteration](Good_Concepts.md).

## 23. Journey Planning

`hashing`, `grouping`, `greedy`

- **Link:** https://codeforces.com/problemset/problem/1320/A
- **Problem:** pick indices `i_1 < i_2 < ... < i_m` (1-indexed) where consecutive chosen values satisfy `b[i_{j+1}] = b[i_j] + (i_{j+1} - i_j)`, maximizing the sum of chosen `b`'s.
- **Key idea:** the constraint rearranges to `b[i_{j+1}] - i_{j+1} == b[i_j] - i_j` — every valid chosen chain shares one constant value of `b[i] - i`. So group *all* indices by that single number and sum each group; no subsequence-building needed.
```cpp
map<int,int> mp;
for (int i = 0; i < n; i++) mp[b[i] - (i+1)] += b[i];
// answer = max value across the map
```
- Whenever a chain constraint reduces to "some expression stays constant along the chain," hashing by that expression turns an apparent subsequence-DP into a single grouping pass.

## 30. Tape

`greedy`, `sorting`, `interval covering`

- **Link:** https://codeforces.com/problemset/problem/1110/B
- **Problem:** cover `n` given points on a line with exactly `k` disjoint segments, minimizing total segment length.
- **Key idea:** one segment spanning everything costs `(max - min)`, which decomposes into the sum of *all* consecutive gaps between sorted points (plus `n` for the points themselves). A split at a gap removes that gap's cost entirely, so minimizing total length with `k` segments means cutting at the **`k-1` largest gaps** and paying for the rest.
```cpp
sort(all(gaps));                                // n-1 gaps between consecutive points
int len = n;                                    // n unit-length points
for (int i = 0; i < n - k; i++) len += gaps[i]; // sum of the (n-k) smallest gaps
```
- "Sort the gaps, keep the smallest, discard the biggest `k-1`" recurs any time a contiguous cost can be cut into `k` pieces for free.

## 31. Mashmokh and ACM

`dp`, `divisibility`, `multiples iteration`

- **Link:** https://codeforces.com/problemset/problem/414/B
- **Problem:** count sequences of length `k` where each element divides the next, over values `1..n`.
- **DP:** `dp[i][j]` = number of length-`(i+1)` divisor chains ending at value `j`. Naively this needs "for every `j`, sum over divisors of `j`" — push **forward** to multiples instead:
```cpp
for (int j = 1; j <= n; j++)
    for (int mult = j; mult <= n; mult += j)
        dp[i+1][mult] += dp[i][j];
```
- Same [multiple-iteration trick](Good_Concepts.md) as **22. Orac and Models** — one an LIS-style optimization, one a counting DP, same $O(n \log n)$ divisor-chain machinery underneath.