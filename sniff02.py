#!/usr/bin/env python3
from scapy.all import *

def process_packet(pkt):
   #hexdump(pkt)
   pkt.show()
   print("--------------------------------")
   
f = 'udp and dst portrange 50-55 or icmp'

sniff(iface='ens160', filter = f, prn=process_packet)
