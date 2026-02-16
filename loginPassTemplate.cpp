#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

int checkLogin(char *login, char *passwd);
//accepted only if Length = 5 and a number 1 or more digits
int checkValidPass(char *ps);

int main() {
	char login[64], password[64];
	
	printf("Enter login : "); gets(login);
	printf("Enter password : "); gets(password);
	
	if(checkLogin(login, password) == 1) {
		printf("Welcome\n");
	}else {
		printf("Incorrect login or password\n");
	}
	
	if (checkValidPass(password)) {
		printf("Accepted\n");
	}else {
		printf("Reject\n");
	}
}

int checkValidPass(char *ps) {
	int accepted = 0, upper_value = 0, num_value = 0;
	
	if (strlen(ps) >= 5 && strlen(ps) <= 8 && !isdigit(ps[0])){
		for(int i = 1; i < strlen(ps); i++){
			if (isdigit(ps[i])){ //if have number
				num_value++;
			}
		}
		for(int j = 0; j < strlen(ps); j++){
			if (isupper(ps[j])){//if have upperchar
				upper_value++; // <<---not repeat Uppercase
			}
		}
		if(upper_value >= 2 && num_value >= 2){
			accepted = 1;
		}
	}
	
	return accepted;
}

int checkLogin(char *login, char *passwd) {
	if( !strcmp(login, "student1") && !strcmp(passwd, "mypass"))
		return 1;
	else
		return 0;
}
