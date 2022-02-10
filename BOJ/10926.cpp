// 10926번_??!
// https://stackoverflow.com/questions/1234582/purpose-of-trigraph-sequences-in-c
#include <iostream>
#include <string>
using namespace std;
string s;
int main(){
    cin >> s;
    cout << s+"\?\?!"; // 그냥 ? 여러개 붙이면 trigraph ignored warning 뜸
    return 0;
}