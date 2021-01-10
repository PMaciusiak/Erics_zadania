
#include <iostream>
#include <string>
using namespace std;

void bintodec()
{
    int num, rem, temp, dec = 0, b = 1;
    cout << "Podaj liczbe binarnie : ";
    cin >> num;
    temp = num;
    while (temp > 0)
    {
        rem = temp % 10;
        dec = dec + rem * b;
        b *= 2;
        temp /= 10;
    }
    cout << "W systemie dziesietnym twoja liczba to " << dec;
}

void dectobin(unsigned int n)
{
    if (n / 2 != 0) {
        dectobin(n / 2);
    }
    printf("%d", n % 2);
}

int main()
{
    unsigned int n;
    char choice;
    cout << "Wybierz tryb dzialania kalkulatora" << endl << "b - binarny do dziesietnego" << endl << "d - dziesietny do binarnego" << endl;
    cin >> choice;
    switch (choice)
    {
    case 'b':
        bintodec();
        break;
    case 'd':
        cout << "podaj liczbe dziesietna:  ";
        cin >> n;
        cout << "W systemie binarnym Twoja liczba to:  ";
        dectobin(n);
        break;
    default:
        cout << "Ten klawisz nie jest aktywny. Sprobuj jeszcze raz." << endl;
        break;
    }
    return 0;
}

