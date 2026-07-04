# Good Questions

## 1. Greetings

`bit`, `inversions`, `coordinate compression`, `intervals`, `pbds`

- **Link:** https://codeforces.com/problemset/problem/1915/F
- **Concept:** People move right on intervals $[a_i, b_i]$. Two greet iff intervals "cross" — $a_i < a_j$ and $b_i > b_j$. Sort by $a$, count inversions in $b$.
- **Approaches:**
  - **BIT** — coordinate-compress $b$, iterate left to right, `i - bit.query(rank)` gives count > current, then insert. Strictness handled via tie-breaking sort + query variant (see [Good_Concepts.md](Good_Concepts.md)).
  - **Ordered set (`pbds`)** — `size() - order_of_key(b)`. No compression. ~3–5× slower, GCC-only.

## 2. Smilo and Monsters

`greedy`, `two pointers`, `simulation`

- **Link:** https://codeforces.com/problemset/problem/1891/C
- **Idea:** sort ascending. Spend the cheapest hp as attacks to build power $x$, then one charge to kill the largest. Repeat. Tail (`l == r`) needs care.
- **Clean implementation:**

```cpp
sort(all(a));
int l = 0, r = n - 1, x = 0;
ll ops = 0;
while (l < r) {
    if (x + a[l] < a[r]) {       // can't reach a[r] even after fully consuming a[l]
        ops += a[l];             // attacks
        x   += a[l];
        l++;
    } else {                     // can charge: spend just enough attacks on a[l] to reach a[r]
        int need = a[r] - x;     // remaining attacks needed
        ops += need;             // attacks
        a[l] -= need;            // leftover hp stays on a[l]
        ops += 1;                // charge kills a[r], resets x
        x = 0;
        r--;
    }
}
// tail: one monster left with hp a[l], power x
if (a[l] <= x) {
    ops += 1;                    // single charge
} else {
    int k = (a[l] - x + 1) / 2;  // ceil((a[l]-x)/2) attacks balances hp and power
    ops += k + 1;                // attacks + charge
}
```

- **Why it's a good question:** the concept is one line, but the tail case is where casework explodes. Writing it as one formula ($\lceil (a[l] - x)/2 \rceil + 1$) kills the whole bug class.

## 4. Data Structures Fan

`xor`, `prefix xor`, `range query`, `sparse table pitfall`

- **Link:** https://codeforces.com/problemset/problem/1872/E
- **Trick:** don't store the string. Keep two scalars: `xor0` (XOR of $a_i$ where $s_i = 0$), `xor1` (XOR of $a_i$ where $s_i = 1$).
- **Why it works:** a flip on $[l, r]$ moves every element there to the other group. So:

$$\texttt{xor0} \mathrel{\oplus}= \text{xor}(l, r), \quad \texttt{xor1} \mathrel{\oplus}= \text{xor}(l, r)$$

- **Range-XOR via prefix-XOR, NOT sparse table:**
> [!WARNING]
> Sparse table needs idempotency $f(a, a) = a$. XOR fails: $a \oplus a = 0$. Use prefix-XOR: $\text{xor}(l, r) = P[r] \oplus P[l-1]$.
- Cross-ref: [Range Query Cheatsheet](https://github.com/two-seven-iitd/CP-tutorials/blob/main/Range_Query_Cheatsheet.md).

## 5. Tea Tasting

`binary search`, `prefix sum`, `difference array`

- **Link:** https://codeforces.com/problemset/problem/1795/C
- **Setup:** tea $i$ with capacity $a_i$ drinks from cups $i, i+1, \dots, n-1$ in order, taking $b_j$ from cup $j$ until empty.
- **Per-tea reformulation:** find smallest $r$ such that $\sum_{j=i}^{r} b_j > a_i$ (binary search on prefix sums).
  - cups $j \in [i, r-1]$ are fully drained by tea $i$ → contribute $+b_j$ to `ans[j]`.
  - cup $r$ gets a partial drain → `ans[r] += a_i - \sum_{j=i}^{r-1} b_j`.
- **Avoiding $O(n^2)$ updates:** the full-drain part is a range update of "+1 fully-drained count" on $[i, r-1]$ → use a **difference array** on counts, prefix-sum at the end, then `ans[j] += cnt[j] * b[j]`. Partial drains are point updates, handle directly.
- **What's nice:** combines binary-search-on-prefix-sum with difference array — two routine tools, the trick is seeing they compose here.

## 6. Controllers

`math`, `number theory`, `linear diophantine`, `lcm`

- **Link:** https://codeforces.com/problemset/problem/1776/L
- Each `'+'` contributes $\pm a$, each `'-'` contributes $\pm b$. Want total $= 0$.
- **Approach 1 — linear equation (what I did):**
  - let $\text{diff} = \text{cnt}_+ - \text{cnt}_-$, $x$ = signed `'+'` contribution in units of $a$.
  - reduces to $(a - b) \cdot x = -b \cdot \text{diff}$. Check integer solution + range $x \in [-\text{cnt}_+, \text{cnt}_+]$.
  - $a = b$ handled separately: answer is `diff == 0`.
- **Approach 2 — LCM (didn't do, worth knowing):**
  - zero-sum needs $a \cdot P = b \cdot Q$ where $P, Q$ are achievable signed counts.
  - smallest non-trivial: $P = b/\gcd(a,b)$, $Q = a/\gcd(a,b)$, scaled by $k$. Check parity + range bounds.
- **Why both matter:** approach 2 generalizes — whenever you see $a \cdot x = b \cdot y$ over bounded integers, think LCM scaling.

## 7. Palindrome Basis

`dp`, `knapsack`, `precompute`, `constraints analysis`

- **Link:** https://codeforces.com/problemset/problem/1673/C
- **The fact:** there are only **498 palindromes** $\le 4 \cdot 10^4$. Precompute them, then it's textbook unbounded-coin-change DP: $\approx 498 \times 4 \cdot 10^4 = 2 \cdot 10^7$, trivial.
- Same lesson as **9. Factorials and Powers of Two**: count the candidates before assuming you need cleverness.

## 9. Factorials and Powers of Two

`bitmask`, `subset enumeration`, `popcount`, `constraints analysis`

- **Link:** https://codeforces.com/problemset/problem/1646/C
- **Key constraint observation:** $n \le 10^{12}$ and $15! > 10^{12}$, so at most $14$ factorials matter.
- **Reduction:** subtract some subset of factorials, fill the rest with powers of 2 = $\text{popcount}$ of the leftover.

$$\text{ans} = \min_{S \subseteq \{1!, 2!, \dots, 14!\}} \big(|S| + \text{popcount}(n - \text{sum}(S))\big)$$

- **Approach:** brute-force all $2^{14}$ subsets. AC.
- **Takeaway:**
> [!TIP]
> Read the constraints first. A lot of 1500-rated problems hide a constant-sized search space behind a scary statement — brute force is allowed, you just have to notice it.

## 10. AGAGA XOOORRR

`xor`, `prefix xor`, `greedy`, `casework`

- **Link:** https://codeforces.com/problemset/problem/1516/B
- **Key observation:** if the array splits into $k \ge 2$ contiguous segments of equal XOR, then it splits into **2 or 3** segments too.
  - merging any 3 adjacent equal-XOR segments gives the same XOR back ($x \oplus x \oplus x = x$), so $k$ drops by 2 each step. Parity preserved → end at 2 (even $k$) or 3 (odd $k$).
- **So check just two cases:**
  - **2 segments:** total XOR $= 0$ (then any split works).
  - **3 segments:** let $y = \text{XOR}(a_1, \dots, a_n)$. Need $i \le j$ with $\text{xor}(1, i{-}1) = \text{xor}(i, j) = \text{xor}(j{+}1, n) = y$. Greedy: earliest prefix with XOR $= y$, latest suffix with XOR $= y$, check non-overlap.
- Without the "reduce to 2 or 3" trick you're stuck at $O(n^2)$. With it, it's $O(n)$.

## 11. Eastern Exhibition

`median`, `manhattan distance`, `geometry`

- **Link:** https://codeforces.com/problemset/problem/1486/B
- **Problem:** minimize $\sum (|x_i - x| + |y_i - y|)$ over integer $(x, y)$, count optimal lattice points.
- **Two ideas:**
  1. **Manhattan separates:** $x$ and $y$ are independent → two 1D median problems. Proof in [Good_Concepts.md](Good_Concepts.md).
  2. **Counting:**
     - $n$ odd → unique median per axis → $1$ point.
     - $n$ even → any $x \in [x_{n/2}, x_{n/2+1}]$ works (same for $y$) → answer:

$$(x_{n/2+1} - x_{n/2} + 1) \cdot (y_{n/2+1} - y_{n/2} + 1)$$

- **Insight:** the median fact is standard; recognizing that 2D Manhattan splits cleanly into two independent 1D problems is the part that unlocks it.

## 13. Mortal Kombat Tower

`dp`, `turn-based dp`, `game theory`

- **Link:** https://codeforces.com/problemset/problem/1418/C
- **Setup:** monsters `a[0..n-1]` (`1` = needs a potion). Two sides alternate turns starting with turn-type `0`; each turn clears 1 or 2 monsters. Potions are spent only for `1`s cleared during a turn-type-`0` turn — turn-type-`1` clears are free.
- **DP:** `dp[i][t]` = min potions to clear `a[i..n-1]` given the upcoming turn is type `t`.
```cpp
for (int x = 1; x <= 2 && i + x - 1 < n; x++) {
    int cnt = count(a.begin()+i, a.begin()+i+x, 1);
    dp[i][t] = min(dp[i][t], dp[i+x][1^t] + (t == 0 ? cnt : 0));
}
```
- **Takeaway:**
> [!TIP]
> "Alternating turns, take 1 or 2 items per turn, cost depends on whose turn it is" is a recurring shape — `dp[i][turn]` with a window capped at 2 keeps it $O(n)$ every time you see it.

## 14. k-Amazing Numbers

`prefix min`, `gap analysis`, `bucketing`

- **Link:** https://codeforces.com/problemset/problem/1416/A
- **Key observation:** for a value $v$, its max gap between consecutive occurrences (with virtual occurrences at $-1$ and $n$) is exactly the smallest $k$ for which $v$ appears in **every** length-$k$ window — i.e. the smallest $k$ for which $v$ is "$k$-amazing".
- **Reduction:** flip the question. Instead of asking "does $v$ work for $k$", bucket every value by its own minimal-$k$, then answer for $k$ = the smallest value over all buckets $\le k$.
```cpp
vector<int> last(n+1,-1), mx(n+1);
for (int i=0;i<n;i++) { mx[a[i]] = max(mx[a[i]], i-last[a[i]]); last[a[i]]=i; }
for (int i=1;i<=n;i++) mx[i] = max(mx[i], n-last[i]);   // closing gap to the end
for (int i=1;i<=n;i++) arr[mx[i]] = min(arr[mx[i]], i); // bucket by gap
for (int i=1;i<=n;i++) arr[i] = min(arr[i], arr[i-1]);  // prefix-min
```
> [!IMPORTANT]
> Seed virtual occurrences at `-1` and `n` before computing gaps. The gap *before* the first real occurrence and the gap *after* the last one both count — skip either boundary and you undercount the max gap for values that sit near the edges.
- **What's nice:** turns a naive $O(n^2)$ "check every $k$ against every value" search into one linear pass, just by inverting which variable you solve for.

## 16. Powered Addition

`bit manipulation`, `prefix max`, `greedy`

- **Link:** https://codeforces.com/problemset/problem/1338/A
- **Problem:** each operation picks an index $i$ and adds $2^x$ (your choice of $x$) to $a_i, a_{i+1}, \dots, a_{n-1}$. Minimize operations to make the array non-decreasing.
- **Key reduction:** only the worst deficit matters — $\text{diff} = \max_i(\text{prefix\_max}(a[0..i]) - a[i])$.
- **Why bits:** every operation raises a *suffix* by exactly one power of two, so suffix-updates on the same range stack like binary digits. Fixing a deficit of $D$ needs exactly $\lfloor \log_2 D \rfloor + 1$ ops — its bit-length.
```cpp
int diff = 0, premx = 0;
for (int i=0;i<n;i++) { premx = max(premx, a[i]); diff = max(diff, premx - a[i]); }
cout << (diff == 0 ? 0 : __lg(diff) + 1) << "\n";
```
- Cross-ref: [Good_Concepts.md](Good_Concepts.md) — "Fixing a Deficit with Power-of-Two Suffix Additions".

## 17. K-Complete Word

`equivalence classes`, `greedy`, `string`

- **Link:** https://codeforces.com/problemset/problem/1332/C
- **Problem:** make a string both $k$-periodic and a palindrome with the minimum number of character changes.
- **Key idea:** both constraints just say "these indices must hold the same character". Fold every index to `group = min(i % k, k-1-i%k)` — everything in the same group must end up identical. Only the first `(k+1)/2` groups need checking; the rest mirror them.

  Example fold for `k = 5`:

  | index `i` | `i % k` | `group = min(i%k, k-1-i%k)` |
  |:---:|:---:|:---:|
  | 0 | 0 | 0 |
  | 1 | 1 | 1 |
  | 2 | 2 | 2 |
  | 3 | 3 | 1 |
  | 4 | 4 | 0 |

```cpp
int md = i % k; md = min(md, k-1-md);
grp[md][s[i]-'a']++;
...
ans += tot - mx; // tot = group size, mx = majority letter's count
```
- **Insight:** two separate structural constraints (period + palindrome) collapse into one equivalence-class problem — the same lens applies any time a problem stacks multiple "these positions must agree" rules on top of each other.

## 18. Ehab and Path-etic MEXs

`construction`, `tree`, `mex`, `greedy`

- **Link:** https://codeforces.com/problemset/problem/1325/C
- **Problem:** label the $n-1$ edges of a tree with $0, \dots, n-2$ so that the **maximum mex over all root-to-anywhere paths** is as small as possible.
- **Key observation:** whichever two edges get labels $0$ and $1$, some path passes through both of them — mex $\ge 2$ is unavoidable no matter how you label. The only lever left is *containing the damage* so no path also sees label $2$.
- **Construction:** find any vertex of degree $\ge 3$ and give its incident edges the smallest labels $0, 1, 2, \dots$ first. Any single path can leave that vertex through at most 2 of its edges, so it can never see all of $\{0,1,2\}$ there — the max mex caps at $3$. Every other edge gets the remaining labels in any order.

  ```
          2
         0 \ 1
        /    \
  ```
  the path from the `0`-edge to the `1`-edge passes through the up-edge, so label it `2` — that path now sees `{0,1,2}` but never both `0` *and* `1` from *another* branch at once.

- **Degenerate case:** if no vertex has degree $\ge 3$ (the tree is a bamboo/path), labeling is irrelevant — some path always sees every label, mex is $n-1$ regardless.
- The idea is one line once seen; *visualizing* why concentrating the small labels at one high-degree vertex (rather than spreading them out) bounds the damage is the actual non-obvious step.

## 19. Count Subrectangles

`divisors`, `run-length encoding`, `binary search`, `combinatorics`

- **Link:** https://codeforces.com/problemset/problem/1323/B
- **Problem:** 0/1 arrays $a$ (len $n$), $b$ (len $m$); matrix $c_{ij} = a_i \cdot b_j$. Count axis-aligned all-ones submatrices of area exactly $k$.
- **Key reduction:** $c$'s 1-blocks are exactly (run of 1s in $a$) × (run of 1s in $b$). An $f_1 \times f_2$ all-ones submatrix exists once for every pair of positions where a run in $a$ is $\ge f_1$ long **and** a run in $b$ is $\ge f_2$ long. So: enumerate factor pairs $(f_1, f_2)$ of $k$ (only $O(\sqrt k)$ of them), and for each, multiply "count of ($a$-runs $\ge f_1$) placements" by "count of ($b$-runs $\ge f_2$) placements".
- **Counting placements for a threshold $f$:** a run of length $L \ge f$ contributes $L - f + 1$ placements. Sort run lengths, take a suffix sum, then for threshold $f$:
```cpp
int idx = lower_bound(all(runs), f) - runs.begin();
int cnt = suffixSum[idx] - (f - 1) * (int)(runs.size() - idx);
```
> [!WARNING]
> Factor pairs of `k` are unordered, but arrays `a` and `b` are not interchangeable — for a factorization `f1 * f2 = k` you must *also* check `(f2, f1)` against `(a, b)`, unless `f1 == f2`. Skip this and you silently miss every rectangle oriented the other way.
- Neither piece (divisor enumeration, run-length counting) is hard alone. The exercise is noticing they compose, and getting the "placements per run" formula right.

## 20. Zero Array

`greedy`, `feasibility check`, `pairing`

- **Link:** https://codeforces.com/problemset/problem/1201/B
- **Problem:** repeatedly pick two *different* indices with positive value and decrement both by 1. Can the whole array reach all-zero?
- **Feasibility condition:** possible iff `sum` is even **and** `max element <= sum / 2`.
```cpp
cout << ((tot % 2 == 0) && (tot / 2 >= mx) ? "YES\n" : "NO\n");
```
- "max $\le$ half of total" is the standard necessary-and-sufficient condition for any "pair up and cancel two at a time" question — worth keeping as a one-liner instead of re-deriving it each time.
- Cross-ref: [Good_Concepts.md](Good_Concepts.md) — "Pairing Feasibility: max ≤ sum / 2".
