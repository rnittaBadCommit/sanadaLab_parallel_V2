#ifndef REQUESTMANAGER_HPP
# define REQUESTMANAGER_HPP

# include "../Message/Message.hpp"

# include <vector>

namespace rnitta
{


class RequestManager
{
	public:
		// constructor
		RequestManager();
		RequestManager( const RequestManager& other );
		~RequestManager();
		RequestManager&	operator=( const RequestManager& other );

		// function
		void	run_new_request( const std::vector<Message>& new_complete_message );
		void	set_clientfd( std::vector<Message>& output );
		std::vector<int>	get_new_output_fd();
	private:

};	// class RequestManager


};	// namespace rnitta


#endif
