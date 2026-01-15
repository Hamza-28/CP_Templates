/**
*Description: Given natural numbers n and k, the numbers 1 to n are arranged in a circle. Starting from 1, every k-th number is removed in a circular manner. This continues until only one number remains. Find the last remaining number.
*/ 
int josephus(int n, int k) {
  if (n == 1)
    return 0;
  if (k == 1)
    return n-1;
  if (k > n)
    return (josephus(n-1, k) + k) % n;
  int cnt = n / k;
  int res = josephus(n - cnt, k);
  res -= n % k;
  if (res < 0)
    res += n;
  else
    res += res / (k - 1);
  return res;
}
