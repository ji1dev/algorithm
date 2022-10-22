# 11004번_k번째 수
import sys
input = sys.stdin.readline
n, k = map(int, input().split())
a = list(map(int, input().split()))

def swap(i, j):
    global a
    temp = a[i]
    a[i] = a[j]
    a[j] = temp

def qselect(left, right, k):
    global a
    if left < right:
        # k번째 원소의 위치가 확정되면 바로 탈출
        # 확정된 위치가 k보다 오른쪽이면 왼쪽 부분만 확인, 반대면 오른쪽 부분만 확인
        pivot = partition(left, right)
        if pivot == k: return
        elif k < pivot: qselect(left, pivot-1, k)
        else: qselect(pivot+1, right, k)

def partition(left, right):
    global a

    # 원소 2개 비교시 바로 탈출
    if left+1 == right:
        if a[left] > a[right]: swap(left, right)
        return right

    # 원소 몰려있는 경우 터지지 않도록 중앙값으로 pivot잡고, 계산 편의 위해 첫 원소와 위치 바꿈
    mid = (left+right)//2
    swap(left, mid)
    pivot = a[left]
    low = left+1
    high = right

    # low, high 역전되기 전까지 돌림
    while low <= high:
        # high위치의 원소가 pivot보다 작지 않은 동안 high 감소 (pivot보다 작은 값 만나면 멈춤)
        # low위치의 원소가 pivot보다 크지 않은 동안 low 증가 (pivot보다 큰 값 만나면 멈춤)
        while pivot<a[high] and high>0: high -= 1
        while pivot>a[low] and low<(len(a)-1): low += 1
        
        # low, high가 이동할 수 있는만큼 움직였는데 교차되지 않았다면 swap
        # pivot보다 큰 값 중 가장 왼쪽에 있는 원소와 pivot보다 작은 값 중 가장 오른쪽에 있는 원소를 교환
        if low <= high:
            swap(low, high)
            low += 1
            high -= 1

    # pivot을 자신보다 작은 원소들과 큰 원소들 사이로 이동함
    # 현재 pivot인 left위치의 원소와 pivot보다 작은 원소들 중 가장 오른쪽인 high의 원소를 바꿈
    # 리턴값은 위치가 확정된 원소의 인덱스이므로 high
    a[left] = a[high]
    a[high] = pivot
    return high

qselect(0, n-1, k-1)
print(a[k-1])