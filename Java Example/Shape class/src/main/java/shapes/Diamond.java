package main.java.shapes;

/**
 * Created by searlzac000 on 2/1/2017.
 */
public class Diamond extends Shape{
    private double width;
    private double length;

    //constructor
    public Diamond(String color, String texture, double width, double length){
        super(color, texture);
        this.width = width;
        this.length = length;
    }

    //encapsulation
    public double getWidth() {
        return width;
    }
    public double getLength() {
        return length;
    }

    //calculations
    public double calcArea(){
        double area = 1/2.0 * width * length;
        return area;
    }

    public double calcPerimeter(){
        double perimeter = 4.0 * (Math.sqrt((Math.pow(width/2, 2) + Math.pow(length/2, 2))));
        return perimeter;
    }
}
