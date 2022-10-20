# 1253번_좋다
import sys
input = sys.stdin.readline
n = int(input())
a = list(map(int, input().split()))
a.sort()

ans = 0
for idx in range(n):
    begin = 0
    end = n-1
    while begin < end:
        # 다른 수 두개의 합으로 나타내야되므로 본인은 건너뜀
        # 이때, 숫자가 같아도 인덱스 다르면 다른 숫자로 취급함!
        if idx == begin:
            begin += 1
            continue
        elif idx == end:
            end -= 1
            continue

        # 두 수의 합 기준으로 포인터 이동
        target = a[idx]
        sum = a[begin]+a[end]
        if sum < target:
            begin += 1
        elif sum > target:
            end -= 1
        else:        
            # print(str(a[begin])+"+"+str(a[end]))
            ans += 1
            break

print(ans)