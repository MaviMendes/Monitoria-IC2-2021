#include <stdio.h>

//procedure merge(X,Y,Z)
//Leia registro x de X
//Leia registro y de Y
//while (not X.EOF() and
//not Y.EOF())do
//if x.key < y.key then
//Escreva x em Z
//Leia x do arquivo X
//else
//Escreva y em Z
//Leia y do arquivo Y
//endif
//endwhile

void mergeFiles(FILE *Z)
{
    FILE *fx = fopen("A.txt","r");
    FILE *fy = fopen("B.txt","r");
    
    int dataX, dataY;
    
    fscanf(fx, "%d", &dataX);
    //fread(&dataX,sizeof(int),1,fx);
    //fread(&dataY,sizeof(int),1,fy);
    fscanf(fy, "%d", &dataY);

    while((!feof(fx)) && (!feof(fy)))
    {
        
        
        if(dataX < dataY)
        {
            //fwrite(&dataX,sizeof(int),1,Z);
            fprintf(Z," %d ",dataX);
            printf("x<y\n");
            //fwrite(&dataX,sizeof(int),1,stdout);
            fprintf(stdout,"%d \n",dataX);
            //fread(&dataX,sizeof(int),1,fx);
            fscanf(fx, "%d", &dataX);
        }
        else 
        {
            //fwrite(&dataY,sizeof(int),1,Z);
            fprintf(Z," %d ",dataY);
            printf("y<x\n");
            //fwrite(&dataY,sizeof(int),1,stdout);
            fprintf(stdout,"%d\n",dataY);
            //fread(&dataY,sizeof(int),1,fy);
            fscanf(fy, "%d", &dataY);
        }
        
    }

    if(!feof(fy))
    {
        while(!feof(fy))
        {
            printf("resto de y\n");
            fscanf(fy, "%d", &dataY);
            fprintf(Z," %d ",dataY);
            //fread(&dataY,sizeof(int),1,fy);
            //fwrite(&dataY,sizeof(int),1,Z);
        }
    }

    if(!feof(fx))
    {
        while(!feof(fx))
        {   
            printf("resto de x\n");
            fscanf(fx, "%d", &dataX);
             fprintf(Z," %d ",dataX);
            //fread(&dataX,sizeof(int),1,fx);
            //fwrite(&dataX,sizeof(int),1,Z);
        }
    }

    fclose(fx);
    fclose(fy);
}
int main()
{
    FILE *file;
    
    file = fopen("C.txt","w+");

    mergeFiles(file);
    
    fclose(file);
    return 0;
}