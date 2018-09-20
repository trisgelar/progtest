#include <iostream>
using namespace std;

template<class T> 
class MyMatrix
{
private:
	T** m_matrix;
	int m_size;
public:
	MyMatrix();
	~MyMatrix(){};

	T** createMatrix();
	void createMatrix(int n);
	void printMatrix();
	void populateMatrix(int *src);
	
	bool Add(MyMatrix& m);
	bool Sub(MyMatrix& m);
	bool Mul(MyMatrix& m);

	void setSize(int n){
		m_size = n;
	}
	void setMatrix(T** m){
		m_matrix = m;
	}
	int getSize(){
		return m_size;
	}
	T** getMatrix(){
		return m_matrix;
	}
};

template<class T>
MyMatrix<T>::MyMatrix(){

}

template<class T>
T** MyMatrix<T>::createMatrix(){
	int n = this->m_size;
	T** new_matrix = new T *[n];
	for(int i = 0; i < n; ++i ){
		new_matrix[i] = new T[n];
	}
	return new_matrix;
}

template<class T>
void MyMatrix<T>::createMatrix(int n){
	T** new_matrix = new T *[n];
	for(int i = 0; i < n; ++i ){
		new_matrix[i] = new T[n];
	}
	this->m_matrix = new_matrix;
	this->m_size = n;
}

template<class T>
void MyMatrix<T>::printMatrix(){
	for(int i = 0; i < this->m_size; ++i){
		for(int j = 0; j < this->m_size; ++j){
			cout << this->m_matrix[i][j] << "\t";
		}
		cout << endl;
	}
}

template<class T> 
void MyMatrix<T>::populateMatrix(int *src){
	int pos = 0;
	for(int i = 0; i < this->m_size; ++i){
		for(int j = 0; j < this->m_size; ++j){
			this->m_matrix[i][j] = src[pos++];
		}
	}
}

template<class T>
bool MyMatrix<T>::Add(MyMatrix& m){
	T** temp = createMatrix();
	for(int i = 0; i < this->m_size; ++i){
		for(int j = 0; j < this->m_size; ++j){
			temp[i][j] = this->m_matrix[i][j] + m.getMatrix()[i][j];
		}
	}

	// for(int i = 0; i < this->m_size; ++i){
	// 	for(int j = 0; j < this->m_size; ++j){
	// 		cout << temp[i][j] << "\t";
	// 	}
	// 	cout << endl;
	// }
	return true;
}

template<class T>
bool MyMatrix<T>::Sub(MyMatrix& m){
	T** temp = createMatrix();
	for(int i = 0; i < this->m_size; ++i){
		for(int j = 0; j < this->m_size; ++j){
			temp[i][j] = this->m_matrix[i][j] - m.getMatrix()[i][j];
		}
	}

	// for(int i = 0; i < this->m_size; ++i){
	// 	for(int j = 0; j < this->m_size; ++j){
	// 		cout << temp[i][j] << "\t";
	// 	}
	// 	cout << endl;
	// }
	return true;
}

template<class T>
bool MyMatrix<T>::Mul(MyMatrix& m){
	T** temp = createMatrix();
	for(int i = 0; i < this->m_size; ++i){
		for(int j = 0; j < this->m_size; ++j){
			temp[i][j] = 0;
		}
	}

	for(int i = 0; i < this->m_size; ++i){
		for(int j = 0; j < this->m_size; ++j){
			for(int k = 0; k < this->m_size; ++k){
				temp[i][j] += this->m_matrix[i][k] * m.getMatrix()[k][j];
			}
		}
	}

	
	for(int i = 0; i < this->m_size; ++i){
		for(int j = 0; j < this->m_size; ++j){
			cout << temp[i][j] << "\t";
		}
		cout << endl;
	}
	return true;
}

int main(){
	int m1_src[] = {1, 1, 1, 1};
	MyMatrix<int> m1;
	m1.createMatrix(2);
	m1.populateMatrix(m1_src);
	m1.printMatrix();

	int m2_src[] = {2, 2, 2, 2};
	MyMatrix<int> m2;
	m2.createMatrix(2);
	m2.populateMatrix(m2_src);
	m2.printMatrix();

	m1.Add(m2);
	m1.Sub(m2);
	m1.Mul(m2);

	return 0;
}