#include <iostream>

using namespace std;

namespace Test
{

	template<class Type>
	class Iterator
	{
	public:
		Type* index = nullptr;

		Iterator(Type* arr)
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


	template<class Type , int MAX>
	class List
	{
	public:
		using iterator = Iterator<Type>;

	private:
		Type arr[MAX] = {0};
	public:
		List() 
		{
		}

		void set(int index, Type t) {
			arr[index] = t;
		}

		Iterator<Type> begin()
		{
			return Iterator<Type>(arr);
		}

		Iterator<Type> end()
		{
			return Iterator<Type>(&arr[MAX]);
		}

	};

}

int main()
{
	Test::List<char,10> list;
	for (int i = 0; i < 10; i++) {
		list.set(i, i + 65);
	}

	Test::List<char, 10>::iterator p = list.begin();
	for (; p != list.end(); p++) {
		printf("%c\n", *p);
	}
}

