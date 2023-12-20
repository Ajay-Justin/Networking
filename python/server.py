#!/usr/bin/python3

import socket
import select
import sys

HOST=""
PORT=9080
SERVER_LIST=[]

def server():
    server_socket=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    server_socket.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR,1)
    server_socket.bind((HOST,PORT))
    server_socket.listen()
    SERVER_LIST.append(server_socket);
    
    while True:
        ready_read,ready_write,ready_error=select.select([],[],[],0)
        for sock in ready_read:
            print("DOne")
if __name__=="__main__":
    sys.exit(server())



