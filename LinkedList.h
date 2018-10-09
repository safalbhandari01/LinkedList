#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include "Node.h"

template<class T>
class LinkedList {
	
private:
	Node<T>* head;
	Node<T>* tail;

	int type;
	int size;

	bool is_circularly;

public:
	LinkedList();// : head(NULL), tail(NULL), type(0), size(0), is_circularly(false) {};
	LinkedList(Node<T>* head, Node<T>* tail, int type, bool is_circularly);
	int get_size();
	
	void append(T data);
	void prepend(T data);
	void add_at_i(T data, int i);
	void remove_at_i(int i);
	void change_type(int type);
	void delete_list();
	void rotate(int r);
	void reverse();
	void random_shuffle();
	void display_i(int i);
	void display_all();
	void display_range(int i = 0, int j = 0);
	void display_links();
	void info();
	void swapNodes(int i, int j);
};

/* Default Constructor */
template<class T>
LinkedList<T>::LinkedList() : head(NULL), tail(NULL), type(0), size(0), is_circularly(false) {}


/* Overloading Constructor */
template<class T>
LinkedList<T>::LinkedList(Node<T>* head, Node<T>* tail, int type, bool is_circularly) {
	this->head = head;
	this->tail = tail;
	this->type = type;
	this->is_circularly = is_circularly;

	Node<T>* c = head;
	if (type == 3 || type == 4)
		tail->set_next(NULL);
	while (c != NULL)
	{
		
		c = c->get_next();
		this->size = size++;
	}
	if (type == 3 || type == 4)
		tail->set_next(head);
	
}

/* getter for size */
template<class T>
int LinkedList<T>::get_size() {
	return size;
}


/* add to the end of the list */
template<class T>
void LinkedList<T>::append(T data) {
	Node<T>* temp = new Node<T>(data);
	if (size == 0) {
		head = temp;
		tail = temp;
		if (type == 2 || type == 4) {
			temp->set_prev(tail);
		}
		tail->set_next(temp);
		if (type == 3 || type == 4) {
			tail->set_next(head);
		}
		else {
			tail->set_next(NULL);
		}
	}
	else
	{
		
		if (type == 2 || type == 4) {
			temp->set_prev(tail);
		}
		tail->set_next(temp);
		if (type == 3 || type == 4) {
			temp->set_next(head);
		}
		else
		{
			temp->set_next(NULL);
		}

		tail = temp;
	}

	size++;
}

/* add to the front of the list */
template<class T>
void LinkedList<T>::prepend(T data) {
	Node<T>* temp;
	temp = new Node<T>(data);
	if (size == 0)
	{
		head = temp;
		tail = temp;
			if (type == 2 || type == 4)
			{
			temp->set_prev(tail);
			}
		tail->set_next(temp);
			if (type == 3 || type == 4)
			{
			tail->set_next(head);
			}
			else 
			{
			tail->set_next(NULL);
			}
	}
		else
	{
			if (type == 2 || type == 4)
			{    
				
				head->set_prev(temp);
			}
			temp->set_next(head);
			if (type == 3 || type == 4)
			{
				tail->set_next(temp);
			}
			if (type == 4)
			{
				temp->set_prev(tail);
			}
			
	}

	head = temp;
	
	size = size + 1;
	
}

/* add so the new node is the ith node */
template<class T>
void LinkedList<T>::add_at_i(T data, int i) {
	std::cout << size << "\n";
	if (i == size) {
		append(data);
		
		return;
	}
	if (size == 0 && i == 1) {
		append(data);
		
		return;
	}
	Node<T>* temp;
	temp = new Node<T>(data);
	if (i == 1) {
		temp->set_next(head);
		
		if (type == 2 || type == 4)
		{

			head->set_prev(temp);
		}
		
		if (type == 3 || type == 4)
		{
			tail->set_next(temp);
		}
		if (type == 4)
		{
			temp->set_prev(tail);
		}
		head = temp;
		size++;
		return;
	}
	if (i > 1 && i < size) {
		Node<T>* temp2 = head;
		for (int j = 0; j < i - 2; j++) {
			temp2 = temp2->get_next();
		}
		temp->set_next(temp2->get_next());
		temp2->set_next(temp);
		if (type == 2 || type == 4)
		{
			temp->set_prev(temp2);
			temp->get_next()->set_prev(temp);
		}
		size++;
		return;
	}

	std::cout << "Please enter valid index\n";


}

/* remove the ith node from the list */
template<class T>
void LinkedList<T>::remove_at_i(int i) {
	Node<T>* temp = head;
	
	if (i == 1) {
		head = temp->get_next();
		delete temp;
	}
	else {
		for (int j = 1; j < i - 1; j++)
			temp = temp->get_next();

		Node<T>* temp2 = temp->get_next()->get_next();
		delete temp->get_next();
		temp->set_next(temp2);
		if (type == 2 || type == 4)
			temp2->set_prev(temp);
	}
	size--;
}

/* update the type of the array along with all the links
and members of the list */
template<class T>
void  LinkedList<T>::change_type(int type){
	
	if (size != 0) {
		int count = size;
		Node<T>* temp = head;
		T* array = new T[count];

		for (int i = 0; i < count; i++) {					 //storing list in dynamic array
			array[i] = temp->get_data();
			temp = temp->get_next();
		}
		delete_list();										 //deleting the current list

		this->type = type;									 //changing to desired type
		if (this->type == 3 || this->type == 4) {
			this->is_circularly = true;
		}
		else {
			this->is_circularly = false;
		}

		for (int i = 0; i < count; i++) {

			append(array[i]);
		}


		delete[] array;

	}
	else {
		this->type = type;
	}

	

}

/* remove all the elements in the list */
template<class T>
void LinkedList<T>::delete_list() {
	
	Node<T>* temp = head;
	Node<T>* temp2;

	if (type == 3 || type == 4)
		tail->set_next(NULL);
	do
	{
		temp2 = temp->get_next();
		delete temp;
		temp = temp2;
		size--;

	} while (temp != NULL);
	
}

/* rotate the nodes in the list r spots.
if r < 0 rotate left
if r > 0 rotate right
*/
template<class T>
void LinkedList<T>::rotate(int r) {
	if (r == 0|| abs(r)==size) {
		return;
	}
	Node<T>* temp = head;
	int* array = new int[size];
	tail->set_next(head);
	head->set_prev(tail);

	for (int i = 0; i < size; i++) {
		array[i] = temp->get_data();
		temp = temp->get_next();
	}
	int k = r;
	k = abs(k) + 1;
	

	//if ( r <=size) {
		temp = head;
		if (r > 0) {
			for (int j = 1; j < k; j++)
			{
				temp = temp->get_next();
			}
		}
		if (r < 0) {
			if (abs(r) > size) {
				r = r % size;
			}
			for (int j = 1; j <=size + r; j++)
				temp = temp->get_next();
			
		}
	
	for (int i = 0; i < size; i++) {
		temp->set_data(array[i]);
		temp = temp->get_next();
	}
	

       if (type == 0 || type == 2) {
		tail->set_next(NULL);
		}
	delete[] array;

}

/* reverse the order of the list */
template<class T>
void LinkedList<T>::reverse() {
	Node<T>* current, *previous, *nextNode;
	current = head;
	previous = NULL;
	nextNode = NULL;
	if (type == 3 || type == 4)
		tail->set_next(NULL);
	tail = head;
	while (current != NULL) {
		nextNode = current->get_next();
		current->set_next(previous);
		if (type == 2 || type == 4)
			current->set_prev(nextNode);
		previous = current;
		current = nextNode;
	}
	head = previous;
	if (type == 3 || type == 4) {
		tail->set_next(head);
		if (type == 4)
			head->set_prev(tail);
	}

}

/* put the list in a random order */
template<class T>
void LinkedList<T>::random_shuffle() {

	//<------------------------------------------------>
	
		
	// We'll randomly shuffle by swapping nodes randomly
	if (type == 3 || type == 4)
		tail->set_next(NULL);
		head->set_prev(NULL);

	int i_rand; // random number for i
	int j_rand; // random number for j

	for (int i = 0; i < this->size; i++)
	{
		i_rand = (rand() % this->size) + 1;
		j_rand = (rand() % this->size) + 1;
		swapNodes(i_rand, j_rand);
	}

	Node<T>* temp = head;
	for (int i = 1; i < size; i++)
		temp = temp->get_next();

	this->tail = temp;

	if (type == 3 || type == 4)
		tail->set_next(head);
		head->set_prev(tail);

	return;

	


}

/* display the node iformation of the ith node */
template<class T>
void LinkedList<T>::display_i(int i) {
	Node<T>* temp = head;
	if (i == 1) {
		std::cout << "Data: " << temp->get_data() << "\n";
		std::cout << "Address of next Node: " << temp->get_next() << "\n";
		std::cout << "Address of prev Node: " << temp->get_prev() << "\n";
			
	}
	else {
		for (int j = 0; j < i - 2; j++) {
			temp = temp->get_next();                                   //temp points to n-1 th node
		}
		Node<T>* temp2 = temp->get_next();                             //nth node
		std::cout << "Data: " << temp2->get_data() << " \n";
		std::cout << "Address of next Node: " << temp2->get_next() << " \n";
		std::cout << "Address of prev Node: " << temp2->get_prev() << " \n";
	}
}

//* Print the data from all the nodes - again a freebie */
template<class T>
void LinkedList<T>::display_all()
{
	std::cout << "List: ";

	if (this->head == NULL)
	{
		std::cout << "EMPTY LIST\n";
		return;
	}

	Node<T>* c = this->head;
	if (type == 3 || type == 4)
		tail->set_next(NULL);
	while (c != NULL)
	{
		std::cout << c->get_data() << " ";
		c = c->get_next();
	}
	if (type == 3 || type == 4)
		tail->set_next(head);
	std::cout << std::endl;
}

//* print node information for all nodes in the given range
//if one of the range values are not given use the following
//if no start: start at node 0


template<class T>
void LinkedList<T>::display_range(int i, int j)                                        
{
	Node<T>* temp = head;
	Node<T>* temp1 = head;
	Node<T>* temp2;

	if (j > i)
	{
		std::cout << "Error: j cannot be larger than i\n";
		return;
	}
	if (i == j) {
		display_i(i);
		return;
	}

	if (j == 1) {
		temp2 = head;
	}
	else
	{
		for (int k = 0; k < j - 2; k++) {
			temp = temp->get_next();
		}
		temp2 = temp->get_next();                   
	}
	for (int l = 0; l < i - 2; l++) {
		temp1 = temp1->get_next();
	}
	Node<T>* temp3 = temp1->get_next();					

	std::cout << "List: ";
	while (temp2->get_data() != temp3->get_data()) {
		std::cout << temp2->get_data() << "\n";
		temp2 = temp2->get_next();

	}
	std::cout << temp3->get_data();
}

/* display the head/tail addresses  */
template<class T>
void LinkedList<T>::display_links()
{
	std::cout << "Links:"
		<< "\n\thead = " << this->head
		<< "\n\ttail = " << this->tail
		<< std::endl;
}

/* display all list information -  */
template<class T>
void LinkedList<T>::info()
{
	if (type == 3) {
		std::cout << "Type: " << "Singly-circularly linked-list\n";
	}
	else {
		std::string t = (this->type) ? "Doubly" : "Singly";
		t += (is_circularly) ? "-circularly " : " ";
		std::cout << "Type: " << t << "linked-list\n";
	}
	std::cout << "Size: " << this->size << std::endl;
	this->display_links();
	
}

template<class T>
void LinkedList<T>::swapNodes(int i, int j)
{

	// If i and j are same, do nothing
	if (i == j)
		return;

	// Search for i keeping track of previous i and current i
	Node <T>* prevI = NULL;
	Node <T>* currI = this->head;

	int count = 1;

	while (count < i)
	{
		prevI = currI;
		currI = currI->get_next();
		count++;
	}

	// Search for j keeping track of previous j and current j
	Node<T>* prevJ = NULL;
	Node<T>* currJ = this->head;
	 count = 1;

	while (count < j)
	{
		prevJ = currJ;
		currJ = currJ->get_next();
		count++;
	}

	// If i and j are not in the linked list
	if (currI == NULL || currJ == NULL)
	{
		cout << "Node Not present in list" << endl;
		return;
	}

	// If i node is not the head of the linked list
	if (prevI != NULL)
	{
		prevI->set_next(currJ);
	}
	else
	{
		this->head = currJ;
	}

	// If j is not head of linked list
	if (prevJ != NULL)
	{
		prevJ->set_next(currI);
	}
	else
	{
		this->head = currI;
	}

	// Swap next pointers
	Node<T>* temp = currJ->get_next();
	currJ->set_next(currI->get_next());
	currI->set_next(temp);

	return;
}

#endif
