#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_MAX_LEN 64

struct name_entry{
    char name[NAME_MAX_LEN + 1];
    float a;
    float b;
    int rank;
    struct name_entry *next;
};

int main(int argc, char *argv[])
{
    FILE *fp;
    int item_cnt = 0;
    struct name_entry nameCnt;  
    struct name_entry *nameEntry = NULL;  

    if(argc != 2){
       printf("Error!\n");
       exit(1);
    }
    fp = (fopen(argv[1], "r"));
    if(fp == NULL){
       printf("Error!\n");
       exit(1);
    }

    while(!feof(fp)){
        if(fscanf(fp, "%s %f %f %d", nameCnt.name, &nameCnt.a, &nameCnt.b, &nameCnt.rank) != 4)
            break;
        item_cnt++;
    }
    fseek(fp, 0, SEEK_SET);

    printf("Found %d names, allocating %d bytes\n", item_cnt, item_cnt * sizeof(struct name_entry));
    nameEntry = malloc(item_cnt * sizeof(struct name_entry));
    if(!nameEntry){
        printf("Malloc fail!\n");
        fclose(fp);
        exit(1);
    }
    item_cnt = 0;
    while(!feof(fp)){
        if(fscanf(fp, "%s %f %f %d", nameEntry[item_cnt].name, &nameEntry[item_cnt].a, &nameEntry[item_cnt].b, &nameEntry[item_cnt].rank) != 4)
            break;
        item_cnt++;
    }

    
    /* Sort the list Alphabetically */

    for(int i = 0; i < item_cnt; i ++)
    {
        printf("[%d] %s\t %f\t%f\t %d\n", i, nameEntry[i].name, nameEntry[i].a, nameEntry[i].b, nameEntry[i].rank);
    }

    free(nameEntry);
    fclose(fp);

    return 0;
}

