#include<bits/stdc++.h>

using namespace std;

unsigned int* failure(string str){
    
    unsigned int f [20];
    unsigned int k=0,q;
    f[0]=0;
    for(q=1;q<12;q++){
    
        while(k>0&&str[q]!=str[k])
            k = f[k-1];
        if(str[q]==str[k])
            k=k+1;
        f[q]=k;
        //cout<<k<<endl;
    }
    
    return f;
}

void UDP(unsigned char pkt[],int length){
    
        unsigned char arr[2048];
            
        for(int i=16;i<length;i++){
        
            arr[i-16]=(unsigned char)pkt[i]&0xff;
        }
        
        unsigned int *fb = failure("facebook.com");
        //char arr[]={"....www.facebook.com.....www.youtube.com......"};
        unsigned char strFb[20] =  "facebook.com";
        
        
            unsigned int k=0,q;
            //f[0]=0;
            for(q=1;q<length;q++){
            
                while(k>0&&arr[q]!=strFb[k])
                    k = fb[k-1];
                if(arr[q]==strFb[k])
                    k=k+1;
                if(k==12){
                    cout<<"facebook found at index"<<q-15<<endl;
                }
                
            }
         
         unsigned int *yt = failure("youbetube.com");
         unsigned char strYt[20] = "youbetube.com" ;
         //strncpy(strYt, "www.youbetube.com",strlen("www.youbetube.com")+1);
         k=0;
            for(q=1;q<length;q++){
            
                while(k>0&&arr[q]!=strYt[k])
                    k = yt[k-1];
                if(arr[q]==strYt[k])
                    k=k+1;
                if(k==12){
                    cout<<"youtube found at index"<<q-11<<endl;
                }
                //cout<<k<<endl;
            }
    
    
}

void IPv4(unsigned char pkt[],int frameLength){

    unsigned int protocol = Convert1byteToInteger(pkt[39]);

    if(protocol==17){
        UDP(pkt,frameLength);
    }
    
}

void kmpsearch(unsigned char pkt[],int frameNum,int length){
       
        unsigned char ch1 = (unsigned char)0x08;
        unsigned char ch2 = (unsigned char)0x00;
        
        if(ch1==pkt[28] && ch2==pkt[29]){
            //printf("Its IPv4");
            IPv4(pkt,length);
        }

    

        //strncpy(strFb, "www.facebook.com",strlen("www.facebook.com")+1);
        //unsigned char arr[2080];
               
}
