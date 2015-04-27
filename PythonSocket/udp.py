import select, socket
from pykeyboard import PyKeyboard

port = 12345  # where do you expect to get a msg?
bufferSize = 1024 # whatever you need
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.bind(('192.168.43.187', port))
s.setblocking(0)
k = PyKeyboard()

while True:
    result = select.select([s],[],[])
    msg = result[0][0].recv(bufferSize)
    print msg
        
    k.tap_key(msg);