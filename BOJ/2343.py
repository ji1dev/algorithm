# 2343번_기타 레슨
import sys
input = sys.stdin.readline
n, m = map(int, input().split()) # n개의 강의, m개 블루레이로 제한
lecture = list(map(int, input().split()))

# 이분탐색으로 M개 블루레이로 모든 강의를 담을 수 있도록 하는 블루레이의 크기를 구함
# 즉, 이분탐색의 대상은 블루레이의 크기(길이)
# 최소크기는 길이가 가장 긴 강의, 최대크기는 모든 강의의 길이 합
left = 0
right = 0
for i in range(n):
    if left < lecture[i]: left = lecture[i]
    right += lecture[i]

# 이분탐색 시작
# 왼쪽, 오른쪽 인덱스(블루레이의 크기)가 같아지는 순간의 값이 찾으려는 값
while left <= right:
    mid = (left+right)//2

    # 강의를 모두 담기 위해 필요한 mid 크기의 블루레이 개수 계산
    cnt = 0
    sum = 0
    for i in lecture:
        sum += i
        if sum > mid:
            cnt += 1
            sum = i # i번째 강의 추가해서 터졌으니 해당 강의부터 다시 합계 계산 시작

    # sum이 0이 아니면 계산이 안된 나머지 강의를 담을 블루레이 하나가 더 필요
    if sum: cnt += 1

    # 사용한 블루레이 개수가 m개보다 적거나 같으면 블루레이 크기를 줄이고, 많으면 키움
    if cnt <= m: right = mid-1
    else: left = mid+1

print(left)