#include <algorithm>
#include <iostream>
using namespace std;
class Term
{
    friend class Polynomial;

  private:
    float coef;
    float exp;
};

class Polynomial
{
  private:
    Term *termArray;
    int capacity;
    int terms;

  public:
    Polynomial() : capacity(1), terms(0)
    {
    }

    void NewTerm(const float theCoef, const int theExp)
    {
        if (terms == capacity)
        {
            capacity *= 2;
            Term *temp = new Term[capacity];
            copy(termArray, termArray + terms, temp);
            delete[] termArray;
            termArray = temp;
        }

        termArray[terms].coef = theCoef;
        termArray[terms++].exp = theExp;
    }

    Polynomial Add(Polynomial b)
    {
        Polynomial c;
        int aPos = 0, bPos = 0;
        while ((aPos < terms) && (bPos < b.terms))
        {
            if ((termArray[aPos].exp) == b.termArray[bPos].exp)
            {
                float t = termArray[aPos].coef + b.termArray[bPos].coef;
                if (t)
                    c.NewTerm(t, termArray[aPos].exp);
                aPos++;
                bPos++;
            }
            else if (termArray[aPos].exp < b.termArray[bPos].exp)
            {
                c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
                bPos++;
            }

            else
            {
                c.NewTerm(termArray[aPos].coef, termArray[bPos].exp);
                aPos++;
            }
        }

        for (; aPos < terms; aPos++)
        {
            c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
        }
        for (; bPos < terms; bPos++)
        {
            c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
        }

        return c;
    }
};

int main()
{
    return 0;
}