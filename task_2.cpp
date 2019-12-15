using namespace std;
#include <iostream>
#include <fstream>
#include <list>
#include <string>


void printList(list<int>& l) {
	list<int>::iterator ptr = l.begin();
	for (ptr; ptr != l.end(); ptr++)
	{
		cout << (*ptr) << ' ';
	}
	cout << endl;
}


void  sortCocktailStyle(list<int>& l)
{
	
	bool swapped = true;
	list<int>::iterator beg = l.begin();
	list<int>::iterator end = l.end();
	while (swapped)
	{
		swapped = false;
		for (list<int>::iterator i = beg; i !=end; i++)
		{
			list<int>::iterator nextI = (++i);
			--i;
			if (nextI != end)
			{
				if ((*i) > (*nextI))
				{

					swap((*i), (*nextI));
					swapped = true;
				}
			}
			else
			{
				break;
			}
		}
		if (!swapped)
		{
			break;
		}
		swapped = false;
		end--;
		list<int>::iterator oneStepBehindEnd = (--end);
		++end;
		for (list<int>::iterator i = oneStepBehindEnd; i != beg; i--)
		{
			
			list<int>::iterator prevI = (--i);
			++i;
			if (prevI == beg)
			{
				if ((*prevI) > (*i))
				{
					swap((*prevI), (*i));
					swapped = true;
				}
				break;
			}
			if ((*prevI) > (*i))
			{
				swap((*prevI), (*i));
				swapped = true;
			}

		}
		if (!swapped)
		{
			break;
		}
		beg++;
	}

}


int main() {

	list<int>  l = {3,2,1};
	sortCocktailStyle(l);
	printList(l);


	//ifstream iFile("test.txt");
	//string line;
	//while (getline(iFile, line))
	//{
	//	list<int> l;
	//	int length = line.length();

	//	for(int i=0;i<length;i++)
	//	{
	//		string number;
	//		bool isNumber = false;
	//		while(line[i] >= '0' && line[i] <= '9')
	//		{
	//			number += line[i];
	//			i++;
	//			isNumber = true;
	//		}
	//		if (isNumber)
	//		{
	//			l.push_back(stoi(number));
	//		}
	//		else
	//		{
	//			continue;
	//		}
	//		number.clear();
	//	}
	//	sortCocktailStyle(l);
	//	printList(l);
	//	l.clear();
	//}
	//
	
	return 0;
}