public class Box
{
    private int length;
    private int width;
    private int height;
    public void setDimensions(int l, int w, int h)
    {
        length = l;
        width = w;
        height = h;
    }
    public void getDimensions()
    {
        System.out.print("Length: " + length);
        System.out.print(", Width: " + width); 
        System.out.print(", Height: " + height);
    }
    public void Volume()
    {
        int volume = length * width * height;
        System.out.println(", Volume: " + volume);
    }
    public static void main(String args[])
    {
        Box box1 = new Box();
        Box box2 = new Box();
        box1.setDimensions(2, 3, 4);
        box2.setDimensions(5, 6, 7);

        System.out.println("Box 1 Dimensions and Volume:");
        
        box1.getDimensions();
        box1.Volume();
        System.out.println("Box 2 Dimensions and Volume:");
        box2.getDimensions();
        box2.Volume();
    }
}