package main.java.shapes;

/**
 * Created by searlzac000 on 2/1/2017.
 */
public class Triangle extends Shape{
    private double base;
    private double height;

    //constructor
    public Triangle(String color, String texture, double base, double height){
        super(color, texture);
        this.base = base;
        this.height = height;
    }

    //encapsulation
    public double getBase() {
        return base;
    }
    public double getHeight() {
        return height;
    }

    //calculations
    public double calcArea(){
        double area = 1/2.0 * base * height;
        return area;
    }
    public double calcPerimeter(){
        double perimeter = base + 2.0 * Math.sqrt(Math.pow(base/2, 2) + Math.pow(height, 2));
        return perimeter;
    }

}
