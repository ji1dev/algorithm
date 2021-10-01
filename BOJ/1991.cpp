// 1991번_트리 순회
#include <iostream>
#define F_IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MP make_pair
using namespace std;
pair <char, char> child[27]; // 어떤 노드의 왼쪽, 오른쪽 자식
void preorder(char node){
	if(node == '.') return; // 더 이상 자식 노드가 없는 경우
    cout << node;
	preorder(child[node].first);
	preorder(child[node].second);
}
void inorder(char node){
	if(node == '.') return;
	inorder(child[node].first);
	cout << node;
	inorder(child[node].second);
}
void postorder(char node){
	if(node == '.') return;
	postorder(child[node].first);
	postorder(child[node].second);
	cout << node;
}
int main(){
    int n;
    char root, left, right;
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> root >> left >> right;
        child[root] = MP(left, right);
    }
    preorder('A'); // 항상 A가 root 임
    cout << "\n";
    inorder('A');
    cout << "\n";
    postorder('A');
    cout << "\n";
	return 0;
}
