

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ifstream plik("input.txt");
    int j = 0;
    vector<string> T;
    vector<string> when;
    if (plik)
    {

        string data;

        while (getline(plik, data))    
        {
            T.push_back(data);
            j++;
        }
    }
    else
    {
        cout << "ERROR" << endl;
    }
    int errors = 0;
    char parity = '0';
    for (int i = 0; i < T.size(); i++)
    {
        if (parity == '0')
        {
            parity = '1';
        }
        else if(parity == '1')
        {
            parity = '0';
        }

        if ((T[i] == "00000000") || (T[i][7] != parity))
        {
            errors++;
        }
        else
        {
            when.push_back(T[i]);
        }
    }
    ofstream plik2("output.txt");
    plik2 << j << endl;
    plik2 << errors << endl;
    for (int i = 0; i < when.size(); i++)
    {
        plik2 << when[i]<<endl;
    }
    plik2.close();
    return 0;
}