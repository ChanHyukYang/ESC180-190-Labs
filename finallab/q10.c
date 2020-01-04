int nsum( float*a, float* b, int n, float** output){
   int i = 0;
   *output = (float*)malloc(n*sizeof(float));
   if (a == NULL || b == NULL || output==NULL){
      return -1;
   }
   for(i=0; i<n;i=i+1){
      (*output)[i] = a[i] + b[i]; 
   }
   return 0;
}
