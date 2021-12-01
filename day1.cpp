#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>
using namespace std;

bool int_vct_to_tuple_vct(vector< tuple<int, int> > &vct_tuple, vector<int> &in, int off)
{
	int s = in.size();
	tuple<int, int> my_tup;
	for (int i = 0; i != s - off; ++i)
	{
		my_tup = make_tuple(in[i], in[i + off]);
		vct_tuple.push_back(my_tup);
	}
	return true;
}

bool file_to_vector(vector<int> &in)
{
	string line;
	ifstream myfile ("input/day1.txt");
	if (myfile.is_open())
	{
		while ( getline(myfile, line) )
		{
			in.push_back(stoi(line));
		}
		myfile.close();
	}
	else
	{
		cout << "Unable to open file" << endl;
		return false;
	}
	return true;
}

void filter_vector(vector< tuple<int, int> > &vct, vector< tuple<int, int> > &filtered)
{
	for (auto i = vct.begin(); i != vct.end(); i++)
	{
		if ( get<0>(*i) < get<1>(*i) )
		{
			filtered.push_back(*i);
		}
	}
}

void solution(vector<int> in, int off)
{
	vector< tuple<int, int> > vct_tup;
	vector< tuple<int, int> > filtered_tup;
	int_vct_to_tuple_vct(vct_tup, in, off);
	filter_vector(vct_tup, filtered_tup);
	cout << "The solution to the problem is: " << filtered_tup.size() << endl;
}

int main () {
	vector<int> in;
	if (!file_to_vector(in))
	{
		cout << "Failed to open File." << endl;
		return -1;
	}
	cout << "Finding solutions" << endl;
	solution(in, 1);
	solution(in, 3);
	return 0;
}
