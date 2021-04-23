#include <iostream>

using namespace std;
void func(double num, double eps, int &ch, int &zn)
{
    int a = 1; int b = 1;
    int mn = 2; // множитель для начального приближения
    int iter = 0;

    ch = a; zn = b;

    // Поиск начального приближения
    double c = 1;

    do{
        b++;
        c = (double)a / b;
    }
    while ((num - c) < 0);
    if ((num - c) < eps){
        ch = a; zn = b;
        return;
    }

    b--;
    c = (double)a / b;

    if ((num - c) > -eps){
        ch = a; zn = b;
        return;
    }

    // Уточнение
    while (iter < 20000){
        int cc = a*mn, zz = b*mn;
        iter++;
        do{
            zz++;
            c = (double)cc / zz;
        }
        while ((num - c) < 0);
        if ((num - c) < eps){
            ch = cc; zn = zz;
            return;
        }
        zz--;
        c = (double)cc / zz;
        if ((num - c) > -eps){
            ch = cc; zn = zz;
            return;
        }
        mn++;
    }
}
int main()
{
    double inp;
    int ch, zn;
    double eps = 0.0000001;

    cout << "num=";
    cin >> inp;
    func(inp, eps, ch, zn);
    cout << ch << " / " << zn << endl;
    cin.get(); cin.get();

    return 1;
}
