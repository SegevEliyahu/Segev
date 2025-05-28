//
//  targil4.c
//  
//
//  Created by שגב  אליהו on 27/05/2025.
//
#include <stdio.h> // puts, printf, scanf
#include <stdlib.h>
#include <string.h>
/*
 Starter file to get you going!
*/
typedef union{
    int iGrade;
    char sGrade[2];
} grade;
typedef struct{
    char name[30];
    int id;
    int age;
    grade studentGrade;
} student;
typedef enum{
    TODO,
    IN_PROGRESS,
    DONE,
}status;
typedef struct{
    char name[50];
    status status;
}task;
typedef enum{
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
}Day;
typedef struct{
    char name[30];
    int id;
    int age;
    char gender[2];
    float GPA;
} student_2;
void input_student(student *ptr);
void print_student(student *ptr);
void input_student_letter(student *ptr);
void print_student_letter(student *ptr);
void* safe_malloc(size_t size);
char* read_lines(void);
int count_word(const char* text_file,char word[]);
FILE* without_spaces(const char* text_file);
int count_word(const char* text_file,char word[]);
int read_lines(const char* text_tasks);
void print_task_stauts(task tasks[],int size);
int count_done_tasks(task tasks[],int size);
void print_done_tasks(task tasks[],int size){;
const char* return_string_representation(Day today);
void csv_students(const char* students_csv);

int main(void)
{
    student s1;
    student *ptr=&s1;
    
    return 0;
}
void input_student_numeric(student *ptr)
{
    scanf("%s",ptr->name);
    scanf("%d",&ptr->id);
    scanf("%d",&ptr->age);
    scanf("%d",&ptr->studentGrade.iGrade);

}
void print_student_numeric(student *ptr)
{
    printf("%s",ptr->name);
    printf("%d",ptr->id);
    printf("%d",ptr->age);
    printf("%d",ptr->studentGrade.iGrade);

}
void input_student_letter(student *ptr)
{
    scanf("%s",ptr->name);
    scanf("%d",&ptr->id);
    scanf("%d",&ptr->age);
    scanf("%s",ptr->studentGrade.sGrade);

}
void print_student_letter(student *ptr)
{
    printf("%s",ptr->name);
    printf("%d",ptr->id);
    printf("%d",ptr->age);
    printf("%s",ptr->studentGrade.sGrade);

}
//question 2
//the purpose of this questin is to create safe malloc
void* safe_malloc(size_t size)
{
    void* ptr=malloc(size);
    if (ptr==NULL) {
        fprintf(stderr,"Error memory allocation failed\n");
        exit(1);
    }
    return ptr;
}
char* read_lines(void)
{
    size_t size=10;
    size_t len=0;
    char* line=(char*)safe_malloc(size);
    int c;
    while ((c=getchar()) !='\n' && c!=EOF) {
        if (len+1>=size){
            size *=2;
            char* temp=realloc(line,size);
            if (temp==NULL) {
                free(line);
                fprintf(stderr,"Error : realloc failed\n");
                exit(1);
            }
            line=temp;
        }
        line[len++]=(char)c;
    }
    line[len]='\0';
    printf("you entered %s\n",line);
    return line;
}
//question 3
//the purpose of this function is to generate textfile without spaces
FILE* without_spaces(const char* text_file)
{
    FILE* input=fopen(text_file,"r");
    if (input==NULL) {
        fprintf(stderr,"Failed to open file %s\n",text_file);
        exit(1);
    }
    FILE* output=fopen("no_spaces.txt","w");
    if (output==NULL) {
        fclose(input);
        fprintf(stderr,"Error creating temporary file\n");
                exit(1);
    }
    int c;
    while((c=fgetc(input)) != EOF){
        if (c!=' '){
            fputc(c,output);
        }
    }
    fclose(input);
    return output;
    
}
//question 4
// the purpose of this file is to count speciefic word in file
int count_word(const char* text_file,char word[])
{
    FILE* input=fopen(text_file,"r");
    if (input==NULL) {
        fprintf(stderr,"Failed to open file %s\n",text_file);
        exit(1);
    }
    int count=0;
    char buffer[100];
    while(fscanf(input,"%99s",buffer)==1){
        
        if (strcmp(buffer,word)==0) {
            count++;
        }
    }
    fclose(input);
    return count;
}
//question 5
//the purose of this question is te read file of list of tasks and process this file
int read_lines(const char* text_tasks)
{
    FILE* file=fopen(text_tasks,"r");
    if(file==NULL){
        fprintf(stderr,"Failed to open file %s\n",text_tasks);
        exit(1);
    }
    task tasks[100];
    char name[50];
    char status_str[20];
    int i=0;
    while(fscanf(file,"%49s %19s",name,status_str)==2){
        strcpy(tasks[i].name,name);
        if(strcmp(status_str,"TODO")==0){
            tasks[i].status=TODO;
        }
        else if(strcmp(status_str,"IN_PROGRESS")==0){
            tasks[i].status=IN_PROGRESS;
        }
        else if(strcmp(status_str,"DONE")==0){
            tasks[i].status=DONE;
        }
        i++;
    }
    fclose(file);
    return i;
    
}
void print_task_stauts(task tasks[],int size)
{
    int i=0;
    const char* status_strings[]={"TO DO","IN PROGRESS","DONE"};
    for(i=0;i<size;i++){
        printf("%d %s %s\n",i,tasks[i].name,status_strings[tasks[i].status]);
    }
}
int count_done_tasks(task tasks[],int size)
{
    int count=0;
    int i=0;
    for(i=0;i<size;i++){
        if (tasks[i].status==DONE) {
            count++;
        }
    }
    return count;
}
void print_done_tasks(task tasks[],int size){
    int i=0;
    for(i=0;i<size;i++){
        if(tasks[i].status==DONE) {
            printf("%d %s\n",i,tasks[i].name);
        }
    }
}
//question 6
//enum Day we need to return the string represetation
const char* return_string_representation(Day today)
{
    const char* day_names[]={"SUNDAY","MONDAY","TUESDAY","WEDNESDAY","THURSDAY","FRIDAY","SATURDAY"};
    return day_names[today];
}
//question 7
//the purpose of this question is process csv of students
void csv_students(const char* students_csv)
{
    FILE* input=fopen(students_csv,"r");
    if(input==NULL){
        fprintf(stderr,"Failed to open file %s\n",students_csv);
        exit(1);
    }
    student_2 students[100];
    char line[100];
    int i=0;
    int count=0;
    while (fgets(line,100,input)){
        char* token =strtok(line,",");
        strcpy(students[count].name,token);
        token=strtok(NULL,",");
        students[count].id=atoi(token);
        token=strtok(NULL,",");
        students[count].age=atoi(token);
        token=strtok(NULL,",");
        strcpy(students[count].gender,token);
        token=strtok(NULL,",");
        students[count].GPA=atof(token);
        count++;
    }
    fclose(input);
    float total_GPA=0;
    float avg_GPA=0;
    int over_25=0;
    int numbers_of_females=0;
    float sum_GPA_female=0;
    float avg_female_GPA=0;
    printf("the total numbers of students is %d\n",count);
    for(i=0;i<count;i++){
        total_GPA+=students[i].GPA;
        if(students[i].age>25){
            over_25++;
        }
        if(strcmp(students[i].gender,"F")==0){
            sum_GPA_female+=students[i].GPA;
            numbers_of_females++;
        }
    }
    avg_GPA=total_GPA/count;
    avg_female_GPA=sum_GPA_female/numbers_of_females;
    printf("the average GPA is: %f\n",avg_GPA);
    printf ("the numbers of students over 25 is: %d\n",over_25);
    printf("the average GPA of females is: %f\n",avg_female_GPA);
    
}


                
