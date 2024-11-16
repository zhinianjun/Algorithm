#include <iostream>
#include <cmath>

using namespace std;

typedef struct NODE{
    long x;
    long y;
}Node;

double distance(const Node& node1, const Node& node2){
    return fabs(sqrt(pow(node1.x - node2.x, 2) + pow(node1.y - node2.y, 2)));
}

int main()
{
    int n;
    Node nodes[1000];
    cin >> n;
    int count;
    while(n--){
        double dis = 99999.0;
        cin >> count;
        for(int i = 0; i < count; i++)
            cin >> nodes[i].x >> nodes[i].y;
        for(int i = 0; i < count; i++)
            for(int j = i + 1; j < count; j++)
                dis = min(dis, distance(nodes[i], nodes[j]));
        
        printf("%.4lf\n", dis);
    }
    return 0;
}
