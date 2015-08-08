
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class JavaDataType {

  static BufferedReader in;
  static PrintWriter out;
  static StringTokenizer tok;

  static void solve() throws Exception {
    int t=nextInt();
    while(t-->0){
        String s=next();
    	StringBuilder ans=new StringBuilder();
    	//out.println(s+" can be fitted in:");
    	boolean ok=false;
    	try{
    		long x=Byte.parseByte(s);
    		if(Byte.MIN_VALUE<=x && x<=Long.MAX_VALUE  ){
    			ans.append("* byte\n");
    			ok=true;
    		}
    	}catch(NumberFormatException e){}
    	try{
    		Short x=Short.parseShort(s);
    		if(Short.MIN_VALUE<=x && x<=Short.MAX_VALUE  ){
    			ans.append("* short\n");
    			ok=true;
    		}
    	}catch(NumberFormatException e){}
    	try{
    		int x=Integer.parseInt(s);
    		if(Integer.MIN_VALUE<=x && x<=Integer.MAX_VALUE  ){
    			ans.append("* int\n");
    			ok=true;
    		}
    	}catch(NumberFormatException e){}	
    	try{
    		long x=Long.parseLong(s);
    		if(Long.MIN_VALUE<=x && x<=Long.MAX_VALUE  ){
    			ans.append("* long\n");
    			ok=true;
    		}
    	}catch(NumberFormatException e){}
    	if(ok){
    		out.println(s+" can be fitted in:\n"+ans.toString().trim());
    	}else{
    		
    		out.println(s+" can't be fitted anywhere.");
    	}
    }
  }

  public static void main(String args[]) {
    try {
      in = new BufferedReader(new InputStreamReader(System.in));
      out = new PrintWriter(new OutputStreamWriter(System.out));
      solve();
      in.close();
      out.close();
    } catch (Throwable e) {
      e.printStackTrace();
      System.exit(1);
    }
  }

  static int nextInt() throws IOException {
    return Integer.parseInt(next());
  }

  static int[] nextIntArray(int len, int start) throws IOException {
    int[] a = new int[len];
    for (int i = start; i < len; i++)
      a[i] = nextInt();
    return a;
  }

  static long nextLong() throws IOException {
    return Long.parseLong(next());
  }

  static long[] nextLongArray(int len, int start) throws IOException {
    long[] a = new long[len];
    for (int i = start; i < len; i++)
      a[i] = nextLong();
    return a;
  }

  static String next() throws IOException {
    while (tok == null || !tok.hasMoreTokens()) {
      tok = new StringTokenizer(in.readLine());
    }
    return tok.nextToken();
  }

}
