import socket
import sys
from threading import Thread;

HOST="127.0.0.1"
PORT=9080

class threadingstart(Thread):
    def __init__(self,sock):
        print("start threading")
        Thread.__init__(self);
        self.sock=sock
    def run(self):
        print("Entering thread")
        while True:
            print(self.sock.recv(1024).decode());

clinet_socket=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
clinet_socket.connect((HOST,PORT));
threadS=threadingstart(clinet_socket,)
threadS.start()
while True:
    #print(clinet_socket.recv(1024).decode())
    data=input("Msg: ")
    clinet_socket.send(data.encode())
