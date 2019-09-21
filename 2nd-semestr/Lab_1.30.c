#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct publisher{ 
 	char nm[20];
 	char adr[20]; 
 	char num[20];
 	struct publisher *next; 
}; 

void settings(void){
	printf ("what can u do: \n");
	printf ("1. print the list\n");
	printf ("2. add an item to the head\n");
	printf ("3. add after k: \n");
	printf ("4. swap elements\n");
	printf ("5. clear the list\n");
	printf ("6. edit an element\n");
	printf ("0. end\n");
}

publisher input(){
 	publisher p;
 	printf ("name of company: "); 
 	scanf ("%s",p.nm);
 	printf ("address: ");
 	scanf ("%s",&p.adr);
 	printf ("telefon number: ");
 	scanf ("%s",&p.num);
 	return p;
}

void show(publisher *head){ 
 	if (head==NULL) {
		printf ("list is empty\n");
		return;
	}
	else{
		while(head){
   			printf("%s %s %s\n", head->nm ,head->adr, head->num);
   			head=head->next;
   		}
	}
}

void copy1 (publisher *to, publisher *from){ 
 	strcpy (to->nm, from->nm); 
 	strcpy (to->adr, from->adr);
 	strcpy (to->num, from->num);
}

publisher *add1 (publisher *head, publisher *st){
 	publisher *current = new publisher;
 	copy1 (current, st); 
 	if (head==NULL) current->next = NULL;
 	else{
  		current->next = head;
  		head = current;
 	}
 	return current;
}


void add_afterk(int k, publisher *head){
  	publisher *p = head;
  	publisher *n = head;
  	publisher *m = head;
  	publisher w;
  	publisher *tmp;
  	w = input(); 
   	tmp=add1(tmp,&w);
  	int i=1,j=1;
   		while (i<(k+1)){
   			m=m->next; i++;
		}
   		while(j<(k)){
    		p=p->next;
    		j++;
   		}
   		p->next=tmp;
   		tmp->next=m;
   		show(n);
  	}
   		


void edit(int k, publisher *head){
	int i=1;
	publisher *l=head;
	publisher *temp=head;
	while (i<k){
		l=l->next; i++;
		}
	printf( "edit information:\n");
	printf ("\nnew company name: "); 
 	scanf ("%s",l->nm);
 	printf ("\nnew address: ");
 	scanf ("%s",&(l->adr));
 	printf ("\nnew telefon number: ");
 	scanf ("%s",&(l->num));
}

void  swap(int k, int j,  publisher *head){
  	publisher *temp=head;
   	publisher *p = new publisher;
   	publisher *l=head;
   	l=head;
   	int i=1, m=1;
   	while(i<k){
    	head=head->next; i++; 
	}
   	while(m<j){
   		temp=temp->next; m++;  
	}
   	strcpy(p->nm, temp->nm);
   	strcpy(p->adr, temp->adr);
   	strcpy(p->num, temp->num);
   	//p->adr=temp->adr;
   
   	strcpy(temp->nm, head->nm);
   	strcpy(temp->adr, head->adr);
   	strcpy(temp->num, head->num);
   	//temp->adr=head->adr;
   
   	strcpy(head->nm, p->nm);
   	strcpy(head->adr, p->adr);
   	strcpy(head->num, p->num);
   	//head->adr=p->adr;
   	show(l);
}
 
publisher *clear(publisher *head){
	publisher * x= head;
 	publisher * temp;
 	while (temp){
   		temp = x -> next;
   		delete x;
   		x = temp;
   	}
  	return temp;
}
 
void outpf( publisher *head){
   
   	FILE *fp;
   	char name[60]="new.txt";
   	fp=fopen(name, "wb");
   	fprintf(fp, "info about companies:\n");
   	while(head){
    	fwrite(head, sizeof(publisher), 1, fp);
   		printf("\n");
   		head=head->next;
    }
   	fclose(fp);
}

int main(){ 
 	publisher *head = NULL;
 	int in;
 
  	publisher p;
  	publisher *cur;
  	int num, n1, n2, n3;
  
 	settings();
  	printf ("\nselect an command from the list: ");
  	scanf ("%d",&in);
 
 	while (in >= 0){
  		switch (in){
   			case 1: show(head);
   				break;
   			case 2: p = input(); 
   				head=add1(head,&p);
   				outpf(head);
   				break;
   				
   				case 3:
   				if (head==NULL) printf("add in head\n");
  				else{
   				printf ("\nenter the number greater than 1: ");
   				scanf ("%d", &num);
    			add_afterk(num,head);
    			outpf(head);
    			}
   				break;
   				
   			case 4:
   				if (head==NULL) printf("nothing to swap\n");
  				else{
    			printf ("\nenter the numbers of the elements you want to change: ");
   				scanf ("%d %d", &n1, &n2);
			   	swap(n1,n2,head);
	   			outpf(head);
	   			}
   				break;
   			case 5:
   				if (head==NULL) printf("list is empty\n");
  				else{
   				head=clear(head);
  				show(head);
  				printf("list is clear");
  				}
   				break;
   			case 6:
   				if (head==NULL) printf("nothing to edit\n");
  				else{
   				printf ("\nnumber of element which u want to edit: ");
   				scanf ("%d", &n3);
   				edit(n3, head);
   				outpf(head);
   				}
   				break;
   			case 0: exit(0);
   				break;
   			default:
				printf ("\nselect an existing command from the list: ");
				settings();
			break;
  		}
  		printf ("\nselect an command from the list: ");
  		scanf ("%d", &in);
 	}
}
