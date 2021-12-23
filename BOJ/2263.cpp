// 2263번_트리의 순회
#include <iostream>
#define MAX 100001
using namespace std;
int n, inOrder[MAX], postOrder[MAX], inIdx[MAX];
// postorder의 루트 구하고 출력, inorder에서 이 루트의 위치를 구함
// inorder에서 앞서 구한 루트의 두 자식 노드를 구할 수 있음
// 각 자식 노드에서 더이상 서브트리 쪼갤 수 없을때까지 위 과정을 반복함
void preOrder(int iBegin, int iEnd, int pBegin, int pEnd){
    if(iBegin>iEnd || pBegin>pEnd) return; // 더 이상 서브트리 안나오는 경우
    int root = postOrder[pEnd]; // postorder는 항상 마지막 노드가 root
    cout << root << " ";
    root = inIdx[root];
    preOrder(iBegin, root-1, pBegin, pBegin+root-iBegin-1); // 왼쪽
    preOrder(root+1, iEnd, pBegin+root-iBegin, pEnd-1); // 오른쪽
}
int main(){
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> inOrder[i];
        inIdx[inOrder[i]] = i; // 각 노드 inorder 순회시 인덱스
    }
    for(int i=0; i<n; ++i) cin >> postOrder[i];
    preOrder(0, n-1, 0, n-1); // inorder, postorder 서브트리 인덱스
    return 0;
}