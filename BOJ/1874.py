# 1874번_스택 수열
import sys
input = sys.stdin.readline
n = int(input())
seq = [0] * n
for i in range(n):
    seq[i] = int(input())

# 자연수 차례대로 삽입하다가 현재 순서에 맞는 수 찾으면 삭제
ans = []
st = []
idx = 0 # seq 배열의 인덱스
for i in range(1, n+1):
    st.append(i)
    ans.append('+')

    # 스택 top에서 원하는 수 만나는동안 계속 pop
    while st and (st[-1]>=seq[idx]):
        st.pop()
        ans.append('-')
        idx += 1

# 스택이 비어있으면 입력된 수열을 만들수 있다는 의미
if not st:
    for op in ans: print(op)
else:
    print('NO')