#include <iostream>

using namespace std;

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

int partiton(int* list, int low, int high){
    int pivot = list[high];
    int pos = low;
    for(int i = low; i < high;i++){
        if(list[i] <= pivot){
            swap(list[i], list[pos]);
            pos++;
        }
    }
    swap(list[pos], list[high]);
    return pos;
}

void quickSort(int* list, int low, int high){
    if(low < high){
        int pos = partiton(list, low, high);
        quickSort(list, low, pos - 1);
        quickSort(list, pos + 1, high);
    }
}

int main() {
    int len;
    int list[50000] = {0};
    cin >> len;
    for(int i = 0; i < len;i++)
        cin >> list[i];

    quickSort(list, 0, len-1);
    for(int i = 0; i < len; i++)
        cout << list[i] << ' ';
    cout << endl;
    return 0;
}