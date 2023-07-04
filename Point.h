#pragma once
#include <iostream>
class Point
{
public:
	float X, Y;
public:
	Point(float X=0, float Y=0) :X(X), Y(Y){ }

	inline Point  operator+ (const Point& p2) const
	{
		return Point(X + p2.X, Y + p2.Y);
	}


	inline friend Point operator+= (Point& p1, const Point& p2)
	{
		p1.X += p2.X;
		p1.Y += p2.Y;
		return p1;
	}

	inline Point operator- (const Point& v2) const
	{
		return Point(X - v2.X, Y - v2.Y);
	}

	inline friend Point operator-= (Point& p1, const Point& p2)
	{
		p1.X -= p2.X;
		p1.Y -= p2.Y;
		return p1;
	}

	//multiplication

	inline Point operator* (const float scaler) const
	{
		return Point(X * scaler, Y * scaler);
	}

	void Log(std::string msg = "") {
		std::cout << msg << "(X Y) - (" << X << " " << Y << ")" << std::endl;
	}
};