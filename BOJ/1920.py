# 1920번_수 찾기
import sys
input = sys.stdin.readline
n = int(input())
a = list(map(int, input().split()))
a.sort()
m = int(input())
b = list(map(int, input().split()))

# b의 원소들이 a에 존재하는지 이분탐색으로 확인
def search(num):
    begin = 0
    end = (n-1)
    while begin <= end:
        mid = (begin+end)//2
        if a[mid] == num: return 1 # 찾음
        elif a[mid] > num: end = mid-1 # 왼쪽 부분 탐색
        else: begin = mid+1 # 오른쪽 부분 탐색
    return 0 # 찾는 원소가 존재하지 않음
    
for i in b:
    print(search(i))