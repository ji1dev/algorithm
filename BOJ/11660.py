# 11660번_구간 합 구하기 5
import sys
input = sys.stdin.readline
n, m = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]
dp = [[0] * (n+1) for _ in range(n+1)] # 빈 합 배열 생성


# 1행 1열부터 합 배열의 값 채우기
for i in range(1, n+1):
    for j in range(1, n+1):
        dp[i][j] = dp[i][j-1]+dp[i-1][j]+arr[i-1][j-1]-dp[i-1][j-1]

# 구간 합 구하기
for _ in range(m):
    x1, y1, x2, y2 = map(int, input().split())
    ans = dp[x2][y2]-dp[x1-1][y2]-dp[x2][y1-1]+dp[x1-1][y1-1]
    print(ans)