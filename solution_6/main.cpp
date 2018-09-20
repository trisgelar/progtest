#include <iostream>
using namespace std;

template<class T> class Node{
public:
	Node(){
		next = NULL;
	}
	~Node(){};
	T data; // template data
	Node<T> *next; // link to next list
};

template<class T> class MyList{
private:
	Node<T> *head, *tail, *curr, *temp;
public:
	MyList(){
		head=NULL;
		tail=NULL;
		curr=NULL;
		temp=NULL;
	}
	~MyList(){}
	bool insertNode(Node<T> *pNode);
	bool deleteNode(T data);
	Node<T>* searchNode(T data);
	void displayList();
};

template<class T> bool MyList<T>::insertNode(Node<T> *pNode){
	bool flag = false;
	if(this->head == NULL){
		this->head = pNode;
		this->tail = pNode;
		flag = true;
	}else{
		this->tail->next = pNode;
		this->tail = pNode;
		flag = true;
	}
	return true;
}

template<class T> void MyList<T>::displayList(){
	this->curr = this->head;
	if(this->curr == NULL){
		cout << "Empty List";
	}else{
		while(curr != NULL){
			cout << this->curr->data << endl;
			this->curr = this->curr->next;
		}
	}
	cout << endl;
}

template<class T> Node<T>* MyList<T>::searchNode(T data){
	this->curr = this->head;
	if(this->curr == NULL){
		this->curr = NULL;
	}else{
		while(this->curr != NULL){
			if(this->curr->data == data){				
				break;
			}
			this->curr = this->curr->next;
		}
	}
	return this->curr;
}

template<class T> bool MyList<T>::deleteNode(T data){
	
	int flag = false; int pos = 1;
	this->temp = this->head;
	if(this->temp->data == data){
		this->head = this->temp->next;
		delete this->temp;
	}else{
		this->curr = this->head;
		while(this->curr != NULL){
			if(this->curr->data == data){	
				flag = true;			
				break;
			}
			pos+=1;
			this->curr = this->curr->next;
		}
	}
	if(flag){
		this->curr = this->head;
		for(int i=1; i<pos; i++){
			this->temp=this->curr;
			this->curr=this->curr->next;
		}
		this->temp->next = this->curr->next;
		delete curr;
	}
	return flag;
}

int main(){
	Node<int>* n1 = new Node<int>;
	Node<int>* n2 = new Node<int>;
	Node<int>* n3 = new Node<int>;
	Node<int>* n4 = new Node<int>;
	Node<int>* n5 = new Node<int>;
	n1->data = 1;
	n2->data = 2; 
	n3->data = 3;
	n4->data = 4; 
	n5->data = 5;

	MyList<int>* mInt = new MyList<int>;
	mInt->insertNode(n1);
	mInt->insertNode(n2);
	mInt->insertNode(n3);
	mInt->insertNode(n4);
	mInt->insertNode(n5);
	mInt->displayList();
	mInt->searchNode(3);
	mInt->deleteNode(3);
	mInt->displayList();
	return 0;

}