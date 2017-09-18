class testaTriangulo{

	public static void main(String[] args){

		Triangulo t = new Triangulo(1,1,3,4,5,1);

		System.out.println("Ponto A: " + t.p1.x + "," + t.p1.y);
		System.out.println("Ponto B: " + t.p2.x + "," + t.p2.y);
		System.out.println("Ponto C: " + t.p3.x + "," + t.p3.y);
	}
}