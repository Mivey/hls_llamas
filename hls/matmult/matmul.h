#include "ap_int.h"
#include "ap_axi_sdata.h"
#include "hls_task.h"
#include "ap_float.h"
#include "ap_stream.h"

#define DATAWIDTH 32

typedef int8_t short_q_t;
typedef int32_t long_q_t;
typedef hls::stream<long_q_t> axis_data_t;