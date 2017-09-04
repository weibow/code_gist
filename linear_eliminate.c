    /*======================================================  
      
     # Author:      Joker@HIT    NolanRobot@163.com  
     # Filetype:    C source code  
     # Environment: Linux & Ubuntu 14.04  
     # Tool:        Vim & Gcc  
     # Date:        Mon Aug 22 2016  
     # Descprition: Solve the AX=b by the Guass Elimination!  
      
    ========================================================*/  
      
    #include<stdio.h>  
    #include<math.h>  
      
    #define ROW 100  
    #define COL 100  
      
    void get_coefficient(double [][COL], int, int);  
    void get_vector(double [], int);  
    void create_Ab(double [][COL], double [], int, int);  
    void show_matrix(double [][COL], int, int);  
    int guass_elimination(double *[ROW], int, int);  
    void exchange_row(double *[ROW], int, int);  
    void show_solution(double *[ROW], int, int);  
      
    int main(void)  
    {  
        double Receptacle[ROW][COL];  
        double Vector[ROW];  
        double *Ab_pointer[ROW];  
        int row, col, i, result;  
      
        printf("Enter the coefficient matrix's size (less than %d * %d): ", ROW, COL-1);  
        while(scanf("%d%d", &row, &col)==2){  
            get_coefficient(Receptacle, row, col);  
            get_vector(Vector, row);  
            create_Ab(Receptacle, Vector, row, col);  
      
            printf("The linear equations in the form of augmented matrix as follow:\n");  
            show_matrix(Receptacle, row, col+1);  
              
            for(i=0;i<ROW;i++)  
                Ab_pointer[i] = Receptacle[i];  
      
            result = guass_elimination(Ab_pointer, row, col+1);  
            if(result==1){  
                printf("There are infinite solutions for the linear equations!\n");  
                show_solution(Ab_pointer, row, col+1);  
            }  
            else if(result==0){  
                printf("There is only one solution for the linear equations!\n");  
                show_solution(Ab_pointer, row, col+1);  
            }  
            else  
                printf("There is no solution for the linear equations!\n");  
                  
            printf("Enter the coefficient matrix's size (less than %d * %d, q to quit): ", ROW, COL-1);  
        }  
        printf("Bye!\n");  
      
        return 0;  
    }  
      
    void get_coefficient(double matrix[ROW][COL], int row, int col)  
    {  
        int i, j;  
      
        printf("Enter the coefficient (%d * %d):\n", row, col);  
        for(i=0;i<row;i++)  
            for(j=0;j<col;j++)  
                scanf("%lf", &matrix[i][j]);  
      
        return;  
    }  
      
    void get_vector(double vector[ROW], int n)  
    {  
        int i;  
      
        printf("Enter the vector (size is %d):\n", n);  
        for(i=0;i<n;i++)  
            scanf("%lf", &vector[i]);  
      
        return;  
    }  
      
    void create_Ab(double matrix[ROW][COL], double vector[ROW], int row, int col)  
    {  
        int i;  
      
        for(i=0;i<row;i++)  
            matrix[i][col] = vector[i];  
      
        return;  
    }  
      
    void show_matrix(double matrix[ROW][COL], int row, int col)  
    {  
        int i, j;  
      
        for(i=0;i<row;i++){  
            for(j=0;j<col;j++)  
                printf("%-8.3f", matrix[i][j]);  
            putchar('\n');  
        }  
      
        return;  
    }  
      
    int guass_elimination(double *matrix[ROW], int row, int col)  
    {  
        int result, i, j, k;  
        double coe;  
      
        for(i=0;i<row-1;i++){  
            exchange_row(matrix, i, row);  
            if(fabs(*(matrix[i]+i))<0.00001)  
                continue;  
            for(j=i+1;j<row;j++){  
                coe = *(matrix[j]+i) / *(matrix[i]+i);  
                for(k=i;k<col;k++)  
                    *(matrix[j]+k) -= coe * *(matrix[i]+k);  
            }  
        }  
      
        if(col-1>row)  
            result = 1;  
        else if(col-1==row){  
            if(fabs(*(matrix[row-1]+row-1))>0.00001)  
                result = 0;  
            else{  
                if(fabs(*(matrix[row-1]+row))>0.00001)  
                    result = -1;  
                else  
                    result = 1;  
            }  
        }  
        else{  
            result = 0;  
            for(i=0;i<row;i++)  
                if(fabs(*(matrix[i]+col-2))<0.00001&&fabs(*(matrix[i]+col-1))>0.00001){  
                    result = -1;  
                    break;  
                }  
        }  
      
      
        return result;  
    }  
      
    void exchange_row(double *matrix[ROW], int flag, int row)  
    {  
        int i;  
        double *temp;  
      
        for(i=flag+1;i<row;i++)  
            if(fabs(*(matrix[flag]+flag))<fabs(*(matrix[i]+flag))){  
                temp = matrix[flag];  
                matrix[flag] = matrix[i];  
                matrix[i] = temp;  
            }  
      
        return;  
    }  
      
    void show_solution(double *matrix[ROW], int row, int col)  
    {  
        int i, j;  
      
        for(i=0;i<row;i++){  
            for(j=0;j<col;j++)  
                printf("%-8.3f", *(matrix[i]+j));  
            putchar('\n');  
        }  
      
        return;  
    }  