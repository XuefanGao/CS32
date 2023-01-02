/*
#include <string>
using namespace std;
int main(){
	struct Node
	{
		int val;
		Node* next;
	};

	class LinkedList
	{
	public:
		void swapFirstTwo() {
			if (m_head != nullptr && m_head->next != nullptr) {
				int temp = m_head->val;
				int t = m_head->next->val;
				m_head->val = t;
				m_head->next->val = temp;
			}
	   }
	 
	private:
		Node* m_head;
	};


	class Stomach
	{
	public:
		Stomach(string items[], int n)
		{
			count = n;

			if (n <= 3)  // if <= 3 items then use array
			{
				for (int i = 0; i < n; i++)
					contents[i] = items[i];
			}
			else          // otherwise use new to alloc array
			{
				moreThanThree = new string[n];
				for (int i = 0; i < n; i++)
					moreThanThree[i] = items[i];
			}
		}
		Stomach(const Stomach& src) {
			count = src.count;
			if (count <= 3) {
				for (int i = 0; i < count; i++)
					contents[i] = src.contents[i];
			}
			else {
				moreThanThree = new string[count];
				for (int i = 0; i < count; i++)
					moreThanThree[i] = src.contents[i];
			}
		}

		Stomach& operator=(const Stomach& src){
			// destructor part
			if (&src == this)
				return *this;
			if (count <=  3) {
				delete contents;
			}
			else {
				delete [] moreThanThree;
			}
			// copy constructor part
			count = src.count;
			if (count <= 3) {
				for (int i = 0; i < count; i++)
					contents[i] = src.contents[i];
			}
			else {
				moreThanThree = new string[count];
				for (int i = 0; i < count; i++)
					moreThanThree[i] = src.contents[i];
			}
			return *this;
		}

		~Stomach()
		{
			if (count > 3)
				delete[] moreThanThree;
		}

	private:

		string contents[3];
		string* moreThanThree;
		int count;
	};



	// practice midterm
	#include <iostream>
	using namespace std;
	class LinkedList
	{
	public:
		LinkedList() : head(nullptr) { }
		~LinkedList();
		void addToList(int value); // add to the end of the linked list
		void reverse(); // Reverse the linked list
		void output();
	private:
		struct Node
		{
			int num;
			Node* next;
		};
		Node* head;
	};
	void LinkedList::output()
	{
		Node* ptr = head;
		cout << "The elements in the list are: ";
		while (ptr != nullptr) {
			cout << ptr->num << " ";
			ptr = ptr->next;
		}
		cout << endl;
	}

	~LinkedList() {
		Node* temp;
		while (head != nullptr) {
			temp = head;
			delete temp;
			head = head->next;
		}
	}

	addToList(int value) {
		Node* p = new Node;
		p->num = value;
		p->next = nullptr;
		Node* temp = head;
		if (temp == nullptr) {
			head = p;
			return;
		}
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = p;
	}

	void LinkedList::reverse()
	{
		Node* nextNode = nullptr, * prevNode = nullptr, * current = head;
		while (current) {
			// Hint: Only 4 lines of codes are needed inside the while loop
			nextNode = current->next;
			current->next = prevNode;
			prevNode = current;
			current = nextNode;
		}
		head = prevNode;
	}



	return 0;
}
*/