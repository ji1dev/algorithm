# 2164번_카드2
from collections import deque
import sys
input = sys.stdin.readline
n = int(input())
q = deque([i for i in range(1, n+1)]) # 큐 채우기

# 큐 front를 가장 위, rear를 가장 아래로 생각하고 구현
while len(q)>1:
    q.popleft() # 가장 위(front)에 있는 카드를 버림
    q.append(q.popleft()) # 가장 위(front)에 있는 카드를 가장 아래(rear)로 옮김

print(q[0])
