#include <stdio.h>
#include <stdlib.h>

void start_menu(void);
void encrypt_file(void);
void decrypt_file(void);

int main(int argc, char** argv)  
{
    start_menu();
    return 0;
}

void start_menu(void)
{
    int choice;
        do 
        {
            printf("Menu \n\n");
            printf("1. Encrypt text file \n");
            printf("2. Decrypt text file \n");
            printf("3. Exit \n");
            scanf("%d", &choice);
                
                switch(choice)
                {
                    case 1: encrypt_file();
                        break;
                    case 2: decrypt_file();
                        break;
                    case 3: printf("Exiting program. \n");
                        exit(0);
                        break;
                    default: printf("Invalid choice \n");
                        break;
                }
        }   while(choice !=3);
}
void encrypt_file(void)
{
    char input_file[20], output_file[20],ch;
    int num_ascii;
    FILE *fd1, *fd2;
    
    printf("Enter the name of the file to be encrypted: \n");
    scanf("%s", input_file);
    
    printf("Enter the name of the output file: \n");
    scanf("%s", output_file);
    
    fd1 = fopen(input_file, "r");
        if(fd1 == NULL)
        {
            printf("File does not exist.. \n");
            exit(0);
        }
        else
        {
            fd2 = fopen(output_file, "w");
            ch = fgetc(fd1);
                while(ch != EOF)
                {
                    num_ascii = (int)ch;
                    num_ascii = num_ascii + 3;
                    fprintf(fd2, "%c", num_ascii);
                    ch = fgetc(fd1);
                }
            fclose(fd2);
        }
    fclose(fd1);
    printf("Encrypted file complete, named: %s.", output_file);
    return;
}
void decrypt_file(void)
{
    char input_file[20], output_file[20],ch;
    int num_ascii;
    FILE *fd1, *fd2;
    
    printf("Enter the name of the file to be decrypted: \n");
    scanf("%s", input_file);
    
    printf("Enter the name of the output file: \n");
    scanf("%s", output_file);
    
    fd1 = fopen(input_file, "r");
        if(fd1 == NULL)
        {
            printf("File does not exist.. \n");
            exit(0);
        }
        else
        {
            fd2 = fopen(output_file, "w");
            ch = fgetc(fd1);
                while(ch != EOF)
                {
                    num_ascii = (int)ch;
                    num_ascii = num_ascii - 3;
                    fprintf(fd2, "%c", num_ascii);
                    ch = fgetc(fd1);
                }
            fclose(fd2);
        }
    fclose(fd1);
    printf("Decrypted file complete, named: %s.", output_file);
    return;
}