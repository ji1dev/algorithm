# 2023번_신기한 소수
import sys, math
input = sys.stdin.readline
n = int(input())

def isPrime(num):
    for i in range(2, round(math.sqrt(num))+1):
        if num%i == 0: return False
    return True

def dfs(num):
    # 2, 3, 5, 7부터 시작해서 n자리 소수가 완성되었으므로 바로 출력하면 오름차순임
    if len(str(num)) == n:
        print(num)
        # return
    # 인자로 받은 소수에 한자리를 추가하고, 해당 수가 소수이면 재귀적으로 들어감
    else:
        for i in range(1, 10):
            if i%2 == 0: continue # 짝수는 붙이면 소수 아니게 되므로 넘어감
            next = num*10+i # 다음 소수 후보
            if isPrime(next): dfs(next)

# 한자릿수의 소수는 2, 3, 5, 7이 전부이므로 여기서부터 DFS 시작
for i in (2, 3, 5, 7): dfs(i)