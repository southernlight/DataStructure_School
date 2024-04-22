#include <iostream>

using namespace std;

class SparseMatrix
{
  private:
    int rows, cols, terms, capacity; // terms는 0이 아닌 항의 총 수
    MatrixTerm *smArray;

  public:
    SparseMatrix(int rows, int cols, int terms) : rows(rows), cols(cols), terms(terms)
    {
        ;
    }
    SparseMatrix Transpose()
    {
        SparseMatrix b(cols, rows, terms);
        if (terms > 0)
        {
            // nonzero matrix
            int currentB = 0;
            for (int c = 0; c < cols; c++)
            {
                for (int i = 0; i < terms; i++)
                    if (smArray[i].col == c)
                    {
                        b.smArray[currentB].row = smArray[i].col;
                        b.smArray[currentB].col = smArray[i].row;
                        b.smArray[currentB++].value = smArray[i].value;
                    }
            }
        }
        return b;
    }
    SparseMatrix FastTranspose()
    {
        SparseMatrix b(cols, rows, terms);
        if (terms > 0)
        {
            int *rowSize = new int[cols];
            int *rowStart = new int[cols];
            fill(rowSize, rowSize + cols, 0);
            for (int i = 0; i < terms; i++)
                rowSize[smArray[i].col]++;

            rowStart[0] = 0;
            for (int i = 1; i < cols; i++)
                rowStart[i] = rowStart[i - 1] + rowSize[i - 1];

            for (int i = 0; i < terms; i++)
            {
                int j = rowStart[smArray[i].col]++;
                b.smArray[j].row = smArray[i].col;
                b.smArray[j].col = smArray[i].row;
                b.smArray[j].value = smArray[i].value;
            }
        }
    }
};
class MatrixTerm
{
    friend class SparseMatrix;

  private:
    int row, col, value;
};
int main()
{
    return 0;
}