#include <iostream>

using namespace std;

int main() {
    int num, find;
    cin >> num >> find;
    int *a = new int[num];
    for(int i = 0; i < num; i++) cin >> a[i];
    
    int low = 0, high = num-1, times = 0;
    int mid = (low + high) / 2;

    while(low<=high){
        times++;
        if(a[mid] == find){
            cout << (low + high)/2 + 1<< endl;
            return 0;
        }  
        else if(a[find > a[mid]]){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
        mid = (low + high)/2;
    }
    cout << -1 << endl;
    return 0;
}