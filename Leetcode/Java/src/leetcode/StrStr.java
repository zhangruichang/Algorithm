package leetcode;


import static java.lang.System.out;

public class StrStr {
    //public static out;
    public static int strStr(String haystack, String needle) {
        if (haystack == null || needle == null || haystack.length() < needle.length()) {
            return -1;
        }
        int len_h = haystack.length();
        int len_n = needle.length();
        if (len_h == 0 && len_n == 0) {
            return 0;
        }
        long hayHash = 0;
        long needHash = 0;
        //long big = BigInteger.probablePrime(33, new Random()).longValue();
        long big = Long.MAX_VALUE;
        
        //out.println(haystack.charAt(0) + 1);
        for (int i = 0; i < len_n; i++) {
            hayHash = (hayHash * 2+ haystack.charAt(i)) % big;
            needHash = (needHash * 2+ needle.charAt(i)) % big;
        }
        if (hayHash == needHash) {
            if(haystack.substring(0, len_n).equals(needle)){
                //out.println(haystack.substring(0, len_n));
                return 0;
            }
        }
        
        long highest = 1;
        for (int j = 0; j < len_n-1 ; j++) {
                highest = (highest * 2) % big;
        }

        for (int i = len_n; i < len_h; i++) {
            long head = (long)( ((haystack.charAt(i - len_n)  * highest) % big));
            hayHash = (long)(((hayHash - head) % big * 2 % big + haystack.charAt(i)) % big);
            if (hayHash == needHash) {
                if(haystack.substring(i-len_n+1, i+1).equals(needle))
                    //out.println(haystack.substring(i-len_n+1, i+1));
                    return i - len_n + 1;
            }
            
        }
        return -1;
    }
    /**
     * @param args
     */
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        String haystack="abcdef", needle="ef";
        out.println(strStr(haystack, needle));
    }

}
