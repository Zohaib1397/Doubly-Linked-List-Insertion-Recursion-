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
			head = head->previous = insertAtFront(head->previous, head, data);
		}
		return head;
	}
	void findAndInsertAfter(Node* head, int data,int val) {
		if (head != NULL) {
			Node* current = head;
			for (current; current != NULL; current = current->next) {
				if (current->data == data) {
					break;
				}
			}
			if (current != NULL) {
				if (current->next != NULL) {
					Node* temp = newNode(val);
					temp->next = current->next;
					temp->previous = current;
					current->next->previous = temp;
					current->next = temp;
				}
				else {
					Node* temp = newNode(val);
					temp->previous = current;
					current->next = temp;
				}
			}
			
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
	obj.setHead(obj.insertAtEnd(obj.getHead(), NULL, 50));
	obj.setHead(obj.insertAtEnd(obj.getHead(), NULL, 52));
	obj.setHead(obj.insertAtEnd(obj.getHead(), NULL, 53));
	obj.setHead(obj.insertAtEnd(obj.getHead(), NULL, 58));
	obj.setHead(obj.insertAtEnd(obj.getHead(), NULL, 59));
	obj.setHead(obj.insertAtEnd(obj.getHead(), NULL, 60));
	obj.findAndInsertAfter(obj.getHead(), 60, 55);
	obj.display(obj.getHead());
	system("pause");
}