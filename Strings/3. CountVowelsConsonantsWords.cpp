#include <iostream>
using namespace std;

int main() {
    string s = "  How are  you   ";
    int i;
    int vcount = 0;
    int ccount = 0;
    int wordCount = 0;
    for(i=0;s[i]!='\0';i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            vcount++;
        else if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z')
            ccount++;
        if(s[i] == ' ')
            if(i>0 && s[i-1] != ' ')    //If space is present at start or white spaces are present in middle
            wordCount++;
    }
    if(i>0 && s[i-1] == ' ') wordCount--;  //If space is present at end
    cout<<"Vowel count is: "<<vcount<<endl;
    cout<<"Consonant count is: "<<ccount<<endl;
    cout<<"Word count is: "<<wordCount+1;
    return 0;
}
