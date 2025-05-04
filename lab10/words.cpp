#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<string> a(n), b(n), c(n);
        unordered_map<string, int> wordCount;

        // Input words for each player and count them
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            wordCount[a[i]]++;
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            wordCount[b[i]]++;
        }
        for (int i = 0; i < n; ++i) {
            cin >> c[i];
            wordCount[c[i]]++;
        }

        // Initialize scores
        int score1 = 0, score2 = 0, score3 = 0;

        // Calculate score for player 1
        for (const string &word : a) {
            if (wordCount[word] == 1) score1 += 3;
            else if (wordCount[word] == 2) score1 += 1;
        }

        // Player 2
        for (const string &word : b) {
            if (wordCount[word] == 1) score2 += 3;
            else if (wordCount[word] == 2) score2 += 1;
        }

        // Player 3
        for (const string &word : c) {
            if (wordCount[word] == 1) score3 += 3;
            else if (wordCount[word] == 2) score3 += 1;
        }

        cout << score1 << " " << score2 << " " << score3 << endl;
    }

    return 0;
}
