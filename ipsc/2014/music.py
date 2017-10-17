import binascii
f = open("l1.mp3", "rb")
s = ""
buf = [0] * 16
try:
  byte = f.read(1)
  while byte != "":
    s = s + binascii.hexlify(byte)
finally:
  f.close();

f.close()
