# 11286번_절댓값 힙
import heapq
import sys
input = sys.stdin.readline
n = int(input())

# 절댓값 힙 연산 시작
# 힙의 원소는 절댓값, 원본값 쌍으로 구성되어서 절댓값 기준 오름차순으로 정렬됨
h = []
ans = []
for i in range(n):
    x = int(input())
    
    # 절댓값이 가장 작은 값의 원본 값 저장하고 제거
    if x == 0:
        result = 0 # 힙 비어있는 경우를 위한 기본값 0 셋팅
        if h: result = heapq.heappop(h)[1]
        ans.append(result)

    # x를 힙에 추가
    else:
        heapq.heappush(h, (abs(x), x))

for i in ans:
    print(i)
