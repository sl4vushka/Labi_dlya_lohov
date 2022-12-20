//подправить формулу
#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
using namespace std;

class square
{
private:
    double m_side;
public:
    square(double side)
    {
        m_side = side;
    }
    square()
    {
        m_side = 1;
    }
    square(square& A)
    {
        m_side = A.get_r();
    }
    ~square()
    {

    }

    double get_r()
    {
        return m_side;
    }
    void set_r(double side)
    {
        m_side = side;
    }

    void show_r()
    {
        cout << m_side;
    }

    double Square_diagonal()
    {
        return (pow(m_side, 2));
    }
};

int main()
{
    square one(10);
    cout << one.Square_diagonal() << endl;

}

