#include<iostream>
#include<cmath>
using namespace std;

// global variables
// matrix A and B and the result matrix and inverse B
long long matrixA[100][100]{ 0 };
long long matrixB[100][100]{ 0 };
long long resMatrix[100][100]{ 0 };


// input and outputs
void input_matrix(long long matrix[][100], int r, int col)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> matrix[i][j];
		}
	}
}

void output_matrix(long long matrix[][100], int r, int col)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
void output_error()
{
	cout << "The operation you chose is invalid for the given matrices.\n";
}


// adding and subtracting and multiplying
void add_A_and_B(int r1, int col1, int r2, int col2)
{
	if (r1 == r2 && col1 == col2)
	{
		for (int i = 0; i < r1; i++)
		{
			for (int j = 0; j < col1; j++)
			{
				resMatrix[i][j] = matrixA[i][j] + matrixB[i][j];
			}
		}
		output_matrix(resMatrix, r1, col1);
	}
	else
	{
		output_error();
	}
}
void subtract_A_and_B(int r1, int col1, int r2, int col2)
{
	if (r1 == r2 && col1 == col2)
	{
		for (int i = 0; i < r1; i++)
		{
			for (int j = 0; j < col1; j++)
			{
				resMatrix[i][j] = matrixA[i][j] - matrixB[i][j];
			}
		}
		output_matrix(resMatrix, r1, col1);
	}
	else
	{
		output_error();
	}
}
void multiply_A_and_B(int r1, int col1, int r2, int col2)
{
	if (col1 == r2)
	{
		int r_res = r1;
		int col_res = col2;
		for (int i = 0; i < r1; i++)
		{
			for (int j = 0; j < col2; j++)
			{
				long long sum = 0;
				for (int k = 0; k < r2; k++)
				{
					sum += matrixA[i][k] * matrixB[k][j];
				}
				resMatrix[i][j] = sum;
			}
		}
		output_matrix(resMatrix, r_res, col_res);
	}
	else
		output_error();
}


// for determinant calculations
int f_c = 0, s_c = 1;
bool cols[100]{ 0 };
long long determinant_2_by_2(int true_col, long long matrix[][100])
{
	f_c = 0, s_c = 1;
	bool first = 1;
	for (int i = 0; i < true_col; i++)
	{
		if (cols[i] == 0 && first)
		{
			f_c = i;
			first = 0;
		}
		else if (cols[i] == 0)
			s_c = i;
	}
	return (matrix[true_col - 2][f_c] * matrix[true_col - 1][s_c]
		- matrix[true_col - 2][s_c] * matrix[true_col - 1][f_c]);
}
long long determinant(long long matrix[][100], int true_col, int col, int idx)  // o(n!)
{
	if (col == 1)
		return matrix[0][0];

	if (col == 2)
	{
		return determinant_2_by_2(true_col, matrix);
	}

	long long sum = 0;
	int sign = 1;
	for (int j = 0; j < true_col; j++)
	{
		if (!cols[j])
		{
			cols[j] = 1; // m4 hna5do
			sum += sign * matrix[idx][j] * determinant(matrix, true_col, col - 1, idx + 1);
			cols[j] = 0;
			sign *= -1;
		}
	}
	return sum;
}
void calculate_determinant(long long matrix[][100], int r, int c) 
{
	if (r != c)
		output_error();
	else
		cout << determinant(matrix, r, r, 0) << endl;
}


// inverse matrix and divison
double inverse_B[100][100]{ 0 };
long long temp_matrix[100][100]{ 0 };
void temp(int r, int col, int n_r, int n_col)
{
	int r_index = 0, col_index = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i != n_r && j != n_col)
			{
				temp_matrix[r_index][col_index] = matrixB[i][j];
				col_index++;
			}
		}
		if (i != n_r)
			r_index++;

		col_index = 0;
	}
}
int power(int po)
{
	int x = 1;
	for (int i = 0; i < po; i++)
	{
		x *= -1;
	}
	return x;
}
void multiply_A_and_inverseB(int r1, int col1, int r2, int col2)
{
	for (int i = 0; i < r1; i++)
	{
		for (int j = 0; j < col2; j++)
		{
			double sum = 0;
			for (int k = 0; k < r2; k++)
			{
				sum += matrixA[i][k] * inverse_B[k][j];
			}
			cout << static_cast<long long>(round(sum)) << " ";
		}
		cout << endl;
	}
}
void divide_A_over_B(int r1, int col1, int r2, int col2)
{
	if (r2 != col2 || col1 != r2)
		output_error();
	else
	{
		long long determint = determinant(matrixB, r2, r2, 0);;
		if (determint == 0)
		{
			output_error();
			return;
		}
		double one_over_A = 1.0 / determint;
		if (r2 > 1)
		{
			for (int i = 0; i < r2; i++)
			{
				for (int j = 0; j < col2; j++)
				{
					temp(r2, col2, i, j);
					long long d = determinant(temp_matrix, r2 - 1, r2 - 1, 0);
					resMatrix[i][j] = power(i + j + 2) * d;
				}
			}
			for (int i = 0; i < r2; i++)
			{
				for (int j = 0; j < col2; j++)
				{
					if (j >= i)
						swap(resMatrix[i][j], resMatrix[j][i]);

					inverse_B[i][j] = resMatrix[i][j] * one_over_A;
				}
			}
		}
		else
			inverse_B[0][0] = 1.0 / matrixB[0][0];

		multiply_A_and_inverseB(r1, col1, r2, col2);
	}
}


int main()
{
	cout << "Please enter dimensions of Matrix A:\n";
	int r1, col1;
	cin >> r1 >> col1;


	cout << "Please enter dimensions of Matrix B:\n";
	int r2, col2;
	cin >> r2 >> col2;


	cout << "Please enter values of Matrix A:\n";
	input_matrix(matrixA, r1, col1);


	cout << "Please enter values of Matrix B:\n";
	input_matrix(matrixB, r2, col2);

	cout << "Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):\n";
	int choise; cin >> choise;
	while (choise != 7)
	{
		switch (choise)
		{
		case 1:
			add_A_and_B(r1, col1, r2, col2);
			break;
		case 2:
			subtract_A_and_B(r1, col1, r2, col2);
			break;
		case 3:
			multiply_A_and_B(r1, col1, r2, col2);
			break;
		case 4:
			divide_A_over_B(r1, col1, r2, col2);
			break;
		case 5:
			calculate_determinant(matrixA, r1, col1);
			break;
		case 6:
			calculate_determinant(matrixB, r2, col2);
			break;
		}
		cout << "Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):\n";
		cin >> choise;
	}
	cout << "Thank you!";
	return 0;
}
