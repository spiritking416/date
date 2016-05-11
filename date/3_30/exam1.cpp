/*************************************************************************
	> File Name: exam1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年03月30日 星期三 13时04分11秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        int tmp;
        vector<int> vec;
        int ave=0;
        int output=0;
        for(int i=0;i<n;++i){
            cin>>tmp;
            ave+=tmp;
            vec.push_back(tmp);
        }
        ave=ave/n;   //调整后每一队的人数
        for(unsigned int i=0;i<vec.size()-1;++i){
            if(vec[i]!=ave){     //从头遍历，若不相等，就要调整一次
                ++output;
                int t=ave-vec[i];
                vec[i+1]=vec[i+1]-t;
            }
        }
        cout<<output<<endl;
    }
}
