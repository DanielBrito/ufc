public class DataHora{
	
	Data date;
	Hora hour;

	DataHora(Data date, Hora hour){

		this.date = date;
		this. hour = hour;
	}

	public String toString(){

		return date.toString() + " - " + hour.toString();
	}
}