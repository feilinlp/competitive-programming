#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

vector < vector <int> > child;
vector < pair <int, int> > result, even;
int n;
int hais=0;

void dfs(int p)
{
    // cout << __LINE__ << endl;
    for (int i=0; i<child[p].size(); i++)
    {
        dfs(child[p][i]);
        if (p!=0)
        {
            result[p].second = 1-result[p].second;
            result[p].first ^= result[child[p][i]].first;
        }
    }
    if (result[p].second==0)
        even.push_back(make_pair(result[p].first, p));
    else if (p!=0)
        hais ^= result[p].first;
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    cin >> n;
    result.resize(n, make_pair(0, 1));
    child.resize(n);
    for (int i=0; i<n; i++)
    {
        int t;
        cin >> t;
        result[i].first=t;
        // cout << __LINE__ << endl;
    }
    hais = result[0].first;
    for (int i=1; i<n; i++)
    {
        int a;
        cin >> a;
        a--;
        child[a].push_back(i);
        // cout << __LINE__ << endl;
    }
    dfs(0);
    // cout << __LINE__ << endl;
    cout << result[0].first << endl;
    for (int i=0; i<even.size(); i++)
        cout << even[i].first << " ";
    cout << endl;

    if (n%2==0)
    {
        cout << 2 << endl;
        cout << 1 << " " << 1 << endl;
    }
    else
    {
        vector <int> before(32, -1);
        vector <int> exist;

        exist.push_back(result[0].first);
        before[result[0].first]=0;
        bool found=false;
        for (int i=0; i<even.size(); i++)
        {
            vector <int> temp;
            for (int j=0; j<exist.size(); j++)
            {
                temp.push_back(exist[j]^even[i].first);
            }
            for (int j=0; j<temp.size(); j++)
            {
                if (before[temp[j]]==-1)
                {
                    exist.push_back(temp[j]);
                    before[temp[j]]=i+1; //its own index + 1
                }
            }

            if (before[0]!=-1)
            {
                found=true;
                break;
            }
        }

        if (found)
        {
            for (int i=0; i<32; i++)
            {
                cout << before[i] << " ";
            }
            cout << endl;

            int curr=0, count=0;
            vector <int> used(even.size(), 0);
            while (before[curr]!=0)
            {
                used[before[curr]-1]=1;
                count++;
                curr=curr ^ even[before[curr]-1].first;
                // cout << __LINE__ << endl;
            }
        
            cout << even.size()-count+1 << endl; 
            for (int i=0; i<even.size(); i++)
            {
                if (!used[i])
                {
                    cout << even[i].second+1 << " ";
                }
            }
            cout << 1 << endl;
        }
        else if (hais==0)
            cout << 1 << endl;
        else
            cout << -1 << endl;
    }
}