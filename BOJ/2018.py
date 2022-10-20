# 2018번_수들의 합 5
import sys
input = sys.stdin.readline
n = int(input())
begin = 1
end = 1
sum = 1
ans = 1 # n 자기 자신은 반드시 포함

# 투 포인터 이동하면서 합 확인
while end != n:
    if sum < n:
        end += 1
        sum += end
    elif sum > n:
        sum -= begin
        begin += 1
    else:
        ans += 1
        end += 1
        sum += end

print(ans)