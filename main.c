#include <stdio.h>

#define NUM_COLS 3


void print_array(int array[], int len);
void print_matrix(int m[][NUM_COLS], int num_rows);
void get_location_of_min(int matrix[][NUM_COLS], int num_rows, int* location_row, int* location_col);
void get_location_of_max(int matrix[][NUM_COLS], int num_rows, int* location_row, int* location_col);
void swap_min_max_values(int matrix[][NUM_COLS], int num_rows);

void print_matrix_pointers(int* matrix[], int num_rows, int num_cols);
void matrix_transpose_pointers(int* m1[], int* m_result[], int num_rows, int num_cols);
void matrix_multiply_by_vector_pointers(int* matrix[], int vector[], int v_result[], int num_rows, int num_cols);
void matrix_multiply_pointers(int* m1[], int* m2[], int* m_result[], int num_rows_m1, int num_cols_m1, int num_cols_m2);



int main (void) {

    // test your functions here!
    int T [5][NUM_COLS]=    {{1,2,3},
                            {4,5,6},
                            {7,8,9},
                            {10,11,12},
                            {13,14,15}};

    int row=0;int col=0;

    int* locrow=&row;
    int* loccol = &col;

    get_location_of_min(T,5,locrow,loccol);
    printf("\n");


    int row1=0;int col1=0;
    int* locrow1=&row1;
    int* loccol1 = &col1;
    get_location_of_max(T,5,locrow1,loccol1);
    swap_min_max_values(T, 5);
    printf("\n\n");

    printf("\n");
    int a[NUM_COLS]= {1,2,3};
    int b[NUM_COLS]= {4,5,6};
    int c[NUM_COLS]= {7,8,9};
    int d[NUM_COLS]= {10,11,12};
    int e[NUM_COLS]=  {13,14,15};


    int* T1 [5]    = {a,b,c,d,e};


//Test for matrix_transpose_pointers
    printf("This is a test for matrix_transpose_pointers:\n");


    int b1[] = {1,2,3};
    int b2[] = {4,5,6};
    int b3[] = {7,8,9};
    int* T5[3] ={b1,b2,b3};

    int c1[] = {1,4,3};
    int c2[] = {4,4,6};
    int c3[] = {7,4,9};
    int* T4[3]={c1,c2,c3};

    matrix_transpose_pointers(T5,T4,3,3);


    printf("\n");

    printf("This is a test for matrix_multiply_by_vector_pointers:\n");
    int g1[] = {1,2,2};
    int g2[] = {0,2,1};
    int* T8[2] = {g1,g2};

    int t_vector[] = {2,1,0};
    int result[2];

    matrix_multiply_by_vector_pointers(T8,t_vector,result,2,3);
    print_array(result,2);

    int g22[] = {0,0,0};
    int g3[] = {0,0,0};
    int* T11[2] = {g22,g3};



    printf("\n");

    matrix_multiply_pointers(T8,T5,T11,2,3,3);
    print_matrix_pointers(T11,2,3);

    return 0;
}


// Purpose: prints values in array on one line with space after each
// Params:  int array[], int len - number of elements in array
// Returns: nothing
void print_array(int array[], int len){
    int i;
    for(i=0; i<len; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void print_matrix(int m[][NUM_COLS], int num_rows){
    for (int i = 0; i < num_rows; ++i) {
        for (int j = 0; j < NUM_COLS; ++j) {
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
}

void get_location_of_min(int matrix[][NUM_COLS], int num_rows, int* location_row, int* location_col){
int min = matrix[0][0];

int arraymaxrows[num_rows];
int counter=0;

    for (int i = 0; i < num_rows ; ++i) {
        for (int j = 0; j < NUM_COLS; ++j) {
            if (matrix[i][j] < min){
                min = matrix[i][j];
            }
        }
    }

    for (int k = 0; k < num_rows ; ++k) {
        for (int i = 0; i < NUM_COLS; ++i) {
            if (matrix[k][i] == min){
                arraymaxrows[counter] = k;
                //printf("%d  ",arraymaxrows[counter]);
                counter++;
            }
        }
    }





    int maxrow = arraymaxrows[0];

    for (int l = 0; l < counter; ++l) {
        if (arraymaxrows[l]>maxrow){
            maxrow = arraymaxrows[l];
        }
    }

    int minfinal = matrix[maxrow][0];

    int array_of_min_in_a_row[5]={111,111,111,111,111};
    int coumty=0;

    for (int m = 0; m < NUM_COLS ; ++m) {
        if (matrix[maxrow][m] == min ){
            array_of_min_in_a_row[coumty] = m;
            coumty++;
        }
    }

    int max_column = array_of_min_in_a_row[0];

    for (int n = 0; n < coumty ; ++n) {
        if (array_of_min_in_a_row[n] > max_column){
            max_column = array_of_min_in_a_row[n];
        }
    }
    *location_col = max_column;
    *location_row = maxrow;

}


void get_location_of_max(int matrix[][NUM_COLS], int num_rows, int* location_row, int* location_col){


    int max = matrix[0][0];

    int arraymaxrows[num_rows];
    int counter=0;

    for (int i = 0; i < num_rows ; ++i) {
        for (int j = 0; j < NUM_COLS; ++j) {
            if (matrix[i][j] > max){
                max = matrix[i][j];
            }
        }
    }

    for (int k = 0; k < num_rows ; ++k) {
        for (int i = 0; i < NUM_COLS; ++i) {
            if (matrix[k][i] == max){
                arraymaxrows[counter] = k;
                //printf("%d  ",arraymaxrows[counter]);
                counter++;
            }
        }
    }





    int maxrow = arraymaxrows[0];

    for (int l = 0; l < counter; ++l) {
        if (arraymaxrows[l]>maxrow){
            maxrow = arraymaxrows[l];
        }
    }

    int minfinal = matrix[maxrow][0];

    int array_of_min_in_a_row[5]={111,111,111,111,111};
    int coumty=0;

    for (int m = 0; m < NUM_COLS ; ++m) {
        if (matrix[maxrow][m] == max ){
            array_of_min_in_a_row[coumty] = m;
            coumty++;
        }
    }

    int max_column = array_of_min_in_a_row[0];

    for (int n = 0; n < coumty ; ++n) {
        if (array_of_min_in_a_row[n] > max_column){
            max_column = array_of_min_in_a_row[n];
        }
    }
    *location_col = max_column;
    *location_row = maxrow;

}


void swap_min_max_values(int matrix[][NUM_COLS], int num_rows){

    int row1=0;int col1=0;
    int* locrow1=&row1;
    int* loccol1 = &col1;

    int row=0;int col=0;
    int* locrow=&row;
    int* loccol = &col;

    get_location_of_min(matrix,num_rows,locrow1,loccol1);
    get_location_of_max(matrix,num_rows,locrow,loccol);

    int max = 0;
    int min = 0;

    max = matrix[row][col];
    min = matrix[row1][col1];
    matrix[row][col] = min;
    matrix[row1][col1] = max;

    for (int i = 0; i < num_rows ; ++i) {
        for (int j = 0; j < NUM_COLS; ++j) {

        }
    }

}


void print_matrix_pointers(int* matrix[], int num_rows, int num_cols){

    for (int i = 0; i < num_rows; ++i) {
        for (int j = 0; j < num_cols; ++j) {
            printf("%d  ", matrix[i][j]);
        }
        printf("\n");
    }

}

void matrix_transpose_pointers(int* m1[], int* m_result[], int num_rows, int num_cols){

    for (int i = 0; i < num_cols; ++i) {
        for (int j = 0; j < num_rows; ++j) {
            m_result[i][j]= m1[j][i];
        }
    }



    print_matrix_pointers(m_result,num_cols,num_rows);
}



void matrix_multiply_by_vector_pointers(int* matrix[], int vector[], int v_result[], int num_rows, int num_cols){
    int count = 0;
    int sum = 0;

    for (int i = 0; i <num_rows ; ++i) {
        sum=0;
        for (int j = 0; j < num_cols ; ++j) {
            sum = sum + (matrix[i][j]*vector[j]);
        }
        v_result[count]= sum;
        count++;

    }


}

void matrix_multiply_pointers(int* m1[], int* m2[], int* m_result[], int num_rows_m1, int num_cols_m1, int num_cols_m2){

    int sum_of_row_times_column = 0;
    for (int i = 0; i < num_rows_m1 ; ++i) {
        for (int j = 0; j < num_cols_m2 ; ++j) {
            for (int k = 0; k < num_cols_m1 ; ++k) {
                sum_of_row_times_column = sum_of_row_times_column + (m1[i][k] * m2[k][j]);

            }
            m_result[i][j] = sum_of_row_times_column;
            sum_of_row_times_column=0;

        }
    }


}