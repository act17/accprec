#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*double x[5] = {6,2.1,5,432,21.3};
double y[5] = {9,1.0,5.2,44.4,63.2};
double centx = 5;
double centy = 5;
double max = 9.89949493661;
int size = 5; */

/*
 *	double * x
 *		- The array that has the x-axis values of the points.
 *	double * y
 *		- The array that has the y-axis values of the points.
 *		- Must be of same size as above.
 *	double centx
 *		- The x-axis value of the center.
 *	double centy
 *		- The y-axis value of the center.
 *	double max
 *		- The maximum possible distance between two points within the area.
 *	int size
 *		- The size of the arrays.
 */

double accuracy(double * x,double * y,double centx,double centy,int size){
	double d[size];					//Distance values.
	double temp;					//Temporary value storage.
	double together = 0;				//Value of all distances from center.
	for(int i = 0; i < size; i++){
		x[i] = x[i] - centx;			//Ensures the values are all relative to
		y[i] = y[i] - centy;			//the center.
	}
	for(int i = 0; i < size; i++){
		temp = pow(x[i],2) + pow(y[i],2);	//Pythagorus would be ashamed of
		d[i] = sqrt(temp);			//this program.	
	}
	for(int i = 0; i < size; i++){
		together = together + d[i];		//This is just adding all of the numbers up. 
	}
	together = together / size;			//This is the average of all distances from the center.
	return (100 - together) / 100;			//This is the % of the distance from the center that was travelled (?).
}

double precision(double * x,double * y,double max,int size){
	double d[size];					//Distance values.
	double dtempx[size];				//Distance between
	double dtempy[size];				//two points arranged in an array.
	double temp;
	double together = 0;
	/*for(int i = 0; i < size; i++){
		x[i] = x[i] - centx;			//Same routine as accuracy().
		y[i] = y[i] - centy;
	}*/
	for(int i = 0; i < size; i++){
		if(i == size - 1){			//Ensures that overflow will not occur.
			dtempx[i] = x[0] - x[i];
			dtempy[i] = y[0] - y[i];
			temp = pow(dtempx[i],2) + pow(dtempy[i],2);
			d[i] = sqrt(temp);
		}
		else{
			dtempx[i] = x[i] - x[i+1];	//Calculates the distance between two points,
			dtempy[i] = y[i] - y[i+1];	//in this case between i and i+1.
			temp = pow(dtempx[i],2) + pow(dtempy[i],2);
			d[i] = sqrt(temp);		//And does the same routine as accuracy().
		}
	}
	for(int i = 0; i < size; i++){
		together = together + d[i];		//Same as accuracy(), once again. 
	}
	together = together / size;			//Here comes the basic averaging,
	return 1 - (together / max);			//And there's the proper percentaging.
}

/*int main(){

	double a = accuracy();
	double b = precision();
	printf("\nThe accuracy is %lf percent.",a * 100);
	printf("\nThe precisiion is %lf percent.",b * 100);
	printf("\n");
	return 0;
}*/
