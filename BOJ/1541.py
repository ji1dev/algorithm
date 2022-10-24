# 1541번_잃어버린 괄호
import sys
input = sys.stdin.readline

# 식을 최소로 만드는 방법은 최대한 큰 수를 빼는 것
# 덧셈을 먼저 수행하고, 이어서 뺄셈을 수행하기 위해 뺄셈 단위로 식을 끊음
expr = list(map(str, input().split('-')))

# 분리된 원소는 덧셈 수식을 포함하며, 각각을 먼저 계산한 뒤 뺄셈 수행
# 첫 원소는 무조건 더하고, 두 번째 원소부터는 덧셈 결과를 뺌
def calc(e):
    sum = 0
    for i in e.split('+'):
        sum += int(i)
    return sum

ans = 0
for i in range(len(expr)):
    if i == 0: ans += calc(expr[i])
    else: ans -= calc(expr[i])

print(ans)