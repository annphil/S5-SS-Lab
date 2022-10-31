#include<stdio.h>
#include<string.h>
int i=0;
char dir[20][20];

void createFile(){
	int k;
	char file[20];
	printf("Enter file name: ");
	scanf("%s", &file);
	if(i<20){
		for(k=0; k<strlen(file); k++)
			dir[i][k] = file[k];
		i++;	
	}
}

void displayFiles(){
	int k, j;
	for(k=0; k<i; k++){
		printf("%s\n", dir[k]);
	}
}

void deleteFile(){
	char file[20], temp[20];
	int k, l;
	printf("Enter name of file to be deleted: ");
	scanf("%s", &file);
	for(k=0; k<i; k++){
		if(strcmp(file, dir[k])==0){
			dir[k][0] = '\0';
		}
	}
}

void searchFile(){
	char file[20];
	int k, flag = 0;
	printf("Enter name of file to be searched: ");
	scanf("%s", &file);
	for(k=0; k<i; k++){
		if(strcmp(file, dir[k])==0){
			flag = 1;
			break;
		}
	}
	if(flag == 1)
		printf("File Found\n");
	else
		printf("File Not Found\n");
}

//void deleteFile()

void main(){
	int y=1, c;
	while(y==1){
		printf("\nEnter choice:\n1. Create File\n2. Delete File\n3. Search File\n4. Display File\n5. Exit\n");
		scanf("%i", &c);
		switch(c){
				case 1: createFile();
						break;
				case 2: deleteFile();
						break;
				case 3: searchFile();
						break;
				case 4: displayFiles();
						break;
				case 5: y = 0;
						break;
		}
	}	
}
