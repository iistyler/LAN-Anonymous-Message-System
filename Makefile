P2P: P2PServer P2PClient P2PInterface
	gcc -std=c11 P2P.c P2PServer.o P2PClient.o P2PInterface.o -o P2P -lncurses

P2PServer: P2PServer.c
	gcc -std=c11 -c P2PServer.c -o P2PServer.o

P2PClient: P2PClient.c
	gcc -std=c11 -c P2PClient.c -o P2PClient.o

P2PInterface: P2PInterface.c
	gcc -std=c11 -c P2PInterface.c -o P2PInterface.o

clean:
	rm -rf *.o
	rm P2P