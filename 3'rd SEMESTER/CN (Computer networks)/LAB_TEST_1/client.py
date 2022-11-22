import socket, pickle
from random import randint
from select import select
from time import sleep

IP = "0"
PORT = 0
ADDR = (IP, PORT)

MAT_SIZE = 3

mat = [[""] * MAT_SIZE for i in range(MAT_SIZE)]

udp = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
udp.sendto(str.encode(""), ADDR)

tcp = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
tcp.connect(ADDR)

input = [tcp, udp]
while True:
    i = randint(0, MAT_SIZE - 1)
    j = randint(0, MAT_SIZE - 1)
    pos = i, j
    tcp.send(pickle.dumps(pos))
    inputRd = select(input, [], [])
    inputRd = inputRd[0][0]
    data = None
    if inputRd == tcp:
        data = pickle.loads(tcp.recv(128))
    elif inputRd == udp:
        data, _ = udp.recvfrom(128)
        data = data.decode()
    print(data)
    if "Game over" in data or "You won" in data:
        break
    sleep(0.025)
