# Problem solving environment

## Before Use

```bash
./clean.sh # to clean the codes of mine (==Undecember)
```

## venv usage

```bash
# to activate
. venv.sh
# to deactivate
deactivate
```

## boj tool usage

```bash
# print boj help message
boj
```
Use boj command only in boj directory

## template usage

### functions

```cpp
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define dbg(x)      // debug-output object x
#define SETMD(md)   // set non-static MD value
#define MDC(x)      // manual modulate x by MD
#define INV(x)      // modulate 1/x by MD
#define DIV(x, y)   // devide x by y (within MD)
fact(n), ifact(n), ncr(n, r)        // n!, 1/n!, nCr (within MD)
```

### types

```cpp
Mint x;                             // auto modulated integer
MinSegTree<int> mnt(A, INT_MAX);    // minimum segtree from vector A
MaxSegTree<int> mxt(A, INT_MIN);    // minimum segtree from vector A
SumSegTree<int> sst(A);             // sum segtree from vector A
using lli = long long int;
```

### structure

```cpp
_predo() // do something before loop test cases
_solve() // solve each test case
```

### note

* Do not use `scanf` and `printf`
