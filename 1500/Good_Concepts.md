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
