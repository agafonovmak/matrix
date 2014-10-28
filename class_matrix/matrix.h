class matrix
{
private:
	int** arr;
	int n;
	int m;
public:
	matrix();
	matrix(int,int);
	matrix operator+(matrix);
	int* operator [] (int);
	matrix operator * (matrix&);
	void zero();
	void input(int* arr);
	void print();
};