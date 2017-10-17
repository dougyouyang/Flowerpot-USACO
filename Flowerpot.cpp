//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;
pair<int, int> input[100001];
set<pair<int, int> > myset;
set<pair<int, int> >::iterator it;

int main()
{
    int n, d, Min=1000001;
    int i;

    cin >> n >> d;
    for(i=1;i<=n;i++)
        cin >> input[i].first >> input[i].second;
    sort(input+1, input+n+1);
    for(i=1;i<=n;i++){
        pair<int, int> com;
        com.first=input[i].second, com.second=input[i].first;
        myset.insert(com);
        for(it=myset.begin(); it!=myset.end(); ++it){
            if(abs(it->first-com.first)<d)
                break;
                Min=min(Min,abs(it->second-com.second)), myset.erase(it);
        }
        for(it=--myset.end(); it!=myset.begin(); --it){
            if(abs(it->first-com.first)<d)
                break;
                Min=min(Min,abs(it->second-com.second)), myset.erase(it);
        }
    }

    if(Min<1000001)
        cout << Min << endl;
    else
        cout << -1 << endl;

    return 0;
}
