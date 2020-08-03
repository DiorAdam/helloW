#include <iostream>
#include <vector>
#include <algorithm>


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
        i++;
    }
    return s.substr(l,m); 
}


bool sentencePalindrome(std::string s){
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    int i=0, j=s.size()-1 ;
    while (i<=j){
        if (isalnum(s[i]) && isalnum(s[j])){
            if (s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        else{
            if (!isalnum(s[i])){ i++; }
            if (!isalnum(s[j])){ j-- ;}
        }
    }
    return true;
}


int main(){
    std::string s = "abbachjkboallbbllaob";
    std::string sentence0 = "race a car";
    std::string sentence1 = "A man, a plan, a canal: Panama";
    if (sentencePalindrome(sentence1)){ 
        std::cout << "palindome\n";
    }else{std::cout << "not a palindrome";}
    
}



