# include <iostream>
# include <vector>
# include <math.h>
using namespace std;

void min_pieces(int L, int l){
    vector<int> finalAsnwer;
    vector<int> power;
    
    for (int i = 0; pow(l , i) <= L; i++){
        power.push_back(pow(l, i));

    }
    
    int index = power.size() - 1;
    while (L > 0){
        if (L - (power[index]) >= 0){
            L -= power[index];
            finalAsnwer.push_back(power[index]);        
        }
    index -= 1;
    }
    
    for (int i : finalAsnwer){
        cout << i << endl;
    }

    cout << finalAsnwer.size();

};

int main(){
    min_pieces(1000, 10);

    return 0;
}