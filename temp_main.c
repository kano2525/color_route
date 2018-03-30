#include "pgmhead.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	PIN *pin_arr = read_files("case1_pin.in");
	NET *net_arr = read_files("case1_net.in");
	BLK *blk_arr = read_files("case1_blockage.in");

	
	printf("%d\n", pin_arr[0].pin_id);
	printf("%c\n", net_arr[3].critical); 
	printf("%d\n", blk_arr[0].lower_left_x);
	printf("%d\n", net_arr[1].connected_pins[5]); 
	
	
	
	return 0;
}
