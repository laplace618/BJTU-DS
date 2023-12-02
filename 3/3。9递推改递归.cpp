#include <iostream>
using namespace std;

void ditui(int n)
{
    int i;
    i = n;
    while(i>1)
        cout << i--;
}

void digui(int n)
{
    if(n>1)
    {
        cout << n;
        digui(n-1);
    }
    return;
}

int main()
{
    int n1, n2;
    cout << "PLZ input number to start ditui:" << endl;
    cin >> n1;
    ditui(n1);
    cout << endl;

    cout << "PLZ input number to start digui:" << endl;
    cin >> n2;
    digui(n2);
    cout << endl;

    return 0;

}