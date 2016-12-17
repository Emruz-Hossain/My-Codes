 int read(void)
 {
     int sm=0;
     while(1)
     {
        int c = getchar_unlocked();
         if(c<'0'||c>'9')
            break;
         else
            c=c-'0';
        sm=sm*10+c;
     }
     return sm;
 }
