/*************************************************************************
	> File Name: sohu.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 19 Mar 2016 09:43:19 PM CST
 ************************************************************************/
/*
 * 搜狐员工小王最近利用假期在外地旅游，在某个小镇碰到一个马戏团表演，精彩的表演结束后发现团长正和大伙在帐篷前激烈讨论，小王打听了下了解到， 马戏团正打算出一个新节目“最高罗汉塔”，即马戏团员叠罗汉表演。考虑到安全因素，要求叠罗汉过程中，站在某个人肩上的人应该既比自己矮又比自己瘦，或相等。 团长想要本次节目中的罗汉塔叠的最高，由于人数众多，正在头疼如何安排人员的问题。小王觉得这个问题很简单，于是统计了参与最高罗汉塔表演的所有团员的身高体重，并且很快找到叠最高罗汉塔的人员序列。 现在你手上也拿到了这样一份身高体重表，请找出可以叠出的最高罗汉塔的高度，这份表中马戏团员依次编号为1到
 * 输入描述:
 * 首先一个正整数N，表示人员个数。 
 * 之后N行，每行三个数，分别对应马戏团员编号，体重和身高。
 *
 *
 * 输出描述:
 * 正整数m，表示罗汉塔的高度。
 */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct p{
    int height;
    int weight;
};

bool cmp(const p& a, const p& b){
    if(a.weight==b.weight)  
        return a.height>b.height;           //为什么这里要把身高高的排在上面?
    return a.weight<b.weight;
}

int main(){
    int N,m;
    while(cin>>N){
        int tmp;
        vector<int> index(N);
        vector<struct p> vec(N);
        for(int i=0;i<N;++i){
            cin>>tmp>>vec[i].weight>>vec[i].height;
            index[i]=i;
        }
        //对体重排序
        sort(vec.begin(),vec.end(),cmp);
       
        //动态规划求最长子序列问题
        vector<int> len(N,1);
        for(int i=1;i<N;++i)
            for(int j=0;j<i;++j)
                if(vec[i].height>=vec[j].height && len[i]<len[j]+1)
                    len[i]=len[j]+1;
        
        m=0;

        for(int i=0;i<N;++i){
            if(m<len[i])
                m=len[i];

        }
        cout<<m<<endl;
    }

}



