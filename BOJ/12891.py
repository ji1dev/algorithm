# 12891번_DNA 비밀번호
import sys
input = sys.stdin.readline
s, p = map(int, input().split())
str = input()
acgt = list(map(int, input().split())) # 문자별 최소 개수
minCnt = {'A': acgt[0], 'C': acgt[1], 'G': acgt[2], 'T': acgt[3]}

# 슬라이딩 윈도우 이동하며 문자별 최소 개수 만족하는지 확인
cur = {'A': 0, 'C': 0, 'G':0, 'T':0}
ans = 0
for i in range(s-p+1):
    # 첫 윈도우 값 설정
    if i == 0:
        for j in range(p):
            cur[str[j]] += 1

    # 이동한 윈도우 값 설정
    else:
        begin = i-1
        end = i+p-1
        cur[str[begin]] -= 1
        cur[str[end]] += 1

    # 최소 개수 조건 만족하는지 확인
    flag = True
    for c in ('A', 'C', 'G', 'T'):
        if minCnt[c] > cur[c]: flag = False
    if flag: ans += 1

print(ans)