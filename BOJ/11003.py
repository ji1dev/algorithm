# 11003번_최솟값 찾기
from collections import deque
import sys
input = sys.stdin.readline
n, l = map(int, input().split())
a = list(map(int, input().split()))
dq = deque()

# 매번 정렬해서 최솟값을 찾는 대신 덱을 사용해서 원소를 항상 오름차순으로 유지
# 덱의 원소는 인덱스와 값 쌍으로 구성되며, 이들이 윈도우의 원소라고 생각
for i in range(n):
    # 덱의 마지막 원소(최댓값)가 새로 삽입할 원소보다 크면 오름차순 깨지므로 pop
    # 이 작업을 반복해서 오름차순 유지되도록 새 원소 삽입
    while dq and (dq[-1][1]>a[i]): dq.pop()
    dq.append((i, a[i]))

    # 윈도우 이동하면서 가장 앞
    if dq[0][0] <= (i-l): dq.popleft()

    # 현재 윈도우에서 최솟값 출력(맨 앞 원소)
    print(dq[0][1], end=' ')
