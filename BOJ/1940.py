# 1940번_주몽의 명령
import sys
input = sys.stdin.readline
n = int(input())
m = int(input())
data = list(map(int, input().split()))
data.sort()

# 투 포인터로 확인하면서 M값 만족하는 경우 찾기
begin = 0
end = n-1
sum = 0
ans = 0
while begin < end:
    sum = data[begin]+data[end]
    if sum < m: 
        begin += 1
    elif sum > m:
        end -= 1
    else:
        ans += 1
        begin += 1 
        end -= 1


print(ans)