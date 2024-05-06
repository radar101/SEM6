public class Greatest {
    public void great(Integer a, Integer b, Integer c) {
        if(a!=0 && b!=0 && c!=0) {
            Integer maxi = Math.max(a, Math.max(b,c));
            System.debug('The value of maximum number is' + maxi);
        }
    }
    
    public void another_great(Integer a, Integer b, Integer c) {
        if(a!=0 && b!=0 && c!=0) {
            if(a>=b && a>=c) {
				System.debug('The maximum number is a');
            } else if (b>=a && b>=c) {
				System.debug('The maximum number is b');
            } else {
				System.debug('The maximum number is c');
            }
		}
    }
}