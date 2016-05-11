#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "read_data.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    qmlRegisterType<read_data>("xd.api.read_data",1,0,"read_data");


    read_data mydata;
    mydata.setPath("x.0.pos");
    mydata.xd_read_para();
    int m=2;
    mydata.xd_read(m);
    FILE* stream=fopen("sd.txt","w");
    for(int i=0;i<mydata.row;++i){
        for(int j=0;j<m;++j){
            fprintf(stream,"%f ",mydata.dataBuff[i][j]);
        }
        printf("\n");
    }
    fclose(stream);


    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


    return app.exec();
}
