#include "dataconfig.h"

dataconfig::dataconfig(QObject *parent) : QObject(parent)
{
    int array1[4][4] = {{1,1,1,1},{1,1,0,1},{1,0,0,0},{1,1,0,1}};

    QVector< QVector<int> > v;
    for(int i=0 ; i<4 ; i++)
    {
        QVector< int > v1;
        for(int j=0; j<4 ;j++)
        {
            v1.push_back(array1[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(1,v);


    int array2[4][4] = {{1,0,1,1},{0,0,1,1},{1,1,0,0},{1,1,0,1}};

    v.clear();
    for(int i=0 ; i<4 ; i++)
    {
        QVector< int > v1;
        for(int j=0; j<4 ;j++)
        {
            v1.push_back(array2[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(2,v);

    int array3[4][4] = {{0,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,0}};

    v.clear();
    for(int i=0 ; i<4 ; i++)
    {
        QVector< int > v1;
        for(int j=0; j<4 ;j++)
        {
            v1.push_back(array3[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(3,v);

    int array4[4][4] = {{0,1,1,1},{1,0,0,1},{1,0,1,1},{1,1,1,1}};

    v.clear();
    for(int i=0 ; i<4 ; i++)
    {
        QVector< int > v1;
        for(int j=0; j<4 ;j++)
        {
            v1.push_back(array4[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(4,v);

    int array5[4][4] = {{1,0,0,1},{0,0,0,0},{0,0,0,0},{1,0,0,1}};

    v.clear();
    for(int i=0 ; i<4 ; i++)
    {
        QVector< int > v1;
        for(int j=0; j<4 ;j++)
        {
            v1.push_back(array5[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(5,v);
}

