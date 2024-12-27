#include<bits/stdc++.h>
using namespace std;

#define JAI_SHREE_RAM ios::sync_with_stdio(0); cin.tie(0);

typedef long long ll;

void solve(){
    string s;
    ll q1 = 0, q2 = 0, q3 = 0, q4 = 0;
    int px, py, vx, vy;

    while(getline(cin, s)){
        stringstream ss(s);
        string temp;

        getline(ss, temp, '=');
        ss >> px;
        ss.ignore(1);
        ss >> py;

        getline(ss, temp, '=');
        ss >> vx;
        ss.ignore(1);
        ss >> vy;

       // cout<<"px = "<<px<<" py = "<<py<<" vx = "<<vx<<" vy = "<<vy<<endl;

        for (int i = 0; i < 100; i++) {
            px = (px + vx + 101) % 101;
            py = (py + vy + 103) % 103;
        }


        if(px < 50 && py < 51) q1++;
        else if(px > 50 && py < 51) q2++;
        else if(px < 50 && py > 51) q3++;
        else if(px > 50 && py > 51) q4++;
    }

    cout << q1 << " " << q2 << " " << q3 << " " << q4 << '\n';
    cout << q1 * q2 * q3 * q4 << '\n';
}

int main(){
    JAI_SHREE_RAM
    freopen("input.txt", "r", stdin);

    solve();
    return 0;
}
