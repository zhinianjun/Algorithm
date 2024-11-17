#include <iostream>
#include <vector>

using namespace std;
int cir(int n,int m)
{
	int p=0;
	for(int i=2;i<=n;i++)
	{
		p=(p+m)%i;
	}
	return p+1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> list;
    
    for(int i = 0; i < n; i++)
        list.push_back(i+1);
    int index = 0;
     while (list.size() > 1) {
        index = (index + 1) % list.size();         
        list.erase(list.begin() + index); 
     }
    cout << list[0] << endl;
    return 0;
}
