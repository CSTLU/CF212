#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	vector<int> V;
	int value;
	int sum = 0;
	while(true)
	{
		cin>> value;
		if (value < 0)
		{
			break;
		}
		V.push_back(value);
	}

	for (int i = 0; i < V.size(); ++i)
	{
		sum += V[i];
	}
	cout<<"Sum: "<<sum<<endl;
	vector<int > indexV;
	for (int i = 0; i < V.size(); ++i)
	{
		if (V[i]%2 == 0)
		{
			indexV.push_back(i);
		}
	}
	for (int i = 0; i < V.size() - 1; ++i)
	{
		for (int j = i + 1; j < V.size(); ++j)
		{
			if (V[i] > V[j])
			{
				V[i] -= V[j];
				V[j] += V[i];
				V[i] = V[j] - V[i]; 
			}
		}
	}
	return 0;
}