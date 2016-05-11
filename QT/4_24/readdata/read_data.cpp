#include "read_data.h"

read_data::read_data(QObject *parent) : QObject(parent)
{
    dataBuff=nullptr;
    row=0;
}

void read_data::xd_read_para(){
    FILE *fp = fopen(file_path, "r");
    if(NULL == fp)
    {
        return;
    }
    int i = 0;
    int j = 0;
    char *strs = "";
    char temp[100] = {0};
    char paratemp[100][20] = {0};				//参数缓存
    char *strpos = "Position";

    static char a_ParaName[][20]=		//参数名称数组 由文本文件决定  NULL无需获取由计算取得
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

        "Dwell",		//10  驻留时间
    };

    while (fgets(temp, 99, fp))
    {
        if (strstr(temp, strpos) != NULL)		//参数提取终点判断
        {
            break;
        }

        if (strlen(temp) < 42)
        {
            strs = strtok(temp, "\t");
            while (strs)
            {
                ++j;
                strcpy(paratemp[j],strs);
                strs = strtok(NULL, "\t");
            }
        }
        else
        {
            strs=strtok(temp, ":\t");
            while (strs)
            {
                ++j;
                strcpy(paratemp[j], strs);
                strs = strtok(NULL, ":\t");
            }
        }

        if(j >= 100)			//防止数组越界
        {
            break;
        }

    }
    for (j = 0; j<sizeof(a_ParaName)/20; j++)		//数据匹配
    {
        for (i = 0; i < 100; i++)
        {
            if(strstr(paratemp[i], a_ParaName[j]) != NULL)
            {
                paraMap.insert(a_ParaName[j],paratemp[i+1]);
 //               strcpy(s_textpara.FileName + j * 20, paratemp[i+1]);
            }
        }
    }
    fclose(fp);
}

void read_data::xd_read_data(FILE *fp,int& n,int& numofPoints)
{
    int i = 0;
    int j = 0;
    char temp[2] = "";

    if(dataBuff!=nullptr){
        for(int i=0;i<row;++i){
                delete []dataBuff[i];
                dataBuff[i]=nullptr;
            }
        delete []dataBuff;
        dataBuff=nullptr;
        row=0;
    }

    row=numofPoints;
    dataBuff = new double* [row];
    for(i=0; i<row; i++)
    {
        dataBuff[i] = new double[n];
    }

    fgets(temp, 1, fp);  //舍去一行 分界行
    for (i = 0; i < numofPoints; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            fscanf(fp,"%lf",&dataBuff[i][j]); //databuff[j][i] 一行文本数据存入一列数组
            if(feof(fp)) return ;
        }
    }
}

void read_data::xd_read(int& n)
{
    //     int nkind[3] = {9, 4, 7};

    FILE *fp = fopen(file_path, "r");
    if(NULL == fp)
    {
       //paraMap.insert("failed to read file!","") ;
       return ;		//文件读取失败
    }

    xd_read_para();		//读参数
    int numofPoints=0;
    if(paraMap.contains("NumofPoints"))
        numofPoints = paraMap["NumofPoints"].toInt();
    xd_read_data(fp, n,numofPoints);		//读数据

    fclose(fp);
    fp = NULL;

}

char* read_data::read_path() const
{
    return file_path;
}

void read_data::setPath(char* path)
{
    file_path=path;
}

read_data::~read_data()
{
    for(int i=0;i<row;++i){
        delete []dataBuff[i];
        dataBuff[i]=nullptr;
    }
    delete []dataBuff;
    file_path=nullptr;
    dataBuff=nullptr;
}


