#include <iostream>

using namespace std;

class myArray
{
public:
	myArray(int sz)
	{
		numElts = sz;
		elts = new int[sz];
	}

	void setValue(int pos, int value)
	{
		elts[pos] = value;
	}

	int getValue(int pos) const
	{
		return elts[pos];
	}

	int& at(int pos)
	{
		return elts[pos];
	}

	void push_back(int value)
	{
		int* tmpElts = new int[numElts + 1];

		for (int i = 0; i < numElts; i++)
		{
			tmpElts[i] = elts[i];
		}
		tmpElts[numElts] = value;

		delete[] elts;

		elts = tmpElts;
		numElts++;
	}

	myArray& operator=(const myArray& rhs)
	{
		if (this != &rhs)
		{
			delete[] elts;

			numElts = rhs.numElts;
			elts = new int[numElts];
			for (int i = 0; i < numElts; i++)
			{
				elts[i] = rhs.elts[i];
			}
		}

		return *this;
	}

private:
	int numElts;
	int* elts;
};

int main()
{
	myArray a(5);

	//a.setValue(0, 10);
	//a.setValue(1, 20);
	a.at(0) = 10;
	a.at(1) = 20;

	//cout << a.getValue(0) << endl;
	//cout << a.getValue(1) << endl;
	cout << a.at(0) << endl;
	cout << a.at(1) << endl;

	a.push_back(100);
	cout << a.at(5) << endl;

	myArray b(10);

	a = b;

	return 0;

}