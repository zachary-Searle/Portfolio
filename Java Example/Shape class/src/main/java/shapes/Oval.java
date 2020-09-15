package main.java.shapes;

/**
 * Created by searlzac000 on 2/1/2017.
 */
public class Oval extends Shape{
    private double width;
    private double height;

    //constructor
    public Oval(String color, String texture, double width, double height){
        super(color, texture);
        this.width = width;
        this.height = height;
    }

    //encapsulation
    public double getWidth() {
        return width;
    }
    public double getHeight() {
        return height;
    }

    //calculations
    public double calcArea(){
        double area = Math.PI * (width/2.0) * (height/2.0);
        return area;
    }
    public double calcPerimeter(){
        double perimeter = (2.0 * Math.PI) * (Math.sqrt(Math.pow(width / 2, 2) + Math.pow(height/2, 2)))/2;
        return perimeter;
    }
}
