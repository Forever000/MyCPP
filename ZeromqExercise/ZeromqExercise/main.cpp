#pragma comment(lib, "libzmq-v120-mt-4_3_4.lib")
#include <zmq.h>
#include <Windows.h>
#include<iostream>
#include<string>
#include<assert.h>
using namespace std;

int main()
{
	/*  Socket to talk to clients */
	void *context = zmq_ctx_new();
	void *responder = zmq_socket(context, ZMQ_REP);
	int rc = zmq_bind(responder, "tcp://*:5555");
	assert(rc == 0);

	while (1) {
		char buffer[10];
		memset(buffer, 0x00, sizeof(buffer));
		rc = zmq_recv(responder, buffer, 10, 0);
		//buffer[rc]=0;
		printf("Server Recv: [%s] space=%d\n", buffer, rc);
		Sleep(1);          //  Do some 'work'
		zmq_send(responder, "World", 9, 0);
		printf("Server Send: [world]\n");
	}
	return 0;
}

