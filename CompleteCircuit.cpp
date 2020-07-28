#include <iostream>
#include <vector>

int Circuit(std::vector<int> gas, std::vector<int> cost){
    int tank, gap, ans;
    tank = 0;
    gap = 0;
    ans = 0;
        for (int i=0; i<gas.size(); i++){
        tank += gas[i];
        if (tank > cost[i]){
            tank-= cost[i];
        }
        else{
            gap += cost[i]-tank;
            tank = 0;
            ans=i+1;
        } 
    }
    if (ans==gas.size() || tank < gap){
        return -1;
    } 
    else{return ans;};
}


int main(){
    std::vector<int> g = {1,2,3,4,5};
    std::vector<int> c = {3,4,5,1,2};

    std::cout << Circuit(g,c);
}

