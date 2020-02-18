import java.util.Scanner; 

class chiffrement {
	public static void main	(String[] args){
		
		Scanner clavier = new Scanner(System.in);	
		
		System.out.println("");
		
		System.out.println("Entrez le nombre de caracteres du mot :");
		
		int n = clavier.nextInt();
		
		char[] mot = new char[n];
		
		initialiserMot(mot);
		
		System.out.println("Le mot entr\u00e9 est :");
		
		afficherMot(mot);
		
		System.out.println("");
		
		char[] chiffre = chiffrer(mot);
		
		System.out.println("Le mot chiffr\u00e9 est :");
		
		afficherMot(chiffre);
		
		System.out.println("");
		
		System.out.println("Le mot d\u00e9crypt\u00e9 est :");
		
		dechiffrer(chiffre);
		
		afficherMot(chiffre);
		
		decroissant(chiffre);
		
		System.out.println("");
		
		System.out.println("Le mot ordonn\u00e9 est :");
		
		System.out.println("");
		
		afficherMot(chiffre);
	}
		
	public static void initialiserMot	(char[] t){
		
		int i;
		
		String s;
		
		Scanner clavier = new Scanner(System.in);
		
		System.out.println("Entrez le mot :");
		
		s = clavier.nextLine();
		
		while(verif(s)==false){
					
			System.out.println("Erreur ! Le mot ne doit contenir que des lettres minuscules !");
			
			s = clavier.nextLine();
		}
		
		for (i=0;i<t.length;i++){
			
			t[i] = s.charAt(i);
			
		}
	
	}
	
	public static boolean verif (String s){ //minuscule lettre uniquement
		
		int i = 0;
		
		boolean verif = true;
		
		while((i<s.length())&&verif!=false){
			
			if(s.charAt(i)<'a'|s.charAt(i)>'z'){
				verif = false;
			}
			
			i ++;
		}
		
		
		return(verif);
	
	}
	
	public static void afficherMot (char[] t){ 
		
		int i;
		
		for(i=0;i<t.length;i++){
			System.out.print(t[i]);
		}
			
	
	}
	
	public static char[] chiffrer (char[] t){ 
		
		int i;
		
		char[] chiffre = new char[t.length];
		
		for(i=0;i<t.length;i++){
			if(t[i]>'y'){
				chiffre[i] = 'a';
			}
			else{
			chiffre[i] = (char)(t[i] + 1);
			}
		}
		
		char a = chiffre[t.length-1];
		for(i=(chiffre.length-1);i>0;i--){
			chiffre[i] = chiffre[i-1];
		}
		chiffre[0] = a;
		
		return(chiffre);
			
	}
	
	public static void dechiffrer (char[] chiffre){ 
		
		int i;
		
		
		char a = chiffre[0];
		for(i=1;i<chiffre.length;i++){
			chiffre[i-1] = chiffre[i];
		}
		chiffre[chiffre.length-1] = a;
		
		for(i=0;i<chiffre.length;i++){
			if(chiffre[i]=='a'){
				chiffre[i] = 'z';
			}
			else{
			chiffre[i] = (char)(chiffre[i] - 1);
			}
		}
		
	}
	
	public static void decroissant (char[] t){ 
	
		int i;
		int g;
		char a;
		
		for(i=0;i<t.length;i++){
			g = i;
			while(g<t.length-1&&t[g]<=t[i]){
				g ++;
				if(t[g]>t[i]){
					a = t[g];
					t[g] = t[i];
					t[i] = a;
				}
			}
		}
		
	}
}