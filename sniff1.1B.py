#!/usr/bin/env python3
from scapy.all import *

def process_packet(pkt):
   #hexdump(pkt)
   pkt.show()
   print("--------------------------------")
   
f = 'src host 172.16.10.130 and tcp and dst port 23'

sniff(iface='ens160', filter = f, prn=process_packet)
