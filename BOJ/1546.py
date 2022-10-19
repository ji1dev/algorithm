# 1546번_평균
n = int(input())
scores = list(map(int, input().split()))
smax = max(scores)
ssum = sum(scores)

# e.g. (s1/smax*100 + s2/smax*100)/2 = (s1+s2)/smax*100/2
print(ssum/smax*100/n)