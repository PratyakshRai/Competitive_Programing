import java.util.*;
public class Main{
  static boolean isPali(int n){
    String binary=Integer.toBinaryString(n);
    int l=0,h=binary.length()-1;
    while(l<h){
      if(binary.charAt(l)!=binary.charAt(h))return false;
      l++;h--;
    }
    return true;
  }
  public static void main (String[]args){
    Scanner sc=new Scanner(Sytem.in);
    int n=sc.nextInt();
    System.out.println(ispali(int n));
    sc.close();
    }
}