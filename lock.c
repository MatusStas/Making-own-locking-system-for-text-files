#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//Function checks if file obtains '#password' in the 1st row of file -> if it's locked
//second row is hidden password we will need to type to unlock our file
int is_locked(FILE *fr, char *file_password) {
	char row[20];							//maximum lenght of file is 20 characters

	fr = fopen("text_file.txt","r");		//opening file
	fgets(row,20,fr);						//getting 1st row of file (#password)
	row[strlen(row)-1] = '\0';

	if(strcmp(row,"#password") == 0) {		//comparing 1st row with text '#password', if math = locked file
		fgets(file_password,20,fr);
		file_password[strlen(file_password)-1] = '\0';
		file_password = (char *) realloc(file_password, strlen(file_password)+1);
		return 1;
	}
	fclose(fr);
	return 0;
}


void get_password(char *password) {			//entering password
	fgets(password,20,stdin);
	password[strlen(password)-1] = '\0';
	password = (char *) realloc(password, strlen(password)+1);
}


int show_file(FILE *fr, char *file_password, char *password) {		//this function show us entire file
	fr = fopen("text_file.txt","r");								//if is locked, it will ask for password
	int sign;
	int counter = 0;

	is_locked(fr,file_password);									//checking if locked file

	if(strlen(file_password) == 0) {
		while((sign = getc(fr)) != EOF) {
			printf("%c", sign);
		}
		fclose(fr);
		return 0;
	}
	printf("File is locked, please enter here password [MAX 20 characters]\n");
	get_password(password);

	if(strcmp(file_password,password) == 0) {						//comparing entered text with password
		while((sign = getc(fr)) != EOF) {							//if matched = shows whole file
			if(sign == '\n'){counter++;}
			if(counter > 1) {
				putchar(sign);
			}
		}
		fclose(fr);
		return 0;
	}
	else{printf("Your password doesn't match. Try again.\n");}		//if not matched, T R Y   A G A I N
}


int main() {
	FILE *fr = NULL;
	char *password = (char *) malloc(20*sizeof(char));
	char *file_password = (char *) malloc(20*sizeof(char));

	show_file(fr,file_password,password);
	return 0;
}