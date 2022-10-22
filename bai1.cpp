#include <iostream>
#include <string>
#include <fstream>
#define M 6
#define V 5


using namespace std;

void init(int arr[][M]) {
  for (int i = 0; i < M; i++)
    for (int j = 0; j < M; j++)
      arr[i][j] = 0;
}

void add(int arr[][M], int i, int j) {
  arr[i][j] = 1;
  arr[j][i] = 1;
}

int read_File1(int m[][M], int s[])
{
    ifstream filein;
    filein.open("input1.txt", ios::in);
    if (filein.is_open() == false)
    {
        cout << "Could not open the file!!!" << endl;
        return -1;
    }
    while (!filein.eof())
    {
        for (int i = 0; i < M; i++)
        {
            filein >> s[i];
            filein.ignore();
            for (int j = 0; j < M; j++)
            {
                filein >> m[i][j];
                filein.ignore();
            }
        }
    }
    filein.close();
}

int input1_1(int m[][M], int s[])
{
    read_File1(m, s);
    ofstream fileout;
    fileout.open("input1_1.txt", ios::out);
    if (fileout.is_open() == false)
    {
        cout << "Could not open file!!!" << endl;
        return -1;
    }
    for (int i = 0; i < M; i++)
    {
        fileout << s[i] << " ";
        for (int j = 0; j < M; j++)
        {
            if(m[i][j]!=0)
                fileout << m[i][j] << " ";
            else
                fileout << 0 <<" ";
        }
        fileout << endl;
    }
    fileout.close();
}

int input1_2(int m[][M], int s[])
{
    read_File1(m, s);
    ofstream fileout;
    fileout.open("input1_2.txt", ios::out);
    if (fileout.is_open() == false)
    {
        cout << "Could not open file!!!" << endl;
        return -1;
    }
    for(int i=0; i<M; i++)
    {
        for(int j=i+1; j<M; j++)
        {
            if(m[i][j]!=0)
            {
                fileout << s[i]<< " " << m[i][j] << endl;
            }
        }
    }
    fileout.close();
}

int read_File1_1(int m[][M], int s[])
{
    ifstream filein;
    filein.open("input1_1.txt", ios::in);
    if (filein.is_open() == false)
    {
        cout << "Could not open the file!!!" << endl;
        return -1;
    }
    while (!filein.eof())
    {
        for (int i = 0; i < M; i++)
        {
            filein >> s[i];
            filein.ignore();
            for (int j = 0; j < M; j++)
            {
                filein >> m[i][j];
                filein.ignore();
            }
        }
    }
    filein.close();
}

int output1_1(int m[][M], int s[])
{
    ofstream fileout;
    fileout.open("output1_1.txt", ios::out);
    if (fileout.is_open() == false)
    {
        cout << "Could not open file!!!" << endl;
        return -1;
    }
    int a1[M];
    read_File1_1(m, s);
    // ma tran ke
    for(int i=0; i<M; i++)
    {
        a1[i]=0;
        for(int j=0; j<M; j++)
        {
            if(m[i][j]!=0)
            {
                fileout << m[i][j] << "  ";
                a1[i]++;
            }
            else
                fileout << 0 << "  ";
        }
        fileout << endl;
    }
    // danh sach canh
    for(int i=0; i<M; i++)
    {
        for(int j=i+1; j<M; j++)
        {
            if(m[i][j]!=0)
                fileout << s[i] << "  " << m[i][j] << endl;
        }
    }
    // bac cua dinh
    for(int i =0; i< M; i++)
    {
        fileout << "deg(" << s[i] << "): " << a1[i] << "" << endl;
    }
    fileout.close();
}

int read_File1_2(int m1[], int m2[])
{
    ifstream filein;
    filein.open("input1_2.txt", ios::in);
    if (filein.is_open() == false)
    {
        cout << "Could not open the file!!!" << endl;
        return -1;
    }
    int i=0;
    while (!filein.eof())
    {
        filein >> m1[i];
        filein.ignore();
        filein >> m2[i];
        filein.ignore();
        i++;
    }
    i--;
    filein.close();
    return i;
}

int output1_2(int m[][M], int s[])
{
    int p[100];
    int q[100];
    int x = read_File1_2(p, q);
    ofstream fileout;
    fileout.open("output1_2.txt", ios::out);
    if (fileout.is_open() == false)
    {
        cout << "Could not open file!!!" << endl;
        return -1;
    }
    init(m);
    // ma tran ke
    for(int i=0; i<x; i++)
    {
        add(m, p[i]-1, q[i]-1);
    }
    int a1[M];
    for(int i=0; i<M; i++)
    {
        a1[i]=0;
        for(int j=0; j<M; j++)
        {
            if(m[i][j]!=0)
            a1[i]++;
            fileout << m[i][j] << " ";
        }
        fileout << endl;
    }
    // danh sach canh
    for(int i=0; i<M; i++)
    {
        fileout << s[i] << " ";
        for(int j=0; j<x; j++)
        {
            if(p[j]== i+1)
                fileout << q[j] << " ";
        }
        fileout << endl;
    }
    // bac cua dinh
    for(int i=0; i<M; i++)
    {
            fileout << "deg(" << s[i] << "): " << a1[i] << "" << endl;
    }
    fileout.close();
}

int read_File2(int m[][V], int s[])
{
    ifstream filein;
    filein.open("input2.txt", ios::in);
    if (filein.is_open() == false)
    {
        cout << "Could not open the file!!!" << endl;
        return -1;
    }
    while (!filein.eof())
    {
        for (int i = 0; i < V; i++)
        {
            filein >> s[i];
            filein.ignore();
            for (int j = 0; j < V; j++)
            {
                filein >> m[i][j];
                filein.ignore();
            }
        }
    }
    filein.close();
}

int input2_1(int m[][V], int s[])
{
    read_File2(m, s);
    ofstream fileout;
    fileout.open("input2_1.txt", ios::out);
    if (fileout.is_open() == false)
    {
        cout << "Could not open file!!!" << endl;
        return -1;
    }
    for (int i = 0; i < V; i++)
    {
        fileout << s[i] << " ";
        for (int j = 0; j < V; j++)
        {
            if(m[i][j]!=0)
                fileout << m[i][j] << " ";
            else
                fileout << 0 <<" ";
        }
        fileout << endl;
    }
    fileout.close();
}

int input2_2(int m[][V], int s[])
{
    read_File2(m, s);
    ofstream fileout;
    fileout.open("input2_2.txt", ios::out);
    if (fileout.is_open() == false)
    {
        cout << "Could not open file!!!" << endl;
        return -1;
    }
    for(int i=0; i<V; i++)
    {
        for(int j=i+1; j<V; j++)
        {
            if(m[i][j]!=0)
            {
                fileout << s[i]<< " " << m[i][j] << endl;
            }
        }
    }
    fileout.close();
}

int read_File2_1(int m[][V], int s[])
{
    ifstream filein;
    filein.open("input2_1.txt", ios::in);
    if (filein.is_open() == false)
    {
        cout << "Could not open the file!!!" << endl;
        return -1;
    }
    while (!filein.eof())
    {
        for (int i = 0; i < V; i++)
        {
            filein >> s[i];
            filein.ignore();
            for (int j = 0; j < V; j++)
            {
                filein >> m[i][j];
                filein.ignore();
            }
        }
    }
    filein.close();
}

int output2_1(int m[][V], int s[])
{
    ofstream fileout;
    fileout.open("output2_1.txt", ios::out);
    if (fileout.is_open() == false)
    {
        cout << "Could not open file!!!" << endl;
        return -1;
    }
    int a1[M];
    read_File2_1(m, s);
    // ma tran ke
    for(int i=0; i<V; i++)
    {
        a1[i]=0;
        for(int j=0; j<V; j++)
        {
            if(m[i][j]!=0)
            {
                fileout << m[i][j] << "  ";
                a1[i]++;
            }
            else
                fileout << 0 << "  ";
        }
        fileout << endl;
    }
    // danh sach canh
    for(int i=0; i<V; i++)
    {
        for(int j=i+1; j<V; j++)
        {
            if(m[i][j]!=0)
                fileout << s[i] << "  " << m[i][j] << endl;
        }
    }
    // bac cua dinh
    for(int i =0; i< V; i++)
    {
        fileout << "deg(" << s[i] << "): " << a1[i] << "" << endl;
    }
    fileout.close();
}
int main()
{
    int standrd[M];
    int matrix[M][M];
    input1_1(matrix, standrd);
    input1_2(matrix, standrd);
    read_File1_1(matrix, standrd);
    output1_1(matrix, standrd);
    output1_2(matrix, standrd);
    int standrd2[V];
    int matrix2[V][V];
    input2_1(matrix2, standrd2);
    input2_2(matrix2, standrd2);
    output2_1(matrix2, standrd2);
}