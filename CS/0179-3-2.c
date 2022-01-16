#include <stdio.h>
int main(){
    char ctrl; // 's'- caculate loan, 'e'- exit
    float h_area=0,h_price=0,h_cash=0,h_rate=0,h_year=0; //area, price, rate, cash, year
    unsigned int loan_month;
    float loan_sum,loan_mon_rate,mon_pay,pay_sum=0;
    int h_type=1;
    float t;
    int i;
    while(1){
        float h_area=0,h_price=0,h_cash=0,h_rate=0,h_year=0; //area, price, rate, cash, year
        unsigned int loan_month;
        float loan_sum,loan_mon_rate,mon_pay,pay_sum=0;
        printf("\ns - cacaulate loan\ne - exit\n");//menu
        ctrl = getchar();
        if(ctrl=='s'){//cacaulate loan
            printf("1.Please enter area\n"); 
            scanf("%f",&h_area); //area
            printf("2.Please enter price\n"); 
            scanf("%f",&h_price);//price
            printf("3.Please enter cash (x%%)\n"); 
            scanf("%f",&h_cash); //cash
            printf("4.Please enter rate (x%%)\n"); 
            scanf("%f",&h_rate); //rate
            printf("5.Please enter year\n"); 
            scanf("%f",&h_year); //year

            printf("6.Please enter type of loan\n0 - equal loan payment， 1 - equal principal payment\n"); 
            scanf("%d",&h_type);

            loan_mon_rate=h_rate/100./12; //month rate
            loan_month=h_year*12; //year rate
            loan_sum=h_area*h_price*(1-h_cash/100); //mount of loan
            printf("Mount of loan is : %.2f\n",loan_sum);

            pay_sum = 0.0; //init payed
            if(h_type==0)//equal loan payment 
            {
                t=1.0; 
                for(i=0;i<loan_month;i++)//factor of monthly payment
                {
                    t*=(1+loan_mon_rate);
                }
                mon_pay=loan_sum*loan_mon_rate*t/(t-1);//monthly
                pay_sum=mon_pay*loan_month;//total
                printf("equal loan payment - monthly : %.2f\n",mon_pay);
                printf("equal loan payment - total : %.2f\n",pay_sum);
            }
            else if(h_type==1){//equal principal payment
                printf("equal principal payment - monthly payment list :\n");
                for(i=0;i<loan_month;i++)//factor of monthly payment
                {
                    mon_pay=loan_sum/loan_mon_rate+(loan_sum-loan_sum/loan_month*i)*loan_mon_rate;
                    pay_sum+=mon_pay;
                    printf("%d th month payment : %.2f\n",i+1,mon_pay);
                }
                printf("equal principal payment - total : %.2f\n",pay_sum);
            }
        }
        else if(ctrl=='e')//exit
            break;
    }
    return 0;
}