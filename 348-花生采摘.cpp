#include <iostream>
#include <vector>

using namespace std;

struct peanut{
    int x;
    int y;
    int nums;
};

void insert(vector<struct  peanut> &peanuts, struct peanut& p)
{
    for(int i=0; i<(int)peanuts.size(); i++)
    {
        if(peanuts[i].nums < p.nums)
        {
            peanuts.insert(peanuts.begin()+i, p);
            return;
        }
    }
    peanuts.push_back(p);
}

int distance(struct peanut& a, struct peanut& b){
  return abs(a.x - b.x) + abs(a.y - b.y);
}

int main() {
    int m, n;
    int steps;
    vector<struct peanut> pick_sequence;
    cin >> m >> n;
    cin >> steps;

    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
        {
            int nums;
            cin>>nums;
            struct peanut p = {j, i, nums};
            insert(pick_sequence, p);
        }
    
    int times = 0;
    int total = 0;
    steps-=2;
    struct peanut current = {pick_sequence[0].x, 0, 0};
    while (steps > 0)
    {  
        //判断能否到达下一个花生
        if(steps - distance(current, pick_sequence[times]) < 0)
            break;
        else{
            steps -= distance(current, pick_sequence[times]);
            steps -= 1;
            total += pick_sequence[times].nums;
            current = pick_sequence[times];
            times++;
        }
    
        if(steps - current.y < 0)
        {
            
            total -= current.nums;
            break;
        }
    }
    cout << total << endl;
    
    return 0;
}