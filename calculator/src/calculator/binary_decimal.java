/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package calculator;

/**
 *
 * @author EMRUZ HOSSAIN
 */
import java.util.Scanner;
public class binary_decimal {
    public static void main(String args[]){
    Scanner input=new Scanner(System.in);
    int a=input.nextInt();
    int b=0,result=0;
    while(a>=0)
    {
    int reminder=a%10;
    a=a/10;
    b++;
    for(int i=1;i<=b;i++)
    {
        result=result+(reminder*i);
    }
    }
    System.out.println(result);}
}
