#include <iostream>
using namespace std;

class Fraction
{
private:
    double dNumenator;
    double dDenominator;
    
public:
    void input_numerator();
    void input_denominator();
    
    void lesa();
    void birta();
    
    friend bool operator < (Fraction& left, Fraction& right);
    friend void operator << (ostream& ut, Fraction& right);
    
};


int main()
{
    const int n = 10;
    
    Fraction arr[n];
    
    // Input ten fractions into the array
    for (int i = 0; i < n; i++)
    {
        arr[i].input_numerator();
        arr[i].input_denominator();
    }
    
    // Bubble sort the fractions; do not try this at home
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (arr[j] < arr[j - 1])
            {
                Fraction tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            }
        }
    }
    
    // Output the fractions
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    
    return 0;
}
void Fraction::input_numerator()
{
    cin >> dNumenator;
}

void Fraction::input_denominator()
{
    cin >> dDenominator;
}

bool operator < (Fraction& left, Fraction& right)
{
    return (left.dNumenator / left.dDenominator) < (right.dNumenator / right.dDenominator);
}

void operator << (ostream& ut, Fraction& right)
{
    ut << right.dNumenator << "/" << right.dDenominator << endl;
    
}
