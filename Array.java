import java.util.*;
class JaggedArray{
    public void Demo() {
        int[][] jagged = new int[3][];
        jagged[0] = new int[] {1, 2, 3};
        jagged[1] = new int[] {4, 5};
        jagged[2] = new int[] {6, 7, 8, 9};
        System.out.println("Jagged Array Elements:");
        for (int i = 0; i < jagged.length; i++) {
            for (int j = 0; j < jagged[i].length; j++) {
                System.out.print(jagged[i][j] + " ");
            }
            System.out.println();
        }
    }
}
class matrix
{
    public void Demo()
    {
        Scanner sc = new Scanner(System.in);   
        int [][ ] matrix = new int[3][3];
        System.out.println("3x3 Matrix:");
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                matrix[i][j] = sc.nextInt();
            }
        }
        System.out.println("Matrix Diagonal Elements:");
        for(int i=0; i<3; i++)
        {
            System.out.print(matrix[i][i] + " ");
        }
    }

}
public class Array
{
    public static void main(String args[])
    {
        int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
        System.out.println("Sum of 3rd and last(15th) element: " + (arr[2] + arr[14]));
    }
}