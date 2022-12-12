interface Shape{
	void getArea();
	void setTopLeft(float x, float y);
	void setColor(string color);
	void draw();
}

class Rectangle implements Shape{
	float height;
	float width;
	String color;
	float x,y;

	void setSize(int height, int width){}

	void getArea(){
		return this.height*this.width;
	}
	void setTopLeft(float x, float y){
		this.x = x;
		this.y = y;
	}
	void setColor(string color){
		this.color = color;
	}
	void draw(){}
}

class Square extends Rectangle {

}

public class Problem {
	Shape square = new Square();
	square.setSize(3,5);
}
