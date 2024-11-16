#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct NODE{
    long x;
    long y;
}Node;

bool compare1(const Node& node1, const Node& node2){
    return node1.x <= node2.x;

}
double distance(const Node& node1, const Node& node2){
    return sqrt(pow(node1.x - node2.x, 2) + pow(node1.y - node2.y, 2));
}

double parition(Node* nodes, int left, int right){
    double dis = 999999;
    if(left == right)
        return dis;
    else if(left+1 == right)
        return distance(nodes[left], nodes[right]);

    int mid = (left + right) / 2;
    dis = min(parition(nodes, left, mid), parition(nodes, mid, right));

    vector<Node> list;
    for(int i = left; i <= right; i++)
        if(fabs(nodes[i].x - nodes[mid].x) <= dis)
            list.push_back(nodes[i]);
    
    for(int i = 0; i < (int)list.size(); i++)
        for(int j = i + 1; j < (int)list.size(); j++)
            dis = min(dis, distance(list[i], list[j]));
    
    return dis;
}

int main()
{
    int n , m;
    cin >> n;
    while(n--){
        cin >> m;
        Node nodes[1000] = {{0, 0}};
        for(int i = 0; i < m; i++)
            cin >> nodes[i].x >> nodes[i].y;
        sort(nodes, nodes+m, compare1);
        
        double dis = parition(nodes, 0, m-1);
        printf("%.4lf\n", dis);
    }
   
    // for(int i = 0; i < m; i++)
    //     cout << nodes[i].x << ' ' << nodes[i].y << endl;
    
    return 0;
}
