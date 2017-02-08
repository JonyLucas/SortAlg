import java.util.Scanner;

public class RadixSort {

	
	public static void main(String[] args) {
		
	Scanner scan = new Scanner(System.in);
		
		int n = scan.nextInt();
		int[] arr = new int[n];	
		String line;	
		
		for(int i = 0; i < n; i++){
			
			line = (scan.nextLine());
			
			if(line.equals("")){
				i--;
				continue;
			}

			arr[i] = Integer.parseInt(line);
		}
		
		//System.out.println("Vetor: ");
		//exibeLista(arr);
		
		arr = radix_sort(arr);
		
		exibeLista(arr);
		
		scan.close();
			
	}
	
	public static int[] radix_sort(int[] arr){
		
		int max = Integer.MIN_VALUE;
		
		for(int i = 0; i < arr.length; i++){		
			if(arr[i] > max)
				max = arr[i];				
		}
		
		for(int dig = 1; max/dig > 0; dig *= 10){
			arr = counting_sort(arr, dig);
		}
		
		return arr;
		
	}
	
	public static int[] counting_sort(int[] arr, int dig){
		
		int[] aux = new int[arr.length];
		int[] cont = new int[10];
		cont[0] = 0;
		
		for(int i = 0; i < arr.length; i++){
			cont[(arr[i]/dig)%10]++;
		}
		
		for(int i = 1; i < 10; i++){
			cont[i] += cont[i-1];
		}
		
		for(int i = arr.length-1; i >= 0; i--){
            aux[cont[(arr[i]/dig)% 10]-1] = arr[i];
            cont[(arr[i]/dig)%10]--;			
		}
		
		arr = aux;
		
		return arr;
		
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
