#include <stdio.h>
int isLeapYear(int year) //check leap year
{
    if((year%4==0)&&(year%100!=0)||(year%400==0))
        return 1;
    else 
        return 0;
}
int monthDay(int month,int year) //get the day number of a month
{
    switch(month)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
            return 31;break;
            
            case 4:
            case 6:
            case 9:
            case 11:
            return 30;break; 
            
            case 2:
            if(isLeapYear(year))    
            {
                return 29;//leapyear
                break;
            }
            else
            {
                return 28;
                break;
            }    
        } 
}
int year,month,days,weekday;
int i,d;
int main()
{
    printf("please input the year & the first day:\n");
    scanf("%d%d",&year,&days);
    days-=1;
    for(month=1;month<=12;month++)
    {
        printf("%d/%d\n",year,month);
        printf("Sun\tMon\tTues\tWed\tThur\tFri\tSat\t\n");
        i = 1;    
        d = 1;
        weekday = (days + 1)%7;  
        while(i<=weekday)   //spaces
        {
            printf("\t");
            i++;
        }     
        int days_num = monthDay(month,year);
        while(d<=days_num)     //check every day in that month
        {
            weekday = (days + 1)%7;
            if(weekday==6)   //\n (END of WEEK)
                printf("%d\n",d);
            else             
                 printf("%d\t",d);
            if(d==days_num)
                 printf("\n\n"); //\n (END of MONTH)
            d++;
            days++;
        }
    }
    return 0;
}