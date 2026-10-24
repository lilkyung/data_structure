# Binary search

# 시간복잡도 log(n)인 이유

- 반복문을 돌 때마다 일반적으로 순회할 때 보다 2배식 빨라지기 때문이다.

|  | 일반 순회(남은 범위) | binary search(남은 범위) |
| --- | --- | --- |
| 0단계 | $n$ | $n$ |
| 1단계 | $n-1$ | $n\over 2$ |
| … | … | … |
| $k$단계 | $n-k$ | $n\over {2^k}$ |
- 범위가 1이 되면 탐색 종료이므로 ${n\over 2^k}=1, n=2^k, k=log_2n$이 되면서 시간복잡도는 $O(log (n))$이 된다.

# 문제 상황

## Leetcode 69. Sqrt

- x/sqrt (연산자) sqrt 대신에 sqrt * sqrt (연산자) x 를 했을 때 더 직관적이지 않을까 싶어 해봤는데 signed integer overflow가 났다.
- right에 $x\over 2$를 대입하여 반복문을 도는 속도를 줄여보려고 했지만 sqrt가 0이 되는 경우가 많아져 안했다.
