#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct userInfo{
    unsigned int userId;
    char userName[20];
}user[200];
int userNum = 0, scheNum = 0;
struct scheduleDate{
    unsigned int year;
    unsigned int month;
    unsigned int day;
};
struct schedule{
    unsigned int sid;
    struct userInfo userinfo;
    struct scheduleDate sdate;
    char smemo[203];
}sche[200];
int maxday(struct schedule x,struct schedule y)//sort day dec
{
	if (x.sdate.year>y.sdate.year) return 1;
	if (x.sdate.month>y.sdate.month) return 1;
	if (x.sdate.day>y.sdate.day) return 1;
	return 0;
}
int minday(struct schedule x,struct schedule y)//sort day asc
{
	if (x.sdate.year<y.sdate.year) return 1;
	if (x.sdate.month<y.sdate.month) return 1;
	if (x.sdate.day<y.sdate.day) return 1;
	return 0;
}
void clearCache();
void printMenu2();
void printMenu1();
int Logged = 0;
int userReg();
int userLogin();
int createSchedule(struct userInfo ui);
int modifySchedule();
int deleteSchedule();
struct schedule getScheduleInfo(int temp);
void sortSchedule(int sortField, int sortType);
void printSchedule(int printType);
int main(){
    char ch;
    //LOGIN & REGISTER
st:    while(Logged == 0){
        printMenu1();
        printf("Please choose (Enter the num):\n");
        scanf("%c",&ch);
        clearCache();
        if(ch == '0')
            break;
        switch (ch){
            case '1':
                userReg();
                clearCache();
                break;
            case '2':
                userLogin();
                clearCache();
                break;
            default:
                break;
        }
        clearCache();
    }
    
    //FUNCTIONS
    while(1){
        printMenu2();
        printf("Please choose (Enter the num):\n");
        scanf("%c",&ch);
        clearCache();
        if(ch == '0')
            break;
        switch (ch){
            case '1':
                createSchedule(user[Logged - 1]);
                clearCache();
                break;
            case '2':
                modifySchedule();
                clearCache();
                break;
            case '3':
                deleteSchedule();
                clearCache();
                break;
            case '4':
                int tid;
                printf("Please enter id:\n");
                scanf("%d", &tid);
                if(getScheduleInfo(tid).sid == -1){
                    printf("Not found.\n");
                }
                else{
                    printf("-----------------------\n");
                    printf("Id: %d\n", getScheduleInfo(tid).sid);
                    printf("Date: %u, %u, %u\n",getScheduleInfo(tid).sdate.year,getScheduleInfo(tid).sdate.month,getScheduleInfo(tid).sdate.day);
                    printf("User: %s, UserId: %u\n", getScheduleInfo(tid).userinfo.userName, getScheduleInfo(tid).userinfo.userId);
                    printf("Memo: %s\n", getScheduleInfo(tid).smemo);
                    printf("-----------------------\n");
                }
                clearCache();
                break;
            case '5':
                int a,b;
                printf("Please choose field(1-sid, 2-uid, 3-date),type(0-Asc, 1-Dec):\n");
                scanf("%d %d",&a, &b);
                sortSchedule(a,b);
                printf("sorted");
                clearCache();
                break;
            case '6':
                printf("Please choose printType(1-sid, 2-uid, 3-date):\n");
                scanf("%d",&a);
                printf("-----------------------\n");
                printSchedule(a);
                clearCache();
                break;
            case '7':
                printf("Logged out.\n");
                Logged = 0;
                clearCache();
                goto st;
                break;
            default:
                break;
        }
    }
}
/* Clear Cache */
void clearCache(){
    while(getchar() != '\n')
        ;
}

/* Menu1 - Login & Register */
void printMenu1(){
    printf("-----------------------\n");
    printf("         Menu          \n");
    printf("     Please Choose     \n");
    printf("-----------------------\n");
    printf("0) Exit\n");
    printf("1) User Register\n");
    printf("2) User Login\n");
    //
    printf("-----------------------\n");
}

/* Menu2 - Functions */
void printMenu2(){
    printf("-----------------------\n");
    printf("         Menu          \n");
    printf("     Please Choose     \n");
    printf("-----------------------\n");
    printf("0) Exit\n");
    printf("1) Create Schedule\n");
    printf("2) Modify Schedule\n");
    printf("3) Delete Schedule\n");
    printf("4) Get Schedule\n");
    printf("5) Sort Schedule\n");
    printf("6) Print Schedule\n");
    printf("7) Logged\n");
    //
    printf("-----------------------\n");
}

/* Register */
int userReg(){
    printf("-------Register--------\n");
    printf("Please enter USERNAME:\n");
    scanf("%s", user[userNum].userName);
    user[userNum].userId = userNum;//save
    userNum ++;
    printf("Resgistered: User[%s], Id[%d]. (Please press ENTER)\n",user[userNum-1].userName, user[userNum-1].userId);
    return 0;
}

/* Login */
int userLogin(){
    printf("--------Login----------\n");
    printf("Please enter USERNAME:\n");
    char temp[20];
    int i;
    scanf("%s", temp);
    for(i = 0; i < userNum; i++){
        //printf("%d, %s, %s",i, user[i].userName, temp);
        if(strcmp(temp, user[i].userName) == 0){//compare
            printf("Successfully logined.\nWelcome, %s! (Please press ENTER)",temp);
            Logged = user[i].userId + 1;
            return 1;
        }
    }
    printf("ERROR, User[%s] not found\n", temp);
    clearCache();
    return 0;
}

/* Create Schedule */
int createSchedule(struct userInfo ui){
    if(scheNum == 199){
        printf("Storage FULL, can not create new schedule.\n");
        return 1;
    }
    printf("--------Create--------\n");
    int year,month = 0,day = 0;
    while(month >= 13 || month <= 0 || day <= 0 || day >= 32){
        printf("Please enter date (YYYY MM DD):\n");
        scanf("%d %d %d", &year, &month ,&day);
    }
    sche[scheNum].sdate.year = year;
    sche[scheNum].sdate.month = month;
    sche[scheNum].sdate.day = day;
    printf("Please enter memo (200 characters):\n");
    scanf("%s", sche[scheNum].smemo);
    sche[scheNum].sid = scheNum;
    sche[scheNum].userinfo = ui;
    printf("Created a schedule at %d, %d ,%d. (Please press Enter)\n",sche[scheNum].sdate.year, sche[scheNum].sdate.month ,sche[scheNum].sdate.day);
    scheNum ++;
    clearCache();
    return 0;
}

/* Modify Schedule */
int modifySchedule(){
    printf("--------Modify--------\n");
    printf("Please enter id of the schedule you want to modify:\n");
    int temp,temp1 = -1;
    scanf("%d", &temp);
    while(temp >= scheNum || temp <0){
        printf("Out of boundary.\n");
        scanf("%d", &temp);
    }
    clearCache();
    for(int i = 0; i < scheNum; i++){
        if(sche[i].sid == temp){
            temp1 = i;
            break;
        }
    }
    if(temp1 == -1){
        printf("Not found. (Please press ENTER)\n");
        return 1;
    }
    temp = temp1;
    int year,month = 0,day = 0;
    while(month >= 13 || month <= 0 || day <= 0 || day >= 32){
        printf("Please enter date (YYYY MM DD):\n");
        scanf("%d %d %d", &year, &month ,&day);
        clearCache();
    }
    sche[temp].sdate.year = year;
    sche[temp].sdate.month = month;
    sche[temp].sdate.day = day;
    printf("Please enter memo (200 characters):\n");
    scanf("%s", sche[temp].smemo);
    clearCache();
    sche[temp].userinfo = user[Logged - 1];
    printf("Modified id[%d] schedule at %d, %d ,%d\n",temp, sche[temp].sdate.year, sche[temp].sdate.month ,sche[temp].sdate.day);
    clearCache();
    return 0;
}

/* Delete Schedule */
int deleteSchedule(){
    printf("--------Delete--------\n");
    printf("Please enter id of the schedule you want to delete:\n");
    int temp, temp1;
    scanf("%d", &temp);
    while(temp >= scheNum || temp <0){
        printf("Out of boundary.\n");
        scanf("%d", &temp);
    }
    for(int i = 0; i < scheNum; i++){
        if(sche[i].sid == temp){
            temp1 = i;
            break;
        }
    }
    if(temp1 == -1){
        printf("Not found. (Please press ENTER)\n");
        return 1;
    }
    temp = temp1;
    sche[temp].sid = -1;
    printf("Deleted id[%d] schedule.\n", temp);
    return 0;
}

/* Get Schedule */
struct schedule getScheduleInfo(int temp){
    struct schedule ret;
    ret.sid=-1;
    int temp1 = -1;
    for(int i = 0; i < scheNum; i++){
        if(sche[i].sid == temp){
            temp1 = i;
            break;
        }
    }
    if(temp1 == -1){
        return ret;
    }
    temp = temp1;
    return sche[temp];
}

/* Sort Schedule*/
void sortSchedule(int sortField,int sortType)
{
	int i,j;
	struct schedule t;
	switch (sortField)
	{
		case 1:
			for (i=0;i<scheNum-1;i++)
				for(j=i;j<scheNum-1;j++)
					if (sche[j].sid>sche[j+1].sid && sortType==0 || sche[j].sid<sche[j+1].sid && sortType==1)
					{
						t=sche[j];
						sche[j]=sche[j+1];
						sche[j+1]=t;
					}
			break;
		case 2:
			for (i=0;i<scheNum-1;i++)
				for(j=i;j<scheNum-1;j++)
					if (sche[j].userinfo.userId>sche[j+1].userinfo.userId && sortType==0 || sche[j].userinfo.userId>sche[j+1].userinfo.userId && sortType==1)
					{
						t=sche[j];
						sche[j]=sche[j+1];
						sche[j+1]=t;
					}
			break;
		case 3:
			for (i=0;i<scheNum-1;i++)
				for(j=i;j<scheNum-1;j++)
					if (maxday(sche[j],sche[j+1]) && sortType==0 || minday(sche[j],sche[j+1]) && sortType==1)
					{
						t=sche[j];
						sche[j]=sche[j+1];
						sche[j+1]=t;
					}
			break;
		default:
			break;
	}
}

/* Print Schedule */
void printSchedule(int printType)
{
	int i;
	sortSchedule(printType,0);
	for (i=0;i<scheNum;i++)
        if(sche[i].sid != -1)
		    printf("sid[%d], uis[%d], uname[%s], date: %d, %d, %d, memo: %s\n",sche[i].sid,sche[i].userinfo.userId,sche[i].userinfo.userName,sche[i].sdate.year,sche[i].sdate.month,sche[i].sdate.day,sche[i].smemo);
}