#include <stdio.h>
#include <stdlib.h>

int ge_fw(float *matrix, int rows, int cols, float *matrix_out){
   int i=0;
   int j=0; 
   int index=0;
   int first=0;
   float *m = NULL;
   float *m2 = NULL;
   float t = 0;
   float k = 0;

   if (matrix == NULL){
      return -1;
}
   if (matrix_out == NULL){
      return -1;
}
   if (rows == 0){
      return 0;
}

   index = -1;
   first = -1;
   for (i = 0; i < cols; i += 1){
      for (j = 0; j < rows; j += 1){
        if (matrix[j * cols + i] != 0){
           index = j;
           first = i;
           break;
}
}

      if (index != -1){
         break;
}
}

     if (index == -1){
        for (i = 0; i < rows; i += 1)
           for (j = 0; j < cols; j += 1)
              matrix_out[i * cols + j] = 0;
        }
        else{
           m = (float*)malloc(sizeof(float) * rows * cols);

           for (i = 0; i < rows; i += 1)
              for (j = 0; j < cols; j += 1)
                 m[i * cols + j] = matrix[i * cols + j];

                for (i = 0; i < cols; i += 1){
                   t = m[i];
                   m[i] = m[index * cols + i];
                   m[index * cols + i] = t;
                }

                for (i = 1; i < rows; i += 1){
                   k = m[i * cols + first] / m[first];

                for (j = first; j < cols; j += 1)
                   m[i * cols + j] -= k * m[j];
                }

                for (i = 0; i < cols; i += 1)
                        matrix_out[i] = m[i];

                m2 = (float*)malloc(sizeof(float) * (rows - 1) * cols);
                ge_fw(&(m[cols]), rows - 1, cols, m2);
                for (i = 1; i < rows; i += 1)
                        for (j = 0; j < cols; j += 1)
                                matrix_out[i * cols + j] = m2[(i - 1) * cols + j];
        }

        free(m);
        free(m2);

        return 0;
}

int ge_bw(float *matrix, int rows, int cols, float *matrix_out){
   int index = 0;
   int i = 0;
   int j = 0;
   int flag = 0;
   float k = 0;
   float *m = NULL;
   float *m2 = NULL;

   if (matrix == NULL){
     return -1;
}  if (matrix_out == NULL){
     return -1;
}
   if (rows == 0)
     return 0;

    index = -1;
    for (i = rows - 1; i >= 0; i -= 1){
       for (j = 0; j < cols; j += 1)
          if (matrix[i * cols + j] != 0){
             index = i;
             k = matrix[i * cols + j];
             break;
}

          if (index != -1)
             break;
        }

   m = (float*)malloc(sizeof(int) * rows * cols);
   if (index != -1){
      for (i = 0; i < rows; i += 1)
         for (j = 0; j < cols; j += 1)
            m[i * cols + j] = matrix[i * cols + j];

                for (i = 0; i < cols; i += 1)
                   m[index * cols + i] /= k;

                for (i = 0; i < index; i += 1){
                   k = 0;
                   flag = 0;
                   for (j = 0; j < cols; j += 1){
                      if (flag == 0 && m[index * cols + j] != 0){
                        flag = 1;
                        k = m[i * cols + j] / m[index * cols + j];
}

                      m[i * cols + j] -= k * m[index * cols + j];
}
}

                   for (i = index; i < rows; i += 1)
                           for (j = 0; j < cols; j += 1)
                                   matrix_out[i * cols + j] = m[i * cols + j];

                   m2 = (float*)malloc(sizeof(float) * index * cols);
                   ge_bw(m, index, cols, m2);

                   for (i = 0; i < index; i += 1)
                           for (j = 0; j < cols; j += 1)
                                   matrix_out[i * cols + j] = m2[i * cols + j];
        }

        return 0;
}
