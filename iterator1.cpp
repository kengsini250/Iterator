#include <iostream>

using namespace std;

namespace Test
{
#define MAX 10

	class Iterator
	{
	public:
		int* index = nullptr;

		Iterator(int* arr)
		{
			index = arr;
		}


		int operator*()const
		{
			return *index;
		}

		Iterator& operator++(int)
		{
			++index;
			return *this;
		}

		bool operator!=(const Iterator&right)const
		{
			return index != right.index;
		}

		Iterator& operator-(int)
		{
			--index;
			return *this;
		}
	};


	class List
	{
	public:
		using Type = int;

	private:
		Type arr[MAX] = {0};
	public:
		List() 
		{
			for (int i = 0; i < MAX; i++) {
				arr[i] = i;
			}
		}

		Iterator begin()
		{
			return Iterator(arr);
		}

		Iterator end()
		{
			return Iterator(&arr[MAX]);
		}

	};

}

int main()
{
	Test::List list;
	Test::Iterator p = list.begin();
	cout << *p << endl;
	p++;
	cout << *p << endl;
	p = list.end();
	cout << *(p-1) << endl;

	for (auto p = list.begin(); p != list.end(); p++) {
		cout << *p << endl;
	}
}

