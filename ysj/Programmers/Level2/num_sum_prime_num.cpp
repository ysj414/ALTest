#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    int num=0;
    int flag;
    for(int i=0; i< nums.size() ;i++)
    {
        num=0;
        for(int j=i+1;j<nums.size(); j++)
        {
            for(int k=j+1;k<nums.size();k++)
            {
                num=nums[i]+nums[j]+nums[k];
                flag=1;
                for(int l=2; l<num ;l++)
                {
                    if(num%l ==0)
                    {
                        flag=0;
                        break;
                    }
                }
                if(flag)
                    answer++;
          
            }
        }
        
    }


    return answer;
}
