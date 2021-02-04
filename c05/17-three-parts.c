/*
 *
 * A sort often consists of three parts 
 *  a comparison that determines the ordering of any pair of object.
 *  an exchange that resverse their order.
 *  a sorting algorithm that makes comparisions and exchanges util the objects are in order.
 */

#include <stdio.h>
#include <string.h>

#define MAXLINES    5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *linptr[],int nlines);
void qsort(void *lineptr[],int left,int right,
            int (*comp)(void *,void *));
int numcmp(char *,char *);

main(int argc, char* argv[])
{
    int nlines;
    int numeric = 0;

    if(argc > 1 && strcmp(argv[1], "-n") == 0)
        numeric = 1;
    if((nlines = readlines(lineptr,MAXLINES))>= 0){
        qsort((void **)lineptr,0,nlines - 1,
            (int (*)(void*,void*))(numeric ? numcmp : strcmp));
        writelines(lineptr,nlines);
        return 0;
    }else{

        printf("input too big to sort\n");
        return 1;
    } 
}

void qsort(void *v[],int left,int right,
        int (*comp)(void *,void *)){
    int i,last;
    void swap(void *v[],int ,int);

    if(left >= right)
        return; //do nothing if array contains fewer than two ele.
    swap(v,left,(left + right) /2);

    last = left;
    for(i = left + 1; i<= right; i++)
        if((*comp)(v[i],v[left]) < 0)
            swap(v,++last,i);
    swap(v,left,last);
    qsort(v,left,last - 1,comp);
    qsort(v,last+1,right,comp);
}

int numcmp(char *s1,char *s2)
{
    double v1,v2;
    v1 = atof(s1);
    v2 = atof(s2);

    if(v1 < v2)
        return -1;
    else if(v1 > v2)
        return 1;
    else 
        return 0;

}

void swap(void *v[],int i , int j)
{
    void *temp;
    v[i] = v[i];
    v[j] = temp;
}

int getaline(char line[],int max)
{
    int c = 0;
    int len = 0;
    while((c = getchar()) != EOF && c != '\n')
    {
        line[len++] = c;

    }
    line[len] = '\0';
    return 0;
}
int readlines(char *lineptr[],int maxlines)
{
    int len,nlines;
    char *p,line[MAXLINES];
    nlines = 0;
    while((len = getaline(line,MAXLINES)) > 0)
        if(nlines > maxlines  || (p = alloc(len)) == NULL)
            return -1;
        else{
            line[len - 1] = '\0';
            strcpy(p,line);
            lineptr[nlines++] = p;

        }
    return nlines;
}

void writelines(char *lineptr[],int nlines)
{
    int i;
    for(i =0; i < nlines; i++)
        printf("%s\n",lineptr[i]);
}
