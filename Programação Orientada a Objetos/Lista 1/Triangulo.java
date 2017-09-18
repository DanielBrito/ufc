class Triangulo{

	Cartesiano p1;
	Cartesiano p2;
	Cartesiano p3;

	Triangulo(int p1x, int p1y, int p2x, int p2y, int p3x, int p3y){

		this.p1 = new Cartesiano(p1x, p1y);
		this.p2 = new Cartesiano(p2x, p2y);
		this.p3 = new Cartesiano(p3x, p3y);
	}
}