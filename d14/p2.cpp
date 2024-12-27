#include<bits/stdc++.h>
using namespace std;

#define JAI_SHREE_RAM ios::sync_with_stdio(0); cin.tie(0);

typedef long long ll;

void solve(){
    string s;
    //ll q1 = 0, q2 = 0, q3 = 0, q4 = 0;
    int px, py, vx, vy;
    vector<pair<int, int>> points;
    vector<pair<int, int>> velocities;

    while(getline(cin, s)){
        //cout<<"s = "<<s<<endl;
        stringstream ss(s);
        string temp;

        getline(ss, temp, '=');
        ss >> px;
        ss.ignore(1);
        ss >> py;

        points.push_back({px, py});

        getline(ss, temp, '=');
        ss >> vx;
        ss.ignore(1);
        ss >> vy;

        //cout<<"px = "<<px<<" py = "<<py<<" vx = "<<vx<<" vy = "<<vy<<endl;


        velocities.push_back({vx, vy});

        // for (int i = 0; i < 100; i++) {
        //     px = (px + vx + 101) % 101;
        //     py = (py + vy + 103) % 103;
        // }

        // if(px < 50 && py < 51) q1++;
        // else if(px > 50 && py < 51) q2++;
        // else if(px < 50 && py > 51) q3++;
        // else if(px > 50 && py > 51) q4++;
    }

    ll min = 99999999999999999;
    ll time = 0;

    for (int i = 1; i < 10000; i++)
    {
        ll q1 = 0, q2 = 0, q3 = 0, q4 = 0;
        for (int j = 0; j < points.size(); j++)
        {
            points[j].first += velocities[j].first+101;
            points[j].second += velocities[j].second+103;
            points[j].first %= 101;
            points[j].second %= 103;

            if(points[j].first < 50 && points[j].second < 51) q1++;
            else if(points[j].first > 50 && points[j].second < 51) q2++;
            else if(points[j].first < 50 && points[j].second > 51) q3++;
            else if(points[j].first > 50 && points[j].second > 51) q4++;
        }

        //cout<<"i = "<<i<<" q1 = "<<q1<<" q2 = "<<q2<<" q3 = "<<q3<<" q4 = "<<q4<<endl;
        cout<<q1*q2*q3*q4<<" "<<min<<endl;
        
        if((q1*q2*q3*q4) < min){
            min = q1*q2*q3*q4;
            time = i;
        }
    }
    
    cout<<"time = "<<time<<endl;



    // cout<<"points.size() = "<<points.size()<<endl;


    // for(int i = 0; i < 10000; i++){
    //     cout<<"i = "<<i<<endl;
    //     vector<vector<char>> grid(103, vector<char>(101, '.'));
    //     for(int j = 0; j < points.size(); j++){
    //         points[j].first += velocities[j].first+101;
    //         points[j].second += velocities[j].second+103;
    //         points[j].first %= 101;
    //         points[j].second %= 103;
    //         grid[points[j].second][points[j].first] = '#';
    //     }

    //     cout<<"at = "<<i<<endl;

    //     if(i<7000) continue;
    //     if(i>8000) continue;

    //     for (int j = 0; j < 101; j++)
    //     {
    //         for (int k = 0; k < 103; k++)
    //         {
    //             cout << grid[k][j];
    //         }
    //         cout << '\n';
    //     }
        
    // }

    // cout << q1 << " " << q2 << " " << q3 << " " << q4 << '\n';
    // cout << q1 * q2 * q3 * q4 << '\n';
}

int main(){
    JAI_SHREE_RAM
    freopen("input.txt", "r", stdin);

    solve();
    return 0;
}
