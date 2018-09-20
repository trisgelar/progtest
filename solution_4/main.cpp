#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
using namespace std;
class Node{
	private:
		Node* pNextCircularList;
		Node* pNextNode;
		char word[32];
	public:
		Node(){
			pNextCircularList=NULL;
			pNextNode=0;
			strcpy(word, "");
		}
		~Node();
		Node* getNextCircularList();
		Node* getNextNode();
		char* getWord();
		void setNextCircularList(Node* pNext);
		void setNextNode(Node* pNext);
		void setWord(char* word);
};
Node* Node::getNextCircularList(){
	return pNextCircularList;
}
Node* Node::getNextNode(){
	return pNextNode;
}
char* Node::getWord(){
	return word;
}
void Node::setNextCircularList(Node* pNextC){
	pNextCircularList = pNextC;
}
void Node::setNextNode(Node* pNext){
	pNextNode = pNext;

}
void Node::setWord(char *w){
	strcpy(word, w);
}
class My2DCircularLinkedList
{
private:
	Node *pHead, *pCurr, *pCurrHead;
public:
	My2DCircularLinkedList(){
		pHead = NULL;
		pCurr = NULL;
		pCurrHead = NULL;
	}
	~My2DCircularLinkedList(){}
	void addCircularNode(Node *wNode);
	void addCircularList(Node *wNode);
	void displayList();
	void getCurrHead();
};
void My2DCircularLinkedList::addCircularNode(Node *wNode){	
	if(this->pHead == NULL){
		this->pHead = wNode;
		wNode->setNextNode(this->pHead);
	}else{
		if(this->pCurrHead == NULL){
			this->pCurr = this->pHead;
			while(this->pCurr->getNextNode() != this->pHead){
				this->pCurr = this->pCurr->getNextNode();
			}
			this->pCurr->setNextNode(wNode);
			wNode->setNextNode(this->pHead);
		}else{
			this->pCurr = this->pCurrHead;
			if(this->pCurr->getNextNode() == NULL){
				this->pCurr->setNextNode(wNode);
				wNode->setNextNode(this->pCurr);
			}else{
				while(this->pCurr->getNextNode() != this->pCurrHead){
					this->pCurr = this->pCurr->getNextNode();
				}
				this->pCurr->setNextNode(wNode);
				wNode->setNextNode(this->pCurrHead);
			}
		}
	}
}
void My2DCircularLinkedList::addCircularList(Node *wNode){
	this->pCurrHead = this->pHead;
	if(this->pCurrHead->getNextCircularList() == NULL){
		this->pCurrHead->setNextCircularList(wNode);
		this->pCurrHead = wNode;
		return;
	}else{
		this->pCurrHead = this->pHead;
		while(this->pCurrHead->getNextCircularList() != NULL){
			this->pCurrHead = this->pCurrHead->getNextCircularList();
		}
		this->pCurrHead->setNextCircularList(wNode);
		this->pCurrHead = wNode;
	}
}
void My2DCircularLinkedList::displayList(){  
    if(this->pHead==NULL)
        cout << "Empty List" << endl;
    else
    {
    	this->pCurr=this->pHead;
        while(this->pCurr->getNextNode() != this->pHead){
        	cout << this->pCurr->getWord() << " -> ";
        	this->pCurr = this->pCurr->getNextNode();
        }
        cout << this->pCurr->getWord();
        cout << endl;
    }
}
int main(){
	My2DCircularLinkedList scList;
	ifstream sampleFile("sample.txt");
	if(sampleFile.is_open()){
		string line;
		int linePos = 0;
		while(getline(sampleFile,line)) {
			istringstream ss(line);
			char word[32];
			int wordPos = 0;
			while(ss >> word){
				Node* wn = new Node;
				wn->setWord(word);
				if(linePos > 0 && wordPos == 0){
					scList.addCircularList(wn);
				}else{
					scList.addCircularNode(wn);
				}
				wordPos +=1;
			}
			linePos+=1;
		}
		sampleFile.close(); 
	}	
	return 0;
}