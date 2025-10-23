#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include <stdlib.h>
#include <stdio.h>

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

    // Fill image with a simple gradient
    // for (int y = 0; y < height; ++y) {
    //     for (int x = 0; x < width; ++x) {
    //         int idx = (y * width + x) * channels;
    //         image[idx + 0] = (unsigned char)x;         // Red channel
    //         image[idx + 1] = (unsigned char)y;         // Green channel
    //         image[idx + 2] = (unsigned char)(x ^ y);   // Blue channel (xor pattern)
    //     }
    // }

    
    int ax =  7, ay =  3;
    int bx = 12, by = 37;
    int cx = 62, cy = 53;

    int idx = (ay * width + ax) * channels;
    image[idx + 0] = 255; // Red
    image[idx + 1] = 255;   // Green
    image[idx + 2] = 255;   // Blue

    idx = (by * width + bx) * channels;
    image[idx + 0] = 255;   // Red
    image[idx + 1] = 255; // Green
    image[idx + 2] = 255;   // Blue

    idx = (cy * width + cx) * channels;
    image[idx + 0] = 255;   // Red
    image[idx + 1] = 255;   // Green
    image[idx + 2] = 255; // Blue

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
