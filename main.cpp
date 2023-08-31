#include <iostream>
#include <string>
#include "header.h"
#include <fstream>
#include <sstream>

using namespace std;

void cal1(int year , int rup , long double arr[100][2])
{ 
  //double ci, ri, rcvmoney;
  int i ;
  float temp, in ,ifl , p;

    p = rup;
    i=(year-1960);
    //cout << i;


    for (int j=i;j<63;j++)
    {
        in = arr[j][0];
        
        temp = (1+((0.01)*in));
        p*=temp;
    }

   cout <<" The money received before inflation rate : "<<p<<endl;

   for(int j=62;j>=i;j--)
    {
        ifl = arr[j][1];
        temp = (1-((0.01)*ifl));
        p*=temp;
    }

    cout <<" The money received after inflation rate : "<<p<<endl;

   
}

void ReadIndiaData(long double arr[100][2],ifstream& file){
    string line;
    string column;
    int lineNumber = -1;
    int columnNumber = 0;
    if (!file.is_open())
    {
        std::cerr << "Error opening file." << std::endl;
        return;
    }
    while (getline(file, line))
    {
        if (lineNumber == -1)
        {
             lineNumber++;
            continue;
        }
        istringstream ss(line);
        columnNumber = 0;
        while (getline(ss, column, ','))
        {
            if (columnNumber == 2)
            {
                arr[lineNumber][0] = stod(column);
            }
            if(columnNumber==3){
                arr[lineNumber][1] = stod(column);
            }
            columnNumber++;

            column = "";
        }
        lineNumber++;
    }
}


int main()
{
    long double arr[100][2];
    int rup , year;

    //string s1 = "india_data.csv";
    //string s2 = "spain_data.csv";
    //par_fil(s1 , arr);
    //par_fil(s2 , arr2);

    cout << "Enter the rupee:";
    cin >> rup;

    cout << "Enter the year:";
    cin >> year;

    ifstream file("india_data.csv");
    ReadIndiaData(arr,file);
    
    //cal1(int year,int rup , long double ary[100]);

    cal1(year,rup,arr);
    return 0;
};