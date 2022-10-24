# 1931번_회의실 배정
import sys
input = sys.stdin.readline
n = int(input())
a = [[] * 2 for _ in range(n)]

# 회의 시간 입력하고 종료시간 기준으로 정렬
# 종료시간이 같은 원소는 경우 시작시간 기준으로 정렬
for i in range(n):
    start, end = map(int, input().split())
    a[i] = (start, end)

a = sorted(a, key=lambda x: (x[1], x[0]))

# 이전 회의 종료와 동시에 다음 회의 시작시키며 횟수를 셈
cnt = 1 # 첫 회의는 무조건 포함
end = a[0][1] # 첫 회의 종료시간
for i in range(1, n): # 두번째 회의부터 확인
    # 현재 회의 종료시간부터 시작하는 회의 중 가장 먼저 가능한 것을 선택
    cur = a[i]
    if cur[0] >= end:
        # print(cur)
        end = cur[1] # 다음 회의의 종료시간으로 갱신
        cnt += 1

print(cnt)