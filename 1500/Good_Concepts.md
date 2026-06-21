# Good Concepts

## Counting Inversions with BIT — Controlling Strictness

**Problem:** Given pairs `(a_i, b_i)`, count pairs where `a_i < a_j` and `b_i > b_j` (or variants with ≤, ≥).

**Core idea:** Sort by `a`, then count inversions in `b` using a BIT. Two knobs control strictness:

### Knob 1: Sorting order for ties in `a`
- **Strict `a` (`<`):** sort ties in `a` by `b` descending → tied-`a` pairs can't form inversions
- **Non-strict* `a` (`<=`):** sort ties in `a` by `b` ascending → tied-`a` pairs can form inversions

### Knob 2: BIT query
- **Strict `b` (`>`):** `ans += i - bit.query(rank)` → equal `b` excluded
> [!IMPORTANT]
> - **Non-strict `a` (`<=`):** sort ties in `a` by `b` ascending → tied-`a` pairs can form inversions

### Cheat sheet

| Condition                   | Sort ties in `a` by | Query              |
|-----------------------------|---------------------|--------------------|
| `a_i < a_j` and `b_i > b_j`  | `b` descending      | `i - query(rank)`  |
| `a_i <= a_j` and `b_i >= b_j` | `b` ascending       | `i - query(rank-1)`|
| `a_i < a_j` and `b_i >= b_j` | `b` descending      | `i - query(rank-1)`|
| `a_i <= a_j` and `b_i > b_j` | `b` ascending       | `i - query(rank)`  |

### BIT template

```cpp
struct BIT {
    vector<int> tree;
    int n;
    BIT(int n) : n(n), tree(n + 1, 0) {}

    void update(int i, int del = 1) {
        for (; i <= n; i += i & (-i))
            tree[i] += del;
    }
    int query(int i) {
        int s = 0;
        for (; i > 0; i -= i & (-i))
            s += tree[i];
        return s;
    }
};
```

### Coordinate compression (fastest method)

```cpp
vector<int> s(a);
sort(s.begin(), s.end());
s.erase(unique(s.begin(), s.end()), s.end());
auto rank = [&](int v) {
    return (int)(lower_bound(s.begin(), s.end(), v) - s.begin()) + 1;
};
```

## Median(x) is the Point that minimizes the summation(|xi-x|)

know that it is kinda very known question, so there's obv. nothing new in that

but the thing that `11. Eastern Exhibition` uses that idea, so there is one new thing to add 
- the `|xi-x|` & `|yi-y|` can be thought as independent quantities

### Why |xi - x| and |yi - y| are Independent

the key observation is that the total manhattan distance from a point $(x, y)$ to all points $(x_i, y_i)$ is:

$$\sum (|x_i - x| + |y_i - y|) = \sum|x_i - x| + \sum|y_i - y|$$

so the summation just splits apart. the x-terms only depend on your choice of $x$, the y-terms only depend on your choice of $y$. changing $x$ does absolutely nothing to the y-cost and vice versa.

that means you can minimize $x$ and $y$ separately — find median of all $x_i$'s, find median of all $y_i$'s, done. you don't need to search over 2D space at all, it collapses into two independent 1D problems.

this independence is special to manhattan distance. with euclidean distance $\sqrt{(x_i-x)^2 + (y_i-y)^2}$, $x$ and $y$ are tangled inside the square root — you can't split them. so the "find median independently" trick wouldn't work there.

### Proof that Median minimizes $\sum|x_i - x|$

consider that you are at position $x$ where there are:
- $c_1$ points with $x_i \le x$ (points to your left or at you)
- $c_2$ points with $x_i \ge x$ (points to your right or at you)

now try moving right to $x + 1$ (wlog, same argument works for left):
- every left point gets farther by 1 → total cost increases by $c_1$
- every right point gets closer by 1 → total cost decreases by $c_2$
- net change in cost:

$$\Delta = c_1 - c_2$$

so:
- $c_1 > c_2 \implies \Delta > 0 \implies$ moving right hurts → optimal is to the left
- $c_1 < c_2 \implies \Delta < 0 \implies$ moving right helps → optimal is to the right
- $c_1 = c_2 \implies \Delta = 0 \implies$ you're at an optimal point

and when does $c_1 = c_2$? exactly when equal number of points are on both sides — that's the definition of the median.

to see it concretely, imagine $n = 7$ and you're sliding $x$ from left to right:

| position of $x$ | $c_1$ | $c_2$ | $\Delta = c_1 - c_2$ | verdict |
|---|---|---|---|---|
| far left of all | 0 | 7 | -7 | rush right → |
| past 1st point | 1 | 6 | -5 | still go right → |
| past 2nd point | 2 | 5 | -3 | still go right → |
| past 3rd point | 3 | 4 | -1 | still go right → |
| **past 4th point (median)** | **4** | **3** | **+1** | **← now going right hurts** |

the moment you cross the median, the sign of $\Delta$ flips — meaning you've gone too far. the median is the exact balance point.

if $n$ is odd, that's the unique middle element. if $n$ is even, any point between the two middle elements works (and all give the same cost).