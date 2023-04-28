#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void inputCube(vector<vector<vector<char>>> &cube){

    char c;

    for(int i = 0; i < 6; i++) cube[i].resize(3);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){

            cin >> c;
            cube[4][i].push_back(c);

        }
    }

    for(int i = 0; i < 3; i++){

        for(int k = 0; k < 4; k++){

            for(int j = 0; j < 3; j++){
                
                cin >> c;
                cube[k][i].push_back(c);

            }
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){

            cin >> c;
            cube[5][i].push_back(c);

        }
    }

}

void rotateAdj(vector<vector<vector<char>>> &cube, int r){

    return;

}


void rotateCube(vector<vector<vector<char>>> &cube, int r){

    vector<vector<char>> M(3);

    for(int i = 0; i < 3; i++) M[i].resize(3, ' ');

    if(r < 0){

        r = (r * -1) - 1;

        for(int j = 2, k = 0; j >= 0; j--, k++){
            for(int i = 0; i < 3; i++){
                M[k][i] = cube[r][i][j];
            }
        }
    }
    else{

        for(int j = 0; j < 3; j++){
            for(int i = 2, k = 0; i >= 0; i--, k++){
                M[j][k] = cube[r][i][j];
            }
        }

    }

    cube[r] = M;

}


int main(){

    int T;

    cin >> T;

    while(T--){

        vector<vector<vector<char>>> cubo(6);

        inputCube(cubo);

        int r;
        vector<int> rot;

        while(cin >> r && r) rot.push_back(r);
        
        for(int k = 0; k < 6; k++){

            for(int i = 0; i < 3; i++){

                for(int j = 0; j < 3; j++){

                    cout << cubo[k][i][j];

                }
                cout << endl;

            }
            cout << endl;

        }

        rotateCube(cubo, 1);

        for(int k = 0; k < 6; k++){

            for(int i = 0; i < 3; i++){

                for(int j = 0; j < 3; j++){

                    cout << cubo[k][i][j];

                }
                cout << endl;

            }
            cout << endl;

        }

    }


}
