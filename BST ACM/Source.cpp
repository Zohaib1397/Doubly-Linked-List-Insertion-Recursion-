#include<iostream>
struct Node {
	int data;
	Node* next;
	Node* previous;
};
class Doubly {
	Node* head;
public:
	Doubly():head(NULL){}
	Node* getHead() {
		return head;
	}
	void setHead(Node* head) {
		this->head = head;
	}
	Node* newNode(int data) {
		Node* temp = new Node;
		temp->next = NULL;
		temp->previous = NULL;
		temp->data = data;
		return temp;
	}
	Node* AssignPrevious(Node* head, Node* next) {
		head->previous = next;
		return head;
	}
	Node* AssignNext(Node* head, Node* data) {
		head->next = data;
		return head;
	}
	Node* insertAtEnd(Node* head, Node* next, int data) {
		return head == NULL ? AssignPrevious(newNode(data),next) : AssignNext(head, insertAtEnd(head->next, head, data));
	}
	Node* insertAtFront(Node* head, Node* previous, int data) {
		//return head == NULL ? AssignNext(newNode(data), previous) : AssignPrevious(head, insertAtFront(head->previous, head, data));
		if (head == NULL) {
			Node* temp = newNode(data);
			temp->next = previous;
			return temp;
		}
		else {
			head->previous = insertAtFront(head->previous, head, data);
		}
	}
	void display(Node* head) {
		if (head == NULL) return;
		else {
			std::cout << head->data << " ";
			display(head->next);
		}
	}
};
int main() {
	Doubly obj;
	Node* root = NULL;
	root = obj.insertAtFront(root, NULL, 55);
	root = obj.insertAtFront(root, NULL, 56);
	root = obj.insertAtFront(root, NULL, 57);
	root = obj.insertAtFront(root, NULL, 58);
	obj.display(root);
	system("pause");
}