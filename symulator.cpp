

#include<iostream>
#include<conio.h>
#include<Windows.h>
using namespace std;

void maxspeed(int parameter1) // metoda okreœlaj¹ca makskymaln¹ prêdkoœæ
{
    if (parameter1 == 150)
    {
        cout << "Max speed!!";
    }
}
void minspeed(int parameter1) // metoda okreœlaj¹ca maksymaln¹ prêdkoœæ na biegu wstecznym
{
    if (parameter1 == -10)
    {
        cout << "Max speed on reverse!!";
    }
}
int gasoline(int velocity, int stan_baku) //metoda okreœlaj¹ca poziom paliwa
{
    double q = 0.03; //wspó³czynnik spalania
    double l = 0; // spalanie
    if (velocity < 0) {
        velocity = velocity * (-1);
    }
    l = q * velocity;
    if (stan_baku <= 100)
    {
        cout << "BITTE TANKEN!!!" << endl;
    }
    if (stan_baku == 0)
    {
        cout << "BRAK PALIWA" << endl;
    }
    stan_baku = stan_baku - l;
    return stan_baku;
}
void turning(int velocity, int radius) // loguje ostrze¿enie przy zbyt du¿ym skrêcie kierwonicy w stosunku do prêdkoœci
{
    if (velocity > 40 && radius / velocity > 0.4)
    {
        cout << "UWAGA MO¯LIWY DRIFT!";
    }
}

int main()
{
    long time_of_log, stan_paliwa;
    char key;
    int asciiValue, p = 0;
    cout << "Type frequency of logging: ";
    cin >> time_of_log;
    cout << endl << "Podaj stan paliwa";
    cin >> stan_paliwa;
    long v = 0, turn = 0;

    while (1)
    {
        //key = _getch();
        //asciiValue = key;

        //if (asciiValue == 27)
        //   break;
        if (GetKeyState(VK_ESCAPE) & 0x8000)
        {
            break;
        }
        while (GetKeyState('W') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
        {
            Sleep(100);
            if (v < 150)
            {
                v = v + 10;
            }
            else
            {
                v = 150;
            }
            maxspeed(v);
        }
        while (GetKeyState('S') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
        {
            Sleep(100);

            if (v > -10)
            {
                v = v - 10;
            }
            else
            {
                v = -10;
            }
            minspeed(v);
        }
        while (GetKeyState('D') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
        {
            Sleep(100);
            turn = turn + 15;
        }
        while (GetKeyState('A') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
        {
            Sleep(100);
            turn = turn - 15;
        }
        stan_paliwa = gasoline(v, stan_paliwa);
        turning(v, turn);
        Sleep(time_of_log);
        cout << "velocity: " << v << endl << "truning radius: " << turn << endl << "bak: " << stan_paliwa << endl;
        if (stan_paliwa <= 0)
        {
            cout << "MAMY KLOPOT BRAK PALIWA";
            Sleep(10000);
            break;
        }
    }
    return 0;
}