#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
    cin >> T;

    for (int t=0; t<T; t++) {
        int n;
        cin >> n;
        
        char dir[n];
        
        cin >> dir;
        
        map <char, int> count;
        
        count['N'] = 0;
        count['S'] = 0;
        count['W'] = 0;
        count['E'] = 0;
        
        for (int i=0; i<n; i++) {
            count[dir[i]] += 1;
        }
        
        bool poss = true;
        if ((count['N'] - count['S'])%2==1 || (count['W']-count['E'])%2==1) {
            poss = false;
        }
        
        
        if (poss) {
            int north = (count['N'] - count['S']) / 2;
            int east = (count['E'] - count['W']) / 2;
            
            // cout << "north" << north << "east" << east;
            int h=0;

            for (int i=0; i<n; i++) {
                if (dir[i] == 'N') {
                    if (north > 0 || h==0) {
                        dir[i] = 'H';
                        north--;
                        h++;
                    } else {
                        dir[i] = 'R';
                    }
                } else if (dir[i] == 'S') {
                    if (north < 0 || h==0) {
                        dir[i] = 'H';
                        north++;
                        h++;
                    } else {
                        dir[i] = 'R';
                    }
                } else if (dir[i] == 'E') {
                    if (east > 0 || h==0) {
                        dir[i] = 'H';
                        east--;
                        h++;
                    } else {
                        dir[i] = 'R';
                    }
                } else if (dir[i] == 'W') {
                    if (east < 0 || h==0) {
                        dir[i] = 'H';
                        east++;
                        h++;
                    } else {
                        dir[i] = 'R';
                    }
                }
            }
            

            bool same = true;
            for (int i=0; i<n-1; i++)
            {
                if (dir[i] != dir[i+1])
                    same = false;
            }

            if (same)
                cout << "NO\n";
            else {
                for (int i=0; i<n; i++)
                    cout << dir[i];
                cout << endl;
            }
        } else {
            cout << "NO\n";
        }
    }
}
