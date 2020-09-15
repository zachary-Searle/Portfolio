package main.java.shapes;

/**
 * Created by searlzac000 on 2/1/2017.
 */
public class Shape {
    private String color;
    private String texture;

    //constructor
    public Shape(String color, String texture){
        this.color = color;
        this.texture = texture;
    }

    //encapsulation
    public String getColor() {
        return color;
    }
    public String getTexture() {
        return texture;
    }
}
