#include <stdio.h>
#include "vertex.h"

/*
class Vertex {
private:
	float x, y, z; // All variables in a class are private by default

public:
	void setToZero() {
		x = 0;
		y = 0;
		z = 0;
	}

	void set(float vx, float vy, float vz) {
		x = vx;
		y = vy;
		z = vz;
	}

	float getY() {
		return y;
	}
};
*/

int main() {
	Vertex v;

	v.setToZero();
	v.set(9, 10, 12);

	printf("Using vertex header: %d\n", int(v.getY()));

	return 0;
}