#include "ap_axi_sdata.h"
#include "hls_stream.h"

typedef ap_axiu<32, 0, 0, 0> trans_pkt;

void sadd(hls::stream< trans_pkt > &INPUT1, hls::stream< trans_pkt > &INPUT2, hls::stream< trans_pkt > &OUTPUT, unsigned int length){
//#pragma HLS INTERFACE s_axilite port=return bundle=CTRL
#pragma HLS INTERFACE s_axilite port=length bundle=CTRL
#pragma HLS INTERFACE axis port=OUTPUT
#pragma HLS INTERFACE axis port=INPUT1
#pragma HLS INTERFACE axis port=INPUT2
	trans_pkt cur1;
	trans_pkt cur2;

	for(unsigned int i=0; i<length; i++){

		INPUT1.read(cur1);
		INPUT2.read(cur2);
		cur1.data = cur1.data + cur2.data;
        OUTPUT.write(cur1);
	}
}
