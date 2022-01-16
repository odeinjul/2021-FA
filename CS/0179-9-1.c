#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
    int id;
    char name[30];
    char gender;
    int age;
    float score;
    struct Node *next;
} student;
FILE *fp;

struct Node *head ;
void clearCache();
void printMenu();
void create(struct Node *head);
void print(struct Node *head);
void delete1(struct Node *head);
void insert(struct Node *head);
void search(struct Node *head);
void statis(struct Node *head);
void destroy(struct Node *head);
void save(struct Node *head);

int main(){
    fp = fopen("save.in","rb+");
    printf("Student Information Manage System\n");
    head = (struct Node *)malloc(sizeof(struct Node));
    while(1){
        char ch;
        printMenu();
        ch = getchar();
        if(ch == '0')
            break;
        switch (ch){
            case '1':
                create(head);
                clearCache();
                break;
            case '2':
                print(head);
                clearCache();
                break;
            case '3':
                insert(head);
                clearCache();
                break;
            case '4':
                delete1(head);
                clearCache();
                break;
            case '5':
                search(head);
                clearCache();
                break;
            case '6':
                statis(head);
                clearCache();
                break;
            case '7':
                destroy(head);
                clearCache();
                break;
            case '8':
                save(head);
                clearCache();
                break;
            default:
                break;

        }

    }
    
    return 0;
}

void printMenu(){
    printf("---------------------------------\n");
    printf("0.exit\n");
    printf("1.create\n");
    printf("2.print\n");
    printf("3.insert\n");
    printf("4.delete\n");
    printf("5.search\n");
    printf("6.statistic\n");
    printf("7.destory\n");
    printf("8.save\n");
    printf("---------------------------------\n");
}

/* Clear Cache */
void clearCache(){
    while(getchar() != '\n')
        ;
}

/* 1.Create */
void create(struct Node *head){
    fp = fopen("save.in","rb+");
    struct Node *temp, *p, *q;
    temp = (struct Node*)malloc(sizeof(struct Node));
    p = head;
    int i;
    printf("LOAD START\n");
    fread(head, sizeof(struct Node), 1, fp);
    p = head;
    printf("%d\n", head -> id);
    for(i = head -> id; i >= 1; i--){
        temp = (struct Node*)malloc(sizeof(struct Node));
        fread(temp, sizeof(struct Node), 1, fp);
        printf("%d\n", temp -> id);
        p -> next = temp;
        p = p -> next;
    }
    p -> next = NULL;
    fclose(fp);
    printf("LOADED\n");
}

/* 2.Print */
void print(struct Node *head){
    printf("---------------------------------\n");
    printf("Print Link:\n");
    struct Node *p = head -> next;
    while(p != NULL){
        printf("Id: %d\tName: %s\tGender: %c\tAge: %d\tScore: %f\n", p -> id, p -> name, p -> gender, p -> age, p -> score);
        p = p -> next;
    }
    printf("---------------------------------\n");
}

/* 3.Insert */
void insert(struct Node *head){
    printf("-----Please Choose-----\n");
    printf("0) Exit\n");
    printf("1) Insert by Index\n");
    printf("2) Insert in a sorted List\n");
    printf("-----------------------\n");
    clearCache();
    char ch;
    struct Node *temp = (student *)malloc(sizeof(student));
    struct Node *p = head -> next;
    struct Node *q = head -> next;
    int index, i;
    ch = getchar();
    if(ch == '0')
        return ;
    switch (ch){
        case '1':{
            printf("Please input the info of the student\n");
            printf("Id(int), Name(string), Gender(char), Age(int), Score(float)\n");
            temp = (student *)malloc(sizeof(student));
            scanf("%d %s %c %d %f", &(temp -> id), temp -> name, &(temp -> gender), &(temp -> age), &(temp -> score));
            printf("Please input the index of the student\n");
            scanf("%d", &index);
            clearCache();
            if(head -> next == NULL){
                head -> next = temp;
                printf("Inserted\n");
                head -> id = 1;
                return ;

            }
            if(index > head -> id +1 || index <= 0){
                printf("Error: Out of Length\n");
                clearCache();
                return;
            }
            else{
                p = head;
                for(i = 1; i <= index - 1; i++)
                    p = p -> next;
                temp -> next = p -> next;
                p -> next = temp;
                head -> id ++;
                printf("Inserted\n");
            }
            clearCache();
            break;
        }
        case '2':{
            printf("Please input the info of the student\n");
            printf("Id(int), Name(string), Gender(char), Age(int), Score(float)\n");
            temp = (student *)malloc(sizeof(student));
            scanf("%d, %s, %c, %d, %f", &(temp -> id), temp -> name, &(temp -> gender), &(temp -> age), &(temp -> score));
            while(p != NULL && p -> id < temp -> id){
                q = p;
                p = p -> next;
            }
            temp -> next = p;
            q -> next = temp;
            head -> id ++;
            printf("Inserted\n");
            clearCache();
            break;
        }
        default:
            clearCache();
            break;
    }
}

/* 4.Delete */
void delete1(struct Node *head){
    printf("-----Please Choose-----\n");
    printf("0) Exit\n");
    printf("1) Delet by Index\n");
    printf("2) Delete by Id\n");
    printf("-----------------------\n");
    clearCache();
    char ch;
    struct Node *p = head -> next;
    struct Node *q = head -> next;
    int index, i ,id;
    ch = getchar();
    if(ch == '0')
        return ;
    switch (ch){
        case '1':{
            printf("Please input the index of the student\n");
            scanf("%d", &index);
            if(index > head -> id || index <= 0){
                printf("Error: Out of Length\n");
                clearCache();
                return;
            }
            else{
                p = head;
                for(i = 1; i <= index - 1; i++)
                    p = p -> next;
                q = p -> next;
                p -> next = p -> next -> next;
                free(q);
                head -> id --;
                printf("Deleted\n");
            }
            clearCache();
            break;
        }
        case '2':{
            printf("Please input the id of the student\n");
            scanf("%d", &id);
            while(p != NULL && p -> id != id){
                q = p;
                p = p -> next;
            }
            if(p == NULL){
                printf("Error: Not found\n");
                clearCache();
                break;
            }
            q -> next = p -> next;
            free(p);  
            printf("Deleted\n");
            clearCache();
            break;
        }
        default:
            clearCache();
            break;
    }
}

/* 5.Search */
void search(struct Node *head){
    int id;
    struct Node *p  = head;
    struct Node *q  = head;
    printf("Please input the id of the student\n");
    scanf("%d", &id);
    while(p != NULL && p -> id != id){
        q = p;
        p = p -> next;
    }
    if(p == NULL){
        printf("Error: Not found\n");
        clearCache();
    }
    printf("---------------------------------\n");
    printf("Student Info:\n");
    q = p;
    printf("Id: %d\tName: %s\tGender: %c\tAge: %d\tScore: %f\n", p -> id, p -> name, p -> gender, p -> age, p -> score);
    printf("---------------------------------\n");
    clearCache();
    return ;
}

/* 6.Statistic */
void statis(struct Node *head){
    printf("-----Please Choose-----\n");
    printf("0) Exit\n");
    printf("1) Count Number\n");
    printf("2) Highest Score & Average Score\n");
    printf("3) Count Failed Student\n");
    printf("-----------------------\n");
    clearCache();
    char ch;
    struct Node *p = head -> next;
    struct Node *temp;
    int sum = 0, i = 0, maxn = -1;
    float avg;
    ch = getchar();
    if(ch == '0')
        return ;
    switch (ch){
        case '1':{
            printf("Number of students:\t%d\n",head -> id);
            clearCache();
            break;
        }
        case '2':{
            p = head ->next;
            if(p == NULL){
                printf("Error: Empty List\n");
                return ;
            }
            while(p != NULL){
                sum += p -> score;
                if(maxn < p -> score){
                    maxn = p -> score;
                    temp = p;
                }
                p = p -> next;
            }
            avg = sum / (1.0 * head -> id);
            printf("AVG:%f, MAX: %d\n",avg, maxn);
            clearCache();
            break;
        }
        case '3':{
            p = head ->next;
            while(p != NULL){
                if(p -> score < 60){
                    i++;
                }
                p = p -> next;
            }
            printf("Failed Students: %d", i);
        }
        default:
            clearCache();
            break;
    }
}

/* 7.destroy */
void destroy(struct Node *head){
    struct Node *p = head;
    struct Node *q;
    while(p != NULL){
        q = p;
        p = p -> next;
        free(q);
    }
    printf("Destroyed\n");
    head = (struct Node *)malloc(sizeof(struct Node)); 
    return ;
}

/* 8.Saved */
void save(struct Node *head){
    printf("-----Please Choose-----\n");
    printf("0) Exit\n");
    printf("1) Rewrite\n");
    printf("2) Attain\n");
    printf("3) Clear\n");
    printf("-----------------------\n");
    clearCache();

    char ch;
    struct Node *temp = (student *)malloc(sizeof(student));
    struct Node *p = head -> next;
    struct Node *q = head -> next;
    int index, i;
    ch = getchar();
    if(ch == '0')
        return ;
    switch (ch){
        case '1':{
            fp = fopen("save.in", "wb+");
            printf("SAVE START\n");
            struct Node *p = head;
            while(p != NULL){
                fwrite(p, 1, sizeof(struct Node), fp);
               p = p -> next;
            }
            fclose(fp);
            printf("SAVED\n");
            clearCache();
            break;
        }
        case '2':{
            fp = fopen("save.in1", "wb+");
            struct Node *p = head;
            while(p != NULL){
                fwrite(p, 1, sizeof(struct Node), fp);
               p = p -> next;
            }
            fclose(fp);
            q = head;

            while(q -> next != NULL){
                q = q -> next;
            }
            fp = fopen("save.in", "rb+");
            p = (student *)malloc(sizeof(student));
            fread(p, sizeof(struct Node), 1, fp);
            printf("%d\n", p -> id);
            for(i = p -> id; i >= 1; i--){
                temp = (struct Node*)malloc(sizeof(struct Node));
                //printf("%d\n", head -> id);
                fread(temp, sizeof(struct Node), 1, fp);
                q -> next = temp;
                q = q -> next;
            }  

            head -> id += p -> id;
            q -> next = NULL;
            fclose(fp);
            fp = fopen("save.in", "wb+");
            fclose(fp);
            fp = fopen("save.in", "wb+");
            printf("SAVE START\n");
            printf("%d %d \n", head -> id, p -> id);
            p = head;
            while(p != NULL){
                fwrite(p, 1, sizeof(struct Node), fp);
                p = p -> next;
            }
            printf("SAVED\n");
            fclose(fp);
            fp = fopen("save.in1","rb+");
            temp = (struct Node*)malloc(sizeof(struct Node));
            p = head;
            int i;
            //printf("LOAD START\n");
            fread(head, sizeof(struct Node), 1, fp);
            p = head;
            //printf("%d\n", head -> id);
            for(i = head -> id; i >= 1; i--){
                temp = (struct Node*)malloc(sizeof(struct Node));
                fread(temp, sizeof(struct Node), 1, fp);
                //printf("%d\n", temp -> id);
                p -> next = temp;
                p = p -> next;
            }   
            p -> next = NULL;
            fclose(fp);
            clearCache();
            break;
        }
        case '3':{
            fp = fopen("save.in","wb+");
            printf("CLEARED\n");
            clearCache();
            fclose(fp);
            break;
        }
        default:
            clearCache();
            break;
    }
}
