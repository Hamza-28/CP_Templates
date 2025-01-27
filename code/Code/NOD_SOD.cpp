pair<ll, ll> nod_sod(ll n) {
  ll divisor = 1; ll sum = 1;
  for (ll i = 0; primes[i]*primes[i] <= n; i++) {
    if (n % primes[i] == 0) {
      ll cnt = 1;
      while (n % primes[i] == 0) {
        n /= primes[i];
        cnt++;
      }
      divisor *= cnt;
      sum *= (pow(primes[i], cnt) - 1) / (primes[i] - 1);  
    } 
  }
  if (n > 1) divisor *= 2, sum *= (pow(n, 2) - 1) / (n - 1);
  return {divisor, sum};
}