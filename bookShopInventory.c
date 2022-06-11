#include<stdio.h>
#include<string.h>

struct record{
	char title[30];
	char author[30];
	char publisher[30];
	struct{
		char month[10];
		int year;
	} date;
	float price;
	int quantity;
};

void get(char []);
int lookUp(struct record [],char [],char [],int);

int main(void){
	int no_of_records,index,quantity;
	char author[30],title[30],ch;
	float price;
	struct record books[] = {
			{"ANSI C","Balagurusamy","MC","Feb",2002,145.00,25},
			{"C language","Ritchie","PHI","May",2005,45.00,10},
			{"Programming in C","Kochan","Hayden","July",1983,75.50,5},
			{"COBOL","Balagurusamy","Macmillan","December",1988,60.00,0}
	};

	do{
		printf("Enter the details of book:\n");
		printf("Author :");
		get(author);
		printf("Book Name :");
		get(title);

		no_of_records = sizeof(books)/sizeof(struct record);
		index = lookUp(books,author,title,no_of_records);

		if(index != -1){
			printf("\n---The Book Details---");
			printf("\nTitle:  %s",books[index].title);
			printf("\nAuthor: %s",books[index].author);
			printf("\nPublisher: %s",books[index].publisher);
			printf("\nDate of publication: %s %d",books[index].date.month,books[index].date.year);
			printf("\nPrice : %f",books[index].price);

			printf("\n\n Enter the quantity of the books ?");
			scanf("%d",&quantity);
			if(quantity<=books[index].quantity){
				price = books[index].price*quantity;
				printf("The amount for %d books is: %f",quantity,price);
			}else{
				printf("The requested quantity is not found.");
			}
		}else{
			printf("The searched book is not found!");
		}
		printf("\nDo you want to search for more books(y/n) ?");
		scanf("%c",&ch);
	}while(ch == 'y' || ch == 'Y');

	printf("Thank You.. ");



	return 0;
}

void get(char query[]){
	int i=0;
	do{
		scanf("%c",&query[i]);
		i++;
	}while(query[i-1] != '\n');
	query[i-1] = '\0';
}

int lookUp(struct record table[],char author[],char title[],int max){
	int i;
	for(i=0;i<max;i++){
		if(strcmp(author,table[i].author) == 0 && strcmp(title,table[i].title) == 0)
			return i;
	}
	return -1;
}

