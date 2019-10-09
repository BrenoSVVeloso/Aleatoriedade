import java.util.Scanner;
public class TP1Q2Palindromo {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		String[] entrada = new String[1000];
		int linha=0;
		
		entrada[linha] = s.nextLine();
		while(!ehIgual(entrada[linha], "FIM")){
			linha++;
			entrada[linha] = s.nextLine();
		}//fim while

		for(int i=0;i<linha;i++){
			if(ehPalindromo(entrada[i])) System.out.println("SIM");
			else System.out.println("NAO");
		}//fim for
	}//fim main()

	public static boolean ehIgual(String s1, String s2){
		boolean igual = true;
		if(s1.length()!=s2.length()) igual = false;
		else{
			int i=0;
			while(i<s1.length() && s1.charAt(i)==s2.charAt(i)){
				i++;
			}//fim for
			if(i<s1.length()) igual = false;
		}//fim if/else
		return igual;
	}//fim ehIgual()

	public static boolean ehPalindromo(String s){
	
		boolean palindromo = true;
		int i=0;
		int j=s.length()-1;
		while(i<j && (s.charAt(i)==s.charAt(j))){
				i++;
				j--;
		}//fim while
		if(i<j) palindromo=false;
		return palindromo;
	}//fim ehPalindromo()

}//fim class
