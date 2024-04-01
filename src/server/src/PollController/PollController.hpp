#ifndef POLLCONTROLLER_HPP
# define POLLCONTROLLER_HPP

# include "../Message/Message.hpp"

# include <vector>

namespace rnitta
{


class PollController
{
	public:
		// constructor
		PollController();
		PollController( const PollController& other );
		~PollController();
		PollController&	operator=( const PollController& other );

		// functions
		void	poll_and_execute_IO();
		std::vector<Message>&	get_new_message_from_client();
		void	clear_message_from_client();
		std::vector<Message>&	get_new_output_from_pipe();
		void	register_message_to_sendback( const std::vector<Message>& message_to_send_vec );
		void	set_output_fd( const std::vector<int>& new_output_fd );
	private:

};	// class PollController


};	// namespace rnitta


#endif
