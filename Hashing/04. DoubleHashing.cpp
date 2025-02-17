#include <bits/stdc++.h>
#define size 10
using namespace std;

int h1(int key){
    return key%size;
}

int h2(int key){
    return 7-(key%7);
}

int doubleHash(int H[], int key){
    int i = 0;
    while(H[(h1(key) + i*h2(key))%size] != 0)
        i++;
    return (h1(key) + i*h2(key))%size;
}

void insert(int H[], int key){
    int index = doubleHash(H, key);
    H[index] = key;
}

int search(int H[], int key){
    int i = 0;
    while(H[(h1(key) + i*h2(key))%size] != key){
        if(H[(h1(key) + i*h2(key))%size] == 0)
            return -1;
        i++;
    }
    return (h1(key) + i*h2(key))%size;
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
