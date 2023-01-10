class NagarVaban{
	private static NagarVaban nagarVaban = null ;

	private int policeCount;

	public static NagarVaban getNagarVaban(){
		if(nagarVaban==null) {
			nagarVaban = new NagarVaban();
			return nagarVaban;
		}
		else return nagarVaban;
	}

	private NagarVaban(){
		this.policeCount = 10;	
	}
	public void enforceLaw(){
	
	}

	public void signPaper(){
	
	}

	public void makePress(){
	
	}

	public void cleanFilths(){
	
	}
}


class Police{ 
	void doStuffs(){
		NagarVaban nagarVaban = NagarVaban.getNagarVaban();
		nagarVaban.enforceLaw();
	}
}
class Surgeon{
	void doOperation(){
		NagarVaban nagarVaban = NagarVaban.getNagarVaban();
		nagarVaban.signPaper();
	}
}
class Engineer{
	void makeBuilding(){
		NagarVaban nagarVaban = NagarVaban.getNagarVaban();
		nagarVaban.signPaper();
	}
}
class HouseOwner{
	void makeBuilding(){
		NagarVaban nagarVaban = NagarVaban.getNagarVaban();
		nagarVaban.cleanFilths();
	}
}

public class Solution{
	public static void main(String[] args){

		Police police = new Police();
	
	}
}

