#include <stdio.h>
#include <math.h>
#include <string.h>
#define PI 3.141592657
struct point{ //define of p(x,y)
    double x;
    double y;
};

void translation(struct point pt[], double tl_x, double tl_y, int num){
    int i = 0;
    for(i = 0; i < num; i++)
    {
        pt[i].x += tl_x;
        pt[i].y += tl_y;
    }
}

void scale(struct point pt[], double s_x, double s_y, int num){
    for(int i = 0;  i < num; i++){
        pt[i].x *= s_x;
        pt[i].y *= s_y;
    }
}

void rotation(struct point pt[], double angle, int num)
{
    double a[2][2];
    struct point temp;
    angle = angle * PI / 180; //degree -> rad
    a[0][0] = cos(angle);
    a[0][1] = -sin(angle);
    a[1][0] = sin(angle);
    a[1][1] = cos(angle);
    for(int i = 0; i < num; i++){
        temp.x = pt[i].x;
        temp.y = pt[i].y;
        pt[i].x = temp.x * a[0][0] + a[0][1] * temp.y;
        pt[i].y = temp.x * a[1][0] + a[1][1] * temp.y;
    }
}

int main(){
    int i = 0, num = 0;
    char mode, action[20];
    double angle, tl_x, tl_y, s_x, s_y;
    struct point pt[10];
    do{ //input num
        printf("Please enter num of points (n >= 2): \n");
        scanf("%d", &num);
    } while(num < 2);
    for(i = 0; i < num; i++){
        printf("Please input each point (x,y): \n");
        scanf("%lf%lf", &pt[i].x, &pt[i].y);
    }
    do{
        getchar();
        printf("Please choose the type of operation:\ntranslation(t), scale(s), rotate(r): \n");
        mode = getchar();
    }while(mode != 't' && mode != 's' && mode != 'r');
    switch(mode){
        case 't':
        //transflation
            printf("Please enter shift_x, shift_y: \n");
            scanf("%lf%lf", &tl_x, &tl_y);
            translation(pt, tl_x, tl_y, num);
            strcpy(action, "translation");
            break;
        case 's':
        //scale
            printf("Please enter scale_x, scale_y: \n");
            scanf("%lf%lf", &s_x, &s_y);
            scale(pt, s_x, s_y, num);
            strcpy(action, "scale");
            break;
        case 'r':
        //rotate
            printf("Please enter angle of rotate: \n");
            scanf("%lf", &angle);
            rotation(pt, angle, num);
            strcpy(action, "rotate");
            break;
    }
    printf("Ater [%s], the coordinate of points are: \n", action);
    for(i = 0; i < num; i++){
        printf("Num:%d (%lf, %lf)\n", i+1, pt[i].x, pt[i].y);
    }
    return 0;
}