#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct _addbook{
    char name[15];
    char phone[18];
    char address[50];
    char birthday[14];
    struct _addbook *link;
};

typedef struct _addbook addbook;

void Insert(addbook*);
void Delete(addbook*);
void Display(addbook*);
void Search(addbook*);

int main(void){
     addbook *ptr;
     int choice;

     ptr = (addbook*)malloc(sizeof(addbook));

     ptr -> link = NULL;

    do{
        printf("===============\n");
        printf(" 학생 관리 프로그램 \n");
        printf("===============\n");
        printf("1. 등 록\n");
        printf("2. 출 력\n");
        printf("3. 검 색\n");
        printf("4. 삭 제\n");
        printf("5. 종 료\n");
        printf("===============\n");


        printf("\n원하는 작업을 입력하시오. : ");
        choice = getchar();
        fflush(stdin);

        switch(choice){
        case '1':
            printf("\n주소록 등록 작업입니다. 정보를 입력하십시오.\n");
            Insert(ptr);
            break;

        case '2':
            printf("\n주소록 출력 작업입니다. 현재 등록된 주소록은 아래와 같습니다.\n");
            Display(ptr -> link);
            break;

	 case '3':
            printf("\n주소록 검색 작업입니다. 정보를 입력하십시오.\n");
            Search(ptr);
            break;

	 case '4':
            printf("\n주소록 삭제 작업입니다. 정보를 입력하십시오.\n");
            break;

        case'5':
            printf("\n종료합니다.\n");
            break;

	 default:
            printf("\n잘못된 값입니다.\n");
        }
    }
    while(choice != '5');
}

void Insert(addbook *ptr){
	     int re;
    while(ptr -> link != NULL)
        ptr = ptr -> link;

        do{
        ptr -> link = (addbook*)malloc(sizeof(addbook));
        ptr = ptr -> link;

        printf("이름 : ");
        fgets(ptr -> name);

        printf("전화번호 : ");
        fgets(ptr -> phone);

        printf("주소 : ");
        fgets(ptr -> address);

        printf("생일 : ");
        fgets(ptr -> birthday);

        printf("\n등록 완료\n");

        for(;;){
            printf("\n계속 등록하시겠습니까? (Y / N) : ");
            re = getchar();
            fflush(stdin);

            if(re != 'Y' && re != 'y' && re != 'N' && re != 'n'){
                printf("\n잘못된 값을 입력하였습니다.\n 다시 입력하여 주십시오.\n\n");
                continue;
            }
            else
                break;
        }
    }
    while(re != 'n' && re != 'N');

    ptr -> link = NULL;
    printf("\n");
}

void Delete(addbook *ptr){
    addbook *temp;
    char _name[15];

    printf("삭제할 사람의 이름 : ");
    fgets(_name);

    while(ptr -> link != NULL){
        temp = ptr;
        ptr = ptr -> link;

        if(strcmp(_name, ptr -> name) == 0){
            temp -> link = ptr -> link;
            free(ptr);
            break;
        }
    }
    return;
}

void Display(addbook *ptr){
    printf("주 소 록\n");
    printf("%-15s", "이 름");
    printf("%-18s", "전 화 번 호");
    printf("%-50s", "주 소");
    printf("%-14s", "생 일");

    while(ptr != NULL){
        printf("%-15s", ptr -> name);
        printf("%-18s", ptr -> phone);
        printf("%-50s", ptr -> address);
        printf("%-14s", ptr -> birthday);

        ptr = ptr -> link;
        printf("\n");
    }
    printf("\n");
}

void Search(addbook *ptr){
    char _name[15];

    printf("찾을 사람의 이름 : ");
    fgets(_name);


    printf("\n검 색 완 료\n");
    printf("%-15s", "이 름");
    printf("%-18s", "전 화 번 호");
    printf("%-50s", "주 소");
    printf("%-14s", "생 일");

    while(ptr != NULL){
        if(strcmp(_name, ptr -> name) == 0){
		printf("%-15s", ptr -> name);
	        printf("%-18s", ptr -> phone);
	        printf("%-50s", ptr -> address);
	        printf("%-14s", ptr -> birthday);
	        printf("\n\n");
        }
        ptr = ptr -> link;
    }
}

