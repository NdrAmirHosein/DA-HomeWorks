# include <vector>
# include <bits/stdc++.h>
# include <iostream>
using namespace std;

int cutRod(vector<int>& p, int n){
    if (n == 0){
        return 0;
    }
    int q = -1;

    for(int i = 0 ; i < n; i++) {
        q = max(q, p[i] + cutRod(p, n - i -1));
    }

    return q;
}


int memomizedCutRodAux(vector<int>& p, int n, vector<int>& r){
    int q = INT_MIN;

    if(r[n] >= 0){
        return r[n];

    }else if(n == 0){
        q = 0;
    }
    else{
        for (int i = 0; i < n; i++){
            q = max(q, p[i] + memomizedCutRodAux(p , n -i -1, r));
        }
    }
    r[n] = q;
    return q;
}

int memomizedCutRod(vector<int>& p , int n){
    vector<int>nn(n+1 , INT_MIN);

    return memomizedCutRodAux(p, n, nn);
}



int main(){
    vector<int> p = {1, 5, 8, 12};
    int sp = p.size();
    cout << memomizedCutRod(p, sp);
    return 0;
}