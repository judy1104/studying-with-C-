#include "pch.h"
#include <iostream>
using namespace std; 

#define	NUM_DATA	4
#define	NUM_WEIGHT	3

double dot(double *v1, double *v2, int nlen)
{
	double sum = 0; 
	for (int i = 0; i < nlen; ++i)
	{
		sum += v1[i] * v2[i];
	}
	return sum;
}

double sigmoid(double v)
{
	return v > 0 ? 1 : 0;
}

double forward(double *x, double *w, int len)
{
	double value = dot(x, w, len);

	return sigmoid(value);
}

void train(double *w, double *x, double t, double e, int len)
{
	double z = forward(x, w, len);
	for (int i = 0; i < len; ++i)
	{
		w[i] += (t - z)*x[i] * e;
	}
}

int main()
{
	double rate = 0.1;

	double input[NUM_DATA][NUM_WEIGHT] = { {1,0,0},{1,0,1},{1,0,1},{1,1,1} };
	double mul[NUM_DATA] = { 0,0,0,1 };
	//double sum[NUM_DATA] = { 0,1,1,1 };
	double w[NUM_WEIGHT] = { 0,0,0 };

	int epoch = 10; 
	for (int i = 0; i < epoch; ++i)
	{
		cout << "epoch:" << i << "\t";
		for (int j = 0; j < NUM_DATA; ++j)
		{
			train(w, input[j], mul[j], rate, NUM_WEIGHT);
		}
		for (int j = 0; j < NUM_WEIGHT; ++j)
		{
			cout << "w" << j << ":" << w[j] << "\t";
		}
		cout << endl; 
	}

	for (int i = 0; i < NUM_DATA; ++i)
	{
		cout << forward(input[i], w, NUM_WEIGHT) << " ";
	}
	cout << endl; 
}
