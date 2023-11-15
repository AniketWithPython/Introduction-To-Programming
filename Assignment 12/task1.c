//calculator
//user inputs numbers and operation to perform
//use function pointers

#include <stdio.h>

float add(float a, float b){    //addition
    return a + b;
}

float sub(float a, float b){    //subtraction
    return a - b;
}

float mul(float a, float b){    //multiplication
    return a * b;
}

float div(float a, float b){    //division
    return a / b;
}

float operate(float a, float b, float (*opsn)(float a, float b)){   //function which accepts pointer to a function which takes 2 float args and returns float
    return (*opsn)(a,b);
}


int main(){
    size_t c;    //choice (which is the index to function pointers array)
    float a,b;   //numbers on which to operate
    float (*arr[])(float,float) = {NULL,add,sub,mul,div};   //array of function pointers each of which takes 2 float args and returns float
    
    while(1){
        puts("Choose operation to perform and Enter Numbers  (e.g 2 9 7)");
        puts("1. Addition");
        puts("2. Subtraction");
        puts("3. Multiplication");
        puts("4. Division");
        scanf("%zu %f %f", &c, &a, &b);
        
        if (c == 4 && b == 0){    //if division by 0
            puts("ERROR: Division by 0"); 
            continue;
        }
        
        printf("%.2f\n\n", operate(a,b,arr[c])); //pass two numbers and the function pointer
                
    }
    
    



}
