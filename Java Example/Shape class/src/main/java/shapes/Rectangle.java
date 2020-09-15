package main.java.shapes;

/**
 * Created by searlzac000 on 2/1/2017.
 */
public class Rectangle extends Shape{
    private double length;
    private double width;

    //constructor
    public Rectangle(String color, String texture, double length, double width){
        super(color, texture);
        this.length = length;
        this.width = width;
    }

    //encapsulation
    public double getLength() {
        return length;
    }
    public double getWidth() {
        return width;
    }

    //Calculations
    public double calcArea(){
        return (length * width);
    }
    public double calcPerimeter(){
        return (2 * length + 2 * width);
    }
}
