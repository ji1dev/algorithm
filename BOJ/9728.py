# 9728번_Pair Sum
import sys
input = sys.stdin.readline
x = int(input())
for r in range(1, x+1):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort() # 탐색 전에 오름차순 정렬

    # 투 포인터 사용해서 합이 m인 두 원소의 개수를 셈
    cnt = 0
    begin = 0
    end = n-1
    while begin < end:
        v = a[begin]+a[end]
        if v == m: # 두 원소의 합이 m인 경우
            cnt += 1
            begin += 1
            end -= 1
        elif v > m:
            end -= 1
        else:
            begin += 1

    print("Case #"+str(r)+": "+str(cnt))