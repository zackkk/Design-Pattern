#include <iostream>
#include <string>
using namespace std;

class Shape{
public:
	virtual void setColor() = 0; /* subclass must implement it */
	virtual void introduce() = 0;
};

class Rectangle : public Shape {
public:
	virtual void setColor(){
		cout<<"set rectangle color"<<endl;
	}
	virtual void introduce(){
		cout<<"Hello, I am a rectangle, nice to meet you."<<endl;
	}
};

class Circle : public Shape{
public:
	virtual void setColor(){
		cout<<"set circle color"<<endl;
	}
	virtual void introduce(){
		cout<<"Hello, I am a circle, nice to meet you."<<endl;
	}
};

/************************** Static Factory **************************/

class ShapeFactory{
public:
	static Shape *createShape(string str){
		if(str == "circle"){
			return new Circle();
		}
		else if(str == "rectangle"){
			return new Rectangle();
		}
		else{
			return NULL;
		}
	}
};

/************************** Testing **************************/

int main(int argc, char** argv){

	/* customers doesn't have to create instances, ShapeFactory will do it for them */
    Shape *rect = ShapeFactory::createShape("rectangle");
    Shape *cir = ShapeFactory::createShape("circle");

    Shape *shape_array[2] = {rect, cir};
    for(int i = 0; i < 2; i++){
        (shape_array[i])->introduce();
        (shape_array[i])->setColor();
    }
    return 0;
}