//
//  targil2.c
//  
//
//  Created]\by שגב  אליהו on 25/05/2025.
//
#include <stdio.h>
#include <string.h>
int sum_of_elements(int arr[],int size);
void reverse_array(int arr[],int size);
void count_even_odd(int arr[],int size);
int remove_element(int arr[],int size,int val);
void duplicate_in_array(int arr[],int size);
void replace_asterisk(char* string1,char* string2);
void delete_chars(char* string1,char* string2);
int two_sum(int arr[],int size,int target);
int main(void){
//    int arr[]={1,3,3,1,3,3};
//    printf("the sum of the elements is %d\n",sum_of_elements(arr,6));
//    reverse_array(arr,6);
//    printf("the new reverse array is :\n");
//    for(int i=0;i<6;i++){
//        printf("%d",arr[i]);
//    }
//    printf("\n");
//    count_even_odd(arr,6);
//    remove_element(arr,6,1);
//    int new_size=remove_element(arr,6,1);
//    for(int i=0;i<new_size;i++){
//        printf("%d",arr[i]);
//    }
//    printf("\n");
//    duplicate_in_array(arr,6);
//    int two_sum(int arr[],int size,int target);
    char str1[]="hello world";
    char str2[]="he";
//     replace_asterisk(str1,str2);
    delete_chars(str1,str2);
    return 0;
}
//question 1
//the purpose of this function is to the element of the array
int sum_of_elements(int arr[],int size){
    int i=0;
    int sum=0;
    for(i=0;i<size;i++){
        sum+=arr[i];
    }
    return sum;
}
//question 2
//the purpose of this question is to reverse the sequence of the array by using pointer.
void reverse_array(int arr[],int size){
    int *left=arr;
    int *right=arr+size-1;
    int temp;
    while(left<right){
        temp=*left;
        *left=*right;
        *right=temp;
        left++;
        right--;
    }
}
//question 3
//the purpose of this function is to count how many numbers are even and how many numbers arr odd
void count_even_odd(int arr[],int size){
    int i=0;
    int even=0;
    int odd=0;
    for(i=0;i<size;i++){
        if(arr[i]%2==0){
            even++;
        }
        else{
            odd++;
        }
    }
    
    printf("the numbers of the even numbers in the array is: %d\n",even);
    printf("the numbers of the odd numbers in the array is: %d\n",odd);
}
//question 4
//the purpose of this question is to copy the constest of one array to another array
void copy_array(int *arr1,int *arr2,int size){
    int i=0;
    for(i=0;i<size;i++){
        *(arr1+i)=*(arr2+i);
    }
}
//question 5
//the purpose of this function is to remove specified elements for array the specified elements are the elements that equal to the value
int remove_element(int arr[],int size,int val){
    int i=0;
    int k=0;
    for(i=0;i<size;i++){
        if (arr[i]!=val){
            arr[k]=arr[i];
            k++;
            
        }
    }
    return k;
}
//question 6
//the purpose of this function is to find duplicate in array and print
void sort_list(int arr[],int size){
    int i=0;
    int temp;
    while(i<size-1){
        if(arr[i]>arr[i+1]){
            temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
            i=0;
        }
        else{
            i++;
        }
    }
}
void duplicate_in_array(int arr[],int size){
    sort_list(arr,size);
    int i=0;
    for(i=0;i<size-1;i++){
        if(arr[i]==arr[i+1]){
            if(i==0 || arr[i]!=arr[i-1]){
                printf("the duplicate number is: %d\n",arr[i]);
            }
        }
    }
}
//question 7
//the purpose of this function is to sum each i to i+1
void compute_prefix_sums(int arr[],int size){
    int i=0;
    for(i=1;i<size;i++){
        arr[i]+=arr[i-1];
    }
}
//question 8
//the purpose of this question is to return if we can achive 2 sum with used specifc list
int two_sum(int arr[],int size,int target){
    sort_list( arr,size);
    int left=0;
    int right=size-1;
    while(left<right){
        if((arr[left]+arr[right])==target){
            return 1;
        }
        else if((arr[left]+arr[right])>target){
            right--;
        }
        else{
            left++;
        }
    }
    return 0;
}
//question 9
//the purpose of this function is to rotate each element one position left
void rotate_left(int arr[],int size){
    int i=0;
    int first_index=arr[0];
    for(i=0;i<size-1;i++){
        arr[i]=arr[i+1];
    }
    arr[size-1]=first_index;
}
//question 10
//the purpose of this question is to reverse a string
void reverse_string(char* string){
    int left=0;
    int right=0;
    int temp;
    while(left<right){
        temp=string[left];
        string[left]=string[right];
        string[right]=temp;
        left++;
        right--;
    }
    
}
//question 11
//the purpose of this function is to replace each occurence of the string 2 in the string 1 with *
void replace_asterisk(char* string1,char* string2){
    int len1=strlen(string1);
    int len2=strlen(string2);
    int i=0;
    int j=0;
    for(i=0;i<len1;i++){
        for(j=0;j<len2;j++){
            if(string1[i]==string2[j]){
                string1[i]='*';
                break;
            }
        }
    }
    printf("the new string1 is: %s\n",string1);
    
}
//question 12
//the purpose of this function is to delete each char from string 1 that equal to string 2
void delete_chars(char* string1,char* string2){
    int i=0;
    int k=0;
    replace_asterisk(  string1, string2);
    for(i=0;string1[i]!='\0';i++){
        if(string1[i]!='*'){
            string1[k]=string1[i];
            k++;
        }
    }
    string1[k]='\0';
    printf("the new string1 is %s\n",string1);
}
