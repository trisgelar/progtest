#include <iostream>
#include <cstring>
using namespace std;


class Person {
protected:
    int age;
    char name[32];
public:
    Person(int a,char *n){
        setAge(a);
        setName(n);
    }
    ~Person();
    virtual void Say() = 0;
    void setAge(int a){
        age = a;
    }
    void setName(char *n){
        strcpy(name, n);
    }
    int getAge(){
        return age;
    }
    char *getName(){
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
    Professor(char *n, int a, int pn,char  *m):Person(a, n){
        setProfessorNumber(pn);
        setMajor(m);
    }
    ~Professor(){};
    void setProfessorNumber(int pn){
        professorNumber = pn;
    }
    void setMajor(char *m){
        strcpy(major, m);
    }
    int getProfessorNumber(){
        return professorNumber;
    }
    char *getMajor(){
        return major;
    }
    int getPersonAge(){
        return Person::getAge();
    }
    char *getPersonName(){
        return Person::getName();
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
    Student(char *n, int a, int sn,char  *m, int sy):Person(a, n){
        setStudentNumber(sn);
        setMajor(m);
        setSchoolYear(sy);
    }
    ~Student(){};
    void setStudentNumber(int sn){
        studentNumber = sn;
    }
    void setMajor(char *m){
        strcpy(major, m);
    }
    void setSchoolYear(int sy){
        schoolYear = sy;
    }
    int getStudentNumber(){
        return studentNumber;
    }
    char *getMajor(){
        return major;
    }
    int getSchoolYear(){
        return schoolYear;
    }
    int getPersonAge(){
        return Person::getAge();
    }
    char *getPersonName(){
        return Person::getName();
    }

    void Say(){
        cout << "Student Information : " << endl;
        Person::Say();
        cout << "Student number is : " << getStudentNumber() << endl;
        cout << "Student has been study in university for  : " << getSchoolYear() << " years" << endl << endl;
    }
};


class Assistant : public Professor, public Student {
protected:
public:
    Assistant(char *nP, int aP, int pn,char *nS, int aS, int sn, int sy, char  *m):Professor(nP, aP, pn, m), Student(nS, aS, sn, m, sy){

    }
    ~Assistant(){};
    void Say(){
        
        cout << "Student " << Student::getPersonName() << " is Assistant of Prof. " << Professor::getPersonName() << endl;
        cout << "he/she is majoring in : " << Student::getMajor() << " and has been studying in university for " <<  Student::getSchoolYear() << " years" << endl << endl;

        cout << "Complete Asistant Information : " << endl;
        cout << "Student number is : " << Student::getStudentNumber() << endl;
        cout << "Student major is : " << Student::getMajor() << endl;
        cout << "Student age is : " << Student::getAge() << endl;
    }
};

int main() {
    // Professor Wawan
    char pName[32] = "Wawan"; // name
    int pAge = 50; // age
    char pMajor[32] = "Mathematics"; // major
    int pNumber = 1; // number
    Professor p1(pName, pAge, pNumber, pMajor);
    // Student Budi
    char sName[32] = "Budi"; // name
    int sAge = 24; // age
    char sMajor[32] = "Mathematics"; // major
    int sNumber = 1; // number
    int sYear = 3;
    Student s1(sName, sAge, sNumber, sMajor, sYear);

    // Student Budi is Assistant for Professor Wawan
    Assistant a1(p1.Person::getName(), p1.Person::getAge(), p1.getProfessorNumber(), s1.Person::getName(), s1.Person::getAge(), s1.getStudentNumber(), s1.getSchoolYear(), p1.getMajor());
    a1.Say();
    return 0;
}