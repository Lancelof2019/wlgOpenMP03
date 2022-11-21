template<class T1>
class Array2D{

public:
	int arows=0;
	int acols=0;
        T1**  __restrict matImg;
Array2D(int rows,int cols,T1 defaultVal):arows(rows),acols(cols){

matImg=new T1*[rows];
for(int i=0;i<rows;i++){
   matImg[i]=new T1[cols];
   memset(matImg[i],defaultVal,sizeof(T1)*cols);
   }
}

T1 &operator()(const int& m, const int& n){

 return matImg[m][n];


 }


T1 *operator()(const int&k){

 return matImg[k];

}


~Array2D(){
for(int i=0,i<matImg.arows;i++){
delete[] matImg[i];
   }
   delete [] matImg;
 }

};

class Array1D{

public:
int rows=0;
int cols=0;
int* __restrict strarr;
Array1D(const int& x,const int&y,const int& defaultVal):rows(x),cols(y){

   strarr=new int[rows*cols];
   memset(strarr,defaultVal,sizeof(int)*rows*cols);
}

int &operator()(const int& z){

 return strarr[z];


 }

~Array1D(){
delete[] strarr;

}

};
