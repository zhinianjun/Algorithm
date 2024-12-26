#include <iostream>
#include <vector>

using namespace std;

int main()
{
    
    int n;
    while(cin >> n){
        vector<int> list;
        for(int i = 0; i < n; i++){
        bool isrepeat = false;
        int t;
        cin >> t;
        for(int i = 0; i < list.size(); i++)
            if(list[i] == t)
                isrepeat = true;
        if(!isrepeat)
            list.push_back(t);
        }
        for(int i = 0; i < list.size(); i++)
            cout << list[i] << ' ';
        // cout << endl;
    }
    
    return 0;
}
