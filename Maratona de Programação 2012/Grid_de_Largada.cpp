#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, value;
    while(cin >> N){
        vector<int> C;
        vector<int> F;

        for(int i = 0; i < N; i++){
            cin >> value;
            C.push_back(value);
        }
        for(int i = 0; i < N; i++){
            cin >> value;
            F.push_back(value);
        }
        int cnt {0};
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(F[i] == C[j]){
                    if(i != j){
                        cnt += std::abs(i - j);
                        C.insert(C.begin()+i, C[j]);
                        C.erase(C.begin()+j + 1);
                    }
                    break;
                }
            }
        }
        cout << cnt << endl;
    }
}
