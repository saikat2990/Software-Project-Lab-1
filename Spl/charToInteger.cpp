#include<bits/stdc++.h>
#include<bitset>

using namespace std;

/// LeftToRight---------------------

unsigned int Convert4byteToIntegerLeftToRight(unsigned char arr[]){

    unsigned int itsInteger;
    itsInteger = arr[0];
    itsInteger = itsInteger<<8|arr[1];
    itsInteger = itsInteger<<8|arr[2];
    itsInteger = itsInteger<<8|arr[3];
    return itsInteger;

}

unsigned short int Convert2byteToIntegerLeftToRight(unsigned char arr[]){

    unsigned short int itsInteger;
    itsInteger = arr[0];
    itsInteger = itsInteger<<8|arr[1];
    return itsInteger;

}

///RightToLeft----------------------

unsigned int Convert4byteToIntegerRightToLeft(unsigned char arr[]){

    unsigned int itsInteger;
    itsInteger = arr[3];
    itsInteger = itsInteger<<8|arr[2];
    itsInteger = itsInteger<<8|arr[1];
    itsInteger = itsInteger<<8|arr[0];
    return itsInteger;

}

unsigned short int Convert2byteToIntegerRightToLeft(unsigned char arr[]){

    unsigned short int itsInteger;
    itsInteger = arr[1];
    itsInteger = itsInteger<<8|arr[0];
    return itsInteger;

}

unsigned int Convert1byteToInteger(unsigned char ch){

    unsigned int itsInteger;
    itsInteger = (int)ch;
    return itsInteger;
}

unsigned int OneByteLeftPortionConvertToInteger(unsigned char ch){

    unsigned int itsInteger;
    itsInteger = ch;
    itsInteger = itsInteger>>4;
    return itsInteger;

}

unsigned int OneByteRightPortionConvertToInteger(unsigned char ch){

    unsigned int itsInteger;
    itsInteger = ch;
    itsInteger = itsInteger<<28;
    itsInteger = itsInteger>>28;
    return itsInteger;

}

///main------------

/*int main(){

    FILE *fp;
    fp = fopen("sai.pcap","rb");

    unsigned char arr[2];
    unsigned char ch;

    fseek(fp,52,SEEK_SET);
    fread(&ch,1,1,fp);
    arr[0] = ch;
    fread(&ch,1,1,fp);
    arr[1] = ch;
    fread(&ch,1,1,fp);
    arr[2] = ch;
    /*fread(&ch,1,1,fp);
    arr[3] = ch;
    */
   /* cout<<OneByteRightPortionConvertToInteger( ch);

return 0;
}*/

