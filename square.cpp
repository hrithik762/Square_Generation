#include "square_boundary.h"

void video_pattern_generator(video_stream& out_stream) {
#pragma HLS INTERFACE s_axilite port = return bundle = CTRL
#pragma HLS INTERFACE axis register both port = out_stream

    ap_axiu<24,1,1,1> pixel_out;

    static int x = 0, y = 0;

    if (y == VIDEO_HEIGHT) {
        y = 0;
    }
    for (int i = 0; i < VIDEO_HEIGHT; i++) {
    		for (int j = 0; j < VIDEO_WIDTH; j++) {
    			#pragma HLS PIPELINE

    			// Start of frame, assert tuser
    			if ((i==0)&&(j==0))
    				pixel_out.user=1;
    			else
    				pixel_out.user=0;

    			//End of line, assert tlast
    			if(j==VIDEO_WIDTH-1){
    				pixel_out.last=1;
    			}
    			else{
    				pixel_out.last=0;

    			}
    // Check if the pixel is on the boundary of the square
    bool is_boundary = (
        (x >= SQUARE_X && x < SQUARE_X + SQUARE_SIZE && (y == SQUARE_Y || y == SQUARE_Y + SQUARE_SIZE - 1)) ||
        (y >= SQUARE_Y && y < SQUARE_Y + SQUARE_SIZE && (x == SQUARE_X || x == SQUARE_X + SQUARE_SIZE - 1))
    );



    if (is_boundary) {
        // Set boundary pixel color
        pixel_out.data = 0x0000ff;

    } else {
        // background color
        pixel_out.data = 0xff0000;
    }

    // Write pixel to output stream
    out_stream << pixel_out;

    // Increment pixel coordinates
    if (x == VIDEO_WIDTH - 1) {
        x = 0;
        y++;
    } else {
        x++;
    }
    			}
    		}
    }


