#include <iostream>

using namespace std;

int main(){
    
    int N, M, C;

    while(cin >> N >> M >> C){
        if(!N && !M && !C){
            return 0;
        }
        int result {0};
        int exp[M][N];

        for(int i = 0; i < M; i++){

            for(int j = 0; j < N; j++){
                cin >> exp[i][j];
            }
        }

        for(int i = 0; i < N; i++){
            int cnt {0};
            for(int j = 0; j < M; j++){
                //cout << j << " " << i << endl;
                //cout << "val: " << exp[j][i] << " cnt: ";
                if(exp[j][i] == 1){
                    cnt++;
                }
                else{
                    if(cnt >= C){
                        result++;
                    }
                    cnt = 0;
                }
                //cout << cnt << endl;
            }
            if(cnt >= C){
                result++;
            }
        }
        cout << result << endl;
    }
}
