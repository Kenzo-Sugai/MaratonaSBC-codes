#include <iostream>

using namespace std;

int main(){

    int A[3], sum, idx = 0, maior = 0, min;
    
    for(int i = 0; i < 3; i++){
        cin >> A[i];
        min += 3 * A[i];
    }
    
    for(int i = 0; i < 3; i++){

        maior = A[i];
        sum = 0;
        for(int j = 0; j < 3; j++){

            sum += std::abs(i - j) * A[j];

        }

        if(sum < min){
            min = sum;
        }

    }

    cout << min * 2 << endl;

}
