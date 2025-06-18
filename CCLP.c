/*
	CCLP Code by Arabzz-Programmer under license General Public License v3
*/
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <windows.h>

int main() {
	char* commands[10] = {"tell","makf","makd","xplr","help", "quit", "?", "cstm", "cshp", "edtf"};
	char* buffer = malloc(255);
	char* entry;
	char* message;
	char cmmnd[5];
	cmmnd[4] = '\0';
	int cmd_marker = 0;
	printf("https://github.com/Arabzz-Programmer/CCPL\n");
	printf("Version 0.0.1\n");
	while(1) {
		if(cmd_marker == 0){
		printf("> ");
		} else if(cmd_marker == 1){
		printf("$ ");
		} else if(cmd_marker == 2){
		printf("-> ");
		} else if(cmd_marker == 3){
		printf("= ");
		} else if(cmd_marker == 4){
		printf("S2 - ");
		} else if(cmd_marker == 5){
		printf("=- ");
		} else if(cmd_marker == 6){
		printf("~ ");
		} else if(cmd_marker == 7){
		printf("* ");
		} else if(cmd_marker == 8){
		printf("& ");
		} else if(cmd_marker == 9){
		printf("% ");
		} else if(cmd_marker == 10){
		printf("# ");
		} else if(cmd_marker == 11){
		printf("@ ");
		} else if(cmd_marker == 12){
		printf("! ");
		}
		fgets(buffer, 100, stdin);
		buffer[strcspn(buffer, "\n")] = '\0';
		entry = (char*) malloc(strlen(buffer)+1);
		if(entry == NULL) {
			printf("FATAL ERROR: Couldn\'t read the entry\n");
			continue;
		}
		strcpy(entry, buffer);
		for(int i = 0; i < 4; i++) {
			cmmnd[i] = entry[i];
		}
		if(strcmp(cmmnd, commands[0]) == 0) {
			int size = strlen(entry);
			if(size < 6) {
				printf("ERROR: Null string");
			} else {
				message = malloc(size - 5 + 1);
				strcpy(message, entry+5);
				printf("%s", message);
			}
			printf("\n");
		} else if (strcmp(cmmnd, commands[1]) == 0) {
			int size = strlen(entry);
			if(size < 6) {
				printf("ERROR: Null string");
			} else {
				message = malloc(size - 5 + 1);
				strcpy(message, entry+5);
				size = strlen(message);
				if(message[size-4] != '.' && message[size-3] != 't' && message[size-2] != 'x' && message[size-1] != 't') {
				printf("ERROR: Missing file type (Only supports .txt)");
				} else {
				FILE *file = fopen(message, "w");
				fclose(file);
				printf("%s created", message);
				}
			}
			printf("\n");
		} else if (strcmp(cmmnd, commands[2]) == 0) {
			int size = strlen(entry);
			if(size < 6) {
				printf("ERROR: Null string");
			} else {
				message = malloc(size - 5 + 1);
				strcpy(message, entry+5);
				size = strlen(message);
				CreateDirectory(message, NULL);
				printf("Directory %s created", message);
				}
			printf("\n");
		} else if (strcmp(cmmnd, commands[3]) == 0) {
			system("start explorer");
			printf("Explorer Initialized");
			printf("\n");
		} else if (strcmp(cmmnd, commands[4]) == 0 || strcmp(cmmnd, commands[6]) == 0) {
			printf("tell <message> - Shows a message on terminal\nmakf <file> - Makes a txt file on the same directory of the cmd\nmakd <directory> - Makes a directory on the same directory of the cmd\nxplr - Opens the windows explorer\nhelp/? - Shows this message on the terminal\nquit - Quit to the cmd\ncstm - Customize the command marker\ncshp - Custom Marker Command Help\nedtf <File-Name> <Text> - This recreates the file and it puts the text that you have written in the command");
			printf("\n");
		} else if (strcmp(cmmnd, commands[5]) == 0) {
			printf("Quitting to CMD...\n");
			free(entry);
			break;
		} else if (strcmp(cmmnd, commands[7]) == 0) {
			int size = strlen(entry);
			if(size < 3) {
				printf("ERROR: Null string");
			} else {
				message = malloc(size - 5 + 1);
				strcpy(message, entry+5);
				size = strlen(message);
				if(strcmp(message, "0")== 0) {
					cmd_marker = 0;
				} else if(strcmp(message, "1")== 0) {
					cmd_marker = 1;
				} else if(strcmp(message, "2")== 0) {
					cmd_marker = 2;
				} else if(strcmp(message, "3")== 0) {
					cmd_marker = 3;
				} else if(strcmp(message, "4")== 0) {
					cmd_marker = 4;
				} else if(strcmp(message, "5")== 0) {
					cmd_marker = 5;
				} else if(strcmp(message, "6")== 0) {
					cmd_marker = 6;
				} else if(strcmp(message, "7")== 0) {
					cmd_marker = 7;
				} else if(strcmp(message, "8")== 0) {
					cmd_marker = 8;
				} else if(strcmp(message, "9")== 0) {
					cmd_marker = 9;
				} else if(strcmp(message, "10")== 0) {
					cmd_marker = 10;
				} else if(strcmp(message, "11")== 0) {
					cmd_marker = 11;
				} else if(strcmp(message, "12")== 0) {
					cmd_marker = 12;
				} else {
					printf("Invalid Marker Mode.");
				}
			}
			printf("\n");
			free(message);
		} else if (strcmp(cmmnd, commands[8]) == 0) {
			printf("Here is the marker modes enumaration:\n0 - \"> \"\n1 - \"$ \"\n2 - \"-> \"\n3 - \"= \"\n4 - \"S2 - \"\n5 - \"=- \"\n6 - \"~ \"\n7 - \"* \"\n8 - \"& \"\n9 - \"% \"\n10 - \"# \"\n11 - \"@ \"\n12 - \"! \"\nIf you want to select anyone, you can do the command: \"cstm <Marker Mode Number>\"");
			printf("\n");
		} else if (strcmp(cmmnd, commands[9]) == 0) {
			printf("Sorry, This command ins\'t completed, We will update this soon.");
			printf("\n");
		} else {
			printf("Invalid Command, do \"?\" or \"help\"");
			printf("\n");
		}
	}
	free(buffer);
	return 0;
}
		

