#include <iostream>

using namespace std;

int main(){

    int n, a, t,cnt = 0;

    cin >> n >> a;

    while(n--){

        cin >> t;
        if(t <= a) cnt++;

    }

    cout << cnt << endl;



}
