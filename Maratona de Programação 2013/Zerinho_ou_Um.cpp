#include <iostream>
 
using namespace std;
 
int main() {
    int A, B, C;
    while(cin >> A >> B >> C){
        if(A != B && A != C){
            cout << "A" << endl;
        }
        else if(B != A && B != C){
            cout << "B" << endl;
        }
        else if(C != A && C != B){
            cout << "C" << endl;
        }
        else{
            cout << "*" << endl;
        }
    }
}
