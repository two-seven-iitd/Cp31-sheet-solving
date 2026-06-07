# Good Question
---
## 2. Grouping Increases

`greedy`, `casework`, `dp`, `good dp`

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

## 16. Arranging the sheep 
- todo -> clearly analyze all the three solutions
  - binary search
  - pointer 
  - median approach (`goated`)

## 19. Ball in Berland
- todo -> graph formulation for the Question , how can we model it as a graph question

##  Johnny and Another Rating Drop

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