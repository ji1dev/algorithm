// 16506번_CPU
#include <iostream>
#include <string>
#define NP string::npos
using namespace std;
int n, a, b, cd;
bool isConst;
string opc;
string r[] = {"000", "001", "010", "011", "100", "101", "110", "111"};
string c[] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111"
            , "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
void convert(){
    if(opc.find("ADD") != NP) cout << "0000";
    else if(opc.find("SUB") != NP) cout << "0001";
    else if(opc.find("MOV") != NP) cout << "0010";
    else if(opc.find("AND") != NP) cout << "0011";
    else if(opc.find("OR") != NP) cout << "0100";
    else if(opc.find("NOT") != NP) cout << "0101";
    else if(opc.find("MULT") != NP) cout << "0110";
    else if(opc.find("LSFTL") != NP) cout << "0111";
    else if(opc.find("LSFTR") != NP) cout << "1000";
    else if(opc.find("ASFTR") != NP) cout << "1001";
    else if(opc.find("RL") != NP) cout << "1010";
    else if(opc.find("RR") != NP) cout << "1011";
    if(opc[opc.length()-1] == 'C') isConst = true;
    if(isConst) cout << "10" << r[a] << r[b] << c[cd] << "\n";
    else cout << "00" << r[a] << r[b] << r[cd] << "0\n";
}
int main(){
    cin >> n;
    for(int i=0; i<n; ++i){
        isConst = false;
        cin >> opc >> a >> b >> cd;
        convert(); 
    }
    return 0;
}