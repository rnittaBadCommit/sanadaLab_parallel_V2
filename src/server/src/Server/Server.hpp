#ifndef SERVER_HPP
# define SERVER_HPP

# include "../MessageManager/MessageManager.hpp"
# include "../PollController/PollController.hpp"
# include "../VersionUpdater/VersionUpdater.hpp"
# include "../RequestManager/RequestManager.hpp"

# include <vector>

namespace rnitta
{


class Server
{
	public:
		// constructor
		Server();
		Server( const Server& other );
		~Server();
		Server&	operator=( const Server& other );

		// function
		void	main_loop();

	private:
		MessageManager	messageManager_;
		PollController	pollController_;
		VersionUpdater	versionUpdater_;
		RequestManager	requestManager_;

		// function
		void	handle_request_from_client();
		void	handle_output_of_request();
	
};	// class Server


};	// namespace rnitta

#endif
