// 20492번_세금
#include <iostream>
using namespace std;
int n;
int main(){
    cin >> n;
    int a1 = n*0.22;
    int a2 = a1*0.2;
    cout << n-a1 << " " << n-a2;
}