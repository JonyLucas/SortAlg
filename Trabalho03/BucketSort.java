import java.util.*;
import java.math.*;

public class BucketSort {
	
	private static HashMap <Integer, ArrayList<Integer>> buckets = new HashMap<Integer, ArrayList<Integer>>();
	
	public static void main(String[] args) {
		
		Scanner scan = new Scanner(System.in);

		int n = scan.nextInt();
		ArrayList<Integer> arr = new ArrayList<Integer>();
		int max = Integer.MIN_VALUE, min = Integer.MAX_VALUE, num;
		String line;
		
		for(int i = 0; i < n; i++){
			
			line = (scan.nextLine());
			
			if(line.equals("")){
				i--;
				continue;
			}

			num = Integer.parseInt(line);

			arr.add(num);
			
			if(arr.get(i) > max){
				max = arr.get(i);
			}
			if(arr.get(i) < min){
				min = arr.get(i);
			}
			
		}
		
		/*System.out.println("Vetor: " + arr);
		
		System.out.println("Min: " + min + " Max: " + max);
		
		System.out.println("Digite o numero de baldes: ");*/

		int B = n/2; /**Numero de baldes*/

		
		for(int i = 0; i < B; i++){
			buckets.put(i, new ArrayList<Integer>());
		}
		
		//System.out.println("Buckets: " + buckets);


		int offset = 0;

		if(min < 0)
			offset = Math.abs(min);

		
		int div = (int)Math.ceil((max + offset + 1f)/B);
		
		//System.out.println("Divider: " + div);
		
		System.out.println("Offset: " + offset);

		arr = bucket_sort(arr, div, offset);
		
		//System.out.println("Vetor ordenado: " + arr);

		exibeLista(arr);
		
		scan.close();
	}
	
	public static ArrayList<Integer> bucket_sort(ArrayList<Integer> arr, int div, int offset){
		
		ArrayList<Integer> arr_ord = new ArrayList<Integer>();
		for(int i = 0; i < arr.size(); i++){
			int j = (int) Math.floor((arr.get(i)+offset)*1.0/div);
			buckets.get(j).add(arr.get(i));
		}
		
		//System.out.println("Buckets: " + buckets);
		
		for(Integer key : buckets.keySet()){
			insertion_sort(buckets.get(key));
			arr_ord.addAll(buckets.get(key));
		}
		
		//System.out.println("Buckets ordenados: " + buckets);
		//System.out.println(arr_ord);

		return arr_ord;
		
	}
	
	public static void insertion_sort(ArrayList<Integer> arrayList){
		int i, j, aux, n = arrayList.size();
		
		for(i = 1; i < n; i++){
			aux = arrayList.get(i);
			for(j = i - 1; j >= 0 && arrayList.get(j) > aux; j--){
				arrayList.set(j+1, arrayList.get(j));
			}
			arrayList.set(j+1, aux);
		}
	}	

	
	public static boolean ordenado(ArrayList <Integer>vetor){ /**Metodo para verificar se o array esta ordenado*/
		int res = 0;
		for (int i = 0; i < vetor.size() - 1; i++){
			if(vetor.get(i) > vetor.get(i+1)){
				//System.out.println(vetor.get(i) + " " + vetor.get(i + 1));
				return false;
			}
		}

		return true;
	}

	public static void exibeLista(ArrayList <Integer>vetor){ /**Metodo para exibir a lista*/
		for(int i = 0; i < vetor.size(); i++){
			System.out.println(vetor.get(i));
		}
	}
}
