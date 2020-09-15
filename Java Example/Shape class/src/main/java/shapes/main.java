package main.java.shapes;

public class main {
    public static void main(String[] args) {
        Rectangle myRectangle = new Rectangle("Yellow", "Smooth", 8, 6);
        Diamond myDiamond = new Diamond("White", "Rough", 4, 9);
        Triangle myTriangle = new Triangle("Orange", "Shiny", 12, 4);
        Oval myOval = new Oval("Blue", "Smooth", 4, 8);

        System.out.printf("Rectangle: %10s, %10s, %8.2f, %8.2f\n", myRectangle.getColor(), myRectangle.getTexture(), myRectangle.calcArea(), myRectangle.calcPerimeter());
        System.out.printf("Triangle: %10s, %10s, %8.2f, %8.2f\n", myTriangle.getColor(), myTriangle.getTexture(), myTriangle.calcArea(), myTriangle.calcPerimeter());
        System.out.printf("Diamond: %10s, %10s, %8.2f, %8.2f\n", myDiamond.getColor(), myDiamond.getTexture(), myDiamond.calcArea(), myDiamond.calcPerimeter());
        System.out.printf("Oval: %10s, %10s, %8.2f, %8.2f\n", myOval.getColor(), myOval.getTexture(), myOval.calcArea(), myOval.calcPerimeter());
    }
}
