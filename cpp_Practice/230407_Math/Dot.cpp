#include <iostream>
#include <math.h>
using namespace std;
float Dot(float, float,float,float);
void Normalize(float& x, float& y);
float Length(float x, float y);
float CalculateDegree(float nor_vec1_x, float nor_vec1_yfloat, float nor_vec2_x, float nor_vec2_y);
float CalculateSize(float a, float b, float degree);
int main(void)
{



	
	float x = 0, y = 10;
	float x1 = 10, y1 = 10;


	Normalize(x, y);
	Normalize(x1, y1);


	cout << CalculateSize(10,10, CalculateDegree(x, y, x1, y1));

	return 0;
}

float Dot(float x, float y,float x1,float y1) {
	return abs((x * x1) + (y * y1));
}
float Length(float x, float y) {
	return sqrt(Dot(x,y,x,y));
}
void Normalize(float& x, float& y) {
	x = x / Length(x,y);
	y = y / Length(x, y);
}
float CalculateDegree(float nor_vec1_x,float nor_vec1_y,float nor_vec2_x, float nor_vec2_y) {
	float cos = Dot(nor_vec1_x, nor_vec1_y,nor_vec2_x,nor_vec2_y);
	return acos(cos) * 58;
}
float CalculateSize(float a, float b,float degree) {
	return a * b * sin(degree) * 0.5f;
}
