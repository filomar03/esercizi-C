#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[32];
    int rating;
} Hotel;

int rateHotel(const char * filename) {
    FILE * stream = fopen(filename, "r");

    if (stream == NULL) return -1;

    char line[32];
    fscanf(stream, "%s", line);

    int m1 = 0, m2 = 0, m3 = 0;
    int i = 0;

    while (!feof(stream)) {
        int a1, a2, a3;
        fscanf(stream, "%d %d %d\n", &a1, &a2, &a3);

        m1 += a1;
        m2 += a2;
        m3 += a3;

        i++;
    }

    fclose(stream);

    return (int) ((m1 + m2 + m3) / (float) i);
}

char * getHotelName(const char * fileName, char * to) {
    FILE * stream = fopen(fileName, "r");
    if (stream == NULL) return NULL;

    char hotelName[32];
    fscanf(stream, "%s", hotelName);

    fclose(stream);
    
    return strcpy(to, hotelName);
}

Hotel * cloneHotel(const Hotel * from) {
    Hotel * hotel = malloc(sizeof(Hotel));

    if (hotel == NULL) return NULL;

    hotel->rating = from->rating;
    strcpy(hotel->name, from->name);

    return hotel;
}

Hotel * incubo(const char * filename) {
    FILE * stream = fopen(filename, "r");

    if (stream == NULL) return NULL;

    char line[32];
    Hotel hotels[50];

    int i = 0, ni = 0;
    while (!feof(stream)) {
        fscanf(stream, "%s", line);

        hotels[i].rating = rateHotel(line);
        getHotelName(line, hotels[i].name);
        
        if (i != 0) {
            if (hotels[i].rating < hotels[ni].rating) {
                ni = i;
            }
        }
        
        i++;
    }

    fclose(stream);

    return cloneHotel(&hotels[ni]);
}

int main(int argc, const char * argv[]) {
    if (argc != 2) {
        printf("Pass index file name as argument.\n");
        return 1;
    }

    Hotel *hotel = incubo(argv[1]);

    if (hotel == NULL) return 2;

    printf("Worst hotel\n - Name: %s.\n - Rating: %d.\n", hotel->name, hotel->rating);
    
    free(hotel);

    return 0;
}