#include "pgmhead.h"
#include <string.h>

	void * read_files(char * file_name){
		
		static PIN pin_data_list[MAX];
		static NET net_data_list[MAX];
		static BLK blk_data_list[MAX];
		
		FILE *fptr;	
		
		fptr = fopen(file_name, "r");
		if(fptr == NULL){

            printf("file does not exist.\n");
            return -1;

        }
        
        
        else if(strcmp(file_name, "case1_pin.in") == 0){
        	
        	int index = 0;
        	while (EOF != fscanf(fptr, "%d%d%d%d", &pin_data_list[index].pin_id, &pin_data_list[index].metal_layer, 
				&pin_data_list[index].coordinate[0], &pin_data_list[index].coordinate[1])){
				
				index++;
				
        	}
        	fclose(fptr);
			return pin_data_list;
		}
		
		
		else if(strcmp(file_name, "case1_net.in") == 0){
        	
        	char line[MAX_LINE_LEN];
        	int value[MAX_LINE_LEN];
        	int index = 0;        	
  			char *delim = " ";
  			char *pch;       
        	
        	
        	while (EOF != fscanf(fptr, "%d%*c%[^\n]%*c", &net_data_list[index].net_id, line)){
        		
				int i = 0;
				
				net_data_list[index].critical = line[strlen(line)-1];  			//  critical first cuz its alpha
				
					
				pch = strtok(line, delim);
					
  				while (pch != NULL){

    				value[i] = atoi(pch);
    				value[i+1] = -1;
    				pch = strtok (NULL, delim);
    				i++;
				}
				
				for(i = 0; i < sizeof(value) ; i++){
					
				  	if(value[i] == -1) break;
	  
	  				else{
	  					net_data_list[index].connected_pins[i] = value[i];
					}
				}
				
				index++;
				
        	}
        	fclose(fptr);
			return net_data_list;
		}
		
		
		else if(strcmp(file_name, "case1_blockage.in") == 0){
        	
        	int index = 0;
        	while (EOF != fscanf(fptr, "%d%d%d%d", &blk_data_list[index].lower_left_x, &blk_data_list[index].lower_left_y, 
				&blk_data_list[index].top_left_x, &blk_data_list[index].top_left_y)){

				index++;
				
        	}
        	fclose(fptr);
			return blk_data_list;
		}
		
		
		else{
			
			printf("incorrect file");
			return -1;
		}
		
		
	}

