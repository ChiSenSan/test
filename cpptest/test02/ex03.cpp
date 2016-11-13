// Inherit1.cpp
#include <iostream.h>

class CA
{
public:
    CA()     { cout << "CA" << endl; }
    CA(int a){ cout << "CA:" << a << endl; }
    ~CA()    { cout << "~CA" << endl; }
};

class CB : public CA
{
public:
    CB() { cout << "CB" << endl; }
    ~CB(){ cout << "~CB" << endl; }
};

int main()
{
    CB b;

    return 0;
}