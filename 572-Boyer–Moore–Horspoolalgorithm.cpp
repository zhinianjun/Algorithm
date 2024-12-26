#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1, str2;
    cin >> str1 >> str2;    
    int pos = str2.find(str1);
    if(pos == str2.npos)
        cout << -1 << endl;
    else
        cout << pos << endl;
    return 0;
}
