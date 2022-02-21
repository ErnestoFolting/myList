#include <iostream>
#include <string>

using namespace std;

struct myList;

struct Node {
	string dataStr = "";
	myList* dataLst;
	Node* nextStr;
	Node* nextLst;
	Node(string temp) {
		dataStr = temp;
		nextStr = nullptr;
		nextLst = nullptr;
	}
	Node(myList* temp) {
		dataLst = temp;
		nextLst = nullptr;
		nextStr = nullptr;
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
			while (temp->nextStr != nullptr || temp->nextLst != nullptr) {
				if (temp->nextLst != nullptr) temp = temp->nextLst;
				else {
					temp = temp->nextStr;
				}
			}
			temp->nextStr = newNode;
		}
	}
	void add(myList* newData) {
		Node* newNode = new Node(newData);
		if (head == nullptr) {
			head = newNode;
		}
		else {
			Node* temp = head;
			while (temp->nextStr != nullptr || temp->nextLst != nullptr) {
				if (temp->nextLst != nullptr) temp = temp->nextLst;
				else {
					temp = temp->nextStr;
				}
			}
			temp->nextLst = newNode;
		}
	}
	void print() {
		cout << "( ";
		Node* temp = head;
		while (temp != nullptr) {
			if (temp->dataStr != "") {
				cout << temp->dataStr << " ";
			}
			else {
				temp->dataLst->print();
			}
			if (temp->nextLst != nullptr) temp = temp->nextLst;
			else {
				temp = temp->nextStr;
			}
		}
		cout << " )";
	}
	myList(Node* temp) {
		head = temp;
	}
	myList car() {
		if (this->head != nullptr) {
			Node* tempNode;
			if (this->head->dataStr != "") {
				tempNode = new Node(this->head->dataStr);
			}
			else {
				tempNode = new Node(this->head->dataLst);
			}
			tempNode->nextLst = nullptr;
			tempNode->nextStr = nullptr;
			myList temp(tempNode);
			return temp;
		}
	}
	myList cdr() {
		if (this->head != nullptr) {
			if (this->head->nextLst != nullptr) {

				myList temp(this->head->nextLst);
				return temp;
			}
			else {
				myList temp(this->head->nextStr);
				return temp;
			}
			
		}
	}
};

int main()
{
	myList temp;
	temp.add("check");
	temp.add("check2");
	temp.add("check3");
	myList* temp2 = new myList;
	temp2->add("jack1");
	myList* temp3 = new myList;
	temp3->add("black1");
	temp3->add("black2");
	temp2->add(temp3);
	temp.add(temp2);
	temp.add("check4");
	cout << "My List: \n";
	temp.print();
	myList afterCar = temp.car();
	cout << endl;
	cout << "After .car() \n";
	afterCar.print(); //after .car()
	myList afterCdr = temp.cdr();
	cout << endl;
	cout << "After .cdr() \n";
	afterCdr.print();
}
