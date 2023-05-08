#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* MakeNode(int x) {
	Node* NewNode = new Node;
	NewNode->data = x;
	NewNode->next = NULL;
	return NewNode;
}

int Count(Node* head) {
	int Count = 0;
	while (head != NULL) {
		Count++;
		head = head->next;
	}
	return Count;
}

void Xuat(Node* head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

void Add_first(Node*& head, int x) {
	Node* NewNode = MakeNode(x);
	NewNode->next = head;
	head = NewNode;
}

void Add_back(Node*& head, int x) {
	Node* tmp = head;
	Node* NewNode = MakeNode(x);
	if (tmp == NULL) {
		head = NewNode;
		return;
	}
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = NewNode;
}

void Insert(Node*& head, int x) {
	Node* tmp = head;
	Node* NewNode = MakeNode(x);
	int k; cout << "Nhap vi tri k can chen: "; cin >> k;
	if (k<1 or k > Count(head) + 1) {
		cout << "Vi tri chen khong hop le!" << endl;
		return;
	}
	if (k == 1) {
		Add_first(head, x);
		return;
	}
	for (int i = 1; i <= k - 2; i++) {
		tmp = tmp->next;
	}
	NewNode->next = tmp->next;
	tmp->next = NewNode;
}

void _delete_first(Node*& head) {
	Node* tmp = head;
	if (tmp == NULL) {
		cout << "Khong co node nao ca!" << endl;
		return;
	}
	head = tmp->next;
	delete tmp;
}

void _delete_back(Node*& head) {
	Node* tmp = head;
	if (tmp == NULL) {
		cout << "Khong co node nao ca!" << endl;
		return;
	}
	if (tmp->next == NULL) {
		delete tmp;
		return;
	}
	while (tmp->next->next != NULL) {
		tmp = tmp->next;
	}
	Node* last = tmp->next;
	tmp->next = NULL;
	delete last;
}

void _delete_anywhere(Node*& head) {
	int k; cout << "Nhap vi tri k can xoa: "; cin >> k;
	if (k < 1 or k > Count(head)) {
		cout << "Vi tri can xoa khong hop le!" << endl;
		return;
	}
	if (k == 1) {
		_delete_first(head);
		return;
	}
	Node* tmp = head;
	for (int i = 1; i <= k - 2; i++) {
		tmp = tmp->next;
	}
	Node* vitrik = tmp->next;
	tmp->next = vitrik->next;
	delete vitrik;
}

int main() {
	Node* head = NULL;
	for (int i = 9; i >= 1; i--) {
		Add_first(head, i);
	}
	for (int i = 10; i <= 20; i++) {
		Add_back(head, i);
	}
	Xuat(head);
	Insert(head, 0);
	Xuat(head);
	_delete_first(head);
	Xuat(head);
	_delete_back(head);
	Xuat(head);
	_delete_anywhere(head);
	Xuat(head);
	
}