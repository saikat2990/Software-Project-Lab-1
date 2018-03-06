struct GlobalHeader{

    //24 bytes

    unsigned char  GHeader[4];
    unsigned char  MajorVersionNumber[2];
    unsigned char  MinorVersionNUmber[2];
    unsigned char  GMTTimeOffset[4];
    unsigned char  sigfigs[4];
    unsigned char  MaximumSnapLength[4];
    unsigned char  LinkLayerProtocol[4];

};

typedef struct packetHeader{


    /*
        here we convert char to int to find time
        and find length of the packet
    */

    unsigned char timestamp[4];            ///seconds since the start of 1970
    unsigned char PacketCapturedTime[4];  ///when the packet is captured
    //char LengthOfThePacket[4];
    unsigned char LengthOfThePacket[4];
    unsigned char Savedata[4];
    /*
        packet length without (Grobalheader+hexdump)(means 40 bytes)

    */
};



typedef struct IPv4Header{

    ///20 bytes;

    unsigned char VersionType;  ///0x45 -->IPv4 0x60 --> IPv6
    unsigned char DifferentiateServiceField;
    unsigned char TotalLength[2];  /// packetSize-14(Ethernet);
    unsigned char IdentificationLength[2];
    unsigned char StoreFlags;
    unsigned char FragmentOffset;
    unsigned char timeTolive;
    unsigned char protocol;
    unsigned char CheckSum;
    unsigned char  SourceIPaddress[4];
    unsigned char DestinationIPaddress[4];

};

typedef struct TcpHeader{

            ///0x06 --> 6 for tcp;

    unsigned char sourceportNumber[2];
    unsigned char destinationPort[2];
    unsigned char sequenceNumber[4];
    unsigned char acknowledgement[4];
    unsigned char headerLength;
    unsigned char flags;
    unsigned char windowSize[2];
    unsigned char checksum[2];
    unsigned char urgentPointer[2];
    //sssunsigned char optionalData[40];

};

typedef struct Udp{

        ///0x11  --->17  for Udp;

    unsigned char sourcePort[2];
    unsigned char destinationPort[2];
    unsigned char lengthOfData[2];
    unsigned char UdpCheckSum[2];


};




