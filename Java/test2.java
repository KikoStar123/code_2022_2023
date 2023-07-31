import java.util.*;

public class test2 {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int m = cin.nextInt();
        int n = cin.nextInt();
        int temp = 0;
        int nul = m * n;
        if (m < n) {
            temp = m;
            m = n;
            n = temp;
        }
        while (m * n != 0) {
            temp = m % n;
            m = n;
            n = temp;
        }
        System.out.println("max=" + (nul / m));
        System.out.println("min=" + m);
        cin.close();
    }
}
