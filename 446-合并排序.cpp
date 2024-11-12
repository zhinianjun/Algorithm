#include <iostream>

using namespace std;

void merge(int* source, int* target, int start, int mid, int end){
    int i = start, j = mid+1, pos=start;
    while(i <= mid && j <= end){
        if(source[i] <= source[j])
        {
            target[pos] = source[i];
            i++;
        }else{
            target[pos] = source[j];
            j++;
        }
        pos++;
    }
    while(i <= mid) 
    {
        target[pos] = source[i];
        i++;
        pos++;
    }
    while(j <= end){
        target[pos] = source[j];
        j++;
        pos++;
    }
}

void mergeSort(int* source, int* target, int start, int end){
    if(start < end){
        int mid = (start + end) / 2;
        mergeSort(source, target, start, mid);
        mergeSort(source, target, mid+1, end);
        merge(source, target, start, mid, end);
        for(int i = 0; i < 12; i++)
            cout << target[i] << ' ';
        cout << endl;
    }
}

int main(){
    int n = 12;
    int source[1000] = {45, 545 , 48, 47, 44, 45, 4857, 58, 57, 485, 1255, 42};
    int target[1000] = {0};

    mergeSort(source, target, 0, 11);

    // for(int i = 0; i < n; i++)
    //     cout << target[i] << ' ';
    return 0;
}