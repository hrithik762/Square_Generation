#ifndef SQUARE_BOUNDARY_H
#define SQUARE_BOUNDARY_H

#include "hls_video.h"

#define VIDEO_WIDTH  1280
#define VIDEO_HEIGHT 1024
#define SQUARE_SIZE  200
#define SQUARE_X     590 // Center of the screen (1920/2 - SQUARE_SIZE/2)
#define SQUARE_Y     462 // Center of the screen (1080/2 - SQUARE_SIZE/2)

typedef hls::stream<ap_axiu<24,1,1,1> > video_stream;

void video_pattern_generator(video_stream& out_stream);

#endif
