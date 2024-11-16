#include <iostream>
#include <cmath>

using namespace std;

int main(){
    bool doorLists[100001] = {false};
    int n;
    int sum = 0;
    cin >> n;

    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j+=i)
                doorLists[j] = !doorLists[j];
    
    for(int i = 1; i <= n; i++)
        if(doorLists[i])
            sum++;
    // sum = sqrt(n);   
    cout << sum << endl;
}