#include <iostream>

using namespace std;

/*
    5 4 2 3 1
    1 3 2 4 5
    3 1 2 4 5
    2 1 3 4 5
    1 2 3 4 5
*/
bool is_sorted(int*, int);
int max_positon(int*, int);
void turn(int*, int);
int sorted_nums(int*, int);

int main() {
    int pancake_list[1000] = {0};
    int count;
    cin >> count;
    for(int i=0; i<count; i++)
        cin >> pancake_list[i];
    
    int turn_count = 0;
    int sorted_count = sorted_nums(pancake_list, count);

    while(sorted_count < count){
        int max_index = max_positon(pancake_list, count-sorted_count);
        if(max_index == 0){
            turn(pancake_list, count-1-sorted_count);
            turn_count++;
        }  
        else{
            turn(pancake_list, max_index);
            turn(pancake_list, count-1-sorted_count);
            turn_count += 2;
        }
        sorted_count = sorted_nums(pancake_list, count);
    }
    cout << turn_count << endl;

    return 0;
}

bool is_sorted(int* pancake_list, int count){
    for(int i=0; i < count-1; i++){
        if(pancake_list[i] > pancake_list[i+1])
            return false;
    }
    return true;
}

int max_positon(int* pancake_list, int count){
    int max_size = 0, max_index = 0;
    for(int i=0; i<count; i++)
        if(pancake_list[i] > max_size)
        {
            max_size = pancake_list[i];
            max_index = i;
        }
    
    return max_index;
}

void turn(int* pancake_list, int pos){
    int left = 0, right =  pos;
    while(left < right){
        int temp = pancake_list[left];
        pancake_list[left] = pancake_list[right];
        pancake_list[right] = temp;
        
        left++;
        right--;
    }
}

int sorted_nums(int* pancake_list, int count){
    int max_index = max_positon(pancake_list, count);
    if(max_index==count-1)
      return sorted_nums(pancake_list, count-1) + 1;
    else 
      return 0;
    
}