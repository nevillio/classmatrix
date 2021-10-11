#include<iostream>
using namespace std;
int i, j;
class Matrix {
	// Private section
	int **A, r, c;
public:
	// Public Declarations
	Matrix(int a, int b)
	{
		r = a, c = b, A = new int* [r];
		for (i = 0; i < r; i++)
		{
			A[i] = new int[c];
		}
	}
	~Matrix()
	{
		for ( i = 0; i < r; i++)
		{
			delete A[i];
		}
		delete A;
		cout << "\nDest";
	}
	void Read()
	{
		for (i = 0; i < r; i++) {
			for (j = 0; j < c; j++) {
				cin >> A[i][j];
			}
		}
	}
	void Print()
	{
		for (i = 0; i < r; i++) {

			for (j = 0; j < c; j++) {
				cout << A[i][j] << " ";
			}
			cout << "\n";
		}
	}
	void sum(Matrix z)
	{
		if (r == z.r && c == z.c)
		{
			for (i = 0; i < r; i++)
				for (j = 0; j < c; j++)
					A[i][j] += z.A[i][j];
			cout << "\nSum Matrix\n";
			Print();
		}
		else
			cout << "\n\nCannot add matrices";
	}

	void prdct(Matrix z)
	{
		if (c == z.r)
		{
			Matrix prdct(r, z.c);
			int k;
			for (i = 0; i < prdct.r; i++)
				for (j = 0; j < prdct.c; j++)
				{
					prdct.A[i][j] = 0;
					for (k = 0; k < c; k++)
						prdct.A[i][j] += A[i][k] * z.A[k][j];
				}
			cout << "\nProduct Matrix\n";
			prdct.Print();
		}
		else
			cout << "\n\nCannot multiply matrices";
	}
protected:
 /*Protected Declarations*/
};
int main()
{
	int n, m, p, q;
	cout << "\nEnter the order of the first matrix\n";
	cin >> m >> n;
	cout << "\nEnter the order of the second matrix\n";
	cin >> p >> q;
	Matrix A(m, n), B(p, q);
	cout << "\nEnter the elements\n";
	A.Read();
	cout << "\nEnter the elements\n";
	B.Read();
	cout << "\nMatrix A\n";
	A.Print();
	cout << "\nMatrix B\n";
	B.Print();
	/*if (m==p && n==q)
	{
		A.sum(B);

	}*/
	A.prdct(B);
	return 0;
}
