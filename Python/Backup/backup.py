#!/usr/bin/python3.5

import os
import time
import getpass
import paramiko


#create a bunch of files
os.system('touch file1')
os.system('mkdir testdir')
os.system('touch testdir/file2')
os.system('touch testdir/file3')
os.system('touch file4')
os.system('touch file5')


#wait for 30 seconds, create 5 more files
#time.sleep(30)
os.system('touch file6')
os.system('mkdir testdir2')
os.system('touch testdir2/file7')
os.system('touch testdir2/file8')
os.system('touch testdir2/file9')
os.system('touch file10')


#find files mofied within last 3 mins, sednd to tarball 
os.system("find . -mmin -3 | tar -czvf backup.tar.gz --null -T -")

#connect and send file
ssh_client=paramiko.SSHClient()
ssh_client.set_missing_host_key_policy(paramiko.AutoAddPolicy())
ssh_client.connect(hostname='ecc-linux.csuchico.edu', username='addollar', password='1Monkeypuppy$')

ftp_client=ssh_client.open_sftp()
ftp_client.put('/home/addollar/lab15/backup.tar.gz','user/home/addollar/CSCI344')
ftp_client.close()


