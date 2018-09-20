#include <iostream>
#include <cstring>
using namespace std;



class Person {
protected:
    int age;
    char name[32];
public:
    Person(int a, char* n){
    	setAge(a);
    	setName(n);
    }
    ~Person();
    virtual void Say() = 0;
    void setAge(int a){
		age = a;
	}
	void setName(char* n){
		strcpy(name, n);
	}
	int getAge(){
		return age;
	}
	char* getName(){
		return name;
	}
};

void Person::Say(){
	cout << "Person name is :" << Person::getName() << endl;
	cout << "Person age is :" << Person::getAge() << endl;
}
Person::~Person(){}

class Professor : public Person {
protected:
	int professorNumber;
	char major[32];
public:
    Professor(char* n, int a, int pn, char* m):Person(a, n){
    	setProfessorNumber(pn);
    	setMajor(m);
    }
    ~Professor(){};
    void setProfessorNumber(int pn){
		professorNumber = pn;
	}
	void setMajor(char* m){
		strcpy(major, m);
	}
	int getProfessorNumber(){
		return professorNumber;
	}
	char* getMajor(){
		return major;
	}
    void Say(){
    	cout << "Professor Information : " << endl;
    	Person::Say();
    	cout << "Professor number is :" << getProfessorNumber() << endl;
		cout << "Professor major is :" << getMajor() << endl << endl;
	}
};

class Student : public Person {
protected:
	int studentNumber;
	char major[32];
	int schoolYear;
public:
    Student(char* n, int a, int sn, char* m, int sy):Person(a, n){
    	setStudentNumber(sn);
    	setMajor(m);
    	setSchoolYear(sy);
    }
    ~Student(){};
    void setStudentNumber(int sn){
		studentNumber = sn;
	}
	void setMajor(char* m){
		strcpy(major, m);
	}
	void setSchoolYear(int sy){
		schoolYear = sy;
	}

	int getStudentNumber(){
		return studentNumber;
	}
	char* getMajor(){
		return major;
	}
	int getSchoolYear(){
		return schoolYear;
	}

	void Say(){
		cout << "Student Information : " << endl;
    	Person::Say();
    	cout << "Student number is :" << getStudentNumber() << endl;
		cout << "Student major is :" << getMajor() << endl;
		cout << "Student has been study in : " << getSchoolYear() << "years" << endl << endl;
	}
};

int main() {
	// Professor Wawan
	char pName[32] = "Wawan"; // name
	int pAge = 50; // age
	char pMajor[32] = "Mathematics"; // major
	int pNumber = 1; // number

	Professor p1(pName, pAge, pNumber, pMajor);
	p1.Say();

	// Student Budi
	char sName[32] = "Budi"; // name
	int sAge = 24; // age
	char sMajor[32] = "Mathematics"; // major
	int sNumber = 1; // number
	int sYear = 3;

	Student s1(sName, sAge, sNumber, sMajor, sYear);
	s1.Say();	
	
    return 0;
}