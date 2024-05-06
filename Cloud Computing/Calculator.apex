public class Calculator {
    public void add(Integer x, Integer y) {
        Integer sum = x + y;
        System.debug('The sum is ' + sum);
    }
    
    public void sub(Integer x, Integer y) {
        Integer sub = x - y;
        System.debug('The sub is ' + sub);
    }
    
    public void mul(Integer x, Integer y) {
        Integer mul = x * y;
        System.debug('The mul is ' + mul);
    }
    
    public void div(Integer x, Integer y) {
        if(y == 0) {
            System.debug('The divisor should not be zero');
            return;
        }
        Integer div = x / y;
        System.debug('The div is ' + div);
    }
    
    public void exp(Integer x, Integer y) {
        Double result = Math.pow(x, y);
        System.debug('The result is ' + result);
    }
}