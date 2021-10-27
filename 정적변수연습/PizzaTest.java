
public class PizzaTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Pizza p1 = new Pizza("Super Supreme");
		Pizza p2 = new Pizza("Cheese");
		Pizza p3 = new Pizza("Pepperoni");
		
		int n = Pizza.count;
		System.out.println("지금까지 판매된 피자 개수="+n);
	}

}
