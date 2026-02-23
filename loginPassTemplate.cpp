#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

int checkLogin(char *login, char *passwd);
//accepted only if Length = 5 and a number 1 or more digits
int checkValidPass(char *ps);

int main() {
	char login[64], password[64];
	
	//printf("Enter login : "); gets(login);
	//printf("Enter password : "); gets(password);
	strcpy(login, "student1");
	strcpy(password, "mTp1AAt2");	
	
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
	int accepted = 0, upper_value = 0, num_value = 0, repeat = 0;;
	char uptext[64], tmp;
	
	if (strlen(ps) >= 5 && strlen(ps) <= 8 && !isdigit(ps[0])){
		for(int i = 1; i < strlen(ps); i++){
			if (isdigit(ps[i])){ //if have number
				num_value++;
			}
		}
		for(int j = 0; j < strlen(ps); j++){
			if (isupper(ps[j])){//if have upperchar
				uptext[upper_value] = ps[j];//keep all upperchar
				upper_value++;
			}
		}
		
		//Bubble Sort
		for(int k = 0;k < upper_value;k++){
			for(int kk = k + 1;kk < upper_value;kk++){
				if(uptext[k] > uptext[kk]){
					tmp = uptext[k];
					uptext[k] = uptext[kk];
					uptext[kk] = tmp;
				}
			}
		}
		
		for(int il = 0; il < upper_value; il++){
			if(uptext[il] == uptext[il + 1]){
				repeat = 1;
			}
		}
		
		if(upper_value >= 2 && num_value >= 2 && !(repeat)){
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
