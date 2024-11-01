#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//define the max length of characters for the animals

#define MAXLENGTH 100

//create node structure OOB!!
struct zoo{
  char Animal[MAXLENGTH];
  int Quantity;
  struct zoo *next;
};

void DeleteNode(struct zoo **head, char removeE[MAXLENGTH]){
    struct zoo *current = *head;
    struct zoo *prev = NULL;

    while(current != NULL){
      if(strcmp(current ->Animal, removeE) == 0){
        //the node to delete is the head

        if(prev == NULL){
          *head = current -> next;
          free(current);
        }
        else{
          //the node to remove is in the middle or at the end
          prev -> next = current -> next;
          free(current);
        }
      }
      else{
        // move to next node
        prev = current;
        current = current -> next;
      }
    }
  
}

void ADD(struct zoo **head, char newanimal[MAXLENGTH], int newquantity){
    struct zoo *newnode = malloc(sizeof(struct zoo));
    struct zoo *current = *head;
    struct zoo *prev = NULL;

    //copy newanimal and newquantity into new node
    strcpy(newnode -> Animal, newanimal);
    newnode -> Quantity = newquantity;
    // link the new node to rest of list
    while(current != NULL){
      prev = current;
      current = current -> next;
}
    prev -> next = newnode;
    newnode -> next = NULL;




}

void pll(struct zoo *zoo){
  while(zoo != NULL){
    printf(" %s,", zoo -> Animal);
    zoo = zoo -> next;
  }
}

char lowercase(char c){
    if(c >= 'A' && c <= 'Z'){
      return c+32;
  }
return c;
}

int main(){

  char removeE[MAXLENGTH];
  // declare nodes

  struct zoo *head;
  struct zoo *enclosure1 = NULL;
  struct zoo *enclosure2 = NULL;
  struct zoo *enclosure3 = NULL;
  struct zoo *enclosure4 = NULL;

  // allocate memory to nodes

  enclosure1 = malloc(sizeof(struct zoo));
  enclosure2 = malloc(sizeof(struct zoo));
  enclosure3 = malloc(sizeof(struct zoo));
  enclosure4 = malloc(sizeof(struct zoo));

  //assign values to the nodes
  //strcpy() to copy string into allocated memory slot
  
  strcpy(enclosure1 -> Animal, "Tiger");
  enclosure1 -> Quantity = 2;
  
  strcpy(enclosure2 -> Animal, "Lion");
  enclosure2 -> Quantity = 2;
  
  strcpy(enclosure3 -> Animal, "Bear");
  enclosure3 -> Quantity = 2;
  
  strcpy(enclosure4 -> Animal, "Shark");
  enclosure4 -> Quantity = 2;

  //link the nodes together
    //next in the link
    enclosure1 -> next = enclosure2;
    enclosure2 -> next = enclosure3;
    enclosure3 -> next = enclosure4;
    enclosure4 -> next = NULL;

  // assign the value of head to the first nodes
  head = enclosure1;

  //print the linked list
  pll(head);
  printf("\n");
  fflush(stdout);

  //asks the user what they want to delete and stores input in a string
  //printf("\nWhat enclosure would you like to remove from the zoo: \n");
  

  //asks the user what is the name of the animal in the enclosure node being created in the zoo linked list
  //char newanimal[MAXLENGTH];
  //int newquantity;
  //printf("\nWhat animal would you like to add to the zoo: \n");
  //fflush(stdout);
  //scanf("%s", newanimal);
  //printf("\nHow many of this animal would you like to add to the zoo: \n");
  //fflush(stdout);
  //scanf("%d", &newquantity);
  
  //ask the user what they want to do within the linked list
  char choice;

      do{
        printf("Insert, Delete, Create: (I) (D) (C):\n");
        fflush(stdout);
        scanf("%c", &choice);
        choice = lowercase(choice);
        if(choice != 'i' && choice != 'd'&& choice != 'c'){
            printf("Wrong Input Try Again!\n");
          }
    } while(choice != 'i' && choice != 'd' && choice != 'c');

    if(choice == 'i'){

      }

    if(choice == 'd'){
      //delete a enclosure/node
        char removeE[MAXLENGTH];
       printf("what animal enclosure would you like to get rid of:\n");
       fflush(stdout);
       scanf("%s", removeE);
       DeleteNode(&head, removeE);



      }

    if(choice == 'c'){
        //add node
        char newanimal[MAXLENGTH];
        int newquantity;

        printf("what is the name of the animal you want in the new enclosure?:\n");
        fflush(stdout);
        scanf("%s", newanimal);

        printf("how many animals per enclosure?:\n");
        fflush(stdout);
        scanf("%d", &newquantity);

        ADD(&head, newanimal, newquantity);
      
      }
  
  pll(head);
  
  return 0;
}
