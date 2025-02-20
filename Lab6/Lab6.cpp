#include <iostream>
#include "CustomLinkedList.h"
using namespace std;

/*
* Author: Alexi Brooks
* Changelog:
* 28.Feb.2024 Created
*/

template <typename T>
void print(T* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i];
	}
}

//Use append, insert in the middle, get to verify
void test1() {
	char initial[] = { 'r','a','d','i','a','l' };
	char expected[] = { 'r','a','d','i','c','a','l'};
	LinkedList<char> word;
	for (int i = 0; i < 6; i++) {
		word.append(initial[i]);
	}
	word.insert(4, 'c');
	char actual[7];
	try {
		bool correct{ true };
		for (int i = 0; i < 7; i++) {
			actual[i] = word.get(i);
			if (actual[i] != expected[i]) {
				correct = false;
			}
		}
		if (correct) {
			if (word.getSize() != 7) {
				cout << "Test 1: FAIL. Check size!" << endl;
				return;
			}
			cout << "Test 1: PASS" << endl;
		}
		else {
			cout << "Test 1: FAIL.\n\tExpected: ";
			print(expected, 7);
			cout << "\n\tActual: ";
			print(actual, 7);
			cout << endl;
		}
	}
	catch (...) {
		cout << "Test 1: FAIL.\n\tRuntime error." << endl;
	}
}

//Use append, insert at the head, get to verify
void test2() {
	char initial[] = { 'r','e','s','i','d','e','n','t' };
	char expected[] = { 'p','r','e','s','i','d','e','n','t' };
	LinkedList<char> word;
	for (int i = 0; i < 8; i++) {
		word.append(initial[i]);
	}
	word.insert(0, 'p');

	char actual[9];
	try {
		bool correct{ true };
		for (int i = 0; i < 9; i++) {
			actual[i] = word.get(i);
			if (actual[i] != expected[i]) {
				correct = false;
			}
		}
		if (correct) {
			if (word.getSize() != 9) {
				cout << "Test 2: FAIL. Check size!" << endl;
				return;
			}
			cout << "Test 2: PASS" << endl;
		}
		else {
			cout << "Test 2: FAIL.\n\tExpected: ";
			print(expected, 9);
			cout << "\n\tActual: ";
			print(actual, 9);
			cout << endl;
		}
	}
	catch (...) {
		cout << "Test 2: FAIL.\n\tRuntime error." << endl;
	}
}

//Use append, remove from the middle, get to verify
void test3() {
	char initial[] = { 'a','m','b','l','e' };
	char expected[] = { 'a','b','l','e' };
	LinkedList<char> word;
	for (int i = 0; i < 5; i++) {
		word.append(initial[i]);
	}
	char ans{ word.remove(1) };
	if (ans != 'm') {
		cout << "Test 3: FAIL\n\t\Expected: m";
		cout << "\n\tActual: " << ans << endl;
	}

	char actual[4];
	try {
		bool correct{ true };
		for (int i = 0; i < 4; i++) {
			actual[i] = word.get(i);
			if (actual[i] != expected[i]) {
				correct = false;
			}
		}
		if (correct) {
			if (word.getSize() != 4) {
				cout << "Test 3: FAIL. Check size!" << endl;
				return;
			}
			cout << "Test 3: PASS" << endl;
		}
		else {
			cout << "Test 3: FAIL.\n\tExpected: ";
			print(expected, 4);
			cout << "\n\tActual: ";
			print(actual, 4);
			cout << endl;
		}
	}
	catch (...) {
		cout << "Test 3: FAIL.\n\tRuntime error." << endl;
	}
}

//Use append, remove from the head, get to verify
void test4() {
	char initial[] = { 't','a','b','l','e' };
	char expected[] = { 'a','b','l','e' };
	LinkedList<char> word;
	for (int i = 0; i < 5; i++) {
		word.append(initial[i]);
	}
	char ans{ word.remove(0) };
	if (ans != 't') {
		cout << "Test 4: FAIL\n\t\Expected: t";
		cout << "\n\tActual: " << ans << endl;
	}

	char actual[4];
	try {
		bool correct{ true };
		for (int i = 0; i < 4; i++) {
			actual[i] = word.get(i);
			if (actual[i] != expected[i]) {
				correct = false;
			}
		}
		if (correct) {
			if (word.getSize() != 4) {
				cout << "Test 4: FAIL. Check size!" << endl;
				return;
			}
			cout << "Test 4: PASS" << endl;
		}
		else {
			cout << "Test 4: FAIL.\n\tExpected: ";
			print(expected, 4);
			cout << "\n\tActual: ";
			print(actual, 4);
			cout << endl;
		}
	}
	catch (...) {
		cout << "Test 4: FAIL.\n\tRuntime error." << endl;
	}
}

//Use append, remove repeating letters, get to verify
void test5() {
	char initial[] = { 'm','i','s','s','i','s','s','i','p','p','i'};
	char expected[] = { 'm','i','i','i','p','p','i' };
	LinkedList<char> word;
	for (int i = 0; i < 11; i++) {
		word.append(initial[i]);
	}
	word.removeAll('s');

	char actual[7];
	try {
		bool correct{ true };
		for (int i = 0; i < 7; i++) {
			actual[i] = word.get(i);
			if (actual[i] != expected[i]) {
				correct = false;
			}
		}
		if (correct) {
			if (word.getSize() != 7) {
				cout << "Test 5: FAIL. Check size!" << endl;
				return;
			}
			cout << "Test 5: PASS" << endl;
		}
		else {
			cout << "Test 5: FAIL.\n\tExpected: ";
			print(expected, 7);
			cout << "\n\tActual: ";
			print(actual, 7);
			cout << endl;
		}
	}
	catch (...) {
		cout << "Test 5: FAIL.\n\tRuntime error." << endl;
	}
}

//Run all tests
int main() {
	test1();
	test2();
	test3();
	test4();
	test5();
	return 0;
}