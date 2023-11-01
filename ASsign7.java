/**
 * AssignmentNo7
 */
public class AssignmentNo7 {
    public static void evenOdd(int arr[]) {
        int even = 0;
        int odd = 0;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] % 2 == 0) {
                even++;
            } else if (arr[i] % 2 == 1) {
                odd++;
            }
        }
        System.out.println("Even: " + even);
        System.out.println("Odd: " + odd);
    }

    
    static int reverse(int n)
    {
        int rev = 0;
        while (n > 0) {
            int d = n % 10;
            rev = rev * 10 + d;
            n = n / 10;
        }
        return rev;
    }
    
    static boolean isPalin(int n)
    {
        return (n == reverse(n));
    }
    
    static int countDigits(int n)
    {
        int c = 0;
        while (n > 0) {
            n = n / 10;
            c++;
        }
        return c;
    }
    public static int countPalinDigits(int[] arr,int n)
    {
        
        int s = 0;
        for (int i = 0; i < n; i++) {
            if (isPalin(arr[i])) {
                s ++;
            }
        }
        return s;
    }

    public static void PrimeNo(int arr[]){
        boolean flag = false;
        int i = 2;
        int count = 0;

        for (int num : arr) {
            while (i <= num /2) {
                if (num %i ==0) {
                    flag = true;
                    break;
                }
                i++;
            }
            if(!flag){
                count++;
            }
        }
        System.out.println(count);

    }
    public static void main(String[] args) {
        int[] arr = {121,434,56,151,131,13,17,19,23};

        evenOdd(arr);

        
        int n = arr.length;
        System.out.println("Palindrome: "+countPalinDigits(arr, n));
        
        PrimeNo(arr);
       

    }

}
