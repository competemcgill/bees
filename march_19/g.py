from collections import Counter

n, d = map(int, input().split())
ctr = Counter([x // d for x in map(int, input().split())])
res = 0
for v in ctr.values():
    res += v * (v - 1) // 2
print(res)

