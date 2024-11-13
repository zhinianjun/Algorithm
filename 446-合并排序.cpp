#include <iostream>

using namespace std;

void merge(int* source, int* temp, int start, int mid, int end){
    int i = start, j = mid+1, pos=start;
    while(i <= mid && j <= end){
        if(source[i] <= source[j])
        {
            temp[pos] = source[i];
            i++;
        }else{
            temp[pos] = source[j];
            j++;
        }
        pos++;
    }
    while(i <= mid) 
    {
        temp[pos] = source[i];
        i++;
        pos++;
    }
    while(j <= end){
        temp[pos] = source[j];
        j++;
        pos++;
    }
    for(int i = start; i <= end; i++)
      source[i] = temp[i];
}

void mergeSort(int* source, int* temp, int start, int end){
    if(start < end){
        int mid = (start + end) / 2;
        mergeSort(source, temp, start, mid);
        mergeSort(source, temp, mid+1, end);
        merge(source, temp, start, mid, end);
    }
}

int main(){
    int n;
    int source[1000] = {0};
    int temp[1000] = {0};
    cin >> n;
    for(int i = 0; i < n; i++)
      cin >> source[i];
      
    mergeSort(source, temp, 0, n-1);

    for(int i = 0; i < n; i++)
    {
      cout << source[i] << "  ";
      if(i % 9 == 0 && i != 0)
        cout << '\n';
    }
    // cout << '\n';
    return 0;
}