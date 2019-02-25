"""
Donald Elrod
824006067
CSCE 315-501
Due: September 10, 2018
project1.py
"""
from contextlib import closing
from socket import socket, AF_INET, SOCK_DGRAM
import sys
import struct
import time
import tkinter as tk

NTP_PACKET_FORMAT = "!12I"
NTP_DELTA = 2208988800  # 1970-01-01 00:00:00
NTP_QUERY = '\x1b' + 47 * '\0'

servers = [
    '0.us.pool.ntp.org',
	'1.us.pool.ntp.org',
	'2.us.pool.ntp.org',
	'0.ubuntu.pool.ntp.org',
	'1.ubuntu.pool.ntp.org',
	'2.ubuntu.pool.ntp.org',
	'3.ubuntu.pool.ntp.org',
	'ntp.ubuntu.com',
	'time.apple.com',
	'time.windows.com',
	'time1.google.com',
	'time2.google.com',
	'time3.google.com',
	'time4.google.com',
	'ntp1.tamu.edu',
	'ntp2.tamu.edu',
	'ntp3.tamu.edu',
	'ops1.engr.tamu.edu',
	'ops2.engr.tamu.edu',
	'ops3.engr.tamu.edu',
	'ops4.engr.tamu.edu',
	'filer.cse.tamu.edu',
	'compute.cse.tamu.edu',
	'linux2.cse.tamu.edu',
	'dns1.cse.tamu.edu',
	'dns2.cse.tamu.edu',
	'dhcp1.cse.tamu.edu',
	'dhcp2.cse.tamu.edu' 
    ]

def create_gui(responses):
	root = tk.Tk()
	root.title('Server NTP Response Times')
	num_responses = len(responses)

	c_width = 400
	c_height = num_responses*20 + 50 #dynamically sizes window
	c = tk.Canvas(root, width=c_width, height=c_height, bg='white')
	c.pack()

	x_stretch = 150
	y_gap = 40
	y_width = 20
	x_gap = 20
	#index, value
	#this part was adapted from a stackoverflow post, but was changed
	#from a vertical bar graph to a horizontal bar graph
	#https://l.messenger.com/l.php?u=https%3A%2F%2Fstackoverflow.com%2F 	\
	# questions%2F35666573%2Fuse-tkinter-to-draw-a-specific-bar-chart&h=	\
	# AT1FxZcM4vdpMMo_CqFHmAk_fsbnZnbqS3_uu7RZHftlAELzoaYfukEIDWpBVtKh9hyF-	\
	# Mv4Ker6fTctr6znSOiV6P-VIO8dp875nr3ftWAVjiSWuVOYIZY2UpBZh6PP-8NSaA 
	for x, y in enumerate(responses):
		x0 = x_gap
		y0 = x * y_width + y_gap

		x1 = y[0] * x_stretch  
		y1 = x * y_width + x_gap

		color = "red" if y[0] > 1 else "green"
		c.create_rectangle(x0,y0,x1,y1, fill=color)
		c.create_text(x0+10, y0, anchor=tk.SW, text="{:+.4f} seconds".format(y[0]))
		c.create_text(150, y0, anchor=tk.SW, text=str(y[1]))
	
	root.mainloop()

def ntp_time(host, port=123):
	s = socket( AF_INET, SOCK_DGRAM)
	response = False
	with closing(socket( AF_INET, SOCK_DGRAM)) as s:
		s.sendto(NTP_QUERY.encode(), (host.encode(), port))
		s.settimeout(5)
		try: #see if we get the response within 5 seconds
			msg, address = s.recvfrom(1024)
			response = True
		except: #if we don't
			print('socket timed out - no response in 5 seconds')

	if (response):
		unpacked = struct.unpack(NTP_PACKET_FORMAT, msg[0:struct.calcsize(NTP_PACKET_FORMAT)])
		return unpacked[10] + float(unpacked[11]) / 2**32 - NTP_DELTA
	else:
		return False

def get_differences(servers):
	total_diff = 0
	responses = 0
	differences = []
	for server in servers: #gets all the differences
		time_from_server = ntp_time(server)
		if (time_from_server == False):
			print('Host ' + server + ' timed out')
		else:
			time_diff = time_from_server - time.time()
			print(time.ctime(time_from_server).replace("  "," "), server, time_diff)
			differences.append([time_diff, server])
			total_diff += time_diff
			responses += 1
			time.sleep(0.250)
	return differences, total_diff, responses

def get_outlier(differences, mean_diff):
	max_diff = [0, 'no server was selected']
	for diff in differences:
		#gets the mean difference minus this particular server
		if (len(differences) == 1):
			max_diff = differences[0]
		else:
			specific_mean = ((mean_diff * len(differences)) - diff[0])/(len(differences)-1) 
			server_diff = abs(diff[0] - specific_mean)
			if (server_diff > max_diff[0]):
				max_diff = diff
	return max_diff

if __name__ == "__main__":
	differences, total_diff, responses = get_differences(servers)
	if (responses == 0):
		print('all servers timed out, have a good day')
	else:
		print('done querying servers, now finding outliers')
		mean_diff = total_diff / responses
		max_diff = get_outlier(differences, mean_diff)
		print('the biggest outlier is ' + max_diff[1] + ', with a difference of', max_diff[0], 'seconds')
		create_gui(differences)