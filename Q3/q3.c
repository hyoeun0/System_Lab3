#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void recursion_dir(const char *name){
	
	DIR *dir;
	struct dirent *entry;
	char *dir_path[20];
	int i=0;
	int k=0;
	
	for(int m=0; m<20; m++)
		dir_path[m] = NULL;

	if (!(dir = opendir(name)))
		return;
		
	printf("%s: \n", name);
	while((entry = readdir(dir)) != NULL){
		if(entry -> d_type == DT_DIR){
			char path[1024];
			if(strcmp(entry->d_name, ".") == 0 || strcmp(entry -> d_name, "..")==0)
				continue;
			snprintf(path, sizeof(path), "%s/%s", name, entry -> d_name);

			dir_path[i] = strdup(path);
			i++;
			printf("%s%5s", dir_path[i-1], "");
		}
		else{
			printf("%s%5s", entry->d_name, "");
			}
		}			
		printf("\n\n");
		while(dir_path[k] != NULL){
			if(dir_path[k] == NULL) break;
			recursion_dir(dir_path[k]);
			free(dir_path[k]);
			k++;
		}
		closedir(dir);
	}
	
	int main(void){
		recursion_dir(".");
		return 0;
	}
	
