#include<bits/stdc++.h>
#include "ConvertCharToIntegerWithShifting.cpp"

using namespace std;

void printGHeader(struct GlobalHeader gH){

    printf("GHeader : %.02x:%.02x:%0.02x:%.02x\n",gH.GHeader[0]&0xff,gH.GHeader[1]&0xff,
           gH.GHeader[2]&0xff,gH.GHeader[3]&0xff);
    printf("MajorVersionNumber : %hd\n",Convert2byteToIntegerLeftToRight(gH.MajorVersionNumber));
    printf("MinorVersionNUmber : %hd\n",Convert2byteToIntegerLeftToRight(gH.MinorVersionNUmber));
    printf("GMTTimeOffset : %d\n",Convert4byteToIntegerLeftToRight(gH.GMTTimeOffset));
    printf("sigfigs : %.02x:%.02x:%0.02x:%.02x\n",gH.sigfigs[0]&0xff,gH.sigfigs[1]&0xff,
           gH.sigfigs[2]&0xff,gH.sigfigs[3]&0xff);
    printf("MaximumSnapLength : %d\n",Convert4byteToIntegerLeftToRight(gH.MaximumSnapLength));
    printf("LinkLayerProtocol : %.02x:%.02x:%0.02x:%.02x\n",gH.LinkLayerProtocol[0]&0xff,
           gH.LinkLayerProtocol[1]&0xff,gH.LinkLayerProtocol[2]&0xff,gH.LinkLayerProtocol[3]&0xff);


}

void forUDP(unsigned char pkt[],int length){

    printf("\n\nUser Datagram protocol ....\n\n");

    unsigned char temp[2];
    temp[0]=(unsigned char)pkt[50];
    temp[1]=(unsigned char)pkt[51];
    printf("\tSource port: ----%d\n",Convert2byteToIntegerLeftToRight(temp));

    unsigned char temp1[2];
    temp1[0]=(unsigned char)pkt[52];
    temp1[1]=(unsigned char)pkt[53];
    printf("\tDestination port: ----%d\n",Convert2byteToIntegerLeftToRight(temp1));

    unsigned char temp2[2];
    temp2[0]=(unsigned char)pkt[54];
    temp2[1]=(unsigned char)pkt[55];
    printf("\tLength: ----%d\n",Convert2byteToIntegerLeftToRight(temp2));

    unsigned char temp3[2];
    temp3[0]=(unsigned char)pkt[56];
    temp3[1]=(unsigned char)pkt[57];
    printf("\tChecksum: ----%d\n",Convert2byteToIntegerLeftToRight(temp3));

    int u=0;
     printf("Data...\n");
    for(int i=58;i<length;i++){

        if(u%16==0)printf("\n");
        printf("%0.02x ",pkt[i]&0xff);
        u++;
    }

}
void forTCP(unsigned char pkt[],int length){

    printf("\n\nTransmission Control Protocol ....\n\n");

    unsigned char temp[2];
    temp[0]=(unsigned char)pkt[50];
    temp[1]=(unsigned char)pkt[51];
    printf("\tSource port: ----%d\n",Convert2byteToIntegerLeftToRight(temp));

    unsigned char temp1[2];
    temp1[0]=(unsigned char)pkt[52];
    temp1[1]=(unsigned char)pkt[53];
    printf("\tDestination port: ----%d\n",Convert2byteToIntegerLeftToRight(temp1));

    //printf("Sequence Number: "Convert4byteToIntegerLeftToRight[]);
    unsigned char temp2[4];
    temp2[0]=(unsigned char)pkt[58];
    temp2[1]=(unsigned char)pkt[59];
    temp2[2]=(unsigned char)pkt[60];
    temp2[3]=(unsigned char)pkt[61];
    printf("\tAcknowledge number: ----%d\n",Convert4byteToIntegerLeftToRight(temp2));

    printf("\tHeader length: ----%d bytes(%d)\n",4*OneByteLeftPortionConvertToInteger(pkt[62]),
           OneByteLeftPortionConvertToInteger(pkt[62]));

    printf("\tFlags: ----%.02x\n",pkt[63]&0xff);

    unsigned char temp3[2];
    temp3[0]=(unsigned char)pkt[64];
    temp3[1]=(unsigned char)pkt[65];
    printf("\twindow size value: ----%d\n",Convert2byteToIntegerLeftToRight(temp3));

    printf("\tCheckSum: ----%.02x%.02x\n",pkt[66]&0xff,pkt[67]&0xff);

    unsigned char temp4[2];
    temp4[0]=(unsigned char)pkt[68];
    temp4[1]=(unsigned char)pkt[69];
    printf("\tUrgent: ----%d\n",Convert2byteToIntegerLeftToRight(temp4));


    printf("\tOptions .........\n");

    unsigned char temp5[4];
    temp5[0]=(unsigned char)pkt[70];
    temp5[1]=(unsigned char)pkt[71];
    temp5[2]=(unsigned char)pkt[72];
    temp5[3]=(unsigned char)pkt[73];
    printf("\tMaximum segment Size: ----%d\n",Convert4byteToIntegerLeftToRight(temp5));

    printf("\tTCP option.....\n   \t\tkind: (%d)\n",Convert1byteToInteger(pkt[74]));
    printf("\tTCP option.....\n   \t\tkind: (%d)\n",Convert1byteToInteger(pkt[75]));
    printf("\tTCP option.....\n   \t\tkind:  SACK Permitted (%d)\n   \t\tLength: (%d)",
           Convert1byteToInteger(pkt[76]),Convert1byteToInteger(pkt[77]));

     int u=0;
     printf("\nData...\n");
    for(int i=78;i<length;i++){

        printf("%0.02x \n",pkt[i]&0xff);
        if(u%16==0)printf("\n");
        u++;
    }

}
void forIPv4(unsigned char pkt[],int frameLength){

    printf("\n\nTPv4........\n\n");
    printf("\tVersion : ----%d\n",OneByteLeftPortionConvertToInteger(pkt[30]));
    printf("\tHeader Length : ----%d\n",OneByteRightPortionConvertToInteger(pkt[30]));
    printf("\tDifferentiated Services field : ----0x%.02x\n",pkt[31]&0xff);

    unsigned char len[2];
    len[0]=(unsigned char)pkt[32];
    len[1]=(unsigned char)pkt[33];
    printf("\tTotal length : ----%d\n",Convert2byteToIntegerLeftToRight(len));

    printf("\tIdentification : ----0x%.02x%.02x \n",pkt[34]&0xff,pkt[35]&0xff);
    printf("\tFlags : ----0x%.02x\n",pkt[36]);

    unsigned char temp[2];
    temp[0]=(unsigned char)pkt[36];
    temp[1]=(unsigned char)pkt[37];
    printf("\tFragment Offset : ----%d\n",Convert2byteToIntegerLeftToRight(temp));

    printf("\tTime to Live : ----%d\n",Convert1byteToInteger(pkt[38]));

    unsigned int protocol = Convert1byteToInteger(pkt[39]);
    printf("\tProtocol: ----%d\n",protocol);

    printf("\tHeader checksum: ----0x%.02x%.02x\n",pkt[40]&0xff,pkt[41]&0xff);
    printf("\tSource: ----%d.%d.%d.%d\n",Convert1byteToInteger(pkt[42]),Convert1byteToInteger(pkt[43]),Convert1byteToInteger(pkt[44]),Convert1byteToInteger(pkt[45]));

    printf("\tDestination: ----%d.%d.%d.%d\n",Convert1byteToInteger(pkt[46]),Convert1byteToInteger(pkt[47]),Convert1byteToInteger(pkt[48]),Convert1byteToInteger(pkt[49]));

    if(protocol==17){
        forUDP(pkt,frameLength);
    }
    else if(protocol==6){
        forTCP(pkt,frameLength);
    }

}

void forARP(unsigned char pkt[],int length){

    printf("\n\nARP.........\n\n");

    unsigned char temp[2];
    temp[0]=(unsigned char)pkt[30];
    temp[1]=(unsigned char)pkt[31];
    printf("\tHardWare Type : ----%d\n",Convert2byteToIntegerLeftToRight(temp));

    unsigned char temp1[2];
    temp1[0]=(unsigned char)pkt[32];
    temp1[1]=(unsigned char)pkt[33];
    printf("\tProtocol Type : ----%d\n",Convert2byteToIntegerLeftToRight(temp1));

    printf("HardWare Type : ----%d\n",Convert1byteToInteger(pkt[34]));

    printf("Protocol Type : ----%d\n",Convert1byteToInteger(pkt[35]));

    unsigned char temp2[2];
    temp2[0]=(unsigned char)pkt[36];
    temp2[1]=(unsigned char)pkt[37];
    unsigned int n =  Convert2byteToIntegerLeftToRight(temp2);

    if(n==1){
        printf("Opcode : request(1)\n");
    }
    else printf("Opcode : reply(2)\n");

    printf("\tSender MAC address: ----%.02x:%.02x:%.02x:%.02x:%.02x:%.02x\n",pkt[38]&0xff,
           pkt[39]&0xff,pkt[40]&0xff,pkt[41]&0xff,pkt[42]&0xff,pkt[43]&0xff);
    printf("\tSender IP address : ----%d.%d.%d.%d\n",Convert1byteToInteger(pkt[44]),Convert1byteToInteger(pkt[45]),Convert1byteToInteger(pkt[46]),Convert1byteToInteger(pkt[47]));

    printf("\tTarget MAC address: ----%.02x:%.02x:%.02x:%.02x:%.02x:%.02x\n",pkt[48]&0xff,
           pkt[49]&0xff,pkt[50]&0xff,pkt[51]&0xff,pkt[52]&0xff,pkt[53]&0xff);
    printf("\tSender IP address : ----%d.%d.%d.%d\n",Convert1byteToInteger(pkt[54]),Convert1byteToInteger(pkt[55]),Convert1byteToInteger(pkt[56]),Convert1byteToInteger(pkt[57]));

    printf("\tPadding.........\n\n");
     int u=0;
     //printf("Data...\n");

    for(int i=59;i<length;i++){

        if(u%16==0)printf("\n");
        printf("%0.02x ",pkt[i]&0xff);
        u++;
    }
}

void printPacket(unsigned char pkt[],int framenumber,int frameLength){


    unsigned char ch1 = (unsigned char)0x08;
    unsigned char ch2 = (unsigned char)0x00;
    unsigned char ch3 = (unsigned char)0x06;

    printf("\n\n\tFrame number : ----%d\n",framenumber);
    printf("\tFrame Lenght : ----%d (with %d bits)\n",frameLength,8*frameLength);

    printf("\n\nEthernet ....\n\n");
    printf("\tDestination address: ----%.02x:%.02x:%.02x:%.02x:%.02x:%.02x\n",pkt[16]&0xff,
           pkt[17]&0xff,pkt[18]&0xff,pkt[19]&0xff,pkt[20]&0xff,pkt[21]&0xff);

    printf("\tSource address: ----%.02x:%.02x:%.02x:%.02x:%.02x:%.02x\n",pkt[22]&0xff,
           pkt[23]&0xff,pkt[24]&0xff,pkt[25]&0xff,pkt[26]&0xff,pkt[27]&0xff);

    printf("\tType: ----%.02x%.02x\n",pkt[28]&0xff,pkt[29]&0xff);
    if(ch1==pkt[28] && ch2==pkt[29]){
        //printf("Its IPv4");
        forIPv4(pkt,frameLength);
    }
    else if(ch1==pkt[28] && ch3==pkt[29]){
        //printf("Its ARP\n");
        forARP(pkt,frameLength);
    }

}


