#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include <stdlib.h>
#include <stdio.h>

typedef struct RGB {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} RGB;

RGB white = {255, 255, 255};
RGB black = {0, 0, 0};
RGB red = {255, 0, 0};
RGB green = {0, 255, 0};
RGB blue = {0, 0, 255};


void set_pixel(unsigned char* image, int width, int x, int y, RGB color) {

    // the image array represented as one dimensional array, so we need to calculate the index
    // index plus 3 for RGB channels 

    int index = ((y * width) + x) * 3; // 3 channels (R, G, B)
    image[index + 0] = color.r;
    image[index + 1] = color.g;
    image[index + 2] = color.b;
}

void draw_line(unsigned char* image, int width, int height, int x0, int y0, int x1, int y1, RGB color) {

 // line formula easy x(t) = ax + (bx - ax)t

    for(float t = 0.1 ; t<1.0; t= t+ 0.1){
        int dif = x1 - x0;
        int pointX  = x0 + ((x1 - x0) * t);
        int pointY  = y0 + ((y1 - y0) * t);

        set_pixel(image,width,pointX,pointY,color);

    }
  

}
int main(void) {
    int width = 300;
    int height = 300;
    int channels = 3; // RGB

    // Allocate image buffer
    unsigned char* image = (unsigned char*)malloc(width * height * channels);
    if (!image) {
        fprintf(stderr, "Failed to allocate memory.\n");
        return 1;
    }
    
    int ax =  7, ay =  3;
    int bx = 12, by = 37;
    int cx = 62, cy = 53;

    // set_pixel(image, width, ax, ay, white);
    // set_pixel(image, width, bx, by, white);
    // set_pixel(image, width, cx, cy, white);

    draw_line(image,width,height,ax, ay, bx, by,red);
    draw_line(image,width,height,ax, ay, cx, cy,white);
    draw_line(image,width,height,bx, by, cx, cy,green);

    // Flip the image vertically before writing
    stbi_flip_vertically_on_write(1);

    // Write TGA file (uncompressed 24-bit)
    if (!stbi_write_tga("output.tga", width, height, channels, image)) {
        fprintf(stderr, "Failed to write TGA file.\n");
        free(image);
        return 1;
    }

    printf("TGA file successfully written: output.tga\n");

    free(image);
    return 0;
}
