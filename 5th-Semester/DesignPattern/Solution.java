abstract class Shape {
	String color;
	float x,y;

	void setTopLeft(float x, float y){
		this.x = x;
		this.y = y;
	}
	void setColor(string color){
		this.color = color;
	}
	void draw(){}
	abstract public void setSize();
	abstract public void getArea();
}

class Rectangle extends Shape{
	int height, width;

	@Override
	public void setSize(int height, int width){
		this.height = height;
		this.width = width;
	}
	@Override
	void getArea(){
		return this.height*this.width;
	}

}

class Square extends Shape {
	int side;
	@Override
	public void setSize(int side){
		this.side = side;
	}
	@Override
	void getArea(){
		return this.side*this.side;
	}

}

public class Solution {
	public static void main(String[] args){
		Shape square = new Square();
		square.setSize(3,5);
	}
}
