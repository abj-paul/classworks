#!/bin/bash

mkdir $1
cd $1
sudo nmap $1 -A -oN $1.all.txt
sudo nmap --script=http-sitemap-generator $1 -oN $1.sitemap.txt
sudo nmap --script=dns-brute $1 -oN $1.domain.txt
sudo -D RND nmap $1 -oN $1.ids.txt

# Fahim Ones
sudo nmap $1 -oN $1.target_specification.txt
# Scans
sudo nmap $1 -sS -oN $1.scan_syn_port.txt # Dont establish a conenction, just send a SYN pack
sudo nmap $1 -sT -oN $1.scan_tcp_port.txt # Establishes TCP connection
sudo nmap $1 -sU -oN $1.scan_udp_port.txt 
sudo nmap $1 -sA -oN $1.scan_ack_port.txt # Just send a ACK package. Its useful when you just want to see if the firewall is stateful or stateless.
# Host Discovery
sudo nmap $1 -sL -oN $1.scan_list_targets.txt
sudo nmap $1 -PS22-25,80 -oN $1.tcp_list_targets.txt # Previous TCP SYN but now scan only selected ports
sudo nmap $1 -PU53 -oN $1.udp_list_targets.txt # UDP discovery
# Port Scan
sudo nmap $1 -p 21 -oN $1.port_scan.txt
sudo nmap $1 -p 21 -oN $1.port_scan.txt
sudo nmap $1 -p 21-100 -oN $1.range_port_scan.txt
sudo nmap $1 -p U:53,T:21-100,443 -oN $1.mixed_port_scan.txt
# Service & Version
sudo nmap $1 -sV -oN $1.service.txt
sudo nmap $1 -sV --version-intensity 8 -oN $1.service_intensity.txt
# Some commands after the one above were ignored as they were clearly not touched by our instructor of nmap.
# NSE Scripts
nmap $1 -sC -oN $1.script_default.txt
nmap -Pn --script=http-sitemap-generator $1 -oN $1.script_sitemap.txt
nmap -p80 --script=http-unsafe-output-escaping $1 -oN $1.script_crossite.txt
nmap $1 --open -oN $1.script_open_ports.txt
# IDS
sudo nmap -D RND $1 -A -oN $1.ids_all.txt
# Find random servers to hunt!
sudo nmap -n -Pn -p 80 --open -sV -vvv --script banner,http-title -iR 1000 -oN $1.random_servers.txt




