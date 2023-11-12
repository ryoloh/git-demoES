include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <linux/fb.h>

int main() {
    int fbfd, fb_size;
    unsigned char *fb_mem;

    // Mở tệp thiết bị framebuffer
    fbfd = open("/dev/fb0", O_RDWR);
    if (fbfd == -1) {
        perror("Error opening framebuffer device");
        exit(1);
    }
   // Tính toán kích thước framebuffer
    fb_size = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;

    // Ánh xạ bộ nhớ framebuffer
    fb_mem = (unsigned char*)mmap(0, fb_size, PROT_READ | PROT_WRITE, MAP_SHARE>
    if (fb_mem == MAP_FAILED) {
        perror("Error mapping framebuffer memory");
        close(fbfd);
        exit(1);
    }

    // Đọc và ghi pixel thông qua con trỏ fb_mem
    //
    // Giải phóng bộ nhớ và đóng tệp thiết bị framebuffer
    munmap(fb_mem, fb_size);
    close(fbfd);

    return 0;
}
