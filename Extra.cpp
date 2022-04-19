#include <iostream>
#include <fstream>
#include <Eigen/Dense>
#include <Eigen/LU>
#include <cmath>
using namespace Eigen;
using namespace std;


int main() {
	MatrixXd X(100, 6);
	MatrixXd X6(100, 7); // 6차 
	MatrixXd X4(100, 5); // 4차
	MatrixXd X3(100, 4); // 3차
	MatrixXd X2(100, 3); // 2차
	MatrixXd X1(100, 2); // 1차 

	VectorXd Y(100), A;
	VectorXd A6;
	VectorXd A4;
	VectorXd A3;
	VectorXd A2;
	VectorXd A1;


	/// read data2 /////
	ifstream fit_data("4fit_data_5th.txt");
	int N = 100;//100 (x,y)'s
	float* x = new float[N];
	float* y = new float[N];
	for (int i = 0; i < N; i++)
		fit_data >> x[i] >> y[i];
	fit_data.close();

	// make X
	//float minx = -1e100, maxx = 1e100;

	//6차
	for (int i = 0; i < N; i++) {
		X6(i, 0) = pow(x[i], 6);
		X6(i, 1) = pow(x[i], 5);
		X6(i, 2) = pow(x[i], 4);
		X6(i, 3) = pow(x[i], 3);
		X6(i, 4) = pow(x[i], 2);
		X6(i, 5) = pow(x[i], 1);
		X6(i, 6) = 1;
	}

	// sprint3 
	for (int i = 0; i < N; i++) {
		X(i, 0) = pow(x[i], 5);
		X(i, 1) = pow(x[i], 4);
		X(i, 2) = pow(x[i], 3);
		X(i, 3) = pow(x[i], 2);
		X(i, 4) = pow(x[i], 1);
		X(i, 5) = 1;
	}

	// 4차
	for (int i = 0; i < N; i++) {
		X4(i, 0) = pow(x[i], 4);
		X4(i, 1) = pow(x[i], 3);
		X4(i, 2) = pow(x[i], 2);
		X4(i, 3) = pow(x[i], 1);
		X4(i, 4) = 1;
	}

	// 3차
	for (int i = 0; i < N; i++) {
		X3(i, 0) = pow(x[i], 3);
		X3(i, 1) = pow(x[i], 2);
		X3(i, 2) = pow(x[i], 1);
		X3(i, 3) = 1;

	}

	// 2차
	for (int i = 0; i < N; i++) {
		X2(i, 0) = pow(x[i], 2);
		X2(i, 1) = pow(x[i], 1);
		X2(i, 2) = 1;

	}

	//1차
	for (int i = 0; i < N; i++) {
		X1(i, 0) = pow(x[i], 1);
		X1(i, 1) = 1;
	}

	cout << "\nX\n";
	cout << X << endl;

	for (int i = 0; i < N; i++) {
		Y(i) = y[i];
	}
	cout << "\nY\n";
	cout << Y << endl;

	// 1. XTX

	//XTX6
	MatrixXd XTX6 = X6.transpose() * X6;
	cout << "\nXTX6\n";
	cout << XTX6 << endl;

	// XTX 
	MatrixXd XTX = X.transpose() * X;
	cout << "\nXTX\n";
	cout << XTX << endl;

	// XTX4
	MatrixXd XTX4 = X4.transpose() * X4;
	cout << "\nXTX4\n";
	cout << XTX4 << endl;

	// XTX3
	MatrixXd XTX3 = X3.transpose() * X3;
	cout << "\nXTX3\n";
	cout << XTX3 << endl;

	// XTX2 
	MatrixXd XTX2 = X2.transpose() * X2;
	cout << "\nXTX2\n";
	cout << XTX2 << endl;

	// XTX1 
	MatrixXd XTX1 = X1.transpose() * X1;
	cout << "\nXTX1\n";
	cout << XTX1 << endl;

	//2. XTXI
	//XTXI6
	MatrixXd XTXI6 = XTX6.inverse();
	cout << "\nXTXI6\n";
	cout << XTXI6 << endl;

	//XTXI
	MatrixXd XTXI = XTX.inverse();
	cout << "\nXTXI\n";
	cout << XTXI << endl;

	//XTXI4
	MatrixXd XTXI4 = XTX4.inverse();
	cout << "\nXTXI4\n";
	cout << XTXI4 << endl;

	//XTXI3
	MatrixXd XTXI3 = XTX3.inverse();
	cout << "\nXTXI3\n";
	cout << XTXI3 << endl;

	//XTXI2
	MatrixXd XTXI2 = XTX2.inverse();
	cout << "\nXTXI2\n";
	cout << XTXI2 << endl;

	//XTXI1
	MatrixXd XTXI1 = XTX1.inverse();
	cout << "\nXTXI1\n";
	cout << XTXI1 << endl;

	//3. A
	//A6
	A6 = XTXI6 * X6.transpose() * Y;
	cout << "\nA6\n";
	cout << A6 << endl;

	//A
	A = XTXI * X.transpose() * Y;
	cout << "\nA\n";
	cout << A << endl;

	//A4
	A4 = XTXI4 * X4.transpose() * Y;
	cout << "\nA4\n";
	cout << A4 << endl;

	//A3
	A3 = XTXI3 * X3.transpose() * Y;
	cout << "\nA3\n";
	cout << A3 << endl;

	//A2
	A2 = XTXI2 * X2.transpose() * Y;
	cout << "\nA2\n";
	cout << A2 << endl;

	//A1
	A1 = XTXI1 * X1.transpose() * Y;
	cout << "\nA1\n";
	cout << A1 << endl;



	// output to show results
	ofstream xx("sprint3_result.txt");
	for (int i = 0; i < N; i++) {
		xx << x[i] << "  " << y[i] << "  " << A[0] * pow(x[i], 5) + A[1] * pow(x[i], 4) + A[2] * pow(x[i], 3) + A[3] * pow(x[i], 2) + A[4] * pow(x[i], 1) + A[5] << endl;

	}

	xx.close();

	//6차
	ofstream xx6("6차 근사.txt");
	for (int i = 0; i < N; i++) {
		xx6 << x[i] << "  " << y[i] << "  " << A6[0] * pow(x[i], 6) + A6[1] * pow(x[i], 5) + A6[2] * pow(x[i], 4) + A6[3] * pow(x[i], 3) + A6[4] * pow(x[i], 2) + A6[5] * pow(x[i], 1) + A6[6] << endl;

	}
	xx6.close();

	//4차
	ofstream xx4("4차 근사.txt");
	for (int i = 0; i < N; i++) {
		xx4 << x[i] << "  " << y[i] << "  " << A4[0] * pow(x[i], 4) + A4[1] * pow(x[i], 3) + A4[2] * pow(x[i], 2) + A4[3] * pow(x[i], 1) + A4[4] << endl;

	}


	xx4.close();

	//3차
	ofstream xx3("3차 근사.txt");
	for (int i = 0; i < N; i++) {
		xx3 << x[i] << "  " << y[i] << "  " << A3[0] * pow(x[i], 3) + A3[1] * pow(x[i], 2) + A3[2] * pow(x[i], 1) + A3[3] << endl;

	}


	xx3.close();

	//2차
	ofstream xx2("2차 근사.txt");
	for (int i = 0; i < N; i++) {
		xx2 << x[i] << "  " << y[i] << "  " << A2[0] * pow(x[i], 2) + A2[1] * pow(x[i], 1) + A2[2] << endl;

	}


	xx2.close();

	//1차
	ofstream xx1("1차 선형 근사.txt");
	for (int i = 0; i < N; i++) {
		xx1 << x[i] << "  " << y[i] << "  " << A1[0] * pow(x[i], 1) + A1[1] << endl;
	}
	xx1.close();




	return 0;
}
