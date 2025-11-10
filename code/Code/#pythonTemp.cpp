import math, sys
input = sys.stdin.buffer.readline
write = sys.stdout.write

tc = int(input())

for t in range (tc):
  h1, h2, b = map(int, input().split())
  h = math.log(h2 / h1)
  bb = math.log((b - 1) / b)
  ans = math.ceil(h / bb)
  print(ans)
