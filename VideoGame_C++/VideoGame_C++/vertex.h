#pragma once

/*Header files for vertex class*/

class Vertex {
private:
	float x, y, z; // All variables in a class are private by default

public:
	void setToZero();
	void set(float vx, float vy, float vz);
	float getY();
};