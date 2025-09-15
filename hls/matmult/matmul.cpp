#include "matmul.h"

short_q_t a[4096] = {0};
long_q_t u_arr[4096] = {0};
short_q_t b[];
int GS = 64;


/* 
  data for a 7B model:
  Each set of weights (q, k, v):
    - 4096 * 4096 * 8 bits 
    - 4096 * 4096 * 32 bits / 64 (for now)
  K26 FPGA memory info:
  - UltraRAM:
    - 72 bits * 4096 * 64 total elements
    - dual port, single clock

  hardware implemenation plan
    - two sets of axi streaming: one 64 bit wide, for token and weights
    - second axis for scaling factors (tokens and weights)
    - copy in token info into BRAM/URAM, then 4 to 8 sets of weights
    - copy in sf info n to BRAM, then 4 - 8 sets of scaling factors to URAM
    - both DMA's will be blocked as we wait for each row to read out to registers
    - for loops from in to out:
      - for loop for shift registers
        - unroll
        - 16 sets
      - for loop for mult of data
        - 16 mults for now
        - 4  sets, pipeline
        - prob a temp out for loop here somewhere
      - 
  software implementation plan
    - first copy token values via dma
    - copy all three weights for that layer to memory (3 * ~134M)
    - also need to copy scaling factors for the layer ( 3 * ~8.4M)
    - tell DMA to move data (need two or 3)
    - ideally interrupt will signal when calculations are done
 */

float write_ubram(axis_data_t &b_in, axis_data_t &u_in, axis_data_t &out){
  // int s = b_in.size();
  for (int i = 0; i < 4096; i++)
  {
    float val = 0.0;
    long_q_t ival = 0;

    for (int  j = 0; j < 4096; j += GS)
    {
      for (int k = 0; k < GS; k++)
      {
        /* code */
      }
      
    }
    
  }
  
}