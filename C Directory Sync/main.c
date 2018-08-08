#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

//Takes in strings for the src file and destination file for the src file to be copied into
void copy(char *src, char *dest){
	int src_fd = open(src, O_RDONLY); //open src with readonly permissions
	int dest_fd = open(dest, O_WRONLY | O_CREAT, 0666); //open destination and either clear it if it exists or create it otherwise
	char c;
	int len;

	while((len = read(src_fd, &c, 1)) == 1){ //read through src file char by char
		if(write(dest_fd, &c, 1) != 1){ //write each char to destination file
			printf("Error copying file\n");
			exit(1);
		}
	}

	close(src_fd);
	close(dest_fd);
}

int main(int argc, char **argv)
{
	if(argc != 3){
		printf("2 arguments must be provided\n");
		exit(1);
	}
	DIR *d1, *d2;
	struct dirent *de1, *de2;
	if(!(d1 = opendir(argv[1]))){
		printf("Failed to open directory 1.\n");
		exit(1);
	}
	if(!(d2 = opendir(argv[2]))){
		printf("Failed to open directory 2.\n");
		exit(1);
	}

	int found = 0;
	while(0 != (de1 = readdir(d1))){ //loop through entries in first directory
		char filepath1[100];
		strcpy(filepath1, argv[1]);
		strcat(filepath1, "/");
		strcat(filepath1, de1->d_name);
		struct stat stat1;
		stat(filepath1, &stat1);
		if(!S_ISDIR(stat1.st_mode)){ //run if file is not a directory
			while(0 != (de2 = readdir(d2))){ //loop through entires in second directory
				if(0 == strcmp(de1->d_name, de2->d_name)){ //if file with same name found
					found = 1;
				}
			}
			char filepath2[100];
			strcpy(filepath2, argv[2]);
			strcat(filepath2, "/");
			strcat(filepath2, de1->d_name);
			//File is not found in directory b so should be copied
			if(found == 0){
				copy(filepath1, filepath2);
				printf("%s was copied to %s\n", filepath1, argv[2]);
			}
			//File is found in directory b so newer should overwrite older
			else{
				struct stat stat2;
				stat(filepath2, &stat2);
				if(0 < difftime(stat1.st_mtime, stat2.st_mtime)){ //if file in first directory is newer copy it to second directory
					copy(filepath1, filepath2);
					printf("%s was copied to %s\n", filepath1, argv[2]);
				}
				else{ //if file in second directory is newer copy it to first directory
					copy(filepath2, filepath1);
					printf("%s was copied to %s\n", filepath2, argv[1]);
				}
			}
			rewinddir(d2);
			found = 0;
		}
	}

	rewinddir(d1);
	rewinddir(d2);

	while(0 != (de2 = readdir(d2))){ //loop through second directory
		char filepath2[100];
		strcpy(filepath2, argv[2]);
		strcat(filepath2, "/");
		strcat(filepath2, de2->d_name);
		struct stat stat2;
		stat(filepath2, &stat2);
		if(!S_ISDIR(stat2.st_mode)){ //if file is not a directory
			while(0 != (de1 = readdir(d1))){ //loop through first directory
				if(0 == strcmp(de1->d_name, de2->d_name)) //if file with same name is found
					found = 1;
			}
			if(found == 0){ //if file is in second directory and not first delete it
				remove(filepath2);
				printf("%s was deleted from %s\n", de2->d_name, argv[2]);
			}
		}
		rewinddir(d1);
		found = 0;
	}

	closedir(d1);
	closedir(d2);

	return 0;
}
