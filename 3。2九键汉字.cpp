#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

map<string, string> pinyinToHanzi = {
    {"qian", "前"},
    {"ru", "入"},
    {"shi", "式"},
    {"qian'ru'shi", "嵌入式"},
    // 添加更多拼音和汉字的映射
};

string recognizePinyin(string inputPinyin) {
    if (pinyinToHanzi.find(inputPinyin) != pinyinToHanzi.end()) {
        return pinyinToHanzi[inputPinyin];
    } else {
        return "未知拼音";
    }
}

int main() {
    string inputPinyin;
    cout << "Enter a sequence of pinyin: ";
    cin >> inputPinyin;

    string recognizedHanzi = recognizePinyin(inputPinyin);

    cout << "Recognized Chinese characters: " << recognizedHanzi << endl;

    return 0;
}
