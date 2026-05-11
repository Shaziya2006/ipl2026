#include<stdio.h>
#include<stdlib.h>
void storerecord(char filename[],int n);
void getrecord(char filename[],int m);
void deleterecord(char filename[],int del);
struct student {
    int id;
    char name[50];
    float marks;
};
int main() {
    int n, m,del;
    char filename[]="student.dat";
    printf("enter number of  records:\n");
    scanf("%d",&n);
    storerecord(filename,n);
    printf("enter record number to be display:\n");
    scanf("%d",&m);
    getrecord(filename,m);
    printf("enter the record number to delete:");
    scanf("%d",&del);
    deleterecord(filename,del);
    FILE *fp;
struct student s;

fp = fopen(filename, "rb");

if (fp == NULL)
{
    printf("File cannot be opened\n");
    return 1;
}

printf("\nRecords after deletion:\n");

while (fread(&s, sizeof(struct student), 1, fp))
{
    printf("\nID    : %d\n", s.id);
    printf("Name  : %s\n", s.name);
    printf("Marks : %.2f\n", s.marks);
}

fclose(fp);
    return 0;

}
void storerecord(char filename[],int n){
    struct student s;
    FILE *fp;
    fp = fopen(filename,"wb");
    if(fp==NULL){
        printf("file cannot be opened\n");
        return;
    }
    for (int i=0;i<n;i++){
        printf("enter details of student %d:\n",i+1);
        printf("enter id:");
        scanf("%d",&s.id);
        printf("enter name:");
        scanf("%s",s.name);
        printf("enter marks:");
        scanf("%f",&s.marks);
        fwrite(&s,sizeof(struct student),1,fp);
    }
    fclose(fp);

}
void getrecord(char filename[],int m){
    FILE* fp;
    struct student s;
    fp=fopen(filename,"rb");
    if(fp==NULL){
        printf("file cannot be opened\n");
        return;
    }
    fseek(fp,(m-1)*sizeof(struct student),SEEK_SET);
    if(fread(&s,sizeof(struct student),1,fp)==1){
        printf("student details:");
        printf("Id: %d\n",s.id);
        printf("NAME:%s\n",s.name);
        printf("marks:%.2f\n",s.marks);
    }
    else{
        printf("record not found");
    }
    fclose(fp);
}
void deleterecord(char filename[],int del){
    FILE *fp,*temp;
    struct student s;
    int count=1;
    fp=fopen(filename,"rb");
    temp=fopen("temp.dat","wb");
    if(fp==NULL|| temp==NULL){
        printf("file cannot open");
        return;
    }
    while(fread(&s,sizeof(struct student),1,fp)){
        if(count != del){
            fwrite(&s,sizeof(struct student),1,temp);
        }
        count++;
    }
    fclose(fp);
    fclose(temp);
    // renaming the file and removing the old file
    remove(filename);
    rename("temp.dat",filename);
    printf("record %d deleted sucessfully\n",del);
}

