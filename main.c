#include <stdint.h>
#include <malloc.h>

#define MIN_TID 300
#define MAX_TID 5000

//Task 1 Question A
typedef struct bitmap{
    uint8_t *bits;
    size_t size_in_bytes;
    size_t occupied;
} bitmap_t;

bitmap_t *map;

int main() {
    /*
     *      Data structures options:
     *  Bitmap, implement queue to avoid bigO(N) complexity on freed locations
     *
     * */


}

//
int allocate_map (void)
{
    map = malloc(sizeof(bitmap_t));
    if(map == NULL)
        return -1;

    map->occupied = 0;
    map->size_in_bytes = MAX_TID-MIN_TID;

    map->bits = calloc(map->size_in_bytes, sizeof(uint8_t));
    if(map->bits == NULL)
        return -1;

    return 1;
}
