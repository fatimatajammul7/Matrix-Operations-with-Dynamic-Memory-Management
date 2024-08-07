#include <iostream>
#include <fstream>


using namespace std;

//function for deallocation of Arrays
void DeallocateMatrix(int** Matrix, int rows)
{
	for(int i=0; i<rows; i++)
	{
		delete[] Matrix[i];
		Matrix[i]=0;
	}
	delete[] Matrix;
	Matrix=0;
	
}

//function for input
int** InputMatrix( ifstream& IN, int& rows, int& cols)
{
	int** Matrix=new int*[rows];
	int** Value=Matrix + rows;
	for(int** i=Matrix; i<Value; i++)
	{
		*(i)=new int[cols];
	}
	
	for(int** i=Matrix; i<Value; i++ )
	{
		int* value=cols+ *i;
		for(int* j=*i; j<cols+ *i; j++)
		{
			IN>>*(j);
		}
	}
	return Matrix;
}

//function for Addition of matrices
int** AddMatrix(int** matrixA, int** matrixB, const int& ROWS, const int& COLS)
{
	int** r=new int*[ROWS];
	int** V=r+ ROWS;
	for(int** i=r; i<V; i++)
	{
		*(i)=new int[COLS];
	}
	int** i=matrixA;
	int** I=matrixB;
	int** k=r;
	int** Value=matrixA+ROWS;
	for(; i<Value; i++,I++,k++ )
	{
		int* j=*i;
		int* J=*I;
		int* K=*k;
		int* value=COLS+ *i;
		for( ; j<value; j++, J++,K++)
		{
			*(K)=*(j) + *(J);
		}
		
	}
	return r;	
}

//function for transpose of matrix
int** TransposeMatrix(int** matrix, const int& rows, const int& cols)
{
	int** r=new int*[cols];
	int** Value=r+ cols;
	for(int** i=r; i<Value; i++)
	{
		*(i)=new int[rows];
	}
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			*(*(r+j)+i)=*(*(matrix+i)+j);
		}
	}
	return r;
	
	
	
}

//interchanging rows
void InterchangeRows( int*& r1, int*& r2 )
{
	int* temp=r1;
	r1=r2;
	r2=temp;
}

//function for row interchange
void InterchangeRows(int** matrix, const int& ROWS, const int& COLS )
{
	int r1=1;
	int r2=3;
	int *R1=matrix[r1-1];
	int* R2=matrix[r2-1];
	InterchangeRows( R1, R2 );
	matrix[r1-1]=R1;
	matrix[r2-1]=R2;
	
}

// function to check if the matrix is symmetric
bool IsSymmetric(int** matrix, const int& rows, const int& cols)
{
	bool check=true;
	int** Transpose=0;
	Transpose=TransposeMatrix(matrix, rows, cols);
	int** i=matrix;
	int** I=Transpose;
	int** Value=matrix+rows;
	for(; i<Value; i++,I++ )
	{
		int* j=*i;
		int* J=*I;
		int* value=cols+ *i;
		for( ; j<value; j++, J++)
		{
			if(*(j)!=*(J))
			{
				check=false;
			}
	
		}
		
	}
	DeallocateMatrix(Transpose, cols);
	
	return check;
	
}

//function for output
void OutputMatrix(int** Matrix, const int& ROWS, const int& COLS)
{
	int** Value=Matrix+ROWS;
	for(int** i=Matrix; i<Value; i++ )
	{
		int* value=COLS+ *i;
		for(int* j=*i; j<value; j++)
		{
			cout<<*(j)<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	ifstream IN("InputFile.txt");
	if(IN.is_open())
	{
		ifstream IN("InputFile.txt");
	   	int** Array1=0;
	   	int** Array2=0;
	   	int** Array3=0;
	   	int** AddArray=0;
	   	int** AddArray1=0;
	   	int** TransposeArray=0;
	   	int** TransposeArray1=0;
	    int rows1,cols1,rows2,cols2,rows3,cols3;
	    IN>>rows1>>cols1;
	    Array1=InputMatrix( IN, rows1, cols1);
	    cout<<"Matrix A ="<<endl;
	    OutputMatrix(Array1, rows1, cols1);
	    cout<<endl;
	    IN>>rows2>>cols2;
	    Array2=InputMatrix( IN, rows2, cols2);
	    cout<<"Matrix B ="<<endl;
	    OutputMatrix(Array2, rows2, cols2);
	    cout<<endl;
	    IN>>rows3>>cols3;
	    Array3=InputMatrix( IN, rows3, cols3);
	    cout<<"Matrix C ="<<endl;
	    OutputMatrix(Array3, rows3, cols3);
	    cout<<endl;
	    if(rows1==rows2 && cols1==cols2)
	    {
	    	AddArray=AddMatrix(Array1, Array2, rows1, cols1);
	    	cout<<"A+B ="<<endl;
		    OutputMatrix(AddArray, rows2, cols2);              //Addition of matrix A and B
		    cout<<endl;
			DeallocateMatrix(AddArray, rows1);
		}
		else
		{
			cout<<"A+B ="<<endl;
			cout<<"Addition not possible.";
			cout<<endl<<endl;
		}
	    if(rows1==rows3 && cols1==cols3)
	    {
	    	AddArray1=AddMatrix(Array1, Array3, rows1, cols1);
	    	cout<<"A+C ="<<endl;
		    OutputMatrix(AddArray1, rows1, cols1);
		    cout<<endl;                                           //Addition for matric A and C
			DeallocateMatrix(AddArray1, rows1);
	    	
		}
		else
		{
			cout<<"A+C ="<<endl;
			cout<<"Addition not possible.";
			cout<<endl<<endl;
		}
		TransposeArray=TransposeMatrix(Array1, rows1, cols1);
		cout<<"Transpose of A = "<<endl;
		OutputMatrix(TransposeArray, cols1, rows1);                  
		cout<<endl;
		TransposeArray1=TransposeMatrix(Array3, rows3, cols3);
		cout<<"Transpose of C = "<<endl;
		OutputMatrix(TransposeArray1, cols3, rows3);                 
		cout<<endl;
		if(IsSymmetric(Array1,rows1,cols1)==true)
			cout<<"Matrix A is Symmetric";
		else
		    cout<<"Matrix A is NOT Symmetric";
		cout<<endl<<endl;   
		if(IsSymmetric(Array2,rows2,cols2)==true)
			cout<<"Matrix B is Symmetric";
		else
		    cout<<"Matrix B is NOT Symmetric";
		cout<<endl<<endl;  
		     
		InterchangeRows(Array1, rows1, cols1 );
        cout<<"Interchanging Rows of Matrix A:"<<endl<<"row1: 1"<<endl<<"row2: 3  "<<endl;;
        cout<<endl;
        cout<<"After Interchanging Rows Matrix A="<<endl;
		OutputMatrix(Array1, rows1, cols1);
		DeallocateMatrix(Array1, rows1);
		DeallocateMatrix(Array2, rows2);
		DeallocateMatrix(Array3, rows3);
		DeallocateMatrix(TransposeArray, cols1);
		DeallocateMatrix(TransposeArray1, cols3);
		
		IN.close();
	}
	else
	{
		cout<<" Error opening the file(InputFIle.txt)";
	}

    return 0;

}
