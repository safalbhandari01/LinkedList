#ifndef NODE_H_
#define NODE_H_

#include <iostream>
#include <cstdlib>

template<class T>
class Node
{
	/* no other member variables should be used */
private:
	T data;
	Node<T>* next;
	Node<T>* prev;

public:
	//default constructor
	

	/* Constructor needs a body */
	//template<class T>
	Node(T data, Node<T>* next = NULL, Node<T>* prev = NULL) {
		this->data = data;
	  
	}

	/* getters/setters for this->data */
	//template<class T>
	T get_data() {
		return data; 
	}
	void set_data(T data) {
		this->data = data;
	}

	/* getters/setters for this->next */
	//template<class T>
	Node<T>* get_next() {
		return next;
	}
	void set_next(Node<T>* next) {
		this->next = next;
	}

	/* getters/setters for this->prev */
	//template<class T>
	Node<T>* get_prev() {
		return prev;
	}
	void set_prev(Node<T>* prev) {
		this->prev = prev;
	}

	/* display the pointer addresses */
	//template<class T>
	void display_links() {
		std::cout << "Links:"
			<< "\n\tnext = " << this->next
			<< "\n\tprev = " << this->prev
			<< std::endl;
	}

	/* display all node information */
	//template<class T>
	void print_node() {
		std::cout << "Data :" << this->data<<"\n";
		std::cout << "Next node: " <<this-> next<<"\n";
		std::cout << "Previous node: " << this->prev << "\n";
	}
};

#endif

