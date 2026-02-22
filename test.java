class student{
  public double calculate(int t, int b){

  }
}
class scholar extends student{
  public double calculate(string s, int x){
return     super.calculate(t,b)*x
  }
}








abstract class gradecalculator{
  abstract double cal();
}
class sube extends gradecalculator{
  double gradecalculator(){
    return ;
  }
}





interface employee {
  double earnings (int bs);
  double deduction (int st);
  double ds(int y);
}
abstract class classname implements employee{
  public double earnings(double x);
  double deduction(double y);
}
class substaf extends classname{
  public bonus (double salary);
}
class fitnesstracker implements stepcount, caloriecount{

}













import java.util.*;
public class Main{
  public static void main (string []args){
    Scanner sc=new Scanner(System.in);
    String ori=sc.nextLine();
    string sub=sc.nextLine();
    int post=sc.nextLine();
    StringBuilder sb=new StringBuilder(ori);
    sb.insert(position,substring);
    sb.toString();
    sb.reverse();
  }
}







import java.util*;
import java.text*;
 class Main{
  public static void main (String []args){
    Scanner sc=new Scanner(System.in);
    String treaninput=sc.nextLine();
    String dateinput=sc.nextLine();
    try{
      if(!treaninput.matches("\\d+")){
        throw new NumberFormatException();
      }
      int treaninput=Integer.parseInt(treaninput);
      if(treaninput>1000){
        throw new NumberFormatException();
      }
      
    }
    catch (NumberFormatException e) {
      sysm.out.printf(bla bla bla );
    }
    try{
      if(!date.matches("\\d{2}/\\d{2}/\\d[4]")){
        throw new NumberFormatException();
      }
    }catch(NumberFormatException e){
      system.out.printf(bla bla bla );
    }
    Dateformat df =new Dateformat("dd/mm/yyyy");
  }
 }













import java.util.*;
calss distancetimevalidator{
  public static void main (String []args){
    Scanner sc=new Scanner(System.in);
    try{
      int n=Integer.parseInt(sc.nextLine());
      for(int i=0;i<n;i++){
        String []input=sc.nextLine().split(" ");
        if(input.length!=2){
          throw new IllegalArgumentException("input bla bla ");
        }
        float distance=Float.parseFloat(input[0]);
        validatedistance(distance);

      }
    }
    catch(NumberFormatException e){
      system.out.printf(e.getMessage());
    }
    finally{
      sc.close();
    }
  }
  public static void validatedistace(float distance) throws IllegalArgumentException{
    if(distance<0)throw new IllegalArgumentException("bal bla bla ");
  }
}










class time {
  int hours bla bla bla 
  public void settime (int t)throws invalidhoursexception, invalidminuteexception{
    if(hour<0){
      throw new invalidhoursexception("bla bla bla ");
    }
  }


}

class invalidhoursexception extends Exception{
  public invalidhoursexception(string messae){
    super(message);
  }
}












import java.io*;
import java.util.*;
public class Main {
  public static void main (String []args){
    Scanner sc=new Scanner (System.in);
    String inputfile=sc.nextLine().trim();
    String backupfile=sc.nextLine().trim();
    String reportfile=sc.nextLine().trim();
    int n =Integer.parseInt(sc.nextLine().trim());
    try(
      PrintWritter pw=new PrintWritter (new BufferedOuputStream(new FileOutputStream(inputfile)))
    ){
      for(int i=0;i<n;i++){
        pw.println(sc.nextLine());
      }
    }catch(IOExcetption e){
      System.out.println("error ",e.getMessage());
    }
    // copy to backup 
    try(
      BufferedInputStream bis =new BufferedInputStream(new FileInputStream (inputfile));
      BufferedOutputStream bos =new BufferedOutputStream(new FileOuputStream(outputfile));
    )
    {
      byte[] buffer=new byte[8192];
      int len;
      while((len=bis.read(buffer))!=-1){
        bos.write(buffer,0,len);
      }bos.flush();
    }



   int present =0,absent=0,total =0;
   try(
    BufferedReader br=new BufferedReader(new FileReader(inputfile));

   )
   String line;
   while((line=br.readLine())!=null){
    total++;
    String []parts=line.split(",");
    if(parts.length==3){
      String status=part[2].trim();
      if(status.equals("p"))p++;
      else a++;
    }
   }







  try (PrintStream report=new PrintStream (new BufferedOutputStream (new FileOutputStream(reportfile))))
{
  report.println();
}































  }
}
























































