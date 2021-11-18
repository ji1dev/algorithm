// 16935번_배열 돌리기 3
#include <iostream>
#include <vector>
using namespace std;
int n, m, r, mat[101][101], tmp[101][101];
vector<int> op;
void copyMatrix(){
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            mat[i][j] = tmp[i][j];
        }
    }
}
void op1(){ // 상하반전
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            tmp[n-i-1][j] = mat[i][j];
        }
    }
}
void op2(){ // 좌우반전
    for(int j=0; j<m; ++j){
        for(int i=0; i<n; ++i){
            tmp[i][m-j-1] = mat[i][j];
        }
    }
}
void op3(){ // 오른쪽으로 90도 회전
    int n0 = n;
    n = m;
    m = n0;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            tmp[i][j] = mat[n0-j-1][i];
        }
    }
}
void op4(){ // 왼쪽으로 90도 회전
    int m0 = m;
    m = n;
    n = m0;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            tmp[i][j] = mat[j][m0-i-1];
        }
    }
}
void op5(){ // 1->2, 2->3, 3->4, 4->1 이동 (시계방향으로 그룹 라벨링)
    int an = n/2;
    int am = m/2;
    for(int i=0; i<an; ++i){
        for(int j=0; j<am; ++j){
            tmp[i][j+am] = mat[i][j];
        }
    }
    for(int i=0; i<an; ++i){
        for(int j=am; j<m; ++j){
            tmp[i+an][j] = mat[i][j];
        }
    }
    for(int i=an; i<n; ++i){
        for(int j=am; j<m; ++j){
            tmp[i][j-am] = mat[i][j];
        }
    }
    for(int i=an; i<n; ++i){
        for(int j=0; j<am; ++j){
            tmp[i-an][j] = mat[i][j];
        }
    }
    copyMatrix();
}
void op6(){ // 1->4, 4->3, 3->2, 2->1 이동
    int an = n/2;
    int am = m/2;
    for(int i=0; i<an; ++i){
        for(int j=0; j<am; ++j){
            tmp[i+an][j] = mat[i][j];
        }
    }
    for(int i=an; i<n; ++i){
        for(int j=0; j<am; ++j){
            tmp[i][j+am] = mat[i][j];
        }
    }
    for(int i=an; i<n; ++i){
        for(int j=am; j<m; ++j){
            tmp[i-an][j] = mat[i][j];
        }
    }
    for(int i=0; i<an; ++i){
        for(int j=am; j<m; ++j){
            tmp[i][j-am] = mat[i][j];
        }
    }  
    copyMatrix();
}
int main(){
    cin >> n >> m >> r;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> mat[i][j];
        }
    }
    for(int i=0; i<r; ++i){
        int tmp;
        cin >> tmp;
        op.push_back(tmp);
    }
    for(int i=0; i<op.size(); ++i){
        if(op[i] == 1) op1();
        else if(op[i] == 2) op2();
        else if(op[i] == 3) op3();
        else if(op[i] == 4) op4();
        else if(op[i] == 5) op5();
        else if(op[i] == 6) op6();
        copyMatrix();
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}