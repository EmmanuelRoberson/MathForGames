//#include "Matrix4.h"
//#define PI 3.14159265
//
//int main()
//{
//	auto testMat = Matrix4(
//	1.0f, 1.0f, 1.0f, 1.0f,
//	1.0f, 1.0f, 1.0f, 1.0f,
//	1.0f, 1.0f, 1.0f, 1.0f,
//	1.0f, 1.0f, 1.0f, 1.0f);
//
//	//works
//	testMat.setRotateX(PI);
//
//	//works
//	testMat.setRotateY(PI);
//
//	//works
//	testMat.setRotateZ(PI);
//
//	//works
//	float* testPtr = (float*)testMat;
//
//	//works
//	Vector4 testVec = testMat[0];
//
//	//works
//	testVec = testMat * testVec;
//
//	//works
//	auto testMat2 = Matrix4();
//
//	//works
//	testMat = testMat * testMat;
//
//	auto testMat3 = Matrix4(testVec, testVec, testVec, testVec);
//}