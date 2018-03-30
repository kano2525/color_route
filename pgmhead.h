/*    define    #include function    */

#include <stdio.h>

/*    define constant    */

#define    MAX					 1000
#define    LOC_ARR_SIZE  		    2
#define	   MAX_LINE_LEN			   50
    	

typedef struct pin{
	int pin_id;
	int metal_layer;
	int coordinate[LOC_ARR_SIZE];
} PIN;

typedef struct net{
	int net_id;
	int connected_pins[MAX];
	char critical;
} NET;

typedef struct blockage{
	int lower_left_x, lower_left_y, top_left_x, top_left_y;
} BLK;

	void * read_files(char * file_name);


