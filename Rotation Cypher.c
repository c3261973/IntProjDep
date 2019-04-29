#include <stdio.h>
#include <stdlib.h>         //stdlib for exit function //

void start_menu(void);
void encrypt_file(void);
void decrypt_file(void);    //function names //
void caesar_encrypt_file;       //added new functions for caesar//

int main(int argc, char** argv)  
{
    start_menu(); //menu start//
    return 0;
}

void start_menu(void) //menu funtion block using switch for options//
{
    int choice;
        do 
        {
            printf("Menu \n\n");
            printf("1. Encrypt text file (rotation) \n");
            printf("2. Decrypt text file (rotation) \n");
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
                    default: printf("Invalid choice \n"); //incase wrong option is selected//
                        break;
                }
        }   while(choice !=3);
}
void encrypt_file(void) //rotation cypher encrption function//
{
    char input_file[20], output_file[20],ch;
    int num_ascii;
    FILE *fd1, *fd2;
    
    printf("Enter the name of the file to be encrypted: \n");
    scanf("%s", input_file); //locating the file //
    
    printf("Enter the name of the output file: \n");
    scanf("%s", output_file); //naming the output file//
    
    fd1 = fopen(input_file, "r");   //reads input file//
        if(fd1 == NULL)
        {
            printf("File does not exist.. \n");
            exit(0);        //warning if file cannot be found and using exit function//
        }
        else
        {
            fd2 = fopen(output_file, "w");      //writing to file//
            ch = fgetc(fd1);    //from input//
                while(ch != EOF)     //limits to end of file//
                {
                    num_ascii = (int)ch;
                    num_ascii = num_ascii + 3;
                    fprintf(fd2, "%c", num_ascii);
                    ch = fgetc(fd1);     //encryption//
                }
            fclose(fd2);
        }
    fclose(fd1);
    printf("Encrypted file complete, named: %s.", output_file);  //closes the files and prints new name//
    return;     //return to main//
}
void decrypt_file(void)     //rotation cypher decryption function code block - basically the same as rotation encryption//
{
    char input_file[20], output_file[20],ch;
    int num_ascii;
    FILE *fd1, *fd2;
    
    printf("Enter the name of the file to be decrypted: \n");   //changed text to decrypted instead//
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
                    num_ascii = num_ascii - 3;      //reversed the rotation amount//
                    fprintf(fd2, "%c", num_ascii);
                    ch = fgetc(fd1);
                }
            fclose(fd2);
        }
    fclose(fd1);
    printf("Decrypted file complete, named: %s.", output_file); //again changed text//
    return;     //return to main//
}

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





