#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<string, string> pinyinToHanzi = {
    {"wo", "我"},
    {"shi", "是"},
    {"nide", "你的"},
    {"pengyou", "朋友"},
    // 添加更多拼音和汉字的映射
};

int editDistance(const string& s1, const string& s2) {
    int len1 = s1.length();
    int len2 = s2.length();
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            }
        }
    }

    return dp[len1][len2];
}

string correctPinyin(const string& inputPinyin) {
    string correctedPinyin = inputPinyin;
    int minDistance = INT_MAX;
    string closestPinyin = inputPinyin;

    for (const auto& entry : pinyinToHanzi) {
        int distance = editDistance(inputPinyin, entry.first);
        if (distance < minDistance) {
            minDistance = distance;
            closestPinyin = entry.first;
        }
    }

    return closestPinyin;
}

int main() {
    string inputPinyin;
    cout << "Enter a sequence of pinyin: ";
    cin >> inputPinyin;

    string correctedPinyin = correctPinyin(inputPinyin);

    cout << "Corrected Pinyin: " << correctedPinyin << endl;

    if (pinyinToHanzi.find(correctedPinyin) != pinyinToHanzi.end()) {
        cout << "Corresponding Chinese characters: " << pinyinToHanzi[correctedPinyin] << endl;
    }

    return 0;
}
