//Sources Used: Goldbach's Conjecture definition: https://en.wikipedia.org/wiki/Goldbach%27s_conjecture
//Goldbach's Code idea stems from: https://dev.to/hakan/goldbach-conjecture-and-a-simple-approach-in-c-56b0
//Primality Test optimization: https://gist.github.com/CarterA/1587394

#include <stdio.h>
#include <stdbool.h> //need true and false for the function bellow
bool prime_c (long long n) {                 //prime checker
    if (n <=1){
        return false;
    }
    for (long long int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
    return true;
    
}
void goldbach(long long g){
    long long i = 2;

    for (long long j = g-i; j > 2; j--){
    
        if(prime_c(i) == 1 && prime_c(j) == 1){
        
            printf("%lld = %lld + %lld\n",g,i,j);
            break;
        }
        i++;
    }
}          
int main(void){

    char tot = '\0'; // tos = type of test
    long long num = 0; // preassigning a variable to an accepted one
    while(true){     //while loop set to true as the only quit condition is user error input
        printf("Give me a number "); //ask for user input 
        if (scanf("%lld", &num) != 1) {
            printf("Invalid input: expected an integer\n");
            return 1; //if the scanf isnt true therrefore 1 and also not an interger, it returns 1 as required
        }
        if (num > 10000000000LL || num < 0) { // checks whether or not the num is in the range we want it to be
            printf("Number should be in the range [0, 10000000000]\n");
            return 1; 
        }
        printf("Choose how to test %lld - ('p' for prime, 'g' for goldbach)", num); //ask user how we want his number to be used in a equation
        if (scanf(" %c", &tot) != 1) { //space is so it doesnt eat input
            printf("Invalid choice: expected 'p' or 'g'\n");
            return 1;
        }
        
        if (tot != 'p' && tot != 'g' && tot != 'P' && tot != 'G'){ //checks if tot is any of the accepted answers
            printf("Invalid choice: expected 'p' or 'g'\n");
            return 1;
        }
        if (tot == 'p' || tot == 'P') {
            if (prime_c(num)){
                printf("%lld is prime\n", num);
            }else {
                printf("%lld is not prime\n", num);
            }
        }
            
        if (tot == 'g' || tot == 'G') { //checking whether or not num is 2 or less and if its even
            if (num % 2 == 1){
                printf("Goldbach's conjecture is applicable only to even numbers greater than 2!\n");
            }
            else if(num<=2){
                printf("Goldbach's conjecture is applicable only to even numbers greater than 2!\n");

            }else {
                goldbach(num);
            }
            
            
        }

    }
    
   

    

    return 0;
}





