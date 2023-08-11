#include<stdio.h>
int main()
{
    FILE *inputFile;
    inputFile=fopen("input.txt","r");
    FILE *outputFile;
    if(inputFile==NULL)
    {
        fprintf(outputFile,"No File found\n");
        return 0;
    }
    outputFile=fopen("output.txt","w");
    int n;
    fscanf(inputFile,"%d",&n);
    int sum=0;
    for(int i=0;i<n;i++)
    {
        int a;
        fscanf(inputFile,"%d",&a);
        sum+=a;
    }
    fprintf(outputFile,"%d\n",sum);
    fclose(inputFile);
    fclose(outputFile);
    return 0;
}