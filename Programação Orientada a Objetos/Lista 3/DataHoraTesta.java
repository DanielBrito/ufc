public class DataHoraTesta{
	
	public static void main(String[] args) {
		
		Data data = new Data(4,1,1993);
		Hora horario = new Hora(13,20,18);

		DataHora entradaFuncionario = new DataHora(data, horario);

		System.out.println(entradaFuncionario.toString());
	}
}