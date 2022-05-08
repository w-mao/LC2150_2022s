#include <iostream>
#include <vector>
#include <cmath>
int common_count(std::vector<int> &v);

int common_count_in(std::vector<int> &v, unsigned i,int key){
    if(i == v.size()){
        return 0;
    }
    return  common_count_in(v,i+1,key) + (v[i] == key);
}

int common_count_out(std::vector<int> &v, unsigned i){
    if(i == v.size()){
        return 0;
    }
    return std::max(common_count_in(v,i,v[i]),common_count_out(v,i+1));
}

int common_count(std::vector<int> &v){
    return common_count_out(v,0);    
}

int testCommon_Count(){
    std::vector<int> v1 = {2,3,3,1,3,5,6,3,2,1,1,3,3,1,1,1,1,1};
    std::cout<< "The times of 2 occur:" << std::endl;
    std::cout << common_count_in(v1, 1, 2) << std::endl;
    std::cout<< "the most common number:" << std::endl;
    std::cout << common_count(v1) << std::endl;
    std::vector<int> v2 = {1,2,3,4,5,6,7,8,9};
    std::cout << common_count(v2)<< std::endl;
    std::vector<int> v3;
    std::cout << common_count(v3)<< std::endl;
    std::vector<int> v4 = {5,3,4,5,5,3,1};
    std::cout << common_count(v4)<< std::endl;
    return 0;
}
