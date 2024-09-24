#include <iostream>
using namespace std;

int counter = 1;

void TOH(int n, char src, char aux, char des){          //Time Complexity - O(2^n)
    if(n>0){                                            //Space Complexity - O(n)
        TOH(n-1, src, des, aux);
        cout<<counter++<<". Move a disk from "<<src<<" to "<<des<<endl;
        TOH(n-1, aux, src, des);
    }    
}

int main()
{
    int n = 3;
    TOH(n, 'A', 'B', 'C');

    return 0;
}
