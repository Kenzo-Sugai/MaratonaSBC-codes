#include <iostream>

using namespace std;

int main(){

    int V, C, R;

    cin >> V >> R >> C;

    int bom[C], ruim[R];

    for (int i = 0; i < R; i++)
    {
        cin >> ruim[i];
    }
    for (int i = 0; i < C; i++)
    {
        cin >> bom[i];
    }

    bool atv = true;
    int cnt = 0;
    int idxR = 0, idxB = 0;

    while(atv){
        atv = false;
        if(idxR < R && V-ruim[idxR] >= 0){
            V -= ruim[idxR];
            cnt++;
            atv = true;
            idxR++;
        }
        else if(idxB < C){
            V += bom[idxB];
            cnt++;
            atv = true;
            idxB++;
        }
       
    }

    cout << cnt << endl;    

}
