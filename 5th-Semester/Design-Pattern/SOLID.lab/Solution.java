// There is no solution because by philosophy, Rectangle is not completely substitutable with Square. Rectangle has some properties that is incompatible with its child - square.
// So instead, we make liskov between ishape--> rectangle and ishape-->square

import java.io.*;

interface IShape {
    void setTopLeft(float x, float y);
    void setColor(String color);
    void draw();
    
    //   void setSize();
    float getArea();
}

abstract class Shape implements IShape {
	String color;
	float x,y;

	public void setTopLeft(float x, float y){
		this.x = x;
		this.y = y;
	}
	public void setColor(String color){
		this.color = color;
	}
	public void draw(){
		// Draw Stuffs
	}
}

class Rectangle extends Shape{
	int height, width;

	public void setSize(int height, int width){
		this.height = height;
		this.width = width;
	}
	public float getArea(){
		return this.height*this.width;
	}

}

class Square extends Shape {
	int side;
	public void setSize(int side){
		this.side = side;
	}
	public float getArea(){
		return this.side*this.side;
	}

}

public class Solution {

	// No Liskov-Substitution principle is possible between Rectangle & Square because by philosophy, a rectangle is not completely substitutable with square.
	// They have many completely separate/conflicting properties.
	public static void main(String[] args){
		IShape square = new Square();
		square.setColor("red");
	}
}
