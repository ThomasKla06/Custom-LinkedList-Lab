#pragma once

//Thomas Klaesges
// Helper class - ListNode
template <typename T>
class ListNode {
	//FIELDS
private:
	T data;
	ListNode<T>* next;

	//CONSTRUCTOR
public:
	ListNode(T data, ListNode<T>* next) {
		this->data = data;
		this->next = next;
	}

	//METHODS (getters, setters)
	T getData() { return data; }

	ListNode<T>* getNext() { return next; }

	void setData(T d) { data = d; }

	void setNext(ListNode<T>* n) { next = n; }
};

template <typename T>
class LinkedList {
	//FIELDS
private:
	int size{ 0 };
	ListNode<T>* head{ nullptr };
	ListNode<T>* tail{ nullptr };

public:
	//CONSTRUCTOR, DESTRUCTOR, Rule of Three
	LinkedList() {
		//Intentionally left empty!
	}

	~LinkedList() {	// Total: 4N = O(N)
		while (size > 0) {				// N*
			//keep deleting!
			ListNode<T>* todel{ head };	// 1
			head = head->getNext();		// 1
			delete todel;				// 1
			size--;						// 1
		}
	}

	LinkedList(const LinkedList<T>& other) {
		ListNode<T>* current{ other.head };
		while (current != nullptr) {
			append(current->getData());
			current = current->getNext();
		}
	}

	LinkedList& operator=(const LinkedList<T>& other) {
		//Get rid of existing chain
		while (size > 0) {
			//keep deleting!
			ListNode<T>* todel{ head };
			head = head->getNext();
			delete todel;
			size--;
		}
		//Replace with the new chain
		ListNode<T>* current{ other.head };
		while (current != nullptr) {
			append(current->getData());
			current = current->getNext();
		}
		return *this;
	}

	//METHODS

	//add methods

	//prepend - add at the beginning of the chain
	void prepend(T item) {
		//1. Build a listnode
		ListNode<T>* newNode = new ListNode<T>{ item,head };

		//2. Update head pointer
		head = newNode;

		//2.5 If chainis empty set the tail pointer
		if (size == 0) {
			tail = newNode;
		}

		//3. Increase size
		size++;
	}

	//append - add at the end of the chain
	void append(T item) {
		//1. Build a listnode
		ListNode<T>* newNode = new ListNode<T>{ item,nullptr };

		//2. Attach the new node onto the chain
		if (size == 0) {
			head = newNode;
			tail = newNode;
		}
		else {

			//Instead of traversal, use tail pointer to skip ahead
			tail->setNext(newNode);
			tail = tail->getNext();
			//ListNode<T>* current{ head };
			//for (int i = 0; i < size - 1; i++) {
			//	current = current->getNext(); //advance one step!
			//}
			//current->setNext(newNode);
		}
		//3. Increase the size
		size++;
	}

	//get
	T get(int index) {
		ListNode<T>* current{ head };
		//traverse!
		for (int i = 0; i < index; i++) {
			current = current->getNext();
		}
		return current->getData();

	}

	//set
	void set(int index, T value) { // Total: N+1 = O(N)
		ListNode<T>* current{ head };		// 1
		//traverse!
		for (int i = 0; i < index; i++) {	// (N-1)*
			current = current->getNext();	// 1
		}
		current->setData(value);			// 1
	}

	//getSize
	int getSize() {		//Total: 1 = O(1)
		return size;	// 1
	}

	//NEW METHODS
	void insert(int index, T value) {
		ListNode<T>* newNode = new ListNode<T>{ value,nullptr };
		if (index == 0 && size == 0) {
			head = newNode;
			tail = newNode;
			size++;
		}
		else if (index == 0 && size > 0) {
			//If inserting at the start but list is not empty
			newNode->setNext(head);
			head = newNode;
			size++;
		}
		else if (index == size - 1) {
			//If inserting at the end
			tail->setNext(newNode);
			tail = tail->getNext();
			size++;
		}
		else {
			//Traverse to the item before index
			ListNode<T>* current{ head };
			for (int i = 0; i < index - 1; i++) {
				current = current->getNext();
			}
			newNode->setNext(current->getNext());
			current->setNext(newNode);
			size++;
		}
	}

	T remove(int index) {
		ListNode<T>* current{ head };
		T temp;

		if (index == 0) {
			head = current->getNext();
			temp = current->getData();
			delete current;
			size--;
			return temp;
		}
		else {
			ListNode<T>* tempNode;
			for (int i = 0; i < index - 1; i++) {
				current = current->getNext();
			}
			tempNode = current;

			current = current->getNext();
			temp = current->getData();
			tempNode->setNext(current->getNext());
			delete current;
			size--;
			return temp;
		}
	}

	void removeAll(T value) {
		ListNode<T>* current{ head };
		ListNode<T>* temp{ head };
		for (int i = 0; i < size - 1; i++) {
			if (i == 0) {
				if (current->getData() == value) {
					head = current->getNext();
					temp = current;
					if (size > 0) {
						current = current->getNext();
					}
					delete temp;
					size--;
				}
				else {
					current = current->getNext();
				}
			}
			else if(i == size - 2) {
				if (current->getNext()->getData() == value) {
					current = current->getNext();
					delete current;
					size--;
				}
			}
			else {
				if (current->getNext()->getData() == value) {
					temp = current->getNext();
					current->setNext(temp->getNext());
					delete temp;
					size--;
				}
				else {
					current = current->getNext();
				}
			}
		}
	}

};
