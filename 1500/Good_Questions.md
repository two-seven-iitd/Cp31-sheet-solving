# Good Questions

## 1. Greetings
- **Link:** https://codeforces.com/problemset/problem/1915/F
- **Concept:** People move right on intervals $[a_i, b_i]$. Two greet iff intervals "cross" — $a_i < a_j$ and $b_i > b_j$. Sort by $a$, count inversions in $b$.
- **Approaches:**
  - **BIT** — coordinate-compress $b$, iterate left to right, `i - bit.query(rank)` gives count > current, then insert. Strictness handled via tie-breaking sort + query variant (see [Good_Concepts.md](Good_Concepts.md)).
  - **Ordered set (`pbds`)** — `size() - order_of_key(b)`. No compression. ~3–5× slower, GCC-only.

## 2. Smilo and Monsters
- **Link:** https://codeforces.com/problemset/problem/1735/C
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
- **Link:** https://codeforces.com/problemset/problem/1722/F
- **Trick:** don't store the string. Keep two scalars: `xor0` (XOR of $a_i$ where $s_i = 0$), `xor1` (XOR of $a_i$ where $s_i = 1$).
- **Why it works:** a flip on $[l, r]$ moves every element there to the other group. So:

$$\texttt{xor0} \mathrel{\oplus}= \text{xor}(l, r), \quad \texttt{xor1} \mathrel{\oplus}= \text{xor}(l, r)$$

- **Range-XOR via prefix-XOR, NOT sparse table:**
  > [!WARNING]
  > Sparse table needs idempotency $f(a, a) = a$. XOR fails: $a \oplus a = 0$. Use prefix-XOR: $\text{xor}(l, r) = P[r] \oplus P[l-1]$.
- Cross-ref: [Range Query Cheatsheet](https://github.com/two-seven-iitd/CP-tutorials/blob/main/Range_Query_Cheatsheet.md).

## 5. Tea Tasting
- **Link:** https://codeforces.com/problemset/problem/1795/C
- **Setup:** tea $i$ with capacity $a_i$ drinks from cups $i, i+1, \dots, n-1$ in order, taking $b_j$ from cup $j$ until empty.
- **Per-tea reformulation:** find smallest $r$ such that $\sum_{j=i}^{r} b_j > a_i$ (binary search on prefix sums).
  - cups $j \in [i, r-1]$ are fully drained by tea $i$ → contribute $+b_j$ to `ans[j]`.
  - cup $r$ gets a partial drain → `ans[r] += a_i - \sum_{j=i}^{r-1} b_j`.
- **Avoiding $O(n^2)$ updates:** the full-drain part is a range update of "+1 fully-drained count" on $[i, r-1]$ → use a **difference array** on counts, prefix-sum at the end, then `ans[j] += cnt[j] * b[j]`. Partial drains are point updates, handle directly.
- **What's nice:** combines binary-search-on-prefix-sum with difference array — two routine tools, the trick is seeing they compose here.

## 6. Controllers
- **Link:** https://codeforces.com/problemset/problem/1742/G
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
- **Link:** https://codeforces.com/problemset/problem/1631/D
- **The fact:** there are only **498 palindromes** $\le 4 \cdot 10^4$. Precompute them, then it's textbook unbounded-coin-change DP: $\approx 498 \times 4 \cdot 10^4 = 2 \cdot 10^7$, trivial.
- Same lesson as **9. Factorials and Powers of Two**: count the candidates before assuming you need cleverness.

## 9. Factorials and Powers of Two
- **Link:** https://codeforces.com/problemset/problem/1646/C
- **Key constraint observation:** $n \le 10^{12}$ and $15! > 10^{12}$, so at most $14$ factorials matter.
- **Reduction:** subtract some subset of factorials, fill the rest with powers of 2 = $\text{popcount}$ of the leftover.

$$\text{ans} = \min_{S \subseteq \{1!, 2!, \dots, 14!\}} \big(|S| + \text{popcount}(n - \text{sum}(S))\big)$$

- **Approach:** brute-force all $2^{14}$ subsets. AC.
- **Takeaway:**
  > [!TIP]
  > Read the constraints first. A lot of 1500-rated problems hide a constant-sized search space behind a scary statement — brute force is allowed, you just have to notice it.

## 10. AGAGA XOOORRR
- **Link:** https://codeforces.com/problemset/problem/1516/B
- **Key observation:** if the array splits into $k \ge 2$ contiguous segments of equal XOR, then it splits into **2 or 3** segments too.
  - merging any 3 adjacent equal-XOR segments gives the same XOR back ($x \oplus x \oplus x = x$), so $k$ drops by 2 each step. Parity preserved → end at 2 (even $k$) or 3 (odd $k$).
- **So check just two cases:**
  - **2 segments:** total XOR $= 0$ (then any split works).
  - **3 segments:** let $y = \text{XOR}(a_1, \dots, a_n)$. Need $i \le j$ with $\text{xor}(1, i{-}1) = \text{xor}(i, j) = \text{xor}(j{+}1, n) = y$. Greedy: earliest prefix with XOR $= y$, latest suffix with XOR $= y$, check non-overlap.
- Without the "reduce to 2 or 3" trick you're stuck at $O(n^2)$. With it, it's $O(n)$.

## 11. Eastern Exhibition
- **Link:** https://codeforces.com/problemset/problem/1486/B
- **Problem:** minimize $\sum (|x_i - x| + |y_i - y|)$ over integer $(x, y)$, count optimal lattice points.
- **Two ideas:**
  1. **Manhattan separates:** $x$ and $y$ are independent → two 1D median problems. Proof in [Good_Concepts.md](Good_Concepts.md).
  2. **Counting:**
     - $n$ odd → unique median per axis → $1$ point.
     - $n$ even → any $x \in [x_{n/2}, x_{n/2+1}]$ works (same for $y$) → answer:

$$(x_{n/2+1} - x_{n/2} + 1) \cdot (y_{n/2+1} - y_{n/2} + 1)$$

- **Insight:** the median fact is standard; recognizing that 2D Manhattan splits cleanly into two independent 1D problems is the part that unlocks it.
