# 1300번_K번째 수
import sys
input = sys.stdin.readline
n = int(input()) # NxN 배열
k = int(input()) # 찾아야 할 K번째 수

# 이분탐색을 위한 인덱스 설정하고 이분탐색 수행
# 각 행의 값이 N의 배수이므로, K번째 수는 K값을 초과하지 않음
# 따라서 오른쪽 인덱스를 K값으로 설정
left = 1
right = k
ans = 0
while left <= right:
    mid = (left+right)//2
    
    # mid보다 작은 값 개수를 셈
    # mid값이 열 개수(N)보다 크면 mid보다 작은 값은 N으로 설정
    cnt = 0
    for i in range(1, n+1):
        cnt += min(mid//i, n)

    # mid보다 작은 값이 k개 미만이면 mid를 더 크게 잡음
    if cnt < k:
        left = mid+1
    # 아니면 현재 mid값보다 작은 수가 k개 이상이므로 mid를 더 작게 잡음
    # 현재 mid값은 정답 후보가 됨
    else:
        ans = mid
        right = mid-1

print(ans)