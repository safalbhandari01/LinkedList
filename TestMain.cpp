#include<iostream>
#include<string>
#include<iomanip>
#include<ctime>
#include "LinkedList.h"

using namespace std;
typedef int LLTYPE;
int printMenu();

int main() {

	//Variable Declaration
	int choice;
	int data;
	size_t i;
	int rotateSpot;
	size_t j;
	int listType;
	bool is_circularly;

    //creating an object for each types 
	LinkedList<int> sl;																			//singly linked list
	LinkedList<int> SCL;																		//Singly Circular linked list				
	LinkedList<int> DL;																			//Doubly linked list
	LinkedList<int> DCL;																		//Doubly Circular linked list

	//assigning the types to created object linked lists						
	SCL.change_type(3);
	DL.change_type(2);
	DCL.change_type(4);


	int randomInteger;
	srand(time(NULL));		//initializing random seed


	

	//creating different desired lists with same 10 integers on all different linked lists
	for (int i = 0; i < 10; i++) {

		randomInteger = rand() % 10;
		sl.append(randomInteger);
		SCL.append(randomInteger);
		DL.append(randomInteger);
		DCL.append(randomInteger);
	
	}


	//Operations options for linked lists
	do
	{
		choice = printMenu();
		switch (choice)
		{
		case 1: cout << "Proceeding to append a node \n";	
			cout << "Please enter the value you want to add\n";
			cin >> data;
			sl.append(data);
			
			break;
		case 2:cout << "Proceeding to prepend a node \n";
			cout << "Please enter the value you want to add\n";
			cin >> data;
			sl.prepend(data);
			
			break;
		case 3:cout << "Proceeding to add a node in ith position \n";
			cout << "Please enter the value you want to add\n";
			cin >> data;
			cout << "Please enter the position you want to add in \n";
			cin >> i;
			sl.add_at_i(data,i);
			
			break;
		case 4:cout << "Proceeding to remove a node in ith position\n";
			cout << "Please enter the position you want to delete from\n";
			cin >> i;
			sl.remove_at_i(i);
			
			break;
		case 5:cout << "Proceeding to change the type of the linked list\n";
			cout << "What type do you want the linked list to be changed into\n";
			cout << "0. Singly Linked List\n";
			cout << "2. Doubly Linked List\n ";
			cout << "3. Singly Circular Linked List\n";
			cout << "4.Doubly Circular Linked List\n";
			cin >> listType;
			sl.change_type(listType);
			break;
		case 6:cout << "Proceeding to delete all elements in the list\n";
			sl.delete_list();
			break;
		case 7:
			//rotate singly non circle list																
			cout << "Proceeding to rotate the list r spots\n";
			cout << "Please enter the number of spots you want to rotate in singly noncircular linked list\n";
			cin >> rotateSpot;
			sl.rotate(rotateSpot);
			int ask;
			cout << "Do you want to print the rotated list: 1 for yes. \n";
			cin >> ask;
			if (ask == 1) {
				sl.display_all();
			}
			//rotate doubly non circle list																
			cout << "Please enter the number of spots you want to rotate doubly non circular linked list \n";
			cin >> rotateSpot;
			DL.rotate(rotateSpot);
			cout << "Do you want to print the rotated list: 1 for yes. \n";
			cin >> ask;
			if (ask == 1)
				DL.display_all();

			break;
		case 8:cout << "Proceeding to reverse the list \n";
			cout << "Reversing the singly circular linked list\n";
			SCL.reverse();
			cout << "\n";
			cout << "Reversing the doubly circular linked list\n";
			DCL.reverse();
			break;
		case 9:cout << "Proceeding to random shuffle the list \n";									
			cout << "Singly Linked list\n";
			sl.random_shuffle();
			cout << "Doubly\n";
			SCL.random_shuffle();
			cout << "Singly Circular\n";
			DL.random_shuffle();
			cout << "Doubly Circular\n";
			DCL.random_shuffle();
			break;
		case 10:cout << "Proceeding to display info of i th node \n";
			cout << "Please enter the position of which you want the info \n";
			cin >> i;
			sl.display_i(i);
			break;
		case 11:																						
			cout << "Type: Singly linked-list \n";
			sl.display_all();
			cout << "Type: Singly-Circular linked-list \n";
			SCL.display_all();
			cout << "Type: Doubly linked-list \n";
			DL.display_all();
			cout << "Type: Doubly-Circular linked-list \n";
			DCL.display_all();

			break;
		case 12:cout << "Please enter the position where you want to begin\n";						  
			cin >> j;
			cout << "Please enter the position where you want to end\n";							   
			cin >> i;
			sl.display_range(i, j);
			break;
		case 13:cout << "Proceeding to display the list \n";
			sl.display_links();
			break;
		case 14:cout << "Proceeding to display all list information\n";
			sl.info();
			break;
		case 15:
			break;

		}
	} while (choice != 15);

	system("pause");
	return 0;
}

int printMenu() {
	int chosen; //local variable

	cout << "What would you like to do? Please choose: \n";
	cout << "1. Append \n" << "2. Prepend \n" << "3. Add at the ith Position \n";
	cout << "4. Remove at the ith Position \n" << "5. Change type(update type with link and member \n" << "6. Remove all elements in the list\n";
	cout << "7. Rotate nodes in list r spots \n" << "8. Reverse the list \n" << "9. Output list in random order\n";
	cout << "10. Display node info of ith node \n" << "11. Print data from all nodes \n" << "12. Print node info in given range \n";
	cout << "13. Display head and tail address \n" << "14. Display all list information \n" << "15. Exit \n";

	do {
		cin >> chosen;
	} while (chosen < 1 || chosen>15);

	return chosen;

}



	
