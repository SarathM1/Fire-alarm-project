/*-----------------------------------------------------------------------------
   Program to demonstrate 4digit counter on 4-SevenSegment(CommonAnode) display
  -----------------------------------------------------------------------------
  note:
Code is for CommonAnode type of segment, fire_code[] and help_code[] must be complemented for CommonCathode
------------------------------------------------------------------------------*/

																	
/* Reg51.h contains the defnition of all ports and SFRs */
#include <reg51.h> 

#include "delay.h"	//User defined delay library which conatins the delay routines

#define SegmentValue P0
#define SegmentSlection P1

#define SegOne   0x01
#define SegTwo   0x02
#define SegThree 0x04
#define SegFour  0x08	 
#define NoSeg    0x00


void display(unsigned char seg_code[])
{						   
	unsigned char i;
								  
   for(i=0;i<100;i++)	   
   	 { 
	   
	   SegmentValue = seg_code[0];
	   SegmentSlection=SegOne;
	   delay_ms(1);
   
	   SegmentValue = seg_code[1];
	   SegmentSlection=SegTwo;
	   delay_ms(1);
 
	   SegmentValue = seg_code[2];
	   SegmentSlection=SegThree;
	   delay_ms(1);

	   SegmentValue = seg_code[3];
	   SegmentSlection=SegFour; 
	   delay_ms(1);

	   //SegmentValue = NoSeg; // to turn off all segments
	  }
 }
/* start the main program */
void main() 
{
    unsigned char fire_code[]={0x71,0x06,0x50,0x79},help_code[]={0x76,0x79,0x38,0x73};
   while(1)
    {
          display(fire_code);
	    	delay_sec(1);

           //display(help_code);
	    	//delay_sec(1);
	  }																			 
  }										