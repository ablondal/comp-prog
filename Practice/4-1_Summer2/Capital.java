import java.io.*;
public class Capital {
   public static void main(String[] args)throws IOException{
      char ch;
      ch=(char)System.in.read();
      while(ch!='?'){
          if('a'<=ch && 'z'>=ch) ch -= ('a'-'A');
          else if('A'<=ch && 'Z'>=ch) ch += ('a'-'A');
          System.out.print(ch);
          ch=(char)System.in.read();
      }
   }
}