#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> list;
    for(int i = 1; i <= n; i++)
        list.push_back(i);

    vector<int>::iterator a = list.begin();
    while(list.size() != 1){
        a++;
        if(a == list.begin())
            a = list.begin();
        list.erase(a);
    }
    cout << list[0] << endl;
    return 0;
}
