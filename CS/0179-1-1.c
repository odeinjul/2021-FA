//BMI
#include <stdio.h>
int main(){
    int weight;
    float height,bmi;
    printf("Enter your weight(kg) and height(m) please.\n");
    scanf("%d",&weight);
    scanf("%f",&height);
    bmi = weight / (height * height);
    if(bmi > 18.5 && bmi < 23.9){
        printf("BMI: Standard , %f", bmi);
    }
    else if (bmi >= 23.9){
        printf("BMI: Overweight, %f",bmi);
    }
    else{
        printf("BMI: Underweight, %f",bmi);
    }
}