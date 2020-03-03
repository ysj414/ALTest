#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<string> letter[10];
    int k=0;
    while(words.size()!=0)
    {
        for(int i=0; i<n; i++)
        {
            letter[i]=words[i];
            for(int c=0; c<k+i-1; c++)
            {
                if(letter[c]==words[c])
                {
                answer.push_back((i+1));
                if(k<n)
                    answer.push_back(1);
                else
                    answer.push_back(k/n);
                }
            }       
        }
        for(int i=0; i<n-1; i++)
        {
            iterator iter1=letter[i].end();
            iterater iter2=letter[i+1].begin();
            if(*iter1 != *iter2)
            {
                answer.push_back((i+1));
                if(k<n)
                    answer.push_back(1);
                else
                    answer.push_back(k/n);
            }
        }
        
        k=k+n;
    }
      
    
    return answer;
}
