#pragma once
class Vector3
{
protected:
	float x, y, z;

public:
	Vector3() {
		
	}


	Vector3(float xp, float yp, float zp)
	{
		x = xp;
		y = yp;
		z = zp;
	}

	float getx() {
		return x;
	}
	float gety() {
		return y;
	}
	float getz() {
		return z;
	}


};

