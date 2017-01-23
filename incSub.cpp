#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
   
    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        int l = nums.size(),mapS,c=0,idx;
        vector<vector<int>> res;
        map<vector<int>,int> myMap;     
        vector<int> temp;
        
        //with 2 elements
        for(int i=0;i<l-1;i++)
        {
            for(int j=i+1;j<l;j++)
            {
            if(nums[i]<=nums[j])
            {
                temp.push_back(nums[i]);
                temp.push_back(nums[j]);
                myMap.insert(std::make_pair(temp, j));
                temp.erase (temp.begin(),temp.begin()+2);
                
            }
        }
        }
        
        // more than 2
       
        //cout<<mapS;
        for (auto& x: myMap) 
        {
            //std::cout << x.first << ": " << x.second << '\n';
            idx = x.second;
            
                for(int i = idx+1;i<l;i++)
                {
                    temp = x.first;
                    if(temp[temp.size()-1] <= nums[i])
                    {
                        temp.push_back(nums[i]);
                        myMap.insert(std::make_pair(temp, i));
                        temp.erase(temp.begin(),temp.begin()+temp.size() - 1);
                    }
                }
            
        }
        //res
         for (auto& x: myMap) 
        {
            res.push_back(x.first);
        }
        
        return res;
    }
};