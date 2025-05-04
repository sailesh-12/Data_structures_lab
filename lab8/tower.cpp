#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<long long> vec(n);

        for (int i = 0; i < n; i++) {
            cin >> vec[i];
        }

        int p1 = 0, p2 = 1;
        sort(vec.begin()+1,vec.end());
        while (p2 < vec.size()) {
            if (vec[p2] > vec[p1] ) {
                vec[p1]++;
                vec[p2]--;
            } else {
                p2++;
            }
        }
        cout<<vec[0]<<endl;
    }


    return 0;
}
