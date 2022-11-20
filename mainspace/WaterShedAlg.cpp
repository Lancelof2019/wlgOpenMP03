 #include "../headerspace/WatershedAlg.h"
 #include<iostream>
 using namespace std;
 using namespace cv;
 #include <time.h>
 int main(){



    cv::Mat srcImg=cv::imread("../image/pexels-sagui-andrea-618833.jpg");
    int rows=srcImg.rows;
    int cols=srcImg.cols;

     cv::Mat duplImage(srcImg.rows,srcImg.cols,CV_8UC3,Scalar::all(0));
     srcImg.copyTo(duplImage);

     if(!srcImg.data){

        cout<<"The file is not loaded or does not exist"<<endl;
        return -1;


     }

Array2D<int> threshmat(rows,cols,0);     
Array2D<int> markers(rows,cols,0);
Array2D<bool> visArr(rows,cols,false);
Array2D<int> plots(rows,cols,0);
Array2D<int> markerMap(rows,cols,0);
Array2D<bool> inprioq(rows,cols,false);
Array2D<int> temp(rows*cols,3,0);
Array2D<int> nextSet(rows*cols*9,3,0);
Array1D plotx(rows,cols,-1);
Array1D ploty(rows,cols,-1);



   clock_t start1,end1;
    double start,end;
    start1=clock();
    start=omp_get_wtime();
     WatershedAlg *walg=new WatershedAlg();
     walg->processImage(srcImg,duplImage,threshmat,markers,visArr,plotx,ploty,plots,inprioq,markerMap,temp,nextSet);
     end=omp_get_wtime();
     end1=clock();
     //cout<<"CLOCKS_PER_SEC :"<<CLOCKS_PER_SEC<<endl;
     cout<<"The total time the parallel  algorithm used is :"<<(double)(end - start)<<"s"<<endl;
     cout<<"The total time the algorithm used is :"<<(double)(end1 - start1)/CLOCKS_PER_SEC<<endl;
     delete walg;
     return 0;
   } 
