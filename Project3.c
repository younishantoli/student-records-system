#include <stdio.h> //necessary library
#include <stdlib.h> //necessary library
#include <string.h> //necessary library
#define ARRAYSIZE 6 //makes ARRAYSIZE = 6
struct student{ //struct called student
    char fname[20]; //initialization
    char lname[20]; //initialization
    float score; //initialization
    char nationality[20]; //initialization
}; 

void Displaymenu() { //displaymenu function to give the options
    printf("Select a numeric choice from the given menu:\n\n"); //print what I want printed
    printf("0) Exit Program.\n\n"); //print what I want printed
    printf("1) Clear Screen.\n\n"); //print what I want printed
    printf("2) Print all student records.\n\n"); //print what I want printed
    printf("3) Search records by first name.\n\n"); //print what I want printed
    printf("4) Search records by last name.\n\n"); //print what I want printed
    printf("5) Search records by Grade (>=).\n\n"); //print what I want printed
    printf("6) Print list, total, count, grade, and average score for all American students.\n\n"); //print what I want printed
    printf("7) Save the records of British students in British.txt.\n\n"); //print what I want printed
    printf("8) Sort all records by first name.\n\n"); //print what I want printed
    printf("9) Sort all records by last name.\n\n"); //print what I want printed
    printf("10) Sort all records by scores.\n\n"); //print what I want printed
}
void choice0() { //if you click 0, this function
    printf("Process returned 0 (0x0)\nPress any key to continue."); //print what I want printed
    getchar(); //removes whatever in buffer
    getchar(); //accept character
    exit(0); //exits
}
void choice1() { //if you click 1, this function
    system("cls");
    Displaymenu(); //redisplay the menu
}
void choice2(struct student information[]) { //if you click 2, this function
    for(int i = 0; i < ARRAYSIZE; i++) { //for loop to go through the information array I have
        printf("%-10s %-10s %-10.1f\n", information[i].fname, information[i].lname,  information[i].score); //print what I want printed
    }
}
void choice3(struct student information[]) { //if you click 3, this function
    char fname[20]; //initializes fname for firstname
    printf("\nEnter student's first name: "); //print what I want printed
    scanf("%s", fname); //stores into fname
    getchar(); //removes anything possibly in buffer
    for(int i = 0; i < ARRAYSIZE; i++) { //for loop to find the name that was entered and to print out the contents
        if(strcmp(information[i].fname, fname) == 0) {
            printf("%-10s %-10s %-10.1f\n", information[i].fname, information[i].lname, information[i].score); //print what I want printed
            break;
        }
    }
}
void choice4(struct student information[]) { //if you click 4, this function
    char lname[20]; //initializes lname for lastname

    printf("\nEnter student's last name: "); //print what I want printed
    scanf("%s", lname); //store into lname 
    getchar();//removes anything possibly in buffer

    for(int i = 0; i < ARRAYSIZE; i++) { //for loop to find the name that was entered and to print out the contents
        if(strcmp(information[i].lname, lname) == 0) {
            printf("%-10s %-10s %-10.1f\n", information[i].fname, information[i].lname, information[i].score); //print what I want printed
            break;
        }
    }
}

void choice5(struct student information[]) { //if you click 5, this function
    float score; //initialization

    printf("\nEnter Score: "); //print what I want printed
    scanf("%f", &score);//stores what you entered (float) into score 
    getchar();//removes anything possibly in buffer

    for(int i = 0; i < ARRAYSIZE-1; i++) { //nested for loops with bubble sort
        for(int j = 0; j < ARRAYSIZE-i-1; j++) {
            if(information[j].score > information[j+1].score) {
                struct student tmp = information[j];
                information[j] = information[j+1];
                information[j+1] = tmp;
            }
        }
    }

    for(int i = 0; i < ARRAYSIZE; i++) { //for loop to print out the content
        if(information[i].score >= score) { //to make sure to print whatever is >=
            printf("%-10s %-10s %-10.1f\n", information[i].fname, information[i].lname, information[i].score); //print what I want printed
        }
    }
}
void choice6(struct student information[]) { //if you click 6, this function
    float total = 0.0; //initialization
    int count = 0; //initialization

    for(int i = 0; i < ARRAYSIZE; i++) { //for loop to go through the list and check nationality and then print out contents
        if(strcmp(information[i].nationality, "American") == 0) {
            printf("%-10s %-10s %-10.1f\n", information[i].fname, information[i].lname, information[i].score); //print what I want printed
            total = total + information[i].score;
            count++;
        }
    }
    printf("Total: %.1f, Count: %d, Average: %.1f\n", total, count, total / count); //print what I want printed
}
void choice7(struct student information[]) { //if you click 7, this function
    FILE *britishFH; //creates file
    britishFH = fopen("British.txt", "w"); //opens the file

    if(britishFH == NULL) { //if NULL then close
        printf("File couldn't be opened\n"); //print what I want printed
        exit(0);
    }

    for(int i = 0; i < ARRAYSIZE; i++) { //for loop to print out content if person's nationality is British
        if(strcmp(information[i].nationality, "British") == 0) {
            fprintf(britishFH, "%s\t\t%s\t\t%.1f\n", information[i].fname, information[i].lname, information[i].score); //print what I want printed IN THE FILE
        }
    }
    fclose(britishFH); //close file

    britishFH = fopen("British.txt", "r"); //open up file
    char line[100]; //intiialization
    printf("British.txt\n"); //print what I want printed 
    while(fgets(line, sizeof(line), britishFH)) { //while it is reading each line from the file
        printf("%s", line); //print what I want printed
    }
    fclose(britishFH); //close file
}
void choice8(struct student information[]) { //if you click 8, this function
    for(int i = 0; i < ARRAYSIZE-1; i++) { //nested forloop to sort list by first name
        for(int j = 0; j < ARRAYSIZE-i-1; j++) {
            if(strcmp(information[j].fname, information[j+1].fname) > 0) {
                struct student tmp = information[j];
                information[j] = information[j+1];
                information[j+1] = tmp;
            }
        }
    }
    choice2(information); //instead of repeating the same exact thing over and over, I just used choice2(information) to print out information content
}
void choice9(struct student information[]) { //if you click 9, this function
    for(int i = 0; i < ARRAYSIZE-1; i++) { //nested forloop to sort list by last name
        for(int j = 0; j < ARRAYSIZE-i-1; j++) {
            if(strcmp(information[j].lname, information[j+1].lname) > 0) {
                struct student tmp = information[j];
                information[j] = information[j+1];
                information[j+1] = tmp;
            }
        }
    }
    choice2(information);
}
void choice10(struct student information[]) { //if you click 10, this function
    for(int i = 0; i < ARRAYSIZE-1; i++) { //nested forloop to sort list by score
        for(int j = 0; j < ARRAYSIZE-i-1; j++) {
            if(information[j].score > information[j+1].score) {
                struct student tmp = information[j];
                information[j] = information[j+1];
                information[j+1] = tmp;
            }
        }
    }
    choice2(information);
}
void main() { //main function
    int choice; //initialization
    struct student information[ARRAYSIZE] = { //student struct with all the information
        {"Henry", "Ford", 3.9, "American"},
        {"Isaac", "Newton", 3.7, "British"},
        {"Albert", "Einstein", 4.1, "American"},
        {"Marie", "Curie", 4.2, "French"},
        {"Charles", "Darwin", 3.7, "British"},
        {"Nikola", "Tesla", 3.8, "American"}
    };

    Displaymenu();

    while(1) {//while infinite loop, while true
        printf("\nSelect an option:"); //print what i want
        scanf("%d", &choice); //accept user input
        switch(choice) { //switch function and each case corresponds to the number's choice function
            case 0: choice0(); break;
            case 1: choice1(); break;
            case 2: choice2(information); break;
            case 3: choice3(information); break;
            case 4: choice4(information); break;
            case 5: choice5(information); break;
            case 6: choice6(information); break;
            case 7: choice7(information); break;
            case 8: choice8(information); break;
            case 9: choice9(information); break;
            case 10: choice10(information); break;
        }
    }
}
