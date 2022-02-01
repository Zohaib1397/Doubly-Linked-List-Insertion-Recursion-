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
	Node* insertAtEnd(Node* head, Node* next, int data) {
		if (head == NULL) {
			Node* temp = newNode(data);
			temp->previous = next;
			return temp;
		}
		else {
			head->next = insertAtEnd(head->next, head, data);
		}
		return head;
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
	root = obj.insertAtEnd(root, NULL, 55);
	root = obj.insertAtEnd(root, NULL, 56);
	root = obj.insertAtEnd(root, NULL, 57);
	root = obj.insertAtEnd(root, NULL, 58);
	obj.display(root);
	system("pause");
}