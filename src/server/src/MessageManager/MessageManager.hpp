#ifndef MESSAGEMANAGER_HPP
# define MESSAGEMANAGER_HPP

# include "../Message/Message.hpp"

namespace rnitta
{


class MessageManager
{
	public:
		// constructor
		MessageManager();
		MessageManager( const MessageManager& other );
		~MessageManager();
		MessageManager&	operator=( const MessageManager& otehr );
		
		// function
		void	add_new_message( const std::vector<Message>& new_message_vec );
		std::vector<Message>&	get_new_complete_message();
		void	clear_complete_message();
		std::vector<Message>&	convert_output_into_message();
	private:

};	// class MessageManager


};	// namespace rnitta

#endif
