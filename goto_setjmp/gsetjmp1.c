#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;
int exception_code;
char *error_code = NULL;

#define TRY if ((exception_code = setjmp(buf)) == 0) 
#define CATCH(x) else if (exception_code == (x))
#define THROW(x, cmd)   \
    error_code = cmd;   \
    longjmp(buf, (x));


double divide(int a, int b) {
    if (a != 0 && b == 0){
        THROW(1, "Error: Divide by 0!\n");
    }
    if (a == 0 && b == 0) {
        THROW(2, "Error: Khong ton tai\n");
    }
    return (double)a / b;
}

int main() {
    int a = 20;
    int b = 0;
    double result = 0.0;

    TRY {
        result = divide(a, b);
        printf("Result: %f\n", result);
    } 
    CATCH(1){
        printf(error_code);
    }
    CATCH(2){
        printf(error_code);
    }


    // Các xử lý khác của chương trình
    return 0;
}
