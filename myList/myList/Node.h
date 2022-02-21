#pragma once
#include <iostream>
#include <string>

using namespace std;
struct Node {
	string dataStr = "";
	myList dataLst;
	Node* nextStr;
	Node* nextLst;
	Node(string temp) {
		dataStr = temp;
		nextStr = nullptr;
		nextLst = nullptr;
	}
	Node(myList temp) {
		dataLst = temp;
		nextLst = nullptr;
		nextStr = nullptr;
	}
};