#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

class StudentNode{
private:
	char name[32];
	double score;
	StudentNode *next;
public:
	StudentNode(){
		next=NULL;
		score=0;
		strcpy(name, "");
	};
	~StudentNode(){};
	StudentNode *getNextNode();
	char* getName();
	double getScore();
	void setNextNode(StudentNode* pNext);
	void setName(char* nm);
	void setScore(double sc);
};
StudentNode* StudentNode::getNextNode(){
	return next;
}
char* StudentNode::getName(){
	return name;
}
double StudentNode::getScore(){
	return score;
}
void StudentNode::setNextNode(StudentNode* pNext){
	next = pNext;
}
void StudentNode::setName(char* nm){
	strcpy(name, nm);
}
void StudentNode::setScore(double sc){
	score = sc;
}

class SubjectNode{
private:
	char name[32];
	SubjectNode *next;
	StudentNode *nextList;
public:
	SubjectNode(){
		nextList=NULL;
		next=NULL;
		strcpy(name, "");
	};
	~SubjectNode(){};
	StudentNode* getNextList();
	SubjectNode* getNextNode();
	char* getName();
	void setNextList(StudentNode* pNextList);
	void setNextNode(SubjectNode* pNext);
	void setName(char* nm);
};
StudentNode* SubjectNode::getNextList(){
	return nextList;
}
SubjectNode* SubjectNode::getNextNode(){
	return next;
}
char* SubjectNode::getName(){
	return name;
}
void SubjectNode::setNextList(StudentNode* pNextList){
	nextList = pNextList;
}
void SubjectNode::setNextNode(SubjectNode* pNext){
	next = pNext;
}
void SubjectNode::setName(char* nm){
	strcpy(name, nm);
}

class ScoreList
{
private:
	SubjectNode *pHead, *pCurr;
	StudentNode *pStuHead, *pStuCurr;
public:
	ScoreList(){
		pHead=NULL;
		pCurr=NULL;
		pStuHead=NULL;
		pStuCurr=NULL;
	}
	~ScoreList(){}
	void addStudentNode(StudentNode *stuNode, char* pSubjectName);
	void addSubjectNode(SubjectNode *subNode);
	void displayList();
	void displayList(char* pSubjectName);
	double avgOfSub(char* pSubjectName);
	double avgOfStu(char* pStudentName);
	int rankOfStu(char* pStudentName);
	void getSubjectNode(char* pSubjectName);
	StudentNode* getStudentNode(char* pStudentName, char* pSubjectName);
};

void ScoreList::getSubjectNode(char* pSubjectName){
	this->pCurr = this->pHead;
	if(this->pCurr == NULL){
		return;
	}else{
		while(this->pCurr != NULL){
			if(strcmp(this->pCurr->getName(), pSubjectName) == 0){
				return;
			}
			this->pCurr = this->pCurr->getNextNode();
		}
	}
}

StudentNode* ScoreList::getStudentNode(char* pStudentName, char* pSubjectName){
	getSubjectNode(pSubjectName);
	this->pStuCurr = this->pCurr->getNextList();
	if(this->pStuCurr == NULL){
	}else{
		while(this->pStuCurr != NULL){
			if(strcmp(this->pStuCurr->getName(), pStudentName) == 0){
				break;
			}
			this->pStuCurr = this->pStuCurr->getNextNode();
		}
	}
	return this->pStuCurr;
}

void ScoreList::addStudentNode(StudentNode *stuNode, char* pSubjectName){
	getSubjectNode(pSubjectName);
	if(this->pCurr->getNextList() == NULL || this->pCurr->getNextList()->
		getScore() < stuNode->getScore()){
		stuNode->setNextNode(this->pCurr->getNextList());
		this->pCurr->setNextList(stuNode);
		return;
	}else{
		this->pStuCurr = this->pCurr->getNextList();
		while(this->pStuCurr->getNextNode() != NULL && this->pStuCurr->getNextNode()->getScore() >= stuNode->getScore()){
			this->pStuCurr = this->pStuCurr->getNextNode();
		}
		stuNode->setNextNode(this->pStuCurr->getNextNode());
		this->pStuCurr->setNextNode(stuNode);

	}
}
void ScoreList::addSubjectNode(SubjectNode *subNode){	
	if(this->pHead == NULL || this->pHead->getName() < subNode->getName()){
		subNode->setNextNode(this->pHead);
		this->pHead = subNode;
		return;
	}else{
		this->pCurr = this->pHead;
		while(this->pCurr->getNextNode() != NULL && this->pCurr->getNextNode()->getName() > subNode->getName()){
			this->pCurr = this->pCurr->getNextNode();
		}
		subNode->setNextNode(this->pCurr->getNextNode());
		this->pCurr->setNextNode(subNode);
	}
}

void ScoreList::displayList(){
	this->pCurr = this->pHead;
	if(this->pCurr == NULL){
		cout << "Empty List";
	}else{
		while(this->pCurr != NULL){
			cout << this->pCurr->getName() << "\t";
			this->pCurr = this->pCurr->getNextNode();
		}
	}
	cout << endl;
}

void ScoreList::displayList(char* pSubjectName){
	getSubjectNode(pSubjectName);
	this->pStuCurr = this->pCurr->getNextList();	
	if(this->pStuCurr == NULL){
		cout << "Empty List";
	}else{
		while(this->pStuCurr != NULL){
			cout << this->pStuCurr->getName() << " -> " << this->pStuCurr->getScore() << " | ";
			this->pStuCurr = this->pStuCurr->getNextNode();
		}
	}
	cout << endl;
	cout << endl;
}

double ScoreList::avgOfSub(char* pSubjectName){
	cout << pSubjectName << endl;
	double total = 0;
	int i = 0;
	getSubjectNode(pSubjectName);
	this->pStuCurr = this->pCurr->getNextList();	
	if(this->pStuCurr == NULL){
		cout << "Empty List";
	}
	else{
		while(this->pStuCurr != NULL){
			total += this->pStuCurr->getScore();
			i++;
			this->pStuCurr = this->pStuCurr->getNextNode();
		}
	}
	return total / i;
}

double ScoreList::avgOfStu(char* pStudentName){
	char sb1Name[32]="English";
	char sb2Name[32]="Mathematics";
	char sb3Name[32]="Physics";

	return (getStudentNode(pStudentName, sb1Name)->getScore() + getStudentNode(pStudentName, sb2Name)->getScore() + getStudentNode(pStudentName, sb3Name)->getScore())/3;
}
int ScoreList::rankOfStu(char* pStudentName){

}

int main(){
	// initiate subject node
	SubjectNode sb1;
	char sb1Name[32]="English";
	sb1.setName(sb1Name);
	SubjectNode sb2;
	char sb2Name[32]="Mathematics";
	sb2.setName(sb2Name);
	SubjectNode sb3;
	char sb3Name[32]="Physics";
	sb3.setName(sb3Name);

	ScoreList scList;
	scList.addSubjectNode(&sb1);
	scList.addSubjectNode(&sb2);
	scList.addSubjectNode(&sb3);
	scList.displayList();

	// Edward  100	89	60
	ifstream scoreFile("score.txt");
	char name[32];
	double scEng;
	double scMat;
	double scPhy;
	while(scoreFile >> name >> scEng >> scMat >> scPhy){
		StudentNode* student1 = new StudentNode;
		student1->setName(name);
		student1->setScore(scEng);
		scList.addStudentNode(student1, sb1Name);
		StudentNode* student2 = new StudentNode;
		student2->setName(name);
		student2->setScore(scMat);
		scList.addStudentNode(student2, sb2Name);
		StudentNode* student3 = new StudentNode;
		student3->setName(name);
		student3->setScore(scPhy);
		scList.addStudentNode(student3, sb3Name);
	}
	scoreFile.close();
	
	scList.displayList(sb1Name);
	scList.displayList(sb2Name);
	scList.displayList(sb3Name);

	cout << "The Average Score of English subjet is : " << scList.avgOfSub(sb1Name) << endl;
	cout << "The Average Score of Math subjet is " << scList.avgOfSub(sb2Name) << endl;
	cout << "The Average Score of Physics subjet is " << scList.avgOfSub(sb3Name) << endl;

	ifstream avgStudentFile("score.txt");
	char nm[32];
	double scE;
	double scM;
	double scP;
	while(avgStudentFile >> nm >> scE >> scM >> scP){
		cout << "The Average Score of " << nm << " is " << scList.avgOfStu(nm) << endl;
	}
	avgStudentFile.close();

	return 0;
}


