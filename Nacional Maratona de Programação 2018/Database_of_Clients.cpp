#include <iostream>
#include <set>

using namespace std;

int main(){

    int N;
    string email;
    set<string> users;
    cin >> N;

    for(int i = 0; i < N; i++){

        cin >> email;
        bool plus = false;
        for(int j = 0; j < email.size(); j++){
            if(email[j] == '@') break;
            else if(plus){
                email.erase(email.begin()+j);
                j--;
            }
            else{
                if(email[j] == '.'){
                email.erase(email.begin()+j);
                j--;
                }
                if(email[j] == '+'){
                    email.erase(email.begin()+j);
                    plus = true;
                    j--;
                }
            }
        }
        users.insert(email);
    }
    cout << users.size() << endl;

}
