import socket, pickle
from threading import Thread
from time import sleep

IP = "192.168.101.99"
PORT = 7778
ADDR = (IP, PORT)

MAT_SIZE = 3

clients = list()
matrices = list()

def isFull(clIdx):
    for i in range(MAT_SIZE):
        for j in range(MAT_SIZE):
            if matrices[clIdx][i][j] == "":
                return 0
    return 1

def validPos(pos, clIdx):
    i, j = pos
    for _ in range(MAT_SIZE):
        for _ in range(MAT_SIZE):
            if matrices[clIdx][i][j] == "X":
                return -1
    matrices[clIdx][i][j] = "X"

def game(client, add):
    if not client in clients:
        clients.append([client, add])
        mat = [[""] * MAT_SIZE for i in range(MAT_SIZE)]
        matrices.append(mat)
    clIdx = clients.index([client, add])
    while True:
        if isFull(clIdx):
            for c in clients:
                if c[1] == add:
                    s1.sendto(str.encode("You won!"), c[1])
                else:
                    s1.sendto(str.encode(f'Client {clIdx} won!\nGame over!'), c[1])
        else:
            pos = pickle.loads(client.recv(128))
            if validPos(pos, clIdx) == -1:
                client.send(pickle.dumps(f'{pos} not a valid position'))
            else:
                validPos(pos, clIdx)
                client.send(pickle.dumps(f'{pos} is a valid position'))

s1 = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s1.bind(ADDR)

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
s.bind(ADDR)
s.listen(5)

while True:
    _, add = s1.recvfrom(128)
    client, _ = s.accept()
    th = Thread(target=game, args=(client, add,))
    th.start()