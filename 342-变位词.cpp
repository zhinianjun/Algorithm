#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int nums;
    cin >> nums;
    string str1, str2;
    vector<string> res;
    while(nums--){
        bool isTrue = true;
        int alphaCounts1[26] = {0};
        int alphaCounts2[26] = {0};
        cin >> str1 >> str2;
        for(int i = 0; i < (int)str1.length(); i++)
            alphaCounts1[str1[i]-'a']++;
        for(int i = 0; i < (int)str2.length(); i++)
            alphaCounts2[str2[i]-'a']++;

        for(int i = 0; i < 26; i++)
            if(alphaCounts1[i] != alphaCounts2[i]){
                isTrue = false;
                break;
            }
        if(isTrue)
           res.push_back("Yes");
        else
            res.push_back("No");
    }
    for(int i = 0; i < (int)res.size(); i++)
        cout << res[i] << endl;
    return 0;
}