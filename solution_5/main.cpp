#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Time
{
protected:
	int m_sec;
	int m_min;
	int m_hour;
public:
	Time(int h, int m, int s);
	Time(int s);
	Time(const Time &p);
	Time(){m_hour=0, m_min=0; m_sec=0;}
	Time operator+(Time);
	Time operator-(Time);
	Time operator ++();
	Time operator ++(int);
	Time operator --();
	Time operator --(int);
	Time operator +=(Time);
	Time operator -=(Time);
	friend bool operator==(Time &T1, Time &T2);
	friend bool operator>(Time &T1, Time &T2);
	friend bool operator<(Time &T1, Time &T2);
	friend bool operator>=(Time &T1, Time &T2);
	friend bool operator<=(Time &T1, Time &T2);

	~Time();
	void setSecond(int s);
	void setMinute(int m);
	void setHour(int h);
	int getSecond();
	int getMinute();
	int getHour();
	void print();
	void convSecond(int s);
	int checkConstraint(int x);
};
Time::Time(int h, int m, int s){
	setHour(h);
	setMinute(Time::checkConstraint(m));
	setSecond(Time::checkConstraint(s));
}
Time::Time(int s){
	setSecond(s);
}
// Copy constructor
Time::Time(const Time &p) {
	m_hour = p.m_hour; 
	m_min = p.m_min; 
	m_sec = p.m_sec;
}
Time Time::operator+(Time T1){
	Time Temp;
	int a,b;
	a = m_sec+T1.m_sec;
	Temp.m_sec = a%60;
	b =(a/60)+m_min+T1.m_min;
	Temp.m_min = b%60;
	Temp.m_hour = (b/60)+m_hour+T1.m_hour;
	return Temp;
}
Time Time::operator-(Time T1){
	Time Temp;
	int a,b;
	a = m_sec-T1.m_sec;
	Temp.m_sec = a%60;
	b =(a/60)+m_min-T1.m_min;
	Temp.m_min = b%60;
	Temp.m_hour = (b/60)+m_hour-T1.m_hour;
	return Temp;
}
Time Time::operator++(){
	Time Temp;
	int a,b;
	a = ++m_sec;
	Temp.m_sec = a%60;
	b =(a/60)+m_min;
	Temp.m_min = b%60;
	Temp.m_hour = (b/60)+m_hour;
	return Temp;
}
Time Time::operator++(int){
	Time Temp;
	int a,b;
	a = m_sec++;
	Temp.m_sec = a%60;
	b =(a/60)+m_min;
	Temp.m_min = b%60;
	Temp.m_hour = (b/60)+m_hour;
	return Temp;
}
Time Time::operator--(){
	Time Temp;
	int a,b;
	a = --m_sec;
	Temp.m_sec = a%60;
	b =(a/60)+m_min;
	Temp.m_min = b%60;
	Temp.m_hour = (b/60)+m_hour;
	return Temp;
}
Time Time::operator--(int){
	Time Temp;
	int a,b;
	a = m_sec--;
	Temp.m_sec = a%60;
	b =(a/60)+m_min;
	Temp.m_min = b%60;
	Temp.m_hour = (b/60)+m_hour;
	return Temp;
}

bool operator==(Time &t1, Time &t2){
	return (t1.m_hour == t2.m_hour && t1.m_min == t2.m_min && t1.m_sec == t2.m_sec);
}

bool operator>(Time &t1, Time &t2){
	return (t1.m_hour > t2.m_hour && t1.m_min > t2.m_min && t1.m_sec > t2.m_sec);
}

bool operator<(Time &t1, Time &t2){
	return (t1.m_hour < t2.m_hour && t1.m_min < t2.m_min && t1.m_sec < t2.m_sec);
}

bool operator>=(Time &t1, Time &t2){
	return (t1.m_hour >= t2.m_hour && t1.m_min >= t2.m_min && t1.m_sec >= t2.m_sec);
}

bool operator<=(Time &t1, Time &t2){
	return (t1.m_hour <= t2.m_hour && t1.m_min <= t2.m_min && t1.m_sec <= t2.m_sec);
}



Time::~Time(){}

void Time::setHour(int h){
	m_hour = h;
}
void Time::setMinute(int m){
	m_min = m;
}
void Time::setSecond(int s){
	m_sec = s;
}
int Time::getHour(){
	return m_hour;
}
int Time::getMinute(){
	return m_min;
}
int Time::getSecond(){
	return m_sec;
}
int Time::checkConstraint(int x){
	if( x >= 0 && x <= 59) {
		return x;
	}else {
   		throw "value must be on 0 to 59";
   	}
}
void Time::convSecond(int s){
	// perhitungan detik ke jam menit detik
	int x  = s;
	int y  = x % 3600;
	int ho = x / 3600;
	int mi = y / 60;
	int se  = y % 60;

	cout << ho << "h " << mi << "m " << se << "s" << endl;
}
void Time::print(){
	if((Time::getHour() != 0 ) || Time::getMinute() != 0){
		// cout << "Time Conversion of " << Time::getHour() << ":" << Time::getMinute() << ":" << Time::getSecond() << endl;
		cout << Time::getHour() << "h " << Time::getMinute() << "m " << Time::getSecond() << "s" << endl;
	}else{
		// cout << "Time Conversion of " << Time::getSecond() << endl;
		Time::convSecond(Time::getSecond());
	}
}
int main(){
	cout << "constructor overloading case 1" << endl;
	// Conversion h m s to xh ym zs
	try {
		Time A(10, 50, 59);
		A.print();
	} catch (const char* msg) {
		cerr << msg << endl;
	}
	cout << "constructor overloading case 2" << endl;
	// Conversion from s to h m s
	try {
		Time B(3665);
		B.print();
	} catch (const char* msg) {
		cerr << msg << endl;
	}
	cout << "constructor overloading case 3" << endl;
	// copy constructor A to C
	try {
		Time A(0, 59, 59);
		Time C = A;
		C.print();
	} catch (const char* msg) {
		cerr << msg << endl;
	}

	cout << "operator overloading case 1" << endl;
	try {
		Time A(18, 30, 59);
		Time B(7, 29, 2);
		Time C;
		C = A + B;
		A.print();
		B.print();
		C.print();
	} catch (const char* msg) {
		cerr << msg << endl;
	}
	cout << "operator overloading case 2" << endl;
	try {
		Time A(10, 30, 58);
		Time B;
		B = A++;
		A.print();
		B.print();
		B = ++A;
		A.print();
		B.print();
	} catch (const char* msg) {
		cerr << msg << endl;
	}
	cout << "operator overloading case 3" << endl;
	try {
		Time A(5, 23, 10);
		Time B, C;
		C = B = A;
		B.print();
		C.print();
	} catch (const char* msg) {
		cerr << msg << endl;
	}
	return 0;
}