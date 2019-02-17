#include <stdio.h>
#include <stdlib.h>

struct nodes{
    int k;
    int curchar;
    struct nodes * left, *right;
};
//bubble-sort
void sort(struct  nodes n[256],int z){
    for(int i = 0 ; i < z - 1; i++) {
        for(int j = 0 ; j < z - i - 1 ; j++) {
            if(n[j].k < n[j+1].k) {
                struct nodes tmp = n[j];
                n[j] = n[j+1] ;
                n[j+1] = tmp;
            }
        }
    }
}
struct nodes create_nodes(struct nodes * right, struct nodes * left ){

    struct nodes a;
    a.curchar;//TODO написать два символа один за другим либо придумать хэш для строки
    a.k = right->k + left->k;
    a.left = left;
    a.right = right;

    return a;
}

int main() {
    struct nodes  n[256];
    //Init nodes in array
    for(int i = 0; i<256; i++){
     n[i].curchar = i;
     n[i].k = 0;
     n[i].left = NULL;
     n[i].right = NULL;
    }
    //Check what will we do
    char c = (char)getchar();
    getchar();
    if(c == 'c') {
        
        int symb;
        while ((symb = getchar()) != '\n') {
            n[symb].k++;
        }

        sort(n, 256);


        for (int i = 0; i < 256; i++) {
            printf("%i ", n[i].k);
        }

        int itter = 0;
        while (n[itter].k != 0) {
            itter++;
        }

        int first = itter - 1, second = first - 1;

        while (first != 0) {
            struct nodes *a = malloc(sizeof(struct nodes));
            *a = n[first];
            struct nodes *b = malloc(sizeof(struct nodes));
            *b = n[second];

            n[second] = create_nodes(a, b);

            sort(n, first);

            first = first - 1;
            second = second - 1;
        }

        struct nodes *k = &n[0];
        while (k!=NULL){
        printf("%i ", k->k);
        k = k->left;
    }

    free(k);


    }
    return 0;
}