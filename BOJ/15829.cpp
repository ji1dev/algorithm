// 15829번_Hashing
#include <iostream>
#include <cmath>
#define M 1234567891
using namespace std;
int main(){
    int L;
    long long H = 0, R = 1;
    char arr[50];
    cin >> L;
    for(int i=0; i<L; ++i) cin >> arr[i];
    for(int i=0; i<L; ++i){
        H = (H+(arr[i]-96)*R)%M;
        R = (R*31)%M;
    }
    cout << H%M;
    return 0;
}