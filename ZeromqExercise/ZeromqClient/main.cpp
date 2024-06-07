#pragma comment(lib, "libzmq-v120-mt-4_3_4.lib")
#include <zmq.h>
#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	cout << "=== Connecting to ZeroMQ Server ===\r\n" << endl;
	void* context = zmq_ctx_new();
	void* client = zmq_socket(context, ZMQ_REQ);
	zmq_connect(client, "tcp://localhost:5555");

	char buffer[10] = { 0 };
	int request_nbr = 0;
	for (request_nbr = 0; request_nbr < 1; request_nbr++)
	{
		zmq_send(client, "hello", 9, 0);
		printf("Client Send: [hello]\n");
		memset(buffer, 0x00, 10);
		zmq_recv(client, buffer, 10, 0);
		printf("Client Recv: [%s]\n", buffer);
	}
	zmq_close(client);
	zmq_ctx_destroy(context);

	system("pause");

	return 0;
}
