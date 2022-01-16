/* 
Caculator for Array 
Wu Shurang PB21000179
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//init
struct configVar{
    int arrayLength;   
    int numsPerLine;
    char splitChar;
}cv;
int arrayLength = 10;   //Global - length of array
int numsPerLine = 5;    //Global - nums of element per line
char splitChar = '\t';  //Global - char for split elements
void printMenu();
void clearCache();
void config(struct configVar cv);
void printArray(int a[], int n);
void fillArray(int a[], int n, int fillType, int var1, int var2);
void config(struct configVar cv);
int deleteElementById(int a[], int n, int id);
int deleteElementByVal(int a[], int n, int val);
int deleteRange(int a[], int n, int begin, int end); //FIRST CHOOSE
int insert(int a[], int n, int pos, int val);
int orderInsert(int a[], int n, int val);
int maxValue(int a[], int n);//SECOND CHOOSE
int minValue(int a[], int n);
float average(int a[], int n);
// s,theta
void findValue();
//int isAsc(int a[], int n);
//int isDesc(int a[], int n);
//int isEqual(int a[], int n);
void bubbleSort(int a[],int n);
void selectSort(int a[], int n);
void exchangeSort(int a[], int n);
//void arrayReverse(int a[], int n);
//void leftRotate(int a[], int n, int m);
//void RightRotate(int a[], int n, int m);
int search(int a[], int n, int val);
int biSearch(int a[], int n, int val);
int Search1(int a[], int n, int val);
//void joseph(int a[], int n, int m);
//void primeByFilter(int a[], int n);
int main(){
    int a[arrayLength];
    char ch, ch1;
    while(1){
        printMenu();
        printf("Please choose (Enter the num):\n");
        scanf("%c",&ch);
        clearCache();
        if(ch == '0')
            break;
        switch (ch){
            case '1':
                printf("Please enter the modify values [Length of array, numsPerLine, char for split elements]:\n");
                scanf("%d%d%c", &cv.arrayLength, &cv.numsPerLine, &cv.splitChar);
                config(cv);
                clearCache();
                break;
            case '2':
                while(1){
                    printf("-----Please Choose-----\n");
                    printf("0) Exit submenu\n");
                    printf("1) Fill the array with random numbers within a range\n");
                    printf("2) Fill the array through the key board\n");
                    printf("3) Fill the array with the same value (1)\n");
                    printf("4) Fill the array by a arithmetic sequence (Please enter a1, d):\n");
                    printf("-----------------------\n");
                    scanf("%c", &ch1);
                    clearCache();
                    if(ch1 == '0')
                        break;
                    switch (ch1){
                        case '1':
                            printf("Please enter the range (min, max):\n");
                            int c,b;
                            scanf("%d%d", &c, &b);
                            fillArray(a, arrayLength, 1, c, b);
                            break;
                        case '2':
                            fillArray(a, arrayLength, 2, 0, 0);
                            break;
                        case '3':
                            fillArray(a, arrayLength, 3 ,1 ,0);
                            break;
                        case '4':
                            fillArray(a, arrayLength, 4, 1, 3);
                            break;
                        default:
                            break;
                    }
                    clearCache();
                }
                break;
            case '3':
                printf("Printed Array:\n");
                printArray(a, arrayLength);
                printf("\n");
                break;
            case '4':
                while(1){
                    printf("-----Please Choose-----\n");
                    printf("0) Exit submenu\n");
                    printf("1) Delete element by id\n");
                    printf("2) Delete element by value\n");
                    printf("3) Delete element within a range\n");
                    printf("-----------------------\n");
                    scanf("%c", &ch1);
                    clearCache();
                    if(ch1 == '0')
                        break;
                    switch (ch1){
                        case '1':
                            printf("Please enter id of the element that should be deleted (id counted from 0):\n");
                            int t0;
                            scanf("%d", &t0);
                            while(t0 >= arrayLength || t0 < 0){
                                printf("Please enter id of the element that should be deleted:\n");
                                scanf("%d", &t0);
                            }
                            arrayLength = deleteElementById(a, arrayLength, t0);
                            break;
                        case '2':
                            printf("Please enter value of the element that should be deleted:\n");
                            int t1;
                            scanf("%d", &t1);
                            arrayLength = deleteElementByVal(a, arrayLength, t1);
                            break;
                        case '3':
                            printf("Please enter the range that should be deleted:\n");
                            int t2;
                            scanf("%d%d", &t1, &t2);
                            arrayLength = deleteRange(a, arrayLength, t1, t2);
                            break;
                        default:
                            break;
                    }
                    clearCache();
                }
                break;
            case '5':
                while(1){ 
                    printf("-----Please Choose-----\n");
                    printf("0) Exit submenu\n");
                    printf("1) Insert element by id\n");
                    printf("2) Insert element in a sorted array\n");
                    printf("-----------------------\n");
                    scanf("%c", &ch1);
                    clearCache();
                    if(ch1 == '0')
                        break;
                    switch (ch1){
                        case '1':
                            printf("Please enter id and value of the element that should be insert(id counted from 0):\n");
                            int t0,t1;
                            scanf("%d%d", &t0, &t1);
                            while(t0 > arrayLength || t0 < 0){
                                printf("Please enter id of the element that should be insert:\n");
                                scanf("%d", &t0);
                            }
                            arrayLength = insert(a, arrayLength, t0, t1);
                            printf("Inserted %d.\n", t1);
                            break;
                        case '2':
                            printf("Please enter the value of the element that should be insert\n(Please ensure this is a sorted array):\n");
                            scanf("%d", &t0);
                            arrayLength = orderInsert(a, arrayLength, t0);
                            printf("Inserted %d.\n", t0);
                            break;
                        default:
                            break;
                    }
                    clearCache();
                }
                break;
            case '6':
                while(1){ 
                    printf("-----Please Choose-----\n");
                    printf("0) Exit submenu\n");
                    printf("1) Get Max\n");
                    printf("2) Get Min\n");
                    printf("3) Get Avg\n");
                    printf("-----------------------\n");
                    scanf("%c", &ch1);
                    clearCache();
                    if(ch1 == '0')
                        break;
                    switch (ch1){
                        case '1':
                            printf("The Maximum is %d. (Please press ENTER)\n", maxValue(a, arrayLength));
                            break;
                        case '2':
                            printf("The Minimum is %d. (Please press ENTER)\n", minValue(a, arrayLength));
                            break;
                        case '3':
                            printf("The Average is %f. (Please press ENTER)\n", average(a, arrayLength));
                            break;
                        default:
                            break;
                    }
                    clearCache();
                }
                break;
            case '7':
                while(1){ 
                    printf("-----Please Choose-----\n");
                    printf("0) Exit submenu\n");
                    printf("1) Bubble Sort\n");
                    printf("2) Select Sort\n");
                    printf("3) exchange Sort\n");
                    printf("-----------------------\n");
                    scanf("%c", &ch1);
                    clearCache();
                    if(ch1 == '0')
                        break;
                    switch (ch1){
                        case '1':
                            bubbleSort(a, arrayLength);
                            printf("Bubble Sorted (Please press ENTER)\n");
                            break;
                        case '2':
                            selectSort(a, arrayLength);
                            printf("Select Sorted (Please press ENTER)\n");
                            break;
                        case '3':
                            exchangeSort(a, arrayLength);
                            printf("Exchange Sorted (Please press ENTER)\n");
                            break;
                        default:
                            break;
                    }
                    clearCache();
                }
                break;
            case '8':
                while(1){ 
                    printf("-----Please Choose-----\n");
                    printf("0) Exit submenu\n");
                    printf("1) Normal Search\n");
                    printf("2) Binary Search\n");
                    printf("-----------------------\n");
                    scanf("%c", &ch1);
                    clearCache();
                    if(ch1 == '0')
                        break;
                    switch (ch1){
                        case '1':
                            int val, ans;
                            printf("Please enter the value you'd like to search in the array.\n");
                            scanf("%d", &val);
                            ans = search(a, arrayLength, val);
                            if(ans)
                                printf("%d is in the array.\n", val);
                            else
                                 printf("%d isn't in the array.\n", val);
                            break;
                        case '2':
                            printf("Bubble Sorted.\n");
                            printf("Please enter the value you'd like to search in the array.\n");
                            scanf("%d", &val);
                            bubbleSort(a, arrayLength);
                            ans = biSearch(a, arrayLength, val);
                            if(ans)
                                printf("%d is in the array.\n", val);
                            else
                                 printf("%d isn't in the array.\n", val);
                            break;
                        default:
                            break;
                    }
                    clearCache();
                }
                break;
            default:
                break;
        }
    }
    return 0;
}

/* Clear Cache */
void clearCache(){
    while(getchar() != '\n')
        ;
}

/* Print Menu */
void printMenu(){
    printf("-----------------------\n");
    printf("         Menu          \n");
    printf("     Please Choose     \n");
    printf("-----------------------\n");
    printf("0) Exit\n");
    printf("1) Config\n");
    printf("2) Generate\n");
    printf("3) Print\n");
    printf("4) Delete\n");
    printf("5) Insert\n");
    printf("6) Statistic\n");
    printf("7) Sort \n");
    printf("8) Search \n");
    //
    printf("-----------------------\n");
}

/* Config */
void config(struct configVar cv){
    arrayLength = cv.arrayLength;
    numsPerLine = cv.numsPerLine;
    splitChar = cv.splitChar;
}

/* Print Array */
void printArray(int a[], int n){
    int i;
    for(int i = 0; i < n; i++){
        if(i != 0 && i % numsPerLine == 0)
            printf("\n");
        printf ("%d%c",a[i],splitChar);
    }
}

/* Fill Array */
void fillArray(int a[], int n, int fillType, int var1, int var2){
    int i;
    switch (fillType){
        case 1:
            srand(time(NULL));
            for(i = 0; i < n; i++){
                a[i] = rand() % (var2 - var1 + 1) + var1; //Generate a random number and put it into the given range. 
            }
            break;
        case 2:
            printf("Please enter %d integers:\n", n);
            for(i = 0; i < n; i++)
                scanf("%d", &a[i]);
            break;
        case 3:
            for(i = 0; i < n; i++)
                a[i] = var1 + var2 * i;
            break;
        default:
            break;
    }
    printf("Finished array generation.\n");
}

/* Delete Element By Id */
int deleteElementById(int a[], int n, int id){
    if(id == n-1){
        a[id] = 0;
        printf("Deleted elem -> id: %d\n", id);
        return n-1;
    }
    else{
        int i;
        for(i = id+1; i <= n-1; i++){
            a[i-1] = a[i];
        }
        printf("Deleted elem -> id: %d\n", id);
        return n-1;
    }
}

/* Delete Element By Value */
int deleteElementByVal(int a[] , int n, int val){
    int cnt = 0, i;
    for(i = 0; i < n; i++){
        if(a[i] == val && i != n-1){
            a[i+1] = a[i];
            cnt ++;
            n--;
        }
        else if(a[i] == val && i == n-1){
            a[i] = 0;
            cnt ++;
            n--;
        }
    }
    printf("Deleted %d elements.\n", cnt);
    return n;
}

/* Delete Element within a range */ //FIRST CHOOSE
int deleteRange(int a[], int n, int begin, int end){
    if(begin < 0 || end >= n || begin > end){
        printf("Range error, please re-enter.\n");
        return n;
    }
    else{
        int i;
        for(i = end; i < n; i++){
            a[i - (end - begin + 1)] = a[i];
        }
        printf("Deleted %d elements.\n", end - begin);
        return n - (end  - begin + 1);
    }
}

/* Insert Element By Id */
int insert(int a[], int n, int pos, int val){
    int i;
    for(i = n; i > pos; i--){
        a[i] = a[i-1];
    }
    a[pos] = val;
    return n + 1;
}

/* Insert Element By Val */
int orderInsert(int a[], int n, int val){
    int index = Search1(a, n , val);
    n = insert(a, n, index, val);
    return n;
}

/* Get Max */ //SECOND CHOOSE
int maxValue(int a[], int n){
    int m = -0x7fffffff, i;
    for(i = 0; i < n; i++){
        if(a[i] > m){
            m = a[i];
        }
    }
    return m;
}

/* Get Mix */ 
int minValue(int a[], int n){
    int m = 0x7fffffff, i;
    for(i = 0; i < n; i++){
        if(a[i] < m){
            m = a[i];
        }
    }
    return m;
}

/* Get Avg */
float average(int a[], int n){
    float sum = 0;
    int i;
    for(i = 0; i < n; i++){
        sum += a[i];
    }
    return sum/(n * 1.0);
}

/* Bubble Sort */
void bubbleSort(int a[],int n){
    int i, j;
    for (i=0; i<n-1; i++) 
        for (j=0; j<n-1-i; j++) { 
            if (a[j] > a[j+1]) { 
                a[j + 1] ^= a[j];
                a[j] ^= a[j + 1];
                a[j + 1] ^= a[j];
            }
        }
}

/* Select Sort */
void selectSort(int a[], int n){
    int i = 0, cnt = 0, k, minn = 0x7fffffff;
    for(cnt = 0; cnt < n - 1; cnt++){
        minn = 0x7fffffff;
        for(k = cnt; k < n; k++){
            if(a[k] < minn){
                minn = a[k];
                i = k;
            }
        }
        a[cnt] ^= a[i];
        a[i] ^= a[cnt];
        a[cnt] ^= a[i];
    }
}

/* Exchange Sort */
void exchangeSort(int a[], int n){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = i + 1; j < n; j++){
            if(a[j] < a[i]){
                a[j] ^= a[i];
                a[i] ^= a[j];
                a[j] ^= a[i];
            }
        }
    }
}

/* Normal Search */
int search(int a[], int n, int val){
    int i;
    for(i = 0; i < n; i++){
        if(a[i] == val)
            return 1;
    }
    return 0;
}

/* Binary Search */
int biSearch(int a[], int n, int val){
    int l = 0, r = n - 1, mid;
    while(l <= r){
        mid = (l+r)>>1;
        //printf("%d %d %d %d %d\n",l, mid, r, a[mid], val);
        if(a[mid] == val)
            return 1;
        else if(a[mid] < val){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return 0;
}

/* Temp Search */
int Search1(int a[], int n, int val){
    int i;
    if(val <= a[0])
        return 0;
    for(i = 0; i < n; i++){
        if(a[i] > val){
            return i - 1;
        }
    }
    return n;
}