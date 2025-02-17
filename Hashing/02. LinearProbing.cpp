#include <bits/stdc++.h>
#define size 10
using namespace std;

int hashFn(int key){
    return key%size;
}

int probe(int H[], int key){
    int index = hashFn(key);
    int i = 0;
    while(H[(index+i)%size] != 0)
        i++;
    return (index+i)%size;
}

void insert(int H[], int key){
    int index = probe(H, key);
    H[index] = key;
}

int search(int H[], int key){
    int index = hashFn(key);
    int i = 0;
    while(H[(index+i)%size] != key){
        if(H[(index+i)%size] == 0)
            return -1;
        i++;
    }
    return (index+i)%size;
}

int main() {
    int H[size] = {0};

    insert(H, 5);
    insert(H, 15);
    insert(H, 52);
    insert(H, 23);
    insert(H, 2);
    int key = 2;
    cout<<search(H, key)<<endl;
    key = 52;
    cout<<search(H, key)<<endl;
    key = 3;
    cout<<search(H, key)<<endl;
    return 0;
}
