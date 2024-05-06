public class Bill {
	public void calculateBill(Decimal unitRate, Decimal fixedCharges, Integer unitsConsumed) {
        Decimal totalBill = unitsConsumed * unitRate + fixedCharges;
        System.debug('The total bill is ' + totalBill);
    }
}