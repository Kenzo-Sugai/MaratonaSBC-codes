#include <iostream>

using namespace std;

int main(){

    int A, B, C, D, diff1, diff2, diff3;

    cin >> A >> B >> C >> D;

    diff1 = abs((A+B) - (C+D));
    diff2 = abs((A+C) - (B+D));
    diff3 = abs((A+D) - (B+C));

    cout << min(min(diff1, diff2), diff3) << endl;

}
