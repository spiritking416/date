/*************************************************************************
	> File Name: ReadData.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月24日 星期日 20时29分11秒
 ************************************************************************/

#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

inline bool str_find(const string& str1,const string& str2){//str2是要查找的字符串
    if(str1.empty() || str2.empty() || str1.size()<str2.size())    return false;
    auto it=str1.begin();
    auto jt=str2.begin();
    while(it!=str1.end() && jt!=str2.end()){
        if(*it!=*jt)    return false;
        ++it;
        ++jt;
    }
    return true;
}

static vector<string> ParaName
{
	"File Name",		//x.0.pos
    "MachName",			//WM
    "TestAxis",			//(X)
    "Instrument",			//4977
    "Operator",				//ZZY
    "TestDate",			//12/03/2015
    "TestTime",			//16:18:18
    "Humidity",		//相对湿度	参数表编号 12  12-7=5
    "ExpCoef",		//膨胀系数
    "IniPos",		//-800 测量起点
    "EndPos",		//0		终点
    "Increm",		//50	测量步进
    "RunNum",		//2	  测量次数
    "Length",		//800
    "NumofPos",		//17
    "NumofPoints",	//68
    "Dwell"		//10  驻留时间
};

static vector<string> ParaData;

void read_data(string& path){
    if(path.empty())    return;
    ifstream file(path);
    if(!file)   return;
    string strtmp;
    //处理第一个字符串读取
    string name;
    while(file>>strtmp>>name){
        if(str_find(name,"File")){
            strtmp="File";
            file>>name;
        }
        if(str_find(strtmp,"File") && str_find(name,"Name"))
        {
            file>>strtmp;
            ParaData.push_back(strtmp);
            break;
        }
    }

    for(unsigned i=1;i<ParaName.size();++i){
        if(ParaData.size()<i) ParaData.push_back("\0");
        file.clear();//因为上次的循环文件指针可能到文件尾，如不调用，则seekg函数无效
        file.seekg(0,ios::beg);
        while(file>>strtmp){
            if(str_find(strtmp,ParaName[i])){
                file>>strtmp;
                ParaData.push_back(strtmp);
                break;
            }
        } 
    }
    file.close();
}

int main(){
    string path;
    getline(cin,path);
    read_data(path);
    cout<<ParaData.size()<<endl;
    for(auto& i:ParaData){
        cout<<i<<' ';
    }
    cout<<endl;
}


