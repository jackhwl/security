#!/usr/bin/env python3
from scapy.all import *

pkt = sniff(iface='ens160', 
		filter='icmp or udp',
		count = 10)
pkt.summary()

