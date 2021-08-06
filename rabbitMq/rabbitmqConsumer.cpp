#include"amqp.h"
#include"amqp_framing.h"
#include"amqp_tcp_socket.h"
#include <cassert> 
#include<iostream>


static void run(amqp_connection_state_t conn) {

	std::cout << "Inside run\n";
	amqp_envelope_t envelope;
	amqp_rpc_reply_t ret;

	amqp_maybe_release_buffers(conn);
	
	while (1)
	{
		ret = amqp_consume_message(conn, &envelope, NULL, 0);
		//amqp_message_t message;

		size_t length = envelope.message.body.len;
		std::string message((char*)envelope.message.body.bytes, length);
		std::cout << "length =  " << message << std::endl;
	}
}


int main()
{
	std::string RabbitMqIP = "127.0.0.1";
	std::string RMQ_ConsumerExchange = "Exchange1";
	std::string exchangetype = "direct";
	std::string RMQ_ConsumerQueueName = "queue1";
	std::string RMQ_ConsumerRoutingKey = "test.queue";
	std::string message = "Hello rabbitMq";

	int RabbitMqPort = 5672;
	static const int fixed_channel_id = 1;
	static const int channel_id = 1;
	amqp_connection_state_t connection_state;
	connection_state = amqp_new_connection();

	amqp_socket_t* socket;
	socket = amqp_tcp_socket_new(connection_state);
	assert(socket);

	int socket_open = amqp_socket_open(socket, RabbitMqIP.c_str(), RabbitMqPort);
	assert(socket_open == AMQP_STATUS_OK);

	amqp_rpc_reply_t reply_t;
	reply_t = amqp_login(connection_state, "/", 1, AMQP_DEFAULT_FRAME_SIZE, AMQP_DEFAULT_HEARTBEAT, AMQP_SASL_METHOD_PLAIN, "finsoltech", "pass123!");

	if (reply_t.library_error == 0)
	{
		std::cout << "successfully login to the rabbitMQ_Consumer" << std::endl;
	}
	else
	{
		
		std::cout << "PLEASE CHECK RABBIT MQ IP AND PORT" << std::endl;
	}

	amqp_channel_open_ok_t* channel_open;
	channel_open = amqp_channel_open(connection_state, channel_id);

	amqp_exchange_declare(connection_state, channel_id, amqp_cstring_bytes(RMQ_ConsumerExchange.c_str()), amqp_cstring_bytes(exchangetype.c_str()), 0, 0, 0, 0, amqp_empty_table);
	std::cout << "Exchange declared\n";
	amqp_queue_declare_ok_t* queue_declare;
	queue_declare = amqp_queue_declare(connection_state, channel_id, amqp_cstring_bytes(RMQ_ConsumerQueueName.c_str()), 0, 0, 0, 0, amqp_empty_table);
	std::cout << "Queue declaring\n";
	amqp_queue_bind(connection_state, channel_id, amqp_cstring_bytes(RMQ_ConsumerQueueName.c_str()), amqp_cstring_bytes(RMQ_ConsumerExchange.c_str()), amqp_cstring_bytes(RMQ_ConsumerRoutingKey.c_str()), amqp_empty_table);
	std::cout << "Queue declared\n";
	amqp_basic_consume(connection_state, channel_id, amqp_cstring_bytes(RMQ_ConsumerQueueName.c_str()), amqp_empty_bytes, 0, 1, 0, amqp_empty_table);
	run(connection_state);
}