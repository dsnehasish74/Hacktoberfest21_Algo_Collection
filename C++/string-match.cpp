/******************************************************************************

String Matching Algorithm helps to find if two string matches or not || if a pattern
can be found in a text or not.
Brute-Force approach to match string is dicussed below.

*******************************************************************************/

#include <iostream>

using namespace std;

int stringMatch(string text, string pattern){
    int text_size = text.size();
    int pattern_size = pattern.size();
    
    for(int i = 0; i<=(text_size - pattern_size); i++){
        int j = 0;
        while(j<pattern_size && text[i+j] == pattern[j]){
            j++;
        }
        if(j == pattern_size){
            return i;
        }
    }
    return -1;
}


int main()
{
    string text = "Hello World";
    string pattern1 = "ello";
    string pattern2 = "asff";
    
    int ans1 = stringMatch(text, pattern1);
    int ans2 = stringMatch(text, pattern2);
    
    if(ans1 != -1){
        cout<<"Pattern1 is found at "<<ans1<<endl;
    }
    else{
        cout<<"Pattern1 is not found."<<endl;
    }
    
    if(ans2 != -1){
        cout<<"Pattern2 is found at "<<ans2<<endl;
    }
    else{
        cout<<"Pattern2 is not found."<<endl;
    }
    
    return 0;
}
