#include "Server.hpp"

namespace rnitta
{


Server::Server()
{

}

void	Server::main_loop()
{
	while (true)
	{
		pollController_.poll_and_execute_IO();
		handle_request_from_client();
		handle_output_of_request();
	}
}

void	Server::handle_request_from_client()
{
	std::vector<Message>	_new_message_vec = pollController_.get_new_message_from_client();
	pollController_.clear_message_from_client();
	messageManager_.add_new_message(_new_message_vec);
	std::vector<Message>	_new_complete_message_vec = messageManager_.get_new_complete_message();
	messageManager_.clear_complete_message();
	requestManager_.run_new_request(_new_complete_message_vec);
	pollController_.set_output_fd(requestManager_.get_new_output_fd());
}

void	Server::handle_output_of_request()
{
	std::vector<Message>	_new_output_vec = pollController_.get_new_output_from_pipe();
	requestManager_.set_clientfd(_new_output_vec);
	std::vector<Message>	_message_to_sendback_vec = messageManager_.convert_output_into_message();
	pollController_.register_message_to_sendback(_message_to_sendback_vec);
}

};	// namespace rnitta
