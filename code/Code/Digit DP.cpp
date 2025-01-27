int dp[10][90][90][2];
int fun(int pos, int digSum, int dig, int smaint){
  if(pos==num.size()){
    if(!dig and !digSum) return 1;
    return 0;
  }
  if(dp[pos][digSum][dig][smaint] != -1) return dp[pos][digSum][dig][smaint];
  int ans = 0;
  int limit = num[pos];
  if(smaint == 1) limit = 9;
  for(int i=0; i<=limit; i++){
    int nsm = (i < num[pos] || smaint);
    int ndigSum = (digSum + i) % c;
    int ndig = (dig* 10 + i) % c;
    ans += fun(pos+1, ndigSum, ndig, nsm);
  }
  return dp[pos][digSum][dig][smaint] = ans;
}