#include <iostream>

using namespace std;

int main(){

    int O1, O2, O3, Q1, Q2, Q3;

    cin >> O1 >> O2 >> O3;
    cin >> Q1 >> Q2 >> Q3;

    int sum = 0;

    if(O1 - Q1 < 0) sum += abs(O1 - Q1);
    if(O2 - Q2 < 0) sum += abs(O2 - Q2);
    if(O3 - Q3 < 0) sum += abs(O3 - Q3);

    cout << sum << endl;
}
