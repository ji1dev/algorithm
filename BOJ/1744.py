# 1744번_수 묶기
import sys
input = sys.stdin.readline
n = int(input())
pnum = [] # 양수 저장
nnum = [] # 음수 저장
zero = False # 0 존재 여부
one = 0 # 1개수
sum = 0

for i in range(n):
    tmp = int(input())
    if tmp > 1: pnum.append(tmp)
    elif tmp < 0: nnum.append(tmp)
    elif tmp == 0: zero = True
    else: one += 1

# 양수는 큰 수부터 2개씩 묶어서 곱하고, 더함
pnum.sort(reverse=True)
end = len(pnum)-1
for i in range(0, end, 2):
    # print(pnum[i], pnum[i+1])
    sum += pnum[i]*pnum[i+1]
    
# 홀수개라서 남는 숫자가 있으면 그냥 더함
if len(pnum)%2:
    # print(pnum[end])
    sum += pnum[end]

# 음수는 작은 수부터 2개씩 묶어서 곱하고, 더함 (음수x음수는 양수가 되므로)
nnum.sort()
end = len(nnum)-1
for i in range(0, end, 2):
    # print(nnum[i], nnum[i+1])
    sum += nnum[i]*nnum[i+1]

# 홀수개라서 남는 숫자가 있고, 0이 없으면 그냥 더함
# 0이 있으면 *0 해서 음수를 제거할 수 있으므로 더하지 않음
if len(nnum)%2:
    if not zero: # 0 
        sum += nnum[end]

# 1은 곱해도 숫자를 크게 만들지 못하므로 개수만큼 그냥 더함
sum += one

print(sum)