/*Why is it hard to calculate the answer directly by the formula in the problem statement? The reason is that 2^n is a very large number, for n = 10^8 it consists of around 30 million decimal digits. (Anyway, it was actually possible to get the problem accepted directly calculating the result in Python or Java using built-in long arithmetics.)

The main thing to notice in this problem: x mod y = x  if x < y.

Hence, m mod 2^n = m if m < 2^n.

Since m ≤ 10^8 by the constraints, for n ≥ 27 the answer is always equal to m.

If n < 27, it's easy to calculate the answer directly.

Solution:
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  printf("%d\n", n >= 31 ? m : m % (1 << n));
  return 0;
}
