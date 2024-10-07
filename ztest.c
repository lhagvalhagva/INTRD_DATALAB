#include <stdlib.h>
#include <string.h>

int bitXor(int x, int y) {
  return ~(~(~x & y) & ~(x & ~y));
}


void printBinary(int n) {
    for (int i = 31; i >= 0; i--) {
        int bit = (n >> i) & 1;
        printf("%d", bit);
      
        if (i % 4 == 0 && i != 0) {
            printf(" ");
        }
    }
    printf("\n");
}


int tmin(void) {
  return 1  << 31;
}

int isTmax(int x) {
  return !!(x + 1) & !(~(x + 1) ^ x);
}


int main() {
    int x = 2147483647;
    // printf("%d\n" , ~(x=x-1));
    // printf("%d\n" , !(0));

    // printf("%d\n", bitXor(5, 3));
    // int m = bitXor(4,5);
    // printf("%d\n", m);
    // printf("%d\n", tmin());
    printf("%d\n", isTmax(x=x-1));
    printBinary(x);
    
}




#include <stdlib.h>
#include <string.h>

void* copy_elements(void *ele_src[], int ele_cnt, size_t ele_size) {
    if (ele_cnt < 0 || ele_size < 0) {
        return NULL;
    }

    if (ele_cnt > 0 && ele_size > 0) {
        size_t total_size = ele_cnt * ele_size;
        if (total_size < ele_cnt || total_size < ele_size) {
            return NULL; 
        }
    }

    void *result = malloc(ele_cnt * ele_size);
    if (result == NULL) {
        return NULL; 
    }

    void *next = result;
    for (int i = 0; i < ele_cnt; i++) {
        memcpy(next, ele_src[i], ele_size);
        next += ele_size;
    }
    return result; 
}



void* copy_elements(void *ele_src[], int ele_cnt, size_t ele_size) {
    void *result = malloc(ele_cnt * ele_size);
    if (result == NULL) {
        return NULL;
    }

    void *next = result;
    for (int i = 0; i < ele_cnt; i++) {
        memcpy(next, ele_src[i], ele_size);
        next += ele_size;
    }
    
    return result;
}
