#include<bits/stdc++.h>
#include "headerFormat.cpp"
#include "printPacket.cpp"


using namespace std;

unsigned char packets[1000][10000];
unsigned char packetlen[5000];
unsigned char Eheader[14];
unsigned char IPv4H[20];
unsigned char tcpH[20];
unsigned char udp[20];
unsigned char arpH[30];
unsigned int lenStore[200];


unsigned int Convert(unsigned char arr[]){

    unsigned int itsInteger;
    itsInteger = arr[0];
    itsInteger = itsInteger<<8|arr[1];
    itsInteger = itsInteger<<8|arr[2];
    itsInteger = itsInteger<<8|arr[3];
    return itsInteger;

}

int sparceThebuffer(unsigned char buffer[],int packetCount,int packetWants){


    for(int i=0;i<100000;i++){

        unsigned char pktLen[4];
        int h=0;

        for(int j=i+8;j<i+12;j++){
            pktLen[h] = buffer[j];
            h++;
        }
        unsigned int pktlen = Convert(pktLen);
        //printf("\n %u ",pktlen);
        pktlen+=16;
        lenStore[packetCount] = pktlen;

        printf("\n\n\npacket number is %d \n",packetCount+1);
        for(h=0;h<pktlen;h++){
            packetlen[h] = buffer[h+i];
            packets[packetCount][h]=buffer[i+h];
            if(h%16==0)printf("\n");
            printf("%.02x ",buffer[h+i]&0xff);

        }

        printPacket( packetlen,packetCount,pktlen);

        packetCount++;
        i=pktlen+i-1;
        //printf("\n  %d  %d\n",i,packetCount);
        if(packetWants==packetCount)return packetCount;


    }

return packetCount;
}

int main(){


    printf("How many packet do you want \n");
    int packetWants;
    scanf("%d",&packetWants);

    FILE *fp;
    fp = fopen("sai.pcap","rb");

    //unsigned char globalHeader[24];
    struct GlobalHeader gH;
    //unsigned char *buffer = new unsigned char [65536];
    unsigned char buffer [300000];

    fread(&gH,sizeof(GlobalHeader),1,fp);
    printGHeader(gH);
    int packetCount=0;


    while(1){

        fread(buffer,sizeof(buffer),1,fp);
        //printf("%.02x",buffer[22]&0xff);
        packetCount+=sparceThebuffer(buffer,packetCount,packetWants);
        if(packetCount>=packetWants)break;
    }

    //for(unsigned int i=0;i<packetWants;i++)printf("%d ",lenStore[i]);

    return 0;

}

