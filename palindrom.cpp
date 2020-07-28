#include <iostream>
#include <vector>


bool isPalin(std::string s){
    int i = 0;
    while (i<s.size()/2+1){
        if (s[i]!= s[s.size()-1-i] ){return false;}
        i+=1;
    }
    return true;
}

std::string longestPalindrom(std::string s){
    int l, i, m;
    l = 0;
    i = 1;
    m = 1;
    while (i < s.size()){
        int lo, le;
        lo = 0;
        le = 0;
        if (i-m-1>=0){lo = i-m-1;}
        if (i-m>=0){le = i-m;}
        std::string odd = s.substr(lo, m+2);
        std::string even = s.substr(le,m+1);
        if (i-m>=0 && isPalin(even) == true){
            m +=1;
            l = le;
        }
        if (i-m-1>=0 && isPalin(odd) == true){
            m += 2;
            l = lo;
        }
        i+=1;
    }
    return s.substr(l,m); 
}


int main(){
    std::string s = "abbachjkallbblla";

    std::cout << longestPalindrom(s);
}


