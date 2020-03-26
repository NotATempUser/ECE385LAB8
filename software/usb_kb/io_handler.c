//io_handler.c
#include "io_handler.h"
#include <stdio.h>

void IO_init(void)
{
	*otg_hpi_reset = 1;
	*otg_hpi_cs = 1;
	*otg_hpi_r = 1;
	*otg_hpi_w = 1;
	*otg_hpi_address = 0;
	*otg_hpi_data = 0;
	// Reset OTG chip
	*otg_hpi_cs = 0;
	*otg_hpi_reset = 0;
	*otg_hpi_reset = 1;
	*otg_hpi_cs = 1;
}

void IO_write(alt_u8 Address, alt_u16 Data)
{

	*otg_hpi_address=Address;	//set address
	*otg_hpi_cs=0;
	*otg_hpi_w=0;						//write enable
	*otg_hpi_data=Data;			// load data
	*otg_hpi_w=1;
	*otg_hpi_cs=1;
}

alt_u16 IO_read(alt_u8 Address)
{
	alt_u16 temp;

	*otg_hpi_address= Address;	//set address to PIO block
	*otg_hpi_cs=0;
	*otg_hpi_r=0;						//enable read
	temp=*otg_hpi_data;					//load value into temp
	*otg_hpi_r=1;						//disable read
	*otg_hpi_cs=1;
	//printf("%x\n",temp);
	return(temp);
}
