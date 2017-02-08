import java.util.Scanner;

public class CountingSort {
	
	public static void main(String[] args) {
		
		Scanner scan = new Scanner(System.in);

		int n = scan.nextInt();
		int[] arr = new int[n];
		int max = Integer.MIN_VALUE, min = Integer.MAX_VALUE;
		String line;
		
		for(int i = 0; i < n; i++){
			
			line = (scan.nextLine());
			
			if(line.equals("")){
				i--;
				continue;
			}

			arr[i] = Integer.parseInt(line);
			
			if(arr[i] > max){
				max = arr[i];
			}
			if(arr[i] < min){
				min = arr[i];
			}
			
		}
		
		//System.out.println("Vetor: " );
		//exibeLista(arr);
		
		//System.out.println("Min: " + min + " Max: " + max);
		
		int[] cont = new int[max+1];
		int[] aux = new int[n];
		cont[0] = 0;
		
		for(int i = 0; i < n; i++){
			cont[arr[i]]++;
		}
		//exibeLista(cont);
		
		for(int i = 1; i < max+1; i++){
			cont[i] += cont[i-1];
		}
		
		//exibeLista(cont);
		
		for(int i = 0; i < n; i++){
            aux[cont[arr[i]]-1] = arr[i];
            cont[arr[i]]--;			
		}
		
		arr = aux;
		
		exibeLista(arr);

		scan.close();
	}

	
	public static void exibeLista(int []vetor){ /**Metodo para exibir a lista*/
		for(int i = 0; i < vetor.length; i++){
			System.out.println(vetor[i]);
		}
		System.out.println();
	}
	
	public static boolean ordenado(int []vetor){ /**Metodo para verificar se o array esta ordenado*/
		for (int i = 0; i < vetor.length - 1; i++){
			if(vetor[i] > vetor[i + 1]){
				System.out.println(i + " " + (i + 1));
				return false;
			}
		}
		
		return true;
	}
}
