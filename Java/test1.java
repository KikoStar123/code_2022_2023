import java.util.*;

public class test1 {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int a = cin.nextInt();// 输入一个整数
        System.out.println(a);
        double b = cin.nextDouble();// 输入一个双精度的浮点数
        System.out.println(b);
        String str = cin.next();// 输入一个单词，遇到分号则输入终止
        System.out.println(str);
        String str2 = cin.nextLine();// 输入一行，中间可有多个空格
        System.out.println(str2);
        cin.close();
    }

}