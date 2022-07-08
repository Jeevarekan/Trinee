#include<iostream>
#include<string>
#include <Windows.h>
#include "TCHAR.H" // for _tcscpy_s
using namespace std;

struct Node {
	TCHAR namedata[256];
	TCHAR desigdata[256];
	int idvalue;
	struct Node *next;
};
struct Node* head = NULL;


////////////////////////////////////
// Name : GetData()
// Use : To get input from user for new data
// parameter : NULL
/////////////////////////////////////
void getdata() {
	struct Node* ptr; // added by jeeva - 
	int id = 0;
	TCHAR name[256];
	TCHAR desig[256];
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	cout << "Enter name :" << endl;
	scanf("%s", &name);
	cout << "Enter id :" << endl;
	scanf("%d", &id);
	cout << "Enter designation :" << endl;
	scanf("%s", &desig);
	if (head == NULL)
	{
		_tcscpy(new_node->desigdata, desig);
		_tcscpy(new_node->namedata, name);
		new_node->idvalue = id;
		//new_node->desigdata = desig;
		/*new_node->next = head;*/
		head = new_node;

	}
	else
	{
		ptr = head;
		//head->next == NULL;
		//Node* n = head->next;		
		_tcscpy(new_node->namedata, name);
		_tcscpy(new_node->desigdata, desig);
		new_node->idvalue = id;
		 
		new_node->next = ptr->next;
		ptr->next = new_node;
	}
}
void deletefirst()
{
	if (head == NULL) {
		cout << "List is already empty" << endl;
	}
	else
	{
		Node* temp = head;
		head = head->next;
		free(temp);
		temp = NULL;
	}
}
void deletemiddle()
{
	int position;
	cout << "Enter the Posttion of node to be deleted:" << endl;
	cin >> position;
	Node *prev = head;
	Node *current = head;
	if (head == NULL)
	{
		cout << "Already List is empty" << endl;
	}
	if (position == 1)
	{
		head = current->next;
		free(current);
		current = NULL;
	}
	else
	{
		while (position != 1)
		{
			prev = current;
			current = current->next;
			position--;
		}
		prev->next = current->next;
		free(current);
		current = NULL;
	}
}
void deletelast()
{
	if (head == NULL)
	{
		cout << "List is already empty" << endl;
	}
	if (head->next == NULL)
	{
		free(head);
		head = NULL;
	}
	else
	{
		Node *temp = head;
		Node *temp2 = head;
		while (temp->next != NULL)
		{
			temp2 = temp;
			temp = temp->next;
		}
		temp2->next = NULL;
		free(temp);
		temp = NULL;
	}
}
void deletedata()
{
	int choice = 0;
	cout << "Enter 1 to delete First Node" << endl;
	cout << "Enter 2 to delete Middle Node" << endl;
	cout << "Enter 3 to delete Last Node" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1: deletefirst(); break;
	case 2: deletemiddle(); break;
	case 3: deletelast(); break;
	default: cout << "Enter only these options";
	}

}

void display();

int main() {
	bool quit = false;
	int choice = 0;
	Node *head = new Node;
	head->next = NULL;

	while (!quit) {
		cout << "\nEnter 1 to Enter Details:" << endl;
		cout << "Enter 2 to Display" << endl;
		cout << "Enter 3 to Delete Details" << endl;
		cout << "Enter 4 to Quit" << endl;
		cin >> choice;
		switch (choice) {
		case 1:getdata();continue;
		case 2:display(); continue;
		case 3:deletedata(); continue;
		case 4: cout << "Exit\n"; break;
		default: cout << "\n That is not a valid input, quitting program" << endl;
			quit = true;
		}
		return 0;
	}
}
void display() {
	struct Node* ptr;
	ptr = head;
	cout << "Name\t\t" << "ID\t\t" << "Designation" << endl;

	while (ptr != NULL)
	{
		/*cout << ptr->namedata << "\t\t ";
		cout << ptr->idvalue << " \t\t";
		cout << ptr->desigdata << endl;*/
		printf("%s\t\t", ptr->namedata);
		printf("%d\t\t", ptr->idvalue);
		printf("%s\n", ptr->desigdata);
		ptr = ptr->next;
	}
}

