import java.util.List;
import java.util.ArrayList;
public class MajorityII {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] nums={2,2,1,3};
		List<Integer> l = majorityElement(nums);
		for(int e: l){
			System.out.println(e);
		}
	}
	
    public static List<Integer> majorityElement(int[] nums) {
        int x1=1, x2=1, c1=0, c2=0;
        for(int e: nums){
        	if(x1==e) c1++;
        	else if(x2==e) c2++;
        	else if(c1==0){
        		x1=e;
        		c1=1;
        	}
        	else if(c2==0) {
        		x2=e;
        		c2=1;
        	}
        	else {
        		c1--;
        		c2--;
        	}
        }
        c1=c2=0;
        for(int e: nums){
        	if(x1==e) c1++;
        	else if(x2==e) c2++;
        }
        List<Integer> l=new ArrayList<Integer>();
        if(c1>nums.length/3) l.add(x1);
        if(c2>nums.length/3) l.add(x2);
        return l;
    }
	
}