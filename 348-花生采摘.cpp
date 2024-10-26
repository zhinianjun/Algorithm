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

int distance(vector<struct peanut>& a, vector<struct peanut>& b){
  return abs(a.x - b.x) + abs(a.y - b.y);
}

int main() {
    struct peanut fileds[20][20];
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
            fileds[i][j].x = i;
            fileds[i][j].y = j;
            fileds[i][j].nums = nums;
            insert(pick_sequence, fileds[i][j]);
        }
    
    int times = 0;
    int total = 0;
    steps-=2;
    while (steps > 0)
    {
      if(times == 0){
        steps -= pick_sequence[times].y;
        steps--;
        times++;
        total += pick_sequence[times].nums;
      }
      if(steps )
    }
    
    
    return 0;
}