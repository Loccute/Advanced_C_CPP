#include <stdio.h>
#include <setjmp.h>

enum ErrorCodes { NO_ERROR, FILE_ERROR, NETWORK_ERROR, CALCULATION_ERROR };

char *error_message = "Không có lỗi!";
int exception;
jmp_buf buf;

#define TRY if ((exception = setjmp(buf)) == 0)
#define CATCH(x) else if(exception == x)
#define THROW(x, cmd)    \
    error_message = cmd;   \
    longjmp(buf, x)     

void readFile() {
    printf("Read file...\n");
    THROW(FILE_ERROR, "file error: File does not exist.\n");
}

void networkOperation() {
    printf("Network loading ...\n");
    THROW(NETWORK_ERROR, "Network error: Network does not exist.\n");
}

void calculateData() {
    printf("Perform caculation data...\n");
    THROW(CALCULATION_ERROR, "Caculate error: Failure caculation.\n");
}

void another_task()
{
    printf("Perform another task...\n");
    THROW(NO_ERROR, "No error!\n");
}

int main()
{
    while (1){
        TRY {
            printf("Please choose task you want to perform: \n");
            printf("1.Read file\n");
            printf("2.Operate Network\n");
            printf("3.Caculate Data\n");
            printf("4.Another task\n");

            unsigned int a;
            scanf("%d", &a);
            switch(a){
                case 1:
                    readFile();
                    break;
                case 2:
                    networkOperation();
                    break;
                case 3:
                    calculateData();
                    break;
                case 4:
                    another_task();
                    break;
                default:
                    printf("Task does not exist, please try again\n");
            };
        } 
        CATCH(FILE_ERROR) {
            printf("%s", error_message);
        } // Bổ sung thêm nhiều CATCH
        CATCH(NETWORK_ERROR){
            printf("%s", error_message);
        }
        CATCH(CALCULATION_ERROR){
            printf("%s", error_message);
        }
        CATCH(NO_ERROR){
            printf("%s", error_message);
        }
        
        printf("Do you want to continue: ");
        getchar();
        char c = getchar();
        
        if ((c != 'y') && (c != 'Y')) break;
        printf("\n");
    }
    
    return 0;
}
