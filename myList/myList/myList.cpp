#include <iostream>
#include <string>

using namespace std;

struct Node {
	string data;
	Node* next;
	Node(string temp) {
		data = temp;
		next = nullptr;
	}
};

struct myList {
	Node* head = nullptr;
	myList() {};
	void add(string newData) {
		Node* newNode = new Node(newData);
		if (head == nullptr) {
			head = newNode;
		}
		else {
			Node* temp = head;
			while (temp->next != nullptr) {
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}
	void print() {
		Node* temp = head;
		while (temp != nullptr) {
			cout << temp->data << endl;
			temp = temp->next;
		}
	}
	void add(myList) {

	}
};

int main()
{
	myList temp;
	temp.add("check");
	temp.add("check2");
	temp.add("check3");
	temp.add("check4");
	temp.print();
}
