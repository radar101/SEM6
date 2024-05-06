public class Temperature {
    public void convert(Integer degree) {
        Double fahrenheit = (degree * (9.0 / 5.0)) + 32.0;
        System.debug('The temperature in degree celcius' + degree);
        System.debug('The temperature in degree fahrenheit' + fahrenheit);
    } 
}