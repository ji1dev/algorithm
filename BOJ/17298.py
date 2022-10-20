# 17298번_오큰수
import sys
input = sys.stdin.readline
n = int(input())
a = list(map(int, input().split()))

# 스택을 이용해서 NGE를 구함
# 스택 top보다 큰 값이 나오면 오큰수로 판단하고, 스택에서 삭제
NGE = [-1] * n
st = []
for i in range(n):
    # 스택 top의 NGE를 찾으면 pop
    while st and (a[st[-1]]<a[i]):
        NGE[st.pop()] = a[i]
    st.append(i) # NGE idx를 스택에 삽입

for i in NGE:
    print(i, end = ' ')
