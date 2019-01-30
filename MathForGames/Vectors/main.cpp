#include "lolmat.h"
#define PI 3.14159265

int main()
{

	auto testMat = lolmat(
	1.0f, 1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, 1.0f, 1.0f);

	//works
	testMat.setRotateX(PI);

	//works
	testMat.setRotateY(PI);

	//works
	testMat.setRotateZ(PI);

	//works
	float* testPtr = (float*)testMat;

	//works
	Vector4 testVec = testMat[0];

	//works
	testVec = testMat * testVec;

	//works
	auto testMat2 = lolmat();

	//works
	testMat = testMat * testMat;

	auto testMat3 = lolmat(testVec, testVec, testVec, testVec);
}