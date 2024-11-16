#include <iostream>

using namespace std;

int main()
{
    int n, m, res = 0;
    cin >> n >> m;
    while(n>0){
        if(n == 1){
            res += m;
            cout << m << ' ' << '=' << ' ' << res << endl; 
            break;
        }
        if(n%2 == 0){
            n /= 2;
            m *= 2;
        }else{
            n /= 2;
            cout << m << ' ' << '+' << ' ';
            res += m;
            m *= 2;
        }
    }
    return 0;
}
