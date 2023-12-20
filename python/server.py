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
    server_socket.listen(5)
    client,addr=server_socket.accept();
    print("connection accepted")
    client.send(b"Echo server accepted your connection")
    while True:
        data=client.recv(1024);
        data=data.decode()
        data=b"H3ckr: "+data.encode()
        client.send(data);
    

if __name__=="__main__":
    sys.exit(server())



