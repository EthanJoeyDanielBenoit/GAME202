#include <iostream>

using namespace std;

class Box {
public:
	int length;
	int width;
	int height;

	int getVolume(){
		return length * width * height;
	}

	void setLength(int l) {
		length = l;
	}

	void setWidth(int w) {
		width = w;
	}

	void setHeight(int h) {
		height = h;
	}
};

int main() {
	Box box1;
	Box box2;
	
	box1.setLength(10);
	box1.setWidth(10);
	box1.setHeight(10);


	cout << box1.getVolume() << "\n";

	box2.setLength(5);
	box2.setWidth(10);
	box2.setHeight(40);

	cout << " " << box2.getVolume() << "\n";

	system("Pause");
	return 0;
}