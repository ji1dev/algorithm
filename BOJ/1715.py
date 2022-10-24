# 1715번_카드 정렬하기
import heapq
import sys
input = sys.stdin.readline
n = int(input())
h = [] # 힙으로 사용할 리스트
for i in range(n):
    tmp = int(input())
    heapq.heappush(h, tmp)

# 우선순위큐 앞에서 원소를 꺼내서 합치고 다시 삽입하는 과정을 반복
# (card1+card2)+((card1+card2)+card3)+...
ans = 0
while len(h) > 1:
    card1 = heapq.heappop(h)
    card2 = heapq.heappop(h)
    sum = card1+card2
    ans += sum
    heapq.heappush(h, sum)

print(ans)