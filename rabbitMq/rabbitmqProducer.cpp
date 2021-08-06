#include"amqp.h"
#include"amqp_framing.h"
#include"amqp_tcp_socket.h"
#include <cassert> 
#include<iostream>
#include <Windows.h>
std::string RabbitMqIP = "127.0.0.1";
std::string RMQ_PublisherExchange = "Exchange1";
std::string exchangetype = "direct";
std::string RMQ_PublisherQueueName = "queue1";
std::string RMQ_PublisherRoutingKey = "test.queue";
std::string message = "Hello rabbitMq";

int RabbitMqPort = 5672;
static const int fixed_channel_id = 1;
static const int channel_id = 1;



int main()
{
	amqp_connection_state_t connection_state; //Creates a new amqp_connection_state_t object. 
	amqp_rpc_reply_t reply_t;  //contains the broker response 
	amqp_basic_properties_t properties;


	properties._flags = 0;
	properties._flags = AMQP_BASIC_DELIVERY_MODE_FLAG;
	properties.delivery_mode = AMQP_DELIVERY_NONPERSISTENT;


	amqp_bytes_t bytes = amqp_cstring_bytes(message.c_str());
	connection_state = amqp_new_connection();

	amqp_socket_t* socket;
	socket = amqp_tcp_socket_new(connection_state);
	assert(socket);
	int socket_open = amqp_socket_open(socket, RabbitMqIP.c_str(), RabbitMqPort);
	assert(socket_open == AMQP_STATUS_OK);

	//amqp_rpc_reply_t reply_t;
	reply_t = amqp_login(connection_state, "/", 1, AMQP_DEFAULT_FRAME_SIZE, AMQP_DEFAULT_HEARTBEAT, AMQP_SASL_METHOD_PLAIN, "finsoltech", "pass123!");
	if (reply_t.library_error == 0)
	{
		std::cout << "successfully login to the rabbitMQ_Producer" << std::endl;
	}
	else
	{

		std::cout << reply_t.library_error << std::endl;
		std::cout << "PLEASE CHECK RABBIT MQ IP AND PORT" << std::endl;
	}


	amqp_channel_open_ok_t* channel_open;
	channel_open = amqp_channel_open(connection_state, channel_id);
	std::cout << amqp_get_rpc_reply(connection_state).reply_type << std::endl;

	amqp_exchange_declare(connection_state, channel_id, amqp_cstring_bytes(RMQ_PublisherExchange.c_str()), amqp_cstring_bytes(exchangetype.c_str()), 0, 0, 0, 0, amqp_empty_table);
	std::cout << "Exchange declaring \n";
	amqp_queue_declare_ok_t* queue_declare;
	std::cout << "Queue declaring \n";
	queue_declare = amqp_queue_declare(connection_state, channel_id, amqp_cstring_bytes(RMQ_PublisherQueueName.c_str()), 0, 0, 0, 0, amqp_empty_table);
	std::cout << "Queue declared ==" << queue_declare;
	amqp_queue_bind(connection_state, channel_id, amqp_cstring_bytes(RMQ_PublisherQueueName.c_str()), amqp_cstring_bytes(RMQ_PublisherExchange.c_str()), amqp_cstring_bytes(RMQ_PublisherRoutingKey.c_str()), amqp_empty_table);

	std::cout << "bytes lengt== " << bytes.len;
	while (1)
	{

		auto return_value = amqp_basic_publish(connection_state, 1, amqp_cstring_bytes(RMQ_PublisherExchange.c_str()), amqp_cstring_bytes(RMQ_PublisherRoutingKey.c_str()), 1, 0, &properties, bytes);
		std::cout << "Message Sent  ";

		Sleep(1000);
	}
}