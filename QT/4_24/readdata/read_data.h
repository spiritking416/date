#ifndef READ_DATA_H
#define READ_DATA_H

#include <QObject>
#include <QMap>
#include <QString>
#include <stdio.h>

class read_data : public QObject
{
    Q_OBJECT
    Q_PROPERTY(char* path READ read_path WRITE setPath) //NOTIFY pathChanged
public:
    explicit read_data(QObject *parent = 0);
    Q_INVOKABLE void xd_read(int& n);
    Q_INVOKABLE void setPath(char* path);
    void xd_read_data(FILE *fp,int& n,int& numofPoints);
    char* read_path() const;
    void xd_read_para();

    ~read_data();
signals:

public slots:

public:
    QMap<QString,QString> paraMap;
    double **dataBuff;
    char* file_path;
    int row;
};

#endif // READ_DATA_H
