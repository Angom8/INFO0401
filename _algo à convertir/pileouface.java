import java.util.Scanner; 

class chiffrement {
	public static void main	(String[] args){ //pile = true, face = false
		
		Scanner clavier = new Scanner(System.in);	
		
		System.out.println("Nombre de lancers");
		
		int nbLancers = clavier.nextInt();
		
		boolean[] essais = new boolean[nbLancers];
		
		
	}
	
	public static boolean lancerPiece(){
		
		return(Math.random()>=0.5);
	
	}
	
	public static void genererEssais(boolean[] t){
		
		int i;
		
		for(i=0;i<t.length;i++){
			
			t[i] = lancerPiece();
			
		}
	
	}
	
	public static int statsEssais(boolean[] t){
		
		int i;
		int compte;
		
		for(i=0;i<t.length;i++){
			if(t[i]==true){
				compte ++;
			}
		}
		
		return((int)((t.length/compte)*100))
	
	}
	
	public static int truquer(boolean[] t){
		
		int i;
		int compte;
		
		for(i=0;i<t.length;i++){
			if(t[i]==true){
				compte ++;
			}
		}
		
		return((int)((t.length/compte)*100))
	
	}
}