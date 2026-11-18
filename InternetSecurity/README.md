## Internet Security: A Hands-on Approach
- Section 1: Course Overview, Lab Setup, and Network Basics
  1. Course Overview (Part I)
  2. Course Overview (Part II)
    - https://seedsecuritylabs.org
  3. Lab Exercises and Setup
  4. Network Basics: IP Addresses
    - Class A: 8+24, 8 is the network address, starting 0, have 2^24 mathines
      -                           |<--      Host ID       -->
      - 0.0.0.0         = 00000000.00000000.00000000.00000000
      - 127.255.255.255 = 01111111.11111111.11111111.11111111
    - Class B: 16+16, 16 is the network address, starting 10, have 2^16 mathines
      -                                    |<--  Host ID  -->
      - 128.0.0.0       = 10000000.00000000.00000000.00000000
      - 191.255.255.255 = 10111111.11111111.11111111.11111111
    - Class C: 24+8, 24 is the network address, starting 110, have 2^8 mathines
      -                                            | Host ID>
      - 192.0.0.0       = 11000000.00000000.00000000.00000000
      - 223.255.255.255 = 11011111.11111111.11111111.11111111
    - Class D: 28 bits: multicast group id, starting 1110
      -                       |<--     Address Range      -->
      - 224.0.0.0       = 11100000.00000000.00000000.00000000
      - 239.255.255.255 = 11101111.11111111.11111111.11111111
    - Class E: reserved, starting 1111
      -                       |<--     Address Range      -->
      - 240.0.0.0       = 11110000.00000000.00000000.00000000
      - 255.255.255.255 = 11111111.11111111.11111111.11111111
    - CIDR: Classless Inter-Domain Routing
    - Private IP Address
      - 10.0.0.0/8
      - 172.16.0.0/12
      - 192.168.0.0/16
    - Lookback Address
      - 127.0.0.0/8
      - commonly used: 127.0.0.1
  5. NAT and Summary
- Section 2: Packet Sniffing and Spoofing
  6. Introduction
